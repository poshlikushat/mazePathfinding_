#ifndef MAZE_HPP
#define MAZE_HPP

#include "MazeLoader.hpp"
#include <vector>

class Maze {
  MazeRepresentation rep_;
  std::vector<int> dist_;
  std::vector<int> path_;

  public:
    Maze(MazeRepresentation  rep);
    ~Maze() = default;

    Maze(const Maze& other) = delete;
    Maze& operator=(const Maze& other) = delete;

    void solve();
    std::vector<int> getPath() const;
    const std::vector<int>& getDist() const;
    const std::vector<int>& getParent() const;
    int getStart() const;
    int getExit() const;
};
#endif // MAZE_HPP