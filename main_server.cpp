/**
 * Writed by RogerYu 2019-09-17
 */

#define LOG_TAG "main_server"

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>

#include <RealnameBinder.h>

using namespace android;

int main(int argc, char *agrv[])
{

    ProcessState::self()->startThreadPool();
    ALOGI("RealnameBinder server is starting now");

    sp<RealnameBinder>  binder = new RealnameBinder();
    sp<IServiceManager> sm(defaultServiceManager());
    sm->addService(String16("RealnameBinder"), binder, false);
    IPCThreadState::self()->joinThreadPool();
    
    return 0;
}