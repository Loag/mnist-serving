#include <iostream>
#include "onnxruntime/onnxruntime_cxx_api.h"
#include "service.pb.h"
#include "service.grpc.pb.h"
#include <grpcpp/grpcpp.h>

using namespace std;
using namespace routing;

class InferenceRPC final : public InferenceService::Service {
    grpc::Status Infer(grpc::ServerContext* context, const InferenceRequest* request, InferenceResponse* response) override {
        response->set_number("1");
        return grpc::Status::OK;
    }

    grpc::Status Available(grpc::ServerContext* context, const ::google::protobuf::Empty* request, IsAvailable* response) override {
        response->set_isavailable(true);
        return grpc::Status::OK;     
    }
};

void RunServer() {
    auto server_address("0.0.0.0:50051");

    InferenceRPC service;
    grpc::ServerBuilder builder;

    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    unique_ptr<grpc::Server> server(builder.BuildAndStart());


    std::cout << "Server listening on " << server_address << std::endl;

    // Wait for the server to shutdown.
    server->Wait();
}


int main(int argc, char* argv[]) {
    try {
        RunServer();

    } catch (const exception& err) {
        cerr << "Error: " << err.what() << endl;
        return 1;
    }

    return 0;
}
