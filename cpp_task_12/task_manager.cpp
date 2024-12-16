#include "task_manager.h"
#include <algorithm>

// Adding a task to the task list
void TaskManager::addTask(const Task& task) {
	this->tasks.push_back(task);
}

// Getting the list of tasks
std::vector<Task>& TaskManager::getTasks() {
	return this->tasks;
}

// Sorting tasks using the provided comparator
void TaskManager::sortTasks(std::function<bool(const Task&, const Task&)> comparator) {
	std::sort(tasks.begin(), tasks.end(), comparator);
}

// Filtering tasks using the provided filter
std::vector<Task, std::allocator<Task>> TaskManager::filterTasks(std::function<bool(const Task&)> filter) const {
	std::vector<Task> filtered_tasks;
	for (const auto& task : tasks) {
		if (filter(task)) {
			filtered_tasks.push_back(task);
		}
	}
	return filtered_tasks;
}
