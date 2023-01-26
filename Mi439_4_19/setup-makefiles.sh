#!/bin/bash
#
# Copyright (C) 2016 The CyanogenMod Project
# Copyright (C) 2017-2020 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

set -e

export DEVICE=Mi439_4_19
export DEVICE_PARENT=Mi439
export DEVICE_COMMON=mithorium-common
export VENDOR=xiaomi

MY_DIR="$(cd "$(dirname "${0}")"; pwd -P)"

"${MY_DIR}/../../../${VENDOR}/${DEVICE_COMMON}/setup-makefiles.sh" "--kernel-4.19" "$@"
