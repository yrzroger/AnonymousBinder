/**
 * Writed by RogerYu 2019-09-17
 */


#define LOG_TAG "main_client"

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>
#include <utils/RefBase.h>
#include <IRealnameBinder.h>
#include <IAnonymousBinder.h>

using namespace android;

int main(int argc, char *argv[])
{
    ALOGI("RealnameBinder client is starting now");
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> b;
    sp<IRealnameBinder> sRealnameBinder;
    
    do {
        b = sm->getService(String16("RealnameBinder"));
        if(b != 0)
            break;
        ALOGI("RealnameBinder is not working, waiting...");
        usleep(500000);
    } while(true);
    
    sRealnameBinder = interface_cast<IRealnameBinder>(b);
    

    sp<IAnonymousBinder> binder = sRealnameBinder->createConnection();
    binder->test(argv[1]);

    
    return 0;
}