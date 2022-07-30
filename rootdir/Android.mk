LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE       := fstab.qcom_ramdisk
LOCAL_MODULE_STEM  := fstab.qcom
LOCAL_MODULE_TAGS  := optional
LOCAL_MODULE_CLASS := ETC
ifeq ($(PRODUCT_USE_DYNAMIC_PARTITIONS),true)
LOCAL_SRC_FILES    := etc/fstab_dynpart.qcom
else
LOCAL_SRC_FILES    := etc/fstab.qcom
endif
LOCAL_MODULE_PATH  := $(TARGET_RAMDISK_OUT)
include $(BUILD_PREBUILT)
