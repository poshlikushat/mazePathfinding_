#include "Maze.hpp"
#include <fstream>

Maze::Maze(const std::string &filename) {
    // Think about how to implement this function
}

Maze::~Maze() { delete mazeData_; }

const std::vector<std::vector<int>> &Maze::getDistance() const {
    if (isEmpty()) throw std::logic_error("Maze is empty");  // Cannot use return 'cuz type of the fucntion is not void

    return mazeData_->distance;
}

const std::pair<int, int> &Maze::getStart() const {
    if (isEmpty()) throw std::logic_error("Maze is empty");

    return mazeData_->start;
}

const std::pair<int, int> &Maze::getExit() const {
    if (isEmpty()) throw std::logic_error("Maze is empty");

    return mazeData_->exit;
}

const std::vector<std::vector<std::pair<int, int>>> &Maze::getParent() const {
    if (isEmpty()) throw std::logic_error("Maze is empty");

    return mazeData_->parent;
}

const bool Maze::isEmpty() const {
    return mazeData_ == nullptr;
}
    
    

