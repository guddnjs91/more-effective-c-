#include <cstdio>
#include <cstring>
#include "String.hpp"

// ctor
String::String(const char *initValue)
    : value(new StringValue(initValue))
{
    printf("String constructor\n");
}

// copy ctor
String::String(const String& rhs)
    : value(rhs.value)
{
    printf("String copy constructur\n");
    value->refCount++;
}

// dtor
String::~String()
{
    if (--value->refCount == 0)
        delete value;
}

// assign operator (e.g., String s1 = String s2)
String& String::operator=(const String& rhs)
{
    printf("String assign operator\n");

    // do nothing if both object share same value
    if (value == rhs.value)
        return *this;

    // decrement reference count of s1
    if (--value->refCount == 0)
        delete value;

    // let s1 share value of s2 and increment reference count of s2
    value = rhs.value;
    ++rhs.value->refCount;

    return *this;
}

void String::printStringValue()
{
    printf("data=%p\n", value->data);
    printf("data allocated size=%lu\n", sizeof(value->data));
    printf("reference count=%d\n", value->refCount);
}

String::StringValue::StringValue(const char *initValue)
    : refCount(1)
{
	data = new char[strlen(initValue) + 1];
	strcpy(data, initValue);
    
    printf("%lu byte allocated at %p\n", sizeof(data), data);
}

String::StringValue::~StringValue()
{
    printf("%lu byte will be freed at %p...", sizeof(data), data);
	delete [] data;
    printf("done\n");
}
