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

  MazeLoader() = delete;
  MazeLoader(const MazeLoader&) = delete;
  MazeLoader& operator=(const MazeLoader&) = delete;
  ~MazeLoader() = delete;
};
#endif // MAZELOADER_HPP