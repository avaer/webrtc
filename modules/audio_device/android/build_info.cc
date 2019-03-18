/*
 *  Copyright (c) 2015 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "modules/audio_device/android/build_info.h"

#include "modules/utility/include/helpers_android.h"

namespace webrtc {

BuildInfo::BuildInfo()
    : // j_environment_(JVM::GetInstance()->environment()),
      j_build_info_(JavaClass(nullptr, nullptr)) {}

std::string BuildInfo::GetStringFromJava(const char* name) {
  return std::string();
  /* jmethodID id = j_build_info_.GetStaticMethodId(name, "()Ljava/lang/String;");
  jstring j_string =
      static_cast<jstring>(j_build_info_.CallStaticObjectMethod(id));
  return j_environment_->JavaToStdString(j_string); */
}

std::string BuildInfo::GetDeviceModel() {
  return std::string();
  // return GetStringFromJava("getDeviceModel");
}

std::string BuildInfo::GetBrand() {
  return std::string();
  // return GetStringFromJava("getBrand");
}

std::string BuildInfo::GetDeviceManufacturer() {
  return std::string();
  // return GetStringFromJava("getDeviceManufacturer");
}

std::string BuildInfo::GetAndroidBuildId() {
  return std::string();
  // return GetStringFromJava("getAndroidBuildId");
}

std::string BuildInfo::GetBuildType() {
  return std::string();
  // return GetStringFromJava("getBuildType");
}

std::string BuildInfo::GetBuildRelease() {
  return std::string();
  // return GetStringFromJava("getBuildRelease");
}

SdkCode BuildInfo::GetSdkVersion() {
  return static_cast<SdkCode>(1);
  /* jmethodID id = j_build_info_.GetStaticMethodId("getSdkVersion", "()I");
  jint j_version = j_build_info_.CallStaticIntMethod(id);
  return static_cast<SdkCode>(j_version); */
}

}  // namespace webrtc
