#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <ranges>

class Student {
public:
    Student(const std::string& name, const std::string& group)
        : name(name), group(group) {}

    std::string getName() const { return name; }
    std::string getGroup() const { return group; }

    void setName(const std::string& newName) { name = newName; }
    void setGroup(const std::string& newGroup) { group = newGroup; }

private:
    std::string name;
    std::string group;
};

class Course {
public:
    Course(const std::string& title)
        : title(title) {}

    void addStudent(const std::shared_ptr<Student> student) {
        students.push_back(student);
    }

    std::vector<std::string> getGroups() const {
        std::vector<std::string> groups;
        for (const auto& student : students) {
            groups.push_back(student->getGroup());
        }
        std::sort(groups.begin(), groups.end());
        groups.erase(std::unique(groups.begin(), groups.end()), groups.end());
        return groups;
    }

public:
    std::string getName() const { return title; }

private:
    std::string title;
    std::vector<std::shared_ptr<Student>> students;
};

#endif // MAIN_H
