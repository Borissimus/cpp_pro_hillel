#include <iostream>

using std::cout;
using std::cin;
using std::endl;

namespace geometry {
	template <typename Dim>
	struct Rectangle {
		Dim width;
		Dim height;

		constexpr Dim area() const {
			return width * height;
		}

		Rectangle (Dim w, Dim h) : width(w), height(h) {}
		~Rectangle() = default;
	};
}

template <typename Dim>
geometry::Rectangle<Dim> create_rectangle(void) {
	Dim width;
	Dim height;

	cout << "Enter width: ";
	cin >> width;
	cout << "Enter height: ";
	cin >> height;

	return geometry::Rectangle<Dim>(width, height);
}

int main() {
	using namespace geometry;

	Rectangle<int> r1(3, 4);
	Rectangle<double> r2(3.5, 4.5);

	cout << "Area of r1: " << r1.area() << std::endl;
	cout << "Area of r2: " << r2.area() << std::endl;

	cout << "Choose type (int 1, double 2): ";
	int type;
	cin >> type;

	switch (type) {
	case 1: {
		Rectangle<int> r3 = create_rectangle<int>();
		cout << "Area of r3: " << r3.area() << endl;
		break;
		}
	case 2: {
		Rectangle<double> r4 = create_rectangle<double>();
		cout << "Area of r4: " << r4.area() << endl;
		break;
		}
	default: {
		cout << "Invalid type" << endl;
		break;
		}
	}

    return 0;
}
