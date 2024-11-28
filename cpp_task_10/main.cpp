#include "main.h"

int main() {
    using namespace std;

    // Create some students
    auto petrenko = make_shared<Student>("Petrenko", "A1");
    auto ivanov = make_shared<Student>("Ivanov", "B1");
    auto kushnir = make_shared<Student>("Kushnir", "A1");

    // Create courses
    auto math = make_shared<Course>("Mathematics");
    math->addStudent(petrenko);
    math->addStudent(ivanov);

    auto physics = make_shared<Course>("Physics");
    physics->addStudent(petrenko);
    physics->addStudent(kushnir);

    // Log group information for each course
    for (const auto& course : { math, physics }) {
        auto groups = course->getGroups();
        cout << "Groups registered for course '" << course->getName() << "': ";
        for (const auto& group : groups) {
            cout << group << " ";
        }
        cout << endl;
    }

	return 0; // Objects are automatically destroyed when exiting main
}