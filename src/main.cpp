#include <iostream>
#include <vector>
#include "MazeLoader.hpp"
#include "Maze.hpp"

int main(int argc, char** argv) {
  std::string filename = (argc > 1 ? std::string(argv[1]) : "data.txt");

  try {
    MazeRepresentation rep = MazeLoader::loadMaze(filename);

    Maze maze(rep);
    maze.solve();

    std::vector<int> path = maze.getPath();

    if (path.empty()) {
      std::cout << "Пути нет\n";
      return 0;
    }

    std::cout << "Кратчайший путь: " << path.size() - 1 << " шаг(ов)\n";
    std::cout << "Маршрут (row, col):\n";

    for (int idx : path) {
      int r = idx / rep.cols;
      int c = idx % rep.cols;
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
