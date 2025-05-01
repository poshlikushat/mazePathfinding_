#include "Maze.hpp"
#include <queue>
#include <algorithm>

int Maze::getStart() const {
  return rep_.start;
}

int Maze::getExit() const {
  return rep_.exit;
}

const std::vector<int>& Maze::getDist() const {
  return dist_;
}

const std::vector<int>& Maze::getParent() const {
  return path_;
}

Maze::Maze(MazeRepresentation  rep) : rep_(std::move(rep)) {
  dist_.assign(rep_.rows * rep_.cols, -1);  // Initialize size and value
  dist_[rep_.start] = 0;
  path_.assign(rep_.rows * rep_.cols, -1);
}

void Maze::solve() {

  std::queue<int> q;
  q.push(rep_.start);

  constexpr int deltaRow[4] = {1, -1, 0, 0};
  constexpr int deltaCol[4] = {0, 0, 1, -1};

  while (!q.empty()) {
    const int front = q.front();  // front() is a member function of the std::queue class that
                        // returns a reference to the front element of the queue.
    q.pop();
    if (front == rep_.exit) break;

    const int row = front / rep_.cols;
    const int col = front % rep_.cols;

    for (int i = 0; i < 4; ++i) {
      const int rowShift = row + deltaRow[i];
      const int colShift = col + deltaCol[i];

      if (rowShift < 0 || rowShift >= rep_.rows || colShift < 0 || colShift >= rep_.cols) continue;

      int v = rowShift * rep_.cols + colShift;

      if (dist_[v] == -1 && rep_.maze[v] != 1) {
        dist_[v] = dist_[front] + 1;
        path_[v] = front;
        q.push(v);
      }
    }
  }
}

std::vector<int> Maze::getPath() const {
  std::vector<int> path;  // Сделать деку
  int exit = rep_.exit;

  if (dist_[exit] == -1) return path;

  for (int curr = exit; curr != rep_.start; curr = path_[curr]) {
    path.push_back(curr);
  }
  path.push_back(rep_.start);

  std::reverse(path.begin(), path.end());
  return path;
}