#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <string>
#include <vector>
#include <chrono>
#include <functional>

// Class representing a task
class Task {
public:
	Task(const std::string& title, const std::string& description, int priority, 
		 const std::chrono::system_clock::time_point& deadline) 
		 : title(title), description(description), priority(priority), 
		   deadline(deadline), is_done(false), created_at(std::chrono::system_clock::now()) {}

	// Methods to access task data
	void markAsDone() { is_done = true; }
	bool isDone() const { return is_done; }
	std::string getTitle() const { return title; }
	std::string getDescription() const { return description; }
	int getPriority() const { return priority; }
	std::chrono::system_clock::time_point getDeadline() const { return deadline; }

	// Methods to modify task data
	void setTitle(const std::string& newTitle) { title = newTitle; }
	void setDescription(const std::string& newDescription) { description = newDescription; }
	void setPriority(int newPriority) { priority = newPriority; }

private:
	std::string title;
	std::string description;
	int priority; 
	std::chrono::system_clock::time_point deadline;
	bool is_done;
	std::chrono::system_clock::time_point created_at;
};

// Class for managing tasks
class TaskManager {
public:
	void addTask(const Task& task);

	std::vector<Task>& getTasks();

	std::vector<Task> filterTasks(std::function<bool(const Task&)> filter) const;

	void sortTasks(std::function<bool(const Task&, const Task&)> comparator);

private:
	std::vector<Task> tasks; // Container for storing tasks
};

#endif // TASK_MANAGER_H