#include "task_view.h"

#include <limits>

// Implementation of the method to display the list of tasks
void TaskView::displayTasks(const std::vector<Task>& tasks) {
	for (const auto& task : tasks) {
		std::cout << "Index: " << &task - &tasks[0] << "\n"
				  << "Title: " << task.getTitle() << "\n"
				  << "Description: " << task.getDescription() << "\n"
				  << "Priority: " << task.getPriority() << "\n"
				  << (task.isDone() ? "Status: Done" : "Status: Not done") << "\n"
				  << std::endl;
	}
}

// Implementation of the method to get input as a string
std::string TaskView::getInput(const std::string& prompt) {
	std::string input;
	std::cout << prompt;
	std::getline(std::cin, input);
	return input;
}

// Implementation of the method to get numerical input
int TaskView::getIntegerInput(const std::string& prompt) {
	int value;
	std::cout << prompt;
	std::cin >> value;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
	return value;
}