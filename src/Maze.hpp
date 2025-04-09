#ifndef MAZE_HPP
#define MAZE_HPP

#include "MazeLoader.hpp"
#include <vector>

class Maze final {
  MazeRepresentation rep_;
  std::vector<int> dist_;
  std::vector<int> parent_;

  public:
    Maze(const MazeRepresentation& rep);
    ~Maze();

    Maze(const Maze& other) = delete;
    Maze& operator=(const Maze& other) = delete;

    void solve();
    const std::vector<int>& getDist() const;
    int getStart() const;
    int getExit() const;

};

#endif // MAZE_HPP