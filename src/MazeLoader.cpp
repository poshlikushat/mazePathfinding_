#include "MazeLoader.hpp"
#include <fstream>
#include <vector>
#include <stdexcept>

MazeRepresentation MazeLoader::loadMaze(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) throw std::runtime_error("Failed to open file: " + filename);

  std::string raw;
  std::vector<std::string> lines;
  while (std::getline(file, raw)) {
    std::string row;
    row.reserve(raw.size());
    for (char c : raw) {
      if (!std::isspace(static_cast<unsigned char>(c)))
        row.push_back(c);
    }
    if (row.empty())
      throw std::runtime_error("Empty (or all-space) line in maze file");
    lines.push_back(row);
  }

    if (lines.empty()) throw std::runtime_error("Maze file is empty");


    MazeRepresentation rep;

    rep.rows = lines.size();
    rep.cols = lines[0].size();

    bool startFound = false;
    bool exitFound = false;

    for (const auto& row : lines) {
      if (row.size() != rep.cols) throw std::runtime_error("All rows must be of the same length");
        for (auto coll : row) {
          switch (coll) {
            case '0':
              rep.maze.push_back(0);
              break;
            case '1':
              rep.maze.push_back(1);
              break;
            case '2':
              if (startFound) throw std::runtime_error("Multiple start positions found");
              rep.maze.push_back(2);
              startFound = true;
              rep.start = rep.maze.size() - 1;
              break;
            case '3':
              if (exitFound) throw std::runtime_error("Multiple exit positions found");
              rep.maze.push_back(3);
              exitFound = true;
              rep.exit = rep.maze.size() - 1;
              break;
            default:
              throw std::runtime_error("Invalid character in maze file");
            }
        }
    }
    if (!startFound) throw std::runtime_error("Start position not found in maze file");
    else if (!exitFound) throw std::runtime_error("Exit position not found in maze file");

    return rep;
}
