#include "my_shared_ptr.h"
#include <unordered_set>

int main() {
    // Example usage of MySharedPtr
    MySharedPtr<int> p1(new int(42));
    MySharedPtr<int> p2 = p1;  // Copy operation
    MySharedPtr<int> p3 = std::move(p1); // Move operation

    std::cout << "Value in p2: " << *p2 << std::endl;
    std::cout << "Value in p3: " << *p3 << std::endl;

    // Demonstrate equality
    if (p2 == p3) {
        std::cout << "p2 and p3 point to the same object." << std::endl;
    } else {
        std::cout << "p2 and p3 point to different objects." << std::endl;
    }

    // Create a hash set using MySharedPtr
    std::unordered_set<MySharedPtr<int>> ptrSet;
    ptrSet.insert(std::move(p3)); // Use of move semantics
    std::cout << "Hash of p3: " << p3.hash() << std::endl;

    // Cleanup is automatic due to destructor
    return 0;
}