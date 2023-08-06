/*
 * Copyright (C) 2019-2020 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "livedisplay/xiaomi_mi439/SunlightEnhancement.h"

#include <android-base/file.h>
#include <android-base/strings.h>

namespace {
constexpr const char* kFileHbm = "/sys/devices/virtual/graphics/fb0/msm_fb_hbm";
};  // anonymous namespace

using ::android::base::ReadFileToString;
using ::android::base::Trim;
using ::android::base::WriteStringToFile;

namespace vendor {
namespace lineage {
namespace livedisplay {
namespace V2_0 {
namespace xiaomi_mi439 {

SunlightEnhancement::SunlightEnhancement() {}

bool SunlightEnhancement::isSupported() {
    return !access(kFileHbm, R_OK | W_OK);
}

// Methods from ::vendor::lineage::livedisplay::V2_0::ISunlightEnhancement follow.
Return<bool> SunlightEnhancement::isEnabled() {
    std::string tmp;

    if (ReadFileToString(kFileHbm, &tmp)) {
        tmp.pop_back();
        return tmp == "hbm_mode:3";
    }

    return false;
}

Return<bool> SunlightEnhancement::setEnabled(bool enabled) {
    return WriteStringToFile(enabled ? "3" : "0", kFileHbm, true);
}

}  // namespace xiaomi_mi439
}  // namespace V2_0
}  // namespace livedisplay
}  // namespace lineage
}  // namespace vendor
