#include "my_shared_ptr.h"

template <typename T>
MySharedPtr<T>::MySharedPtr(T* ptr)
    : data(ptr), counter(new size_t(1)) {}

template <typename T>
MySharedPtr<T>::MySharedPtr(const MySharedPtr<T>& other)
    : data(other.data), counter(other.counter) {
    ++(*counter);
}

template <typename T>
MySharedPtr<T>::MySharedPtr(MySharedPtr<T>&& other) noexcept
    : data(other.data), counter(other.counter) {
    other.data = nullptr;
    other.counter = nullptr;
}

template <typename T>
MySharedPtr<T>& MySharedPtr<T>::operator=(const MySharedPtr<T>& other) {
    if (this != &other) {
        release();
        data = other.data;
        counter = other.counter;
        ++(*counter);
    }
    return *this;
}

template <typename T>
MySharedPtr<T>& MySharedPtr<T>::operator=(MySharedPtr<T>&& other) noexcept {
    if (this != &other) {
        release();
        data = other.data;
        counter = other.counter;
        other.data = nullptr;
        other.counter = nullptr;
    }
    return *this;
}

template <typename T>
MySharedPtr<T>::~MySharedPtr() {
    release();
}

template <typename T>
T& MySharedPtr<T>::operator*() const {
    return *data;
}

template <typename T>
T* MySharedPtr<T>::operator->() const {
    return data;
}

template <typename T>
bool MySharedPtr<T>::operator==(const MySharedPtr<T>& other) const {
    return data == other.data;
}

template <typename T>
size_t MySharedPtr<T>::hash() const {
    return std::hash<T*>()(data);
}

template <typename T>
void MySharedPtr<T>::release() {
    if (counter) {
        --(*counter);
        if (*counter == 0) {
            delete data;
            delete counter;
        }
    }
}