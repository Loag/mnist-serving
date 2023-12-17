package main

import (
	"image"
	"image/jpeg"
	pb "model_serving_frontend/routing"

	"github.com/gin-gonic/gin"
	"google.golang.org/grpc"
	"google.golang.org/grpc/credentials/insecure"
	"google.golang.org/protobuf/types/known/emptypb"
)

func to_bytes(img image.Image) []byte {
	// Convert the image to a byte slice
	bounds := img.Bounds()
	width, height := bounds.Max.X, bounds.Max.Y
	imgBytes := make([]byte, 0, width*height*3) // 3 bytes for each pixel in RGB

	for y := 0; y < height; y++ {
		for x := 0; x < width; x++ {
			r, g, b, _ := img.At(x, y).RGBA()
			// Convert 16-bit color to 8-bit color
			imgBytes = append(imgBytes, byte(r>>8), byte(g>>8), byte(b>>8))
		}
	}
	return imgBytes
}

func main() {
	conn, err := grpc.Dial("localhost:50051", grpc.WithTransportCredentials(insecure.NewCredentials()))
	if err != nil {
		println(err.Error())
	}

	inferenceClient := pb.NewInferenceServiceClient(conn)

	router := gin.Default()

	router.GET("/", func(c *gin.Context) {
		res, err := inferenceClient.Available(c, &emptypb.Empty{})

		if err != nil {
			c.JSON(500, gin.H{
				"message": "Error. backend not available.",
			})
		}

		c.JSON(200, gin.H{
			"message":   "success",
			"available": res.IsAvailable,
		})
	})

	router.POST("/upload", func(c *gin.Context) {

		file, _, err := c.Request.FormFile("file")
		if err != nil {
			c.JSON(500, gin.H{
				"message": "Error posting file",
			})
		}

		defer file.Close()

		img, err := jpeg.Decode(file)
		if err != nil {
			panic(err)
		}

		bytes := to_bytes(img)

		res, err := inferenceClient.Infer(c, &pb.InferenceRequest{File: bytes})

		if err != nil {
			c.JSON(500, gin.H{
				"message": "Error infering integer image",
				"error":   err.Error(),
			})
		}

		c.JSON(200, gin.H{
			"message": "success",
			"result":  res.Number,
		})
	})

	router.Run(":8080")
}
