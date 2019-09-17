/**
 * Writed by RogerYu 2019-09-17
 */
 
#define LOG_TAG "IAnonymousBinder"

#include <binder/Parcel.h>
#include <IAnonymousBinder.h>

namespace android {

enum {
    TEST = IBinder::FIRST_CALL_TRANSACTION,
};

class BpAnonymousBinder : public BpInterface<IAnonymousBinder>
{
public:
    BpAnonymousBinder(const sp<IBinder>& impl)
                        : BpInterface<IAnonymousBinder>(impl)
    {}

    status_t test(const char *str) {
        Parcel data, reply;
        data.writeInterfaceToken(IAnonymousBinder::getInterfaceDescriptor());
        data.writeCString(str);
        status_t status = remote()->transact(TEST, data, &reply);
        if(status != NO_ERROR) {
            ALOGE("call test error: %s", strerror(-status));
        } else {
            status = reply.readInt32();
        }
        return status;
    }

};


IMPLEMENT_META_INTERFACE(AnonymousBinder, "android.test.IAnonymousBinder");

status_t BnAnonymousBinder::onTransact(uint32_t code,
                            const Parcel& data,
                            Parcel* reply,
                            uint32_t flags)
{
    switch(code) {
        case TEST: {
            CHECK_INTERFACE(IAnonymousBinder, data, reply);
            const char * str;
            str = data.readCString();
            reply->writeInt32(test(str));
            return NO_ERROR;
        }
        default: {
            return BBinder::onTransact(code, data, reply, flags);
        }
    }
}

}; //namespace android