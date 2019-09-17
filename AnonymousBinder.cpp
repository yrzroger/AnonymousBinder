/**
 * Writed by RogerYu 2019-09-17
 */

#define LOG_TAG "AnonymousBinder"

#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <AnonymousBinder.h>
#include <utils/Log.h>

namespace android {

status_t AnonymousBinder::test(const char *str) {
    ALOGI("%s[%d]: %s\n", __FUNCTION__, __LINE__, str);
    return NO_ERROR;
}

AnonymousBinder::AnonymousBinder() {
    ALOGI("AnonymousBinder is created");
}

AnonymousBinder::~AnonymousBinder() {
    ALOGI("AnonymousBinder is destroyed");
}

}; // namespace android
