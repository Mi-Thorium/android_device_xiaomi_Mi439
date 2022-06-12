#
# Copyright (C) 2021 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

PRODUCT_MAKEFILES := \
    $(LOCAL_DIR)/lineage_Mi439.mk

COMMON_LUNCH_CHOICES := \
    lineage_Mi439-user \
    lineage_Mi439-userdebug \
    lineage_Mi439-eng

PRODUCT_MAKEFILES += \
    $(LOCAL_DIR)/awaken_Mi439.mk

COMMON_LUNCH_CHOICES += \
    awaken_Mi439-user \
    awaken_Mi439-userdebug \
    awaken_Mi439-eng
