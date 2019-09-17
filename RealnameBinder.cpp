/**
 * Writed by RogerYu 2019-09-17
 */

#define LOG_TAG "RealnameBinder"

#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <RealnameBinder.h>
#include <AnonymousBinder.h>
#include <utils/Log.h>

namespace android {

sp<IAnonymousBinder> RealnameBinder::createConnection() {
    ALOGI("createConnection: new AnonymousBinder");
    
    sp<IAnonymousBinder> binder = new AnonymousBinder;
    
    return binder;
}

RealnameBinder::RealnameBinder() {
    ALOGI("RealnameBinder is created");
}

RealnameBinder::~RealnameBinder() {
    ALOGI("RealnameBinder is destroyed");
}

}; // namespace android