// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: service.proto
#ifndef GRPC_service_2eproto__INCLUDED
#define GRPC_service_2eproto__INCLUDED

#include "service.pb.h"

#include <functional>
#include <grpc/impl/codegen/port_platform.h>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace routing {

class InferenceService final {
 public:
  static constexpr char const* service_full_name() {
    return "routing.InferenceService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status Infer(::grpc::ClientContext* context, const ::routing::InferenceRequest& request, ::routing::InferenceResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::routing::InferenceResponse>> AsyncInfer(::grpc::ClientContext* context, const ::routing::InferenceRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::routing::InferenceResponse>>(AsyncInferRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::routing::InferenceResponse>> PrepareAsyncInfer(::grpc::ClientContext* context, const ::routing::InferenceRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::routing::InferenceResponse>>(PrepareAsyncInferRaw(context, request, cq));
    }
    virtual ::grpc::Status Available(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::routing::IsAvailable* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::routing::IsAvailable>> AsyncAvailable(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::routing::IsAvailable>>(AsyncAvailableRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::routing::IsAvailable>> PrepareAsyncAvailable(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::routing::IsAvailable>>(PrepareAsyncAvailableRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void Infer(::grpc::ClientContext* context, const ::routing::InferenceRequest* request, ::routing::InferenceResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void Infer(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::routing::InferenceResponse* response, std::function<void(::grpc::Status)>) = 0;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void Infer(::grpc::ClientContext* context, const ::routing::InferenceRequest* request, ::routing::InferenceResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void Infer(::grpc::ClientContext* context, const ::routing::InferenceRequest* request, ::routing::InferenceResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void Infer(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::routing::InferenceResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void Infer(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::routing::InferenceResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
      virtual void Available(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::routing::IsAvailable* response, std::function<void(::grpc::Status)>) = 0;
      virtual void Available(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::routing::IsAvailable* response, std::function<void(::grpc::Status)>) = 0;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void Available(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::routing::IsAvailable* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void Available(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::routing::IsAvailable* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void Available(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::routing::IsAvailable* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void Available(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::routing::IsAvailable* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
    };
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    typedef class experimental_async_interface async_interface;
    #endif
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    async_interface* async() { return experimental_async(); }
    #endif
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::routing::InferenceResponse>* AsyncInferRaw(::grpc::ClientContext* context, const ::routing::InferenceRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::routing::InferenceResponse>* PrepareAsyncInferRaw(::grpc::ClientContext* context, const ::routing::InferenceRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::routing::IsAvailable>* AsyncAvailableRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::routing::IsAvailable>* PrepareAsyncAvailableRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status Infer(::grpc::ClientContext* context, const ::routing::InferenceRequest& request, ::routing::InferenceResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::routing::InferenceResponse>> AsyncInfer(::grpc::ClientContext* context, const ::routing::InferenceRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::routing::InferenceResponse>>(AsyncInferRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::routing::InferenceResponse>> PrepareAsyncInfer(::grpc::ClientContext* context, const ::routing::InferenceRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::routing::InferenceResponse>>(PrepareAsyncInferRaw(context, request, cq));
    }
    ::grpc::Status Available(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::routing::IsAvailable* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::routing::IsAvailable>> AsyncAvailable(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::routing::IsAvailable>>(AsyncAvailableRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::routing::IsAvailable>> PrepareAsyncAvailable(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::routing::IsAvailable>>(PrepareAsyncAvailableRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void Infer(::grpc::ClientContext* context, const ::routing::InferenceRequest* request, ::routing::InferenceResponse* response, std::function<void(::grpc::Status)>) override;
      void Infer(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::routing::InferenceResponse* response, std::function<void(::grpc::Status)>) override;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void Infer(::grpc::ClientContext* context, const ::routing::InferenceRequest* request, ::routing::InferenceResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void Infer(::grpc::ClientContext* context, const ::routing::InferenceRequest* request, ::routing::InferenceResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void Infer(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::routing::InferenceResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void Infer(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::routing::InferenceResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
      void Available(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::routing::IsAvailable* response, std::function<void(::grpc::Status)>) override;
      void Available(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::routing::IsAvailable* response, std::function<void(::grpc::Status)>) override;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void Available(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::routing::IsAvailable* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void Available(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::routing::IsAvailable* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void Available(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::routing::IsAvailable* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void Available(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::routing::IsAvailable* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::routing::InferenceResponse>* AsyncInferRaw(::grpc::ClientContext* context, const ::routing::InferenceRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::routing::InferenceResponse>* PrepareAsyncInferRaw(::grpc::ClientContext* context, const ::routing::InferenceRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::routing::IsAvailable>* AsyncAvailableRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::routing::IsAvailable>* PrepareAsyncAvailableRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Infer_;
    const ::grpc::internal::RpcMethod rpcmethod_Available_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Infer(::grpc::ServerContext* context, const ::routing::InferenceRequest* request, ::routing::InferenceResponse* response);
    virtual ::grpc::Status Available(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::routing::IsAvailable* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_Infer : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_Infer() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Infer() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Infer(::grpc::ServerContext* /*context*/, const ::routing::InferenceRequest* /*request*/, ::routing::InferenceResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestInfer(::grpc::ServerContext* context, ::routing::InferenceRequest* request, ::grpc::ServerAsyncResponseWriter< ::routing::InferenceResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_Available : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_Available() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_Available() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Available(::grpc::ServerContext* /*context*/, const ::google::protobuf::Empty* /*request*/, ::routing::IsAvailable* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestAvailable(::grpc::ServerContext* context, ::google::protobuf::Empty* request, ::grpc::ServerAsyncResponseWriter< ::routing::IsAvailable>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Infer<WithAsyncMethod_Available<Service > > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_Infer : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_Infer() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(0,
          new ::grpc_impl::internal::CallbackUnaryHandler< ::routing::InferenceRequest, ::routing::InferenceResponse>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::routing::InferenceRequest* request, ::routing::InferenceResponse* response) { return this->Infer(context, request, response); }));}
    void SetMessageAllocatorFor_Infer(
        ::grpc::experimental::MessageAllocator< ::routing::InferenceRequest, ::routing::InferenceResponse>* allocator) {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
    #else
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::experimental().GetHandler(0);
    #endif
      static_cast<::grpc_impl::internal::CallbackUnaryHandler< ::routing::InferenceRequest, ::routing::InferenceResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_Infer() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Infer(::grpc::ServerContext* /*context*/, const ::routing::InferenceRequest* /*request*/, ::routing::InferenceResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* Infer(
      ::grpc::CallbackServerContext* /*context*/, const ::routing::InferenceRequest* /*request*/, ::routing::InferenceResponse* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* Infer(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::routing::InferenceRequest* /*request*/, ::routing::InferenceResponse* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_Available : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_Available() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(1,
          new ::grpc_impl::internal::CallbackUnaryHandler< ::google::protobuf::Empty, ::routing::IsAvailable>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::google::protobuf::Empty* request, ::routing::IsAvailable* response) { return this->Available(context, request, response); }));}
    void SetMessageAllocatorFor_Available(
        ::grpc::experimental::MessageAllocator< ::google::protobuf::Empty, ::routing::IsAvailable>* allocator) {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(1);
    #else
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::experimental().GetHandler(1);
    #endif
      static_cast<::grpc_impl::internal::CallbackUnaryHandler< ::google::protobuf::Empty, ::routing::IsAvailable>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_Available() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Available(::grpc::ServerContext* /*context*/, const ::google::protobuf::Empty* /*request*/, ::routing::IsAvailable* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* Available(
      ::grpc::CallbackServerContext* /*context*/, const ::google::protobuf::Empty* /*request*/, ::routing::IsAvailable* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* Available(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::google::protobuf::Empty* /*request*/, ::routing::IsAvailable* /*response*/)
    #endif
      { return nullptr; }
  };
  #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
  typedef ExperimentalWithCallbackMethod_Infer<ExperimentalWithCallbackMethod_Available<Service > > CallbackService;
  #endif

  typedef ExperimentalWithCallbackMethod_Infer<ExperimentalWithCallbackMethod_Available<Service > > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_Infer : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_Infer() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Infer() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Infer(::grpc::ServerContext* /*context*/, const ::routing::InferenceRequest* /*request*/, ::routing::InferenceResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_Available : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_Available() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_Available() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Available(::grpc::ServerContext* /*context*/, const ::google::protobuf::Empty* /*request*/, ::routing::IsAvailable* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_Infer : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_Infer() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_Infer() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Infer(::grpc::ServerContext* /*context*/, const ::routing::InferenceRequest* /*request*/, ::routing::InferenceResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestInfer(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_Available : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_Available() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_Available() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Available(::grpc::ServerContext* /*context*/, const ::google::protobuf::Empty* /*request*/, ::routing::IsAvailable* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestAvailable(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_Infer : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_Infer() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(0,
          new ::grpc_impl::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->Infer(context, request, response); }));
    }
    ~ExperimentalWithRawCallbackMethod_Infer() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Infer(::grpc::ServerContext* /*context*/, const ::routing::InferenceRequest* /*request*/, ::routing::InferenceResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* Infer(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* Infer(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_Available : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_Available() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(1,
          new ::grpc_impl::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->Available(context, request, response); }));
    }
    ~ExperimentalWithRawCallbackMethod_Available() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Available(::grpc::ServerContext* /*context*/, const ::google::protobuf::Empty* /*request*/, ::routing::IsAvailable* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* Available(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* Available(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Infer : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_Infer() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::routing::InferenceRequest, ::routing::InferenceResponse>(
            [this](::grpc_impl::ServerContext* context,
                   ::grpc_impl::ServerUnaryStreamer<
                     ::routing::InferenceRequest, ::routing::InferenceResponse>* streamer) {
                       return this->StreamedInfer(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_Infer() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Infer(::grpc::ServerContext* /*context*/, const ::routing::InferenceRequest* /*request*/, ::routing::InferenceResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedInfer(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::routing::InferenceRequest,::routing::InferenceResponse>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Available : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_Available() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler<
          ::google::protobuf::Empty, ::routing::IsAvailable>(
            [this](::grpc_impl::ServerContext* context,
                   ::grpc_impl::ServerUnaryStreamer<
                     ::google::protobuf::Empty, ::routing::IsAvailable>* streamer) {
                       return this->StreamedAvailable(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_Available() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Available(::grpc::ServerContext* /*context*/, const ::google::protobuf::Empty* /*request*/, ::routing::IsAvailable* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedAvailable(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::google::protobuf::Empty,::routing::IsAvailable>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_Infer<WithStreamedUnaryMethod_Available<Service > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_Infer<WithStreamedUnaryMethod_Available<Service > > StreamedService;
};

}  // namespace routing


#endif  // GRPC_service_2eproto__INCLUDED
