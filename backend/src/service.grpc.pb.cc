// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: service.proto

#include "service.pb.h"
#include "service.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace routing {

static const char* InferenceService_method_names[] = {
  "/routing.InferenceService/Infer",
  "/routing.InferenceService/Available",
};

std::unique_ptr< InferenceService::Stub> InferenceService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< InferenceService::Stub> stub(new InferenceService::Stub(channel));
  return stub;
}

InferenceService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_Infer_(InferenceService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Available_(InferenceService_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status InferenceService::Stub::Infer(::grpc::ClientContext* context, const ::routing::InferenceRequest& request, ::routing::InferenceResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Infer_, context, request, response);
}

void InferenceService::Stub::experimental_async::Infer(::grpc::ClientContext* context, const ::routing::InferenceRequest* request, ::routing::InferenceResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Infer_, context, request, response, std::move(f));
}

void InferenceService::Stub::experimental_async::Infer(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::routing::InferenceResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Infer_, context, request, response, std::move(f));
}

void InferenceService::Stub::experimental_async::Infer(::grpc::ClientContext* context, const ::routing::InferenceRequest* request, ::routing::InferenceResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Infer_, context, request, response, reactor);
}

void InferenceService::Stub::experimental_async::Infer(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::routing::InferenceResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Infer_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::routing::InferenceResponse>* InferenceService::Stub::AsyncInferRaw(::grpc::ClientContext* context, const ::routing::InferenceRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::routing::InferenceResponse>::Create(channel_.get(), cq, rpcmethod_Infer_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::routing::InferenceResponse>* InferenceService::Stub::PrepareAsyncInferRaw(::grpc::ClientContext* context, const ::routing::InferenceRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::routing::InferenceResponse>::Create(channel_.get(), cq, rpcmethod_Infer_, context, request, false);
}

::grpc::Status InferenceService::Stub::Available(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::routing::IsAvailable* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Available_, context, request, response);
}

void InferenceService::Stub::experimental_async::Available(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::routing::IsAvailable* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Available_, context, request, response, std::move(f));
}

void InferenceService::Stub::experimental_async::Available(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::routing::IsAvailable* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Available_, context, request, response, std::move(f));
}

void InferenceService::Stub::experimental_async::Available(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::routing::IsAvailable* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Available_, context, request, response, reactor);
}

void InferenceService::Stub::experimental_async::Available(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::routing::IsAvailable* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Available_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::routing::IsAvailable>* InferenceService::Stub::AsyncAvailableRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::routing::IsAvailable>::Create(channel_.get(), cq, rpcmethod_Available_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::routing::IsAvailable>* InferenceService::Stub::PrepareAsyncAvailableRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::routing::IsAvailable>::Create(channel_.get(), cq, rpcmethod_Available_, context, request, false);
}

InferenceService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      InferenceService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< InferenceService::Service, ::routing::InferenceRequest, ::routing::InferenceResponse>(
          [](InferenceService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::routing::InferenceRequest* req,
             ::routing::InferenceResponse* resp) {
               return service->Infer(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      InferenceService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< InferenceService::Service, ::google::protobuf::Empty, ::routing::IsAvailable>(
          [](InferenceService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::google::protobuf::Empty* req,
             ::routing::IsAvailable* resp) {
               return service->Available(ctx, req, resp);
             }, this)));
}

InferenceService::Service::~Service() {
}

::grpc::Status InferenceService::Service::Infer(::grpc::ServerContext* context, const ::routing::InferenceRequest* request, ::routing::InferenceResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status InferenceService::Service::Available(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::routing::IsAvailable* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace routing

