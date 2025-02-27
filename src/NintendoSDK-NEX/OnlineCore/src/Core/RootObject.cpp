#include "OnlineCore/src/Core/RootObject.h"
#include <cstdlib>
#include "OnlineCore/src/Core/MemoryManager.h"

namespace nn::nex {

void* RootObject::operator new(ulong size) {
    ulong aligned = size + 23 & ~7;

    void* ptr;
    if (MemoryManager::s_fcnMalloc)
        ptr = MemoryManager::s_fcnMalloc(aligned);
    else
        ptr = malloc(aligned);

    *(void**)(ptr) = (void*)MemoryManager::s_fcnFree;
    return (void*)(reinterpret_cast<ulong*>(ptr) + 2);
}

void RootObject::operator delete(void* ptr) {
    if (ptr) {
        void** func = reinterpret_cast<void**>(ptr) - 2;
        void (*freeFunc)(void*) = reinterpret_cast<void (*)(void*)>(*func);
        void* mem = static_cast<void*>(func);

        if (freeFunc) {
            freeFunc(mem);
        } else {
            free(mem);
        }
    }
}

void* RootObject::operator new(ulong size, const char* a2, unsigned int a3) {
    return operator new(size);
}

void* RootObject::operator new[](ulong size) {
    return operator new(size);
}

void* RootObject::operator new[](ulong size, const char* a2, unsigned int a3) {
    return operator new(size);
}

void RootObject::operator delete[](void* ptr) {
    operator delete(ptr);
}

void RootObject::operator delete(void* ptr, const char* a2, unsigned int a3) {
    operator delete(ptr);
}

void RootObject::operator delete[](void* ptr, const char* a2, unsigned int a3) {
    operator delete(ptr);
}

void* RootObject::operator new(ulong, nn::nex::RootObject::TargetPool) {}

void* RootObject::operator new(ulong, nn::nex::RootObject::TargetPool, const char*, unsigned int) {}

}  // namespace nn::nex
