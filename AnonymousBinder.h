/**
 * Writed by RogerYu 2019-09-17
 */

#ifndef ANDROID_ANONYMOUS_BINDER_H
#define ANDROID_ANONYMOUS_BINDER_H

#include <IAnonymousBinder.h>
#include <utils/Log.h>

namespace android {

class AnonymousBinder : public BnAnonymousBinder
{
public:
    AnonymousBinder();
    virtual ~AnonymousBinder();

    virtual status_t test(const char *str);

};

}; // namespace android

#endif // ANDROID_ANONYMOUS_BINDER_H
