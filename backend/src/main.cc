#include <iostream>
#include "onnxruntime/onnxruntime_cxx_api.h"
#include "service.pb.h"
#include "service.grpc.pb.h"
#include <grpcpp/grpcpp.h>

using namespace std;
using namespace routing;

const ORTCHAR_T* model_path = "mnist.onnx"; // Replace "model.onnx" with the actual model file path
Ort::Session session_{nullptr};
auto memory_info = Ort::MemoryInfo::CreateCpu(OrtDeviceAllocator, OrtMemTypeCPU);

static void softmax(std::array<float, 10>& input) {
  float rowmax = *std::max_element(input.begin(), input.end());
  std::vector<float> y(input.size());
  float sum = 0.0f;
  for (size_t i = 0; i != input.size(); ++i) {
    sum += y[i] = std::exp(input[i] - rowmax);
  }
  for (size_t i = 0; i != input.size(); ++i) {
    input[i] = y[i] / sum;
  }
}

class InferenceRPC final : public InferenceService::Service {
    grpc::Status Infer(grpc::ServerContext* context, const InferenceRequest* request, InferenceResponse* response) override {

        try {
            vector<float> filedata(request->file().begin(), request->file().end());
            vector<int64_t> input_tensor_shape = {1, 784};

            Ort::Value input_tensor_ = Ort::Value::CreateTensor<float>(
                memory_info,                  // You need to define memory_info
                filedata.data(),   // Pointer to the data vector
                filedata.size(),   // Size of the data vector
                input_tensor_shape.data(),    // Pointer to the shape vector
                input_tensor_shape.size()     // Size of the shape vector
            );    

            const char* input_names[] = {"Input3"};
            const char* output_names[] = {"Plus214_Output_0"};

            std::array<float, 10> results_{};
            std::array<int64_t, 2> output_shape_{1, 10};

            auto output_tensor_ = Ort::Value::CreateTensor<float>(memory_info, results_.data(), results_.size(),
                                                            output_shape_.data(), output_shape_.size());

            session_.Run(Ort::RunOptions{nullptr}, input_names, &input_tensor_, 1, output_names, &output_tensor_, 1);

            softmax(results_);
            int64_t result_ = std::distance(results_.begin(), std::max_element(results_.begin(), results_.end()));

            response->set_number(to_string(result_));
            return grpc::Status::OK;
        } catch (const exception& err) {
            cerr << "Error: " << err.what() << endl;
            return grpc::Status::CANCELLED;
        }
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
        Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "Default");

        Ort::SessionOptions session_options;
        session_options.SetIntraOpNumThreads(1);
        session_options.SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_ALL);
        
        session_ = Ort::Session(env, model_path, session_options);

        RunServer();

    } catch (const exception& err) {
        cerr << "Error: " << err.what() << endl;
        return 1;
    }

    return 0;
}
