/**
 * Writed by RogerYu 2019-09-17
 */

#ifndef ANDROID_REALNAME_BINDER_H
#define ANDROID_REALNAME_BINDER_H

#include <IRealnameBinder.h>
#include <IAnonymousBinder.h>
#include <utils/Log.h>

namespace android {

class RealnameBinder : public BnRealnameBinder
{
public:
    RealnameBinder();
    virtual ~RealnameBinder();

    virtual sp<IAnonymousBinder> createConnection();

};

}; // namespace android

#endif // ANDROID_REALNAME_BINDER_H
