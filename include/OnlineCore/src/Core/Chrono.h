#pragma once

#include "OnlineCore/src/Core/LocalClock.h"
#include "OnlineCore/src/Core/RootObject.h"

namespace nn::nex {
class Chrono : public RootObject {
public:
    Chrono();
    virtual ~Chrono();

    void Reset();
    void Start();
    void Pause();
    void UpdateAccumulatedTime();
    void Elapsed() const;
    void Resume();
    void Check();
    void Stop();
    void GetState() const;

private:
    LocalClock m_LocalClock;
    u64 qword_18 = 0;
    int dword_20 = 0;
    int dword_24 = 2;
};
}  // namespace nn::nex
