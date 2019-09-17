/**
 * Writed by RogerYu 2019-09-17
 */

#ifndef ANDROID_IREALNAME_BINDER_H
#define ANDROID_IREALNAME_BINDER_H

#include <binder/IInterface.h>
#include <IAnonymousBinder.h>

namespace android {

class IRealnameBinder : public IInterface {
public:
    DECLARE_META_INTERFACE(RealnameBinder);

    virtual sp<IAnonymousBinder> createConnection() = 0;
};


class BnRealnameBinder : public BnInterface<IRealnameBinder> {
public:
    virtual status_t onTransact(uint32_t code,
                                const Parcel& data,
                                Parcel* reply,
                                uint32_t flags = 0);
};

}; // namespace android

#endif // ANDROID_IREALNAME_BINDER_H