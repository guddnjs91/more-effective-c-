#include "RCPtr.hpp"
#include "String.hpp"

template<class T>
RCPtr<T>::RCPtr(T* realPtr)
    : pointee(realPtr)
{
    init();
}

template<class T>
RCPtr<T>::RCPtr(const RCPtr& rhs)
    : pointee(rhs.pointee)
{
    init();
}

template<class T>
void RCPtr<T>::init()
{
    if (pointee == 0)
        return ;

    // if value is not shareable, copy it
    if (pointee->isSharable() == false)
    {
        // NOTE: T's copy ctor is called,
        // need deep copy ctor for T's data
        pointee = new T(*pointee);
    }

    // new reference for value added here
    pointee->addReference();
}

template<class T>
RCPtr<T>& RCPtr<T>::operator=(const RCPtr& rhs)
{
    if (pointee != rhs.pointee)
    {
        if (pointee) {
            pointee->removeReference();
        }

        pointee = rhs.pointee;
        init(); // make share if possible
    }

    return *this;
}

template<class T>
RCPtr<T>::~RCPtr()
{
    if (pointee)
        pointee->removeReference();
}

template<class T>
T* RCPtr<T>::operator->() const
{
    return pointee;
}

template<class T>
T& RCPtr<T>::operator*() const
{
    return *pointee;
}

template class RCPtr<String::StringValue>;
