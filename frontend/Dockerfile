FROM golang:alpine as build

WORKDIR /usr/local/src

COPY . .

RUN go mod download

RUN CGO_ENABLED=0 GOARCH=amd64 GOOS=linux go build -a -installsuffix cgo -ldflags "-s -w" -o dist ./

FROM scratch
COPY --from=build /usr/local/src/dist dist

EXPOSE 8080

CMD ["/dist"]