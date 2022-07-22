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
    $(LOCAL_DIR)/derpfest_Mi439.mk

COMMON_LUNCH_CHOICES += \
    derpfest_Mi439-user \
    derpfest_Mi439-userdebug \
    derpfest_Mi439-eng
