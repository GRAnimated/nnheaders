#pragma once

#include <nn/types.h>

namespace nn::nex {
class MemoryManager {
public:
    enum _InstructionType : s32 {};

    using fcnMalloc = void* (*)(unsigned long);
    using fcnFree = void* (*)(void*);

    static fcnMalloc s_fcnMalloc;
    static fcnFree s_fcnFree;
    static void* s_eShutDownState;

    MemoryManager(const char* watermark);

    virtual ~MemoryManager();
    virtual void BeginProtection();
    virtual void EndProtection();
    static void Allocate(ulong);
    static void* GenericMalloc(ulong);
    static void AllocateForPbPool(void*, fcnFree, void*);
    static void Free(void*);
    static void GenericFree(fcnFree, void*);
    static void AllocateThreadSafe(ulong);
    static void FreeThreadSafe(void*);
    static void IncreaseMemUsage(ulong);
    static void DecreaseMemUsage(ulong);
    static void GetDefaultMemoryManager();
    static void ShutdownDefaultMemoryManager();
    static void Trace();
    const char* GetInstructionTypeString(_InstructionType) const;

private:
    int dword_8 = 0;
    const char* field_10 = nullptr;
    const char* field_18 = nullptr;
};
}  // namespace nn::nex
