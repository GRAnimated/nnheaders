#include "Platform/Core/Platform.h"
#include <cstring>
#include "Platform/Core/BadEvents.h"
#include "Platform/Core/EventLog.h"
#include "nn/os.h"

static bool s_HasInitialized;

namespace nn::nex {
Platform::Platform() {
    _Instance = this;
}

Platform::~Platform() = default;

Platform* Platform::Instance() {
    return _Instance;
}

void Platform::CreateInstance() {
    _Instance = new Platform();
}

void Platform::DeleteInstance() {
    if (_Instance)
        delete _Instance;
}

void Platform::Sleep(u32 milliseconds) {
    if (milliseconds)
        nn::os::SleepThread(nn::TimeSpan::FromMilliSeconds(milliseconds));
    else
        nn::os::YieldThread();
}

nn::os::Tick Platform::GetTick() {
    return nn::os::GetSystemTick();
}

#include <cstring>

inline u16 htons(u16 host) {
    return (host >> 8) | (host << 8);
}

inline u32 ntnol(u32 host) {
    return ((host >> 24) & 0xFF) | ((host >> 8) & 0xFF00) | ((host << 8) & 0xFF0000) |
           ((host << 24) & 0xFF000000);
}

inline u64 htonll(u64 host) {
    return ((host >> 56) & 0xFF) | ((host >> 40) & 0xFF00) | ((host >> 24) & 0xFF0000) |
           ((host >> 8) & 0xFF000000) | ((host << 8) & 0xFF00000000) |
           ((host << 24) & 0xFF0000000000) | ((host << 40) & 0xFF000000000000) |
           ((host << 56) & 0xFF00000000000000);
}

inline u16 ntohs(u16 network) {
    return htons(network);
}

inline u32 ntohl(u32 network) {
    return ntnol(network);
}

inline u64 ntohll(u64 network) {
    return htonll(network);
}

inline u16 _byteswap_ushort(u16 value) {
    return (value >> 8) | (value << 8);
}

void Platform::NetworkToHost(unsigned const char* network, u16* host) {
    *host = ntohs(*reinterpret_cast<const u16*>(network));
}

void Platform::NetworkToHost(unsigned const char* network, u32* host) {
    *host = ntohl(*reinterpret_cast<const u32*>(network));
}

void Platform::NetworkToHost(unsigned const char* network, u64* host) {
    *host = ntohll(*reinterpret_cast<const u64*>(network));
}

void Platform::HostToNetwork(const u16* host, unsigned char* network) {
    u16 network_value = htons(*host);
    memcpy(network, &network_value, sizeof(u16));
}

void Platform::HostToNetwork(const u32* host, unsigned char* network) {
    u32 network_value = ntnol(*host);
    memcpy(network, &network_value, sizeof(u32));
}

void Platform::HostToNetwork(const u64* host, unsigned char* network) {
    u64 network_value = htonll(*host);
    memcpy(network, &network_value, sizeof(u64));
}

void Platform::WarnObsoleteMethod(const char* a2, const char* a3) {
    _QLOG(EventLog::_2, "WARNING  Using obsolete API '%s', use '%s' instead", a2, a3);
    if (BadEvents::s_pInstance)
        ++BadEvents::s_pInstance->field_c;
}

#define STATE_VECTOR_LENGTH 624

struct tagMTRand {
    u32 mt[STATE_VECTOR_LENGTH];
    u32 index;
} rand;

// MT19937 algorithm from https://github.com/ESultanik/mtwister/blob/master/mtwister.c#L19
void Platform::SetRandomNumberSeed(u32 seed) {
    u32 defaultSeed = 0x1105;

    rand.mt[0] = (seed == 0) ? defaultSeed : seed;
    rand.mt[1] = rand.mt[0] * 0x10DCD;

    for (rand.index = 2; rand.index < STATE_VECTOR_LENGTH; rand.index++) {
        rand.mt[rand.index] = (0x10DCD * rand.mt[rand.index - 1]) & 0xFFFFFFFF;
    }

    Platform::s_bSeedIsInitialized = true;
}

void Platform::GetRandomNumber(u32 val) {}

u32 Platform::GetRandomSeed() {
    u32 bytes = 0;
    nn::os::GenerateRandomBytes(&bytes, 4);
    return bytes;
}

void Platform::GetRealRandomNumber(f32 val) {}

u32 Platform::GetProcessID() {
    return 0;
}

u64 Platform::GetPlatformID() {
    if (!s_HasInitialized)
        s_HasInitialized = true;
    return 0;
}

void Platform::Breakpoint() {}

void Platform::YieldThread() {}
}  // namespace nn::nex
