#include <cstdio>
#include <cstring>
#include "String.hpp"

// ctor
String::String(const char *initValue)
    : value(new StringValue(initValue))
{
    printf("String constructor\n");
}

// dtor
String::~String()
{
    printf("String destructor\n");
}

// const operator[]
const char& String::operator[](int index) const
{
    return value->data[index];
}

// non-const operator[]
// NOTE: should consider caller object can modify this data, 
// so apply copy-on-write here
char& String::operator[](int index)
{
    if (value->isShared())
    {
        value = new StringValue(value->data); // make copy (refCount=1)
    }

    // Set shareable flag to false since who calls this operator
    // could modify the shared value. Unfortunately, resetting this
    // flag is non-trivial...
    value->markUnshareable();

    return value->data[index];
}

void String::printStringValue()
{
    printf("data=%p\n", value->data);
    printf("reference count=%d\n", value->getRefCount());
    printf("shareable==%s\n", (value->isSharable() ? "true" : "false"));
}

String::StringValue::StringValue(const char *initValue)
{
	data = new char[strlen(initValue) + 1];
	strcpy(data, initValue);
    
    printf("%lu byte allocated at %p\n", sizeof(data), data);
}

String::StringValue::StringValue(const StringValue& rhs)
{
    data = new char[strlen(rhs.data) + 1];
    strcpy(data, rhs.data);

    printf("%lu byte allocated at %p\n", sizeof(data), data);
}

String::StringValue::~StringValue()
{
    printf("%lu byte will be freed at %p...", sizeof(data), data);
	delete [] data;
    printf("done\n");
}
