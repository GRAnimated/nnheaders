#include "Platform/Core/RootObject.h"
#include <cstdlib>
#include "Platform/Core/MemoryManager.h"

namespace nn::nex {

__attribute__((noinline)) void* RootObject::operator new(ulong size) {
    return MemoryManager::Allocate(size);
}

__attribute__((noinline)) void RootObject::operator delete(void* ptr) {
    MemoryManager::Free(ptr);
}

void* RootObject::operator new(ulong size, const char* a2, unsigned int a3) {
    return MemoryManager::Allocate(size);
}

void* RootObject::operator new[](ulong size) {
    return MemoryManager::Allocate(size);
}

void* RootObject::operator new[](ulong size, const char* a2, unsigned int a3) {
    return MemoryManager::Allocate(size);
}

void RootObject::operator delete[](void* ptr) {
    MemoryManager::Free(ptr);
}

void RootObject::operator delete(void* ptr, const char* a2, unsigned int a3) {
    MemoryManager::Free(ptr);
}

void RootObject::operator delete[](void* ptr, const char* a2, unsigned int a3) {
    MemoryManager::Free(ptr);
}

void* RootObject::operator new(ulong, nn::nex::RootObject::TargetPool) {}

void* RootObject::operator new(ulong, nn::nex::RootObject::TargetPool, const char*, unsigned int) {}

}  // namespace nn::nex
