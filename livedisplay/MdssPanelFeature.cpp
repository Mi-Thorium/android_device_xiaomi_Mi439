/*
 * Copyright (C) 2019-2021 The LineageOS Project
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

#include "livedisplay/xiaomi_mi439/MdssPanelFeature.h"

#include <android-base/file.h>

using ::android::base::WriteStringToFile;

using ::vendor::lineage::livedisplay::V2_0::xiaomi_mi439::AdaptiveBacklight;
using ::vendor::lineage::livedisplay::V2_0::xiaomi_mi439::ColorEnhancement;

MdssPanelFeature panel;

constexpr const char* kNode = "/sys/devices/virtual/graphics/fb0/msm_fb_custom_panel_cmds";

bool MdssPanelFeature::isSupported() {
    return !access(kNode, W_OK);
}

bool MdssPanelFeature::Initialize() {
    mAdaptiveBacklightEnabled = false;
    mColorEnhancementEnabled = false;
    return sendCmds();
}

bool MdssPanelFeature::isAdaptiveBacklightEnabled() {
    return mAdaptiveBacklightEnabled;
}

bool MdssPanelFeature::isColorEnhancementEnabled() {
    return mColorEnhancementEnabled;
}

bool MdssPanelFeature::setAdaptiveBacklightEnabled(bool enabled) {
    bool orig = mAdaptiveBacklightEnabled;
    bool ret;

    mAdaptiveBacklightEnabled = enabled;

    ret = sendCmds();
    if (!ret) { // Failure
        mAdaptiveBacklightEnabled = orig;
        sendCmds();
    }

    return ret;
}

bool MdssPanelFeature::setColorEnhancementEnabled(bool enabled) {
    bool orig = mColorEnhancementEnabled;
    bool ret;

    mColorEnhancementEnabled = enabled;

    ret = sendCmds();
    if (!ret) { // Failure
        mColorEnhancementEnabled = orig;
        sendCmds();
    }

    return ret;
}

bool MdssPanelFeature::sendCmds() {
    std::string buf = "";

    // AdaptiveBacklight
    buf.append(mAdaptiveBacklightEnabled ?
        "qcom,mdss-dsi-CABC_UI_on-command" :
        "qcom,mdss-dsi-CABC_off-command");
    buf.append("\n");

    // ColorEnhancement
    buf.append(mColorEnhancementEnabled ?
        "qcom,mdss-dsi-CE_on-command" :
        "qcom,mdss-dsi-CE_off-command");

    return WriteStringToFile(buf, kNode, true);
}

namespace vendor {
namespace lineage {
namespace livedisplay {
namespace V2_0 {
namespace xiaomi_mi439 {

AdaptiveBacklight::AdaptiveBacklight() {}

ColorEnhancement::ColorEnhancement() {}

Return<bool> AdaptiveBacklight::isEnabled() {
    return panel.isAdaptiveBacklightEnabled();
}

Return<bool> ColorEnhancement::isEnabled() {
    return panel.isColorEnhancementEnabled();
}

Return<bool> AdaptiveBacklight::setEnabled(bool enabled) {
    return panel.setAdaptiveBacklightEnabled(enabled);
}

Return<bool> ColorEnhancement::setEnabled(bool enabled) {
    return panel.setColorEnhancementEnabled(enabled);
}

}  // namespace xiaomi_mi439
}  // namespace V2_0
}  // namespace livedisplay
}  // namespace lineage
}  // namespace vendor
