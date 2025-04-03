#include <iostream>
#include <vector>
#include <queue>

class Maze final {
	struct MazeData {
    std::vector<std::vector<int>> maze;       // Source maze
    std::vector<std::vector<int>> distance;   // Matrix of distances
    std::queue<std::pair<int, int>> q;        // Queue for BFS
    std::pair<int, int> start;                // Starting position (2)
    std::pair<int, int> exit;                 // Exit (3)
    std::vector<std::vector<std::pair<int, int>>> parent; // For backtracking
	};

	MazeData *mazeData_;

    const bool isEmpty() const;

	public:
	    Maze(const std::string& filename);

        Maze(const Maze& other) = delete;               // explicitly delete copy constructor
        Maze& operator=(const Maze& other) = delete;    // explicitly delete copy assignment operator

        ~Maze();

        const std::vector<std::vector<int>>& getDistance() const;
        const std::pair<int, int>& getStart() const;
        const std::pair<int, int>& getExit() const;
        const std::vector<std::vector<std::pair<int, int>>>& getParent() const;

        void solveMaze();
};
