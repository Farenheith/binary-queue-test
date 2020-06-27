#include <napi.h>
#include <queue>

class BinaryQueue : public Napi::ObjectWrap<BinaryQueue> {
 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  BinaryQueue(const Napi::CallbackInfo& info);

 private:
  static Napi::FunctionReference constructor;
  std::queue<Napi::Reference<Napi::Value>> queue_;
  Napi::Value shift(const Napi::CallbackInfo& info);
  Napi::Value push(const Napi::CallbackInfo& info);
  Napi::Value getLength(const Napi::CallbackInfo& info);
};
