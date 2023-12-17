# mnist-serving

## setup

### c++ grpc

``` bash
sudo apt-get install libgrpc++-dev libprotobuf-dev protobuf-compiler-grpc

# sys monitor
sudo apt-get install htop
```

``` bash
# c++
protoc -I . --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` *.proto
protoc --cpp_out=. *.proto
```

### golang grpc

``` bash

# install protobuf go compiler 
 go install google.golang.org/protobuf/cmd/protoc-gen-go@latest
 go install google.golang.org/grpc/cmd/protoc-gen-go-grpc@latest

 # add to path
 $ export PATH="$PATH:$(go env GOPATH)/bin"
```

``` bash
# build golang bindings
protoc --go_out=. --go_opt=paths=source_relative --go-grpc_out=. --go-grpc_opt=paths=source_relative *.proto
```