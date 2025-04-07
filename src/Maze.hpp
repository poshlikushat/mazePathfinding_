#include <iostream>
#include <vector>
#include <queue>

class Maze final {
	struct MazeData {
    std::vector<int> maze;       // Source maze
    std::vector<int> distance;   // Matrix of distances
    std::queue<int> q;           // Queue for BFS
    std::vector<int> parent;     // For backtracking

    struct Start {               // Starting position (2)
        int x;
        int y;
    };

   struct Exit {                 // Exit (3)
        int x;
        int y;
    };

	};

	MazeData *mazeData_;

    const bool isEmpty() const;

	public:
	    Maze(const std::string& filename);

        Maze(const Maze& other) = delete;               // explicitly delete copy constructor
        Maze& operator=(const Maze& other) = delete;    // explicitly delete copy assignment operator

        virtual ~Maze();

        const std::vector<int>& getDistance() const;
        const MazeData::Start& getStart() const;
        const MazeData::Exit& getExit() const;
        const std::vector<int>& getParent() const;

        void solveMaze();
};
