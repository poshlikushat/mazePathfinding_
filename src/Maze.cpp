#include "Maze.hpp"
#include <fstream>

// Constructor
Maze::Maze(const std::string &filename) {
    mazeData_ = new MazeData();

    std::ifstream file(filename);
    if(!file.is_open()) throw std::runtime_error("Failed to open file: " + filename);

    std::string line;
    bool startFound = false;
    bool exitFound = false;
    int row_idx = 0;

    while(std::getline(file, line)) {
        int col_idx = 0;
        std::vector<int> row;
        for(char c : line) {
            switch (c) {
                case '0': row.push_back(0); break;
                case '1': row.push_back(1); break;
                case '2': 
                    if (startFound) throw std::runtime_error("Multiple start positions found");
                    row.push_back(2);
                    startFound = true;
                    mazeData_->start = std::make_pair(row_idx, col_idx);
                    break;
                case '3': 
                    if (exitFound) throw std::runtime_error("Multiple exit positions found");
                    row.push_back(3);
                    exitFound = true;
                    mazeData_->exit = std::make_pair(row_idx, col_idx);
                    break;
                default: throw std::runtime_error("Invalid character in maze file");
            }
            col_idx++;
        }
        mazeData_->maze.push_back(row);
        row_idx++;
    }
    if (!startFound || !exitFound) throw std::runtime_error("Start or exit position not found");

    mazeData_->distance[mazeData_->start.first][mazeData_->start.second] = 0;

    // Distance matrix initialization
    /*
    Очередь (queue) инициализируется стартовой позицией
    На каждом шаге из очереди извлекается текущая клетка (x, y), и проверяются её соседи (вверх, вниз, влево, вправо).
    Для каждого соседа (nx, ny), если клетка не стена (maze[nx][ny] != 1) и еще не посещена (distance[nx][ny] == -1), 
    то обновляем расстояние до нее (distance[nx][ny] = distance[x][y] + 1)
    и добавляем ее в очередь.
    */

    // Parent matrix initialization
}

// Destructor
Maze::~Maze() { delete mazeData_; }

// Getter functions
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

// Helper functions
const bool Maze::isEmpty() const {
    return mazeData_ == nullptr;
}

// Main solving function
void Maze::solveMaze() {
    // Think about how to implement this function
}
    
    

