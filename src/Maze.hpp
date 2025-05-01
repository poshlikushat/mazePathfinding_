#ifndef MAZE_HPP
#define MAZE_HPP

#include "MazeLoader.hpp"
#include <vector>
#include <deque>

class Maze {
  MazeRepresentation rep_;
  std::vector<int> dist_;
  std::vector<int> path_;

  public:
    explicit Maze(MazeRepresentation rep);
    ~Maze() = default;

    Maze(const Maze& other) = delete;
    Maze& operator=(const Maze& other) = delete;

    void solve();
    [[nodiscard]] std::deque<int> getPath() const;
    [[nodiscard]] const std::vector<int>& getDist() const;
    [[nodiscard]] const std::vector<int>& getParent() const;
    [[nodiscard]] int getStart() const;
    [[nodiscard]] int getExit() const;
};
#endif // MAZE_HPP