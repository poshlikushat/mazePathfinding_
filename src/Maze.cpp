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
  return parent_;
}

Maze::Maze(const MazeRepresentation& rep) : rep_(rep) {
  dist_.assign(rep_.rows * rep_.cols, -1);  // Initialize size and value
  dist_[rep_.start] = 0;
  parent_.assign(rep_.rows * rep_.cols, -1);
}

void Maze::solve() {
  int size = rep_.rows * rep_.cols;

  std::queue<int> q;
  q.push(rep_.start);

  /* dr (delta row):

  * 1: down
  * -1: up
  * 0: moving horizantally

  */

  /* dc (delta col):

  * 1: right
  * -1: left
  * 0: moving vertically

  */

  const int dr[4] = {1, -1, 0, 0};
  const int dc[4] = {0, 0, 1, -1};

  while (!q.empty()) {
    int u = q.front();  // front() is a member function of the std::queue class that
                        // returns a reference to the front element of the queue.
    q.pop();
    if (u == rep_.exit) break;

    int r = u / rep_.cols;
    int c = u % rep_.cols;

    for (int i = 0; i < 4; ++i) {
      int nr = r + dr[i];
      int nc = c + dc[i];

      if (nr < 0 || nr >= rep_.rows || nc < 0 || nc >= rep_.cols) continue;

      int v = nr * rep_.cols + nc;

      if (dist_[v] == -1 && rep_.maze[v] != 1) {
        dist_[v] = dist_[u] + 1;
        parent_[v] = u;
        q.push(v);
      }
    }
  }
}

std::vector<int> Maze::getPath() const {
  std::vector<int> path;
  int exit = rep_.exit;

  if (dist_[exit] == -1) return path;

  for (int curr = exit; curr != rep_.start; curr = parent_[curr]) {
    path.push_back(curr);
  }
  path.push_back(rep_.start);

  std::reverse(path.begin(), path.end());
  return path;
}