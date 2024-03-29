LOCAL_PATH:=$(call my-dir)

# build hello world service

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
                IRealnameBinder.cpp \
                RealnameBinder.cpp \
                IAnonymousBinder.cpp \
                AnonymousBinder.cpp
                
LOCAL_SHARED_LIBRARIES := \
                liblog \
                libcutils \
                libutils \
                libbinder \
    
LOCAL_C_INCLUDES := \
                $(LOCAL_PATH) \
                frameworks/native/include \
                system/core/base/include \

LOCAL_MODULE := libbindertest

include $(BUILD_SHARED_LIBRARY)

# build server

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
                main_server.cpp
                
LOCAL_SHARED_LIBRARIES := \
                libutils \
                libbinder \
                liblog \
                libbindertest \
                
LOCAL_PRELINK_MODULE := false

LOCAL_MODULE := main_server

include $(BUILD_EXECUTABLE)

# build client

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
                main_client.cpp
                
LOCAL_SHARED_LIBRARIES := \
                libutils \
                liblog \
                libbinder \
                libbindertest \
                
LOCAL_PRELINK_MODULE := false

LOCAL_MODULE := main_client

include $(BUILD_EXECUTABLE)