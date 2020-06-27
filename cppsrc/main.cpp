#include <napi.h>
#include "lib/binary-queue.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return BinaryQueue::Init(env, exports);
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)
