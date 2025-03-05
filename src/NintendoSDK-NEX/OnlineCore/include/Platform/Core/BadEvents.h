#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class BadEvents : public RootObject {
public:
    static BadEvents* s_pInstance;

    enum _ID {};

    BadEvents();
    virtual ~BadEvents();

    void Reset();
    void SetExpectedEvent(_ID id);
    void CreateInstance();
    void DeleteInstance();
    void SignalEvent(_ID id);
    void ClearExpectedEvent(_ID id);
    void IsExpected(_ID id) const;
    void ClearCount(_ID id);
    void GetCount(_ID id) const;
    void GlobalNewDeleteAllowed();
    void Signal(_ID id);

    s32 field_8;
    s32 field_c;
};
}  // namespace nn::nex
