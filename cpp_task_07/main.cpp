#include "logger.h"
#include <vector>
#include <list>
#include <set>

int main() {
    Logger& logger = Logger::getInstance();

    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::list<int> lst = {10, 20, 30};
    std::set<int> st = {100, 200, 300};

    logger.logContainer(vec);
    logger.logContainer(lst);
    logger.logContainer(st);
    logger.logContainer({1000, 2000, 3000});

    return 0;
}

