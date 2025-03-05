#pragma once

#include "nn/types.h"

namespace nn::nex {
class StorageUnit {
public:
    static StorageUnit* AppendData(const StorageUnit*, StorageUnit*);
    static StorageUnit* CopyData(const StorageUnit*, StorageUnit*);

    virtual ~StorageUnit();
    virtual bool Reserve(u64);
    virtual u64 GetReservedSize();
};
}  // namespace nn::nex
