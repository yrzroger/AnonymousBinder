/**
 * Writed by RogerYu 2019-09-17
 */

#include <binder/Parcel.h>
#include <IRealnameBinder.h>

namespace android {

enum {
    CONNECTION = IBinder::FIRST_CALL_TRANSACTION,
};

class BpRealnameBinder : public BpInterface<IRealnameBinder>
{
public:
    BpRealnameBinder(const sp<IBinder>& impl)
                : BpInterface<IRealnameBinder>(impl)
    {}

    sp<IAnonymousBinder> createConnection() {
        Parcel data, reply;
        data.writeInterfaceToken(IRealnameBinder::getInterfaceDescriptor());
        remote()->transact(CONNECTION, data, &reply);
        return interface_cast<IAnonymousBinder>(reply.readStrongBinder());
    }

};


IMPLEMENT_META_INTERFACE(RealnameBinder, "android.test.IRealnameBinder");

status_t BnRealnameBinder::onTransact(uint32_t code,
                            const Parcel& data,
                            Parcel* reply,
                            uint32_t flags)
{
    switch(code) {
        case CONNECTION: {
            CHECK_INTERFACE(IRealnameBinder, data, reply);
            sp<IBinder> b = IInterface::asBinder(createConnection());
            reply->writeStrongBinder(b);
            return NO_ERROR;
        }
        default: {
            return BBinder::onTransact(code, data, reply, flags);
        }
    }
}

}; //namespace android