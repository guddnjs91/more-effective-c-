#ifndef __RCPTR_H__
#define __RCPTR_H__

/* 
 * template class for smart pointers-to-T objects.
 * T must support the RCObject interface, typically by inheriting from that class.
 * 
 * RCPtr is like regular pointer, but additionally manages 
 * RCObject's reference count during its life cycle.
 * */
template<class T>
class RCPtr {

public:
    RCPtr(T* realPtr = 0);
    RCPtr(const RCPtr& rhs);
    ~RCPtr();

    RCPtr& operator=(const RCPtr& rhs);

    T* operator->() const;
    T& operator*() const;

private:
    T* pointee;
    void init();
};

#endif // __RCPTR_H__
