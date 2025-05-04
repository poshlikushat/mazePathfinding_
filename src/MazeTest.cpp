#include "gtest/gtest.h"
#include "MazeLoader.hpp"
#include "Maze.hpp"

TEST(MazeGetTest, GetStartExit) {
  const auto rep = MazeLoader::loadMaze("data.txt");
  const Maze maze(rep);
  EXPECT_EQ(maze.getStart(), rep.start);
  EXPECT_EQ(maze.getExit(),  rep.exit);
}

TEST(MazeGetTest, DistAndParentAfterSolve) {
  const auto rep = MazeLoader::loadMaze("data.txt");
  Maze maze(rep);

  EXPECT_NO_THROW(maze.solve());
  const auto& dist   = maze.getDist();
  const auto& parent = maze.getParent();

  EXPECT_EQ(dist[rep.start], 0);
  EXPECT_EQ(dist[rep.exit], 15);

  EXPECT_TRUE(parent[rep.start] == -1);
}

TEST(MazePathTest, StartAndExitAtEndsAndLength) {
    const auto rep  = MazeLoader::loadMaze("data.txt");
    Maze maze(rep);

    const auto path = maze.solve();
    const auto& dist = maze.getDist();

    EXPECT_EQ(path.front(), rep.start);
    EXPECT_EQ(path.back(),  rep.exit);

    EXPECT_EQ(path.size(), dist[rep.exit] + 1);
}

TEST(MazePathTest, DistancesAlongPathMonotonic) {
    const auto rep  = MazeLoader::loadMaze("data.txt");
    Maze maze(rep);

    const auto& path = maze.solve();
    const auto& dist = maze.getDist();

    for (size_t i = 0; i < path.size(); ++i) {
        EXPECT_EQ(dist[path[i]], static_cast<int>(i));
    }
}

TEST(MazePathTest, ConsecutiveStepsAreAdjacent) {
    const auto rep  = MazeLoader::loadMaze("data.txt");
    Maze maze(rep);

    const auto path = maze.solve();
    for (size_t i = 1; i < path.size(); ++i) {
        const int a = path[i-1], b = path[i];
        const int ar = a / rep.cols, ac = a % rep.cols;
        const int br = b / rep.cols, bc = b % rep.cols;
        EXPECT_EQ(std::abs(ar - br) + std::abs(ac - bc), 1);
    }
}

TEST(MazePathTest, WallsRemainUnreachable) {
    const auto rep  = MazeLoader::loadMaze("data.txt");
    Maze maze(rep);
    maze.solve();

    const auto& dist = maze.getDist();
    // для всех клеток-стен dist == -1
    for (int i = 0; i < rep.rows * rep.cols; ++i) {
        if (rep.maze[i] == 1) {
            EXPECT_EQ(dist[i], -1);
        }
    }
}

TEST(MazePathTest, ParentsOfUnreachableAlsoMinusOne) {
    const auto rep  = MazeLoader::loadMaze("data.txt");
    Maze maze(rep);
    maze.solve();

    const auto& dist   = maze.getDist();
    const auto& parent = maze.getParent();
    // для всех недостижимых клеток parent == -1
    for (int i = 0; i < rep.rows * rep.cols; ++i) {
        if (dist[i] == -1) {
            EXPECT_EQ(parent[i], -1);
        }
    }
}
