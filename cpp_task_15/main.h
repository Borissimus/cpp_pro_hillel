#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <ranges>
#include <thread>
#include <mutex>
#include <atomic>

class Course; // Forward declaration to avoid cyclic dependencies

class Student {
public:
    Student(const std::string& name, const std::string& group)
        : name(name), group(group) {}

    std::string getName() const { return name; }
    std::string getGroup() const { return group; }

    void setName(const std::string& newName) {
        std::lock_guard<std::mutex> lock(mutex);
        name = newName;
    }

    void setGroup(const std::string& newGroup) {
        std::lock_guard<std::mutex> lock(mutex);
        group = newGroup;
    }

    void addCourse(std::shared_ptr<Course> course) {
        courses.push_back(course);
    }

private:
    std::string name;
    std::string group;
    std::vector<std::shared_ptr<Course>> courses; // Student knows about the courses they are enrolled in
    mutable std::mutex mutex; // Mutex to protect access to student data
};

class Course {
public:
    Course(const std::string& title)
        : title(title) {}

    void addStudent(std::shared_ptr<Student> student) {
        students.push_back(student);
    }

    std::vector<std::string> getGroups() const {
        std::vector<std::string> groups;
        for (const auto& weak_student : students) {
            if (auto student = weak_student.lock()) { // Get shared_ptr from weak_ptr
                groups.push_back(student->getGroup());
            }
        }
        std::sort(groups.begin(), groups.end());
        groups.erase(std::unique(groups.begin(), groups.end()), groups.end());
        return groups;
    }

    std::string getName() const { return title; }

private:
    std::string title;
    std::vector<std::weak_ptr<Student>> students; // Store students as weak_ptr
};

std::mutex coutMutex; // Mutex for console output

void modifyStudentName(std::shared_ptr<Student> student, const std::string& newName) {
    // Modify student name in a separate thread
    std::lock_guard<std::mutex> lock(coutMutex); // Locking output for thread safety
    student->setName(newName);
    std::cout << "Student name changed to: " << student->getName() << std::endl;
}

#endif // MAIN_H
