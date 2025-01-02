#ifndef MY_SHARED_PTR_H
#define MY_SHARED_PTR_H

#include <cstddef>
#include <functional>
#include <iostream>

template <typename T>
class MySharedPtr {
public:
    explicit MySharedPtr(T* ptr = nullptr);
    MySharedPtr(const MySharedPtr<T>& other);
    MySharedPtr(MySharedPtr<T>&& other) noexcept;
    MySharedPtr<T>& operator=(const MySharedPtr<T>& other);
    MySharedPtr<T>& operator=(MySharedPtr<T>&& other) noexcept;
    ~MySharedPtr();

    T& operator*() const;
    T* operator->() const;
    bool operator==(const MySharedPtr<T>& other) const;
    size_t hash() const;

private:
    T* data;
    size_t* counter;

    void release();
};

// Specialization of std::hash for MySharedPtr
namespace std {
    template <typename T>
    struct hash<MySharedPtr<T>> {
        size_t operator()(const MySharedPtr<T>& ptr) const {
            return ptr.hash();
        }
    };
}

#include "my_shared_ptr.tpp" // Template implementation

#endif // MY_SHARED_PTR_H
