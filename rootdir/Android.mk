LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE       := fstab.qcom_ramdisk
ifeq ($(MI439_UNIFY_BOOT_IMAGE_WITH_MI8937),true)
LOCAL_MODULE_STEM  := fstab.mi439
else
LOCAL_MODULE_STEM  := fstab.qcom
endif
LOCAL_MODULE_TAGS  := optional
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := etc/fstab.qcom
LOCAL_MODULE_PATH  := $(TARGET_RAMDISK_OUT)
include $(BUILD_PREBUILT)
