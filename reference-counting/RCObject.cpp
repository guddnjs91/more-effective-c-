#include <cstdio>
#include "RCObject.hpp"

// ctor
// NOTE: let creators of RCObject to set refCount to 1
RCObject::RCObject()
	: refCount(0)
	, shareable(true)
{
	printf("RCObject constructor\n");
}

// copy ctor
// NOTE: we're creating a new object representing a value
// again, let creators of RCObject to set refCount
RCObject::RCObject(const RCObject&)
	: refCount(0)
	, shareable(true)
{
	printf("RCObject copy constructor\n");
}

// assign operator
// NOTE:
// This operator is not expected to be called in usual.
// Objects are not assigned to one another,
// but what objects pointing to them are.
//
// e.g., sv1 = sv2;
// This only changes sv1's value.
// Objects referencing to sv1 doesn't changed,
// nor does objects referencing to sv2.
// So we do nothing here.
RCObject& RCObject::operator=(const RCObject&)
{
	printf("RCObject assign operator\n");
	return *this;
}

// dtor
RCObject::~RCObject()
{
	printf("RCObject destructor\n");
}

void RCObject::addReference()
{
	++refCount;
}

void RCObject::removeReference()
{
	if (--refCount == 0)
		delete this; // NOTE: *this should be heap object
}

void RCObject::markUnshareable()
{
	shareable = false;
}

bool RCObject::isSharable() const
{
	return shareable;
}

bool RCObject::isShared() const
{
	return refCount > 1;
}

int RCObject::getRefCount()
{
    return refCount;
}
