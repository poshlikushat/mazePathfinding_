#include <iostream>
#include <vector>
#include "MazeLoader.hpp"
#include "Maze.hpp"

int main(const int argc, char** argv) {
  const std::string filename = (argc > 1 ? std::string(argv[1]) : "data.txt");

  try {
    const MazeRepresentation rep = MazeLoader::loadMaze(filename);

    Maze maze(rep);

    const std::deque<int> path = maze.solve();

    if (path.empty()) {
      std::cout << "There is no way\n";
      return 0;
    }

    std::cout << "The shortest path: " << path.size() - 1 << " step(s)\n";
    std::cout << "Route (row, col):\n";

    for (const int idx : path) {
      const int r = idx / rep.cols;
      const int c = idx % rep.cols;
      std::cout << "(" << c << "," << r << ") ";
    }
    std::cout << "\n";
  }
  catch (const std::exception& e) {
    std::cerr << "Ошибка: " << e.what() << "\n";
    return 1;
  }

  return 0;
}
