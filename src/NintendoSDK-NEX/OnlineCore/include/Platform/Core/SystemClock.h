#pragma once

#include "Platform/Core/Time.h"

namespace nn::nex {
class TimeProvider;
class Time;
class SystemClock {
public:
    SystemClock();
    virtual ~SystemClock();

    static void RegisterTimeProvider(TimeProvider*, bool);
    static void ApplyCorrection(Time curTime, Time newTime);
    static Time* ProtectedGetTime();
    static Time* GetTimeImpl(bool);
    static Time* GetTimeImplCorrectless();
    static void Reset();

    static Time* GetTime() {
        Time* time;
        if (s_needCorrection)
            time = GetTimeImpl(false);
        else
            time = GetTimeImplCorrectless();
        s_cachedTime = time;
        return time;
    }

    operator u64() const { return GetTime()->GetTimeVal(); }

    static nn::nex::TimeProvider* s_pTimeProvider;
    static Time* s_cachedTime;
    static bool s_needCorrection;
    static bool s_tiCorrection;
};

}  // namespace nn::nex
