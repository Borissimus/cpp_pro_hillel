#include "main.h"

int main() {
    // Create a list of students
    std::vector<std::shared_ptr<Student>> students;
    auto petrenko = std::make_shared<Student>("Petrenko", "A1");
    auto ivanov = std::make_shared<Student>("Ivanov", "B1");
    auto kushnir = std::make_shared<Student>("Kushnir", "A1");

    students.push_back(petrenko);
    students.push_back(ivanov);
    students.push_back(kushnir);

    // Create courses
    std::vector<std::shared_ptr<Course>> courses;

    auto math = std::make_shared<Course>("Mathematics");
    math->addStudent(petrenko);
    math->addStudent(ivanov);

    auto physics = std::make_shared<Course>("Physics");
    physics->addStudent(petrenko);
    physics->addStudent(kushnir);

    courses.push_back(math);
    courses.push_back(physics);

    // Output groups registered for each course
    for (const auto& course : courses) {
        auto groups = course->getGroups();
        std::cout << "Groups registered for course '" << course->getName() << "': ";
        for (const auto& group : groups) {
            std::cout << group << " ";
        }
        std::cout << std::endl; // Print a new line after the group list
    }

    return 0; // Exit the program
}
