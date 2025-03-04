#pragma once

#include "OnlineCore/src/Core/RootObject.h"
#include "OnlineCore/src/Core/Time.h"

namespace nn::nex {
class LocalClock : public RootObject {
public:
    static LocalClock* s_pInstance;

    LocalClock();
    ~LocalClock() override;

    static void DeleteInstance();

private:
    u64 m_Time;
};
}  // namespace nn::nex