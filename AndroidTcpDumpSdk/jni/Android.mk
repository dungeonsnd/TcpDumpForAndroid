######################################
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)  
LOCAL_MODULE := libpcap
LOCAL_SRC_FILES := ./armeabi/libpcap.a
include $(PREBUILT_STATIC_LIBRARY) 

include $(CLEAR_VARS)
LOCAL_MODULE    := tcpdumpinterface
LOCAL_SRC_FILES := com_mtzijin_androidtcpdumpsdk_TcpDumpInterface.cpp
LOCAL_C_INCLUDES := ./jni/libpcap-1.7.4
LOCAL_STATIC_LIBRARIES :=libpcap

LOCAL_LDLIBS :=  -L$(SYSROOT)/usr/lib -llog
include $(BUILD_SHARED_LIBRARY)
