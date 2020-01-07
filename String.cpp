#include <cstdio>
#include <cstring>
#include "String.hpp"

String::String(const char *value)
{
    printf("String constructor\n");

    data = new char[strlen(value)+1];
    strcpy(data, value);

    printf("%lu byte allocated at %p\n", sizeof(data), data);
}

String& String::operator=(const String& rhs)
{
    printf("String assign operator\n");

    if (this == &rhs)
        return *this;

    printf("%lu byte will be freed at %p...", sizeof(data), data);
    delete [] data;
    printf("done\n");

    data = new char[strlen(rhs.data) + 1];
    strcpy(data, rhs.data);
    
    printf("%lu byte newly allocated at %p\n", sizeof(data), data);

    return *this;
}

