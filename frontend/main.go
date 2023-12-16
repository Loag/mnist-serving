package main

import (
	"io"

	pb "model_serving_frontend/routing"

	"github.com/gin-gonic/gin"
	"google.golang.org/grpc"
	"google.golang.org/grpc/credentials/insecure"
)

func main() {
	conn, err := grpc.Dial("localhost:50051", grpc.WithTransportCredentials(insecure.NewCredentials()))
	if err != nil {
		println(err.Error())
	}

	inferenceClient := pb.NewInferenceServiceClient(conn)

	router := gin.Default()

	router.POST("/upload", func(c *gin.Context) {

		file, _, err := c.Request.FormFile("file")
		if err != nil {
			c.JSON(500, gin.H{
				"message": "Error posting file",
			})
		}

		defer file.Close()

		bytes, err := io.ReadAll(file)
		if err != nil {
			c.JSON(500, gin.H{
				"message": "Error reading file",
			})
		}
		res, err := inferenceClient.Infer(c, &pb.InferenceRequest{File: bytes})

		if err != nil {
			c.JSON(500, gin.H{
				"message": "Error infering integer image",
			})			
		}

		c.JSON(200, gin.H{
			"message": "success",
			"result": res.Number,
		})	
	})
	router.Run(":8080")
}
