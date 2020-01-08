#ifndef __RCOBJECT_H__
#define __RCOBJECT_H__

/* RCObject class is used for base class of any class
 * who wants to implement object with reference-countable
 * functionalities in context-independent manner
 *
 * Reference-countable object provides:
 * 1. add/remove reference count
 * 2. get/set shareability
 * */
class RCObject {

    friend class String;

    public:
    RCObject();
    RCObject(const RCObject &rhs);
    RCObject& operator=(const RCObject& rhs);
    virtual ~RCObject() = 0;

    void addReference();
    void removeReference();

    void markUnshareable();
    bool isSharable() const;
    bool isShared() const;

    private:
    int refCount;
    bool shareable;
};

#endif // __RCOBJECT_H__

