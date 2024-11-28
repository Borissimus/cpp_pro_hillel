#include <iostream>

template <typename T>
class MySharedPtr {
public:
	// Constructor that accepts a raw pointer
	explicit MySharedPtr(T* ptr = nullptr) : data(ptr), counter(new size_t(1)) {
		std::cout << "Constructor: Initialized with counter=" << *counter << std::endl;
	}

	// Copy constructor
	MySharedPtr(const MySharedPtr<T>& other) : data(other.data), counter(other.counter) {
		++(*counter);
		std::cout << "Copy Constructor: counter incremented to " << *counter << std::endl;
	}

	// Assignment operator overload
	MySharedPtr<T>& operator=(const MySharedPtr<T>& other) {
		if (this != &other) {
			release();
			data = other.data;
			counter = other.counter;
			++(*counter);
			std::cout << "Assignment Operator: counter incremented to " << *counter << std::endl;
		}
		return *this;
	}

	// Dereference operator overload
	T& operator*() const {
		return *data;
	}

	// Arrow operator overload
	T* operator->() const {
		return data;
	}

	// Destructor
	~MySharedPtr() {
		release();
	}

private:
	T* data;
	size_t* counter;

	void release() {
		if (counter) {
			--(*counter);
			std::cout << "Destructor/Release: counter decremented to " << *counter << std::endl;
			if (*counter == 0) {
				delete data;
				delete counter;
				std::cout << "Destructor/Release: data and counter deleted" << std::endl;
			}
		}
	}
};

int main() {
	MySharedPtr<int> ptr1(new int(42));
	MySharedPtr<int> ptr2 = ptr1;

	std::cout << "Value: " << *ptr2 << std::endl;

	*ptr2 = 100;
	std::cout << "Updated Value: " << *ptr1 << std::endl;

	return 0;
}
