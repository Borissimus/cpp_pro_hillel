#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <functional>
#include <cstdlib>
#include <unordered_set>

template <typename T>
class MySharedPtr {
public:
    // Default constructor
    explicit MySharedPtr(T* ptr = nullptr)
        : data(ptr), counter(new size_t(1)) {}

    // Copy constructor
    MySharedPtr(const MySharedPtr<T>& other)
        : data(other.data), counter(other.counter) {
        ++(*counter);
    }

    // Move constructor
    MySharedPtr(MySharedPtr<T>&& other) noexcept
        : data(other.data), counter(other.counter) {
        other.data = nullptr; // Transfer ownership
        other.counter = nullptr; // Transfer ownership
    }

    // Copy assignment operator
    MySharedPtr<T>& operator=(const MySharedPtr<T>& other) {
        if (this != &other) {
            release();
            data = other.data;
            counter = other.counter;
            ++(*counter);
        }
        return *this;
    }

    // Move assignment operator
    MySharedPtr<T>& operator=(MySharedPtr<T>&& other) noexcept {
        if (this != &other) {
            release();
            data = other.data;
            counter = other.counter;
            other.data = nullptr; // Transfer ownership
            other.counter = nullptr; // Transfer ownership
        }
        return *this;
    }

    // Dereference operator
    T& operator*() const {
        return *data;
    }

    // Pointer access operator
    T* operator->() const {
        return data;
    }

    // Destructor
    ~MySharedPtr() {
        release();
    }

    // Equal operator
    bool operator==(const MySharedPtr<T>& other) const {
        return data == other.data; 
    }

    // Hash function
    size_t hash() const {
        return std::hash<T*>()(data);
    }

private:
    T* data;
    size_t* counter;

    void release() {
        if (counter) {
            --(*counter);
            if (*counter == 0) {
                delete data;
                delete counter;
            }
        }
    }
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

#endif // MAIN_H
