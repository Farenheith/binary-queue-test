#include "binary-queue.h"
#include <queue>

Napi::FunctionReference BinaryQueue::constructor;
Napi::Object BinaryQueue::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  // Napi::ClassPropertyDescriptor<BinaryQueue> prop = InstanceAccessor("length", &BinaryQueue::getLength, &BinaryQueue::setLength);
  Napi::Function func = DefineClass(env, "BinaryQueue", {
    InstanceAccessor("length", &BinaryQueue::getLength, nullptr),
    InstanceMethod("push", &BinaryQueue::push),
    InstanceMethod("shift", &BinaryQueue::shift)
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("BinaryQueue", func);
  return exports;
}

BinaryQueue::BinaryQueue(const Napi::CallbackInfo& info) : Napi::ObjectWrap<BinaryQueue>(info)  {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
}

Napi::Value BinaryQueue::shift(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (this->queue_.empty()) {
     return env.Undefined();
  }
  Napi::Value value = this->queue_.front().Value();
  this->queue_.pop();
  return Napi::Value::From(env, value);
}

Napi::Value BinaryQueue::push(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  int length = info.Length();

  for (int n = 0; n < length; n++) {
    Napi::Value value = info[n];
    this->queue_.push(Napi::Reference<Napi::Value>::New(value));
  }
  return Napi::Value::From(env, length);
}

Napi::Value BinaryQueue::getLength(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  return Napi::Number::New(env, this->queue_.size());
}