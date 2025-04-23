#ifndef MAZELOADER_HPP
#define MAZELOADER_HPP

#include <string>
#include <vector>

struct MazeRepresentation {
  std::vector<int> maze;
  int rows;
  int cols;
  int start;
  int exit;
};

class MazeLoader final {
  public:
    static MazeRepresentation loadMaze(const std::string& filename);
};


#endif // MAZELOADER_HPP