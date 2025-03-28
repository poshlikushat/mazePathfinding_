#include <iostream>
#include <vector>
#include <queue>

class Maze {
	struct MazeData {
    std::vector<std::vector<int>> maze;       // Source maze
    std::vector<std::vector<int>> distance;   // Matrix of distances
    std::queue<std::pair<int, int>> q;        // Queue for BFS
    std::pair<int, int> start;                // Starting position (2)
    std::pair<int, int> exit;                 // Exit (3)
    std::vector<std::vector<std::pair<int, int>>> parent; // For backtracking
	};

	MazeData *mazeData_;

	public:
	
	int getStart() const;

	int getExit() const;


};
