/*
 *  Copyright 2017 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "api/proxy.h"

#include <iostream>

namespace webrtc {
namespace internal {

SynchronousMethodCall::SynchronousMethodCall(rtc::MessageHandler* proxy)
    : e_(), proxy_(proxy) {}

SynchronousMethodCall::~SynchronousMethodCall() = default;

void SynchronousMethodCall::Invoke(const rtc::Location& posted_from,
                                   rtc::Thread* t) {
  std::cout << "SynchronousMethodCall::Invoke 1 " << t->IsCurrent() << std::endl;
  if (t->IsCurrent()) {
    std::cout << "SynchronousMethodCall::Invoke 2" << std::endl;
    proxy_->OnMessage(nullptr);
    std::cout << "SynchronousMethodCall::Invoke 3" << std::endl;
  } else {
    std::cout << "SynchronousMethodCall::Invoke 4" << std::endl;
    e_.reset(new rtc::Event(false, false));
    std::cout << "SynchronousMethodCall::Invoke 5" << std::endl;
    t->Post(posted_from, this, 0);
    std::cout << "SynchronousMethodCall::Invoke 6" << std::endl;
    e_->Wait(rtc::Event::kForever);
    std::cout << "SynchronousMethodCall::Invoke 7" << std::endl;
  }
  std::cout << "SynchronousMethodCall::Invoke 8" << std::endl;
}

void SynchronousMethodCall::OnMessage(rtc::Message*) {
  proxy_->OnMessage(nullptr);
  e_->Set();
}

}  // namespace internal
}  // namespace webrtc
