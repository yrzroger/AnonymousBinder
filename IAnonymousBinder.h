/**
 * Writed by RogerYu 2019-09-17
 */

#ifndef ANDROID_IANONYMOUS_BINDER_H
#define ANDROID_IANONYMOUS_BINDER_H

#include <binder/IInterface.h>

namespace android {

class IAnonymousBinder : public IInterface {
public:
    DECLARE_META_INTERFACE(AnonymousBinder);

    virtual status_t test(const char *str) = 0;
};


class BnAnonymousBinder : public BnInterface<IAnonymousBinder> {
public:
    virtual status_t onTransact(uint32_t code,
                                const Parcel& data,
                                Parcel* reply,
                                uint32_t flags = 0);
};

}; // namespace android

#endif // ANDROID_IANONYMOUS_BINDER_H