# mnist-serving

Learning how to host and run a model as a service.

## Design

- Golang frontend web service handling posts of mnist images.
- C++ onnxruntime service hosting model.
- grpc for service to service communication.
- simple mnist torch model

## setup

### c++ grpc

``` bash
# grpc libs
sudo apt-get install libgrpc++-dev libprotobuf-dev protobuf-compiler-grpc

# build cpp grpc defs
protoc -I . --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` *.proto
protoc --cpp_out=. *.proto
```

### golang grpc

``` bash
go install google.golang.org/protobuf/cmd/protoc-gen-go@latest
go install google.golang.org/grpc/cmd/protoc-gen-go-grpc@latest

export PATH="$PATH:$(go env GOPATH)/bin"

protoc --go_out=. --go_opt=paths=source_relative --go-grpc_out=. --go-grpc_opt=paths=source_relative *.proto
```


## build

``` bash
# backend
cd /backend/build && make

# frontend
go build -o dist main.go

# model
python mnist.py # model output in model dir
```