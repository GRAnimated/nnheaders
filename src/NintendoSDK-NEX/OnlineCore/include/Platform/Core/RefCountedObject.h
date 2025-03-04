#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class RefCountedObject : public RootObject {
public:
    RefCountedObject(){};
    virtual ~RefCountedObject();
};
}  // namespace nn::nex
