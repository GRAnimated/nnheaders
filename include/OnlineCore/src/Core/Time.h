#pragma once

#include <nn/types.h>

namespace nn::nex {
class TimeProvider;

class Time {
public:
    static u64 GetTime();
    void Reset();
    void RegisterTimeProvider(TimeProvider*);
    void Multiply(float) const;
    void Divide(float) const;
    void Scale(float) const;
    void ConvertTimeoutToDeadline(unsigned int);
    void ConvertDeadlineToTimeout(Time);
};
}  // namespace nn::nex
