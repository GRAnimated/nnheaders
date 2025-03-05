#pragma once

#include "Platform/Core/RootObject.h"

namespace nn::nex {
class String : public RootObject {
public:
    class NoAllocTag;

    String();
    String(nn::nex::String::NoAllocTag);
    String(const char*);
    String(const wchar_t*);
    String(const char16*);
    String(const nn::nex::String&);
    virtual ~String();

    void Format(const char*, ...);
    void CreateCopy(char**) const;
    void ReleaseCopy(char*);

    void operator=(const nn::nex::String&);
    void operator=(const char*);
    void operator=(wchar_t const*);
    void operator=(char16_t const*);
    void IsEqual(const char*, const char*);
    void operator<(const nn::nex::String&) const;
    void operator+=(const nn::nex::String&);

    void Truncate(unsigned long) const;
    void GetLength() const;
    void Reserve(unsigned long);
    void SetBufferPtr(char*);
    void SetStringToPreReservedBuffer(const char*);
    void GetWideCharLength() const;
    void CopyString(char*, unsigned long) const;
    void CreateCopy(wchar_t**) const;
    void ReleaseCopy(wchar_t*);
    void CopyString(wchar_t*, unsigned long) const;
    void CreateCopy(char16_t**) const;
    void ReleaseCopy(char16_t*);
    void CopyString(char16_t*, unsigned long) const;
    void ToUpper();
    void ToLower();
    void FindSubstringCase(const char*, int) const;
    void FindSubstringNoCase(const char*) const;
    void ByteArrayToBase64(unsigned const char*, unsigned long, char*, unsigned long);
    void Base64ToByteArray(const char*, unsigned long, unsigned char*, unsigned long);
    void Base64ToByteArray(const nn::nex::String&, unsigned char*, unsigned long);
    void ContainsCase(const nn::nex::String&) const;
    void ToUInt64() const;
    void ContainsNoCase(const nn::nex::String&) const;
    void SetDefaultStringEncoding(unsigned int);
    void Trace(unsigned long);

    // operator const char*() const { return m_String; }
    const char* cstr() const { return m_String; }

private:
    const char* m_String;
};
}  // namespace nn::nex
