#include "Core/LocalClock.h"
#include "Platform/Core/Time.h"

namespace nn::nex {
LocalClock::LocalClock() {
    m_Time = Time::GetTime();
}

LocalClock::~LocalClock() {}

void LocalClock::DeleteInstance() {
    if (!s_pInstance)
        return;

    delete s_pInstance;
    s_pInstance = nullptr;
}
}  // namespace nn::nex
