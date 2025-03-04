#include "Platform/Core/MemoryManager.h"
#include <cstdlib>
#include "Platform/Core/GlobalVariables.h"
#include "Platform/Core/MutexPrimitive.h"
#include "nn/mem.h"
#include "nn/os/os_Mutex.h"

namespace nn::nex {
MemoryManager::MemoryManager(const char* watermark) {
    if (!s_fcnMalloc)
        MutexPrimitive* prim = new MutexPrimitive(true);

    // field_10 =
    s_eShutDownState = 0;
}

void* MemoryManager::GenericMalloc(unsigned long size) {
    if (s_fcnMalloc)
        return s_fcnMalloc(size);
    else
        return malloc(size);
}

void MemoryManager::GenericFree(fcnFree freeFunc, void* address) {
    if (freeFunc)
        freeFunc(address);
    else
        free(address);
}

void MemoryManager::AllocateThreadSafe(ulong ptr) {
    GlobalVariables::s_pGv->getStandardAllocator()->Allocate(ptr);
}

void MemoryManager::FreeThreadSafe(void* address) {
    GlobalVariables::s_pGv->getStandardAllocator()->Free(address);
}

void MemoryManager::Trace() {}

const char* s_InstructionTypeStrings[11] = {"Unknown",
                                            "DirectCall",
                                            "UntrackedDirectCall",
                                            "RootObjectNewDelete",
                                            "RootObjectNewDeleteArray",
                                            "GlobalNewDelete",
                                            "GlobalNewDeleteArray",
                                            "AllocatorClass",
                                            "qSpecialNewDelete",
                                            "qSpecialNewDeleteArray",
                                            "qAllocFree"};

const char* MemoryManager::GetInstructionTypeString(_InstructionType instructionType) const {
    if (instructionType > 10)
        return "UNDEFINED INSTRUCTION TYPE!";
    else
        return s_InstructionTypeStrings[instructionType];
}

void MemoryManager::BeginProtection() {}

void MemoryManager::EndProtection() {}

}  // namespace nn::nex
