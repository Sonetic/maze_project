#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Cell {
    int x, y; // cell coordinates
    bool walls[4] = {true, true, true, true}; // initialize cell closed on all sides
    bool visited = false;
};

vector<vector<Cell>> maze;
stack<Cell*> cellStack; // stack of cells

void initialize(int width, int height) {
    maze.resize(width, vector<Cell>(height)); // set maze size
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; ++y) {
            maze[x][y].x = x; // set coordinates
            maze[x][y].y = y;
        }
    }
    maze[0][0].walls[3] = false;
    maze[0][height - 1].walls[3] = false;
}

Cell* neighbours(Cell* cell, int width, int height) {
    vector<Cell*> neighbours; // initialize neighbors array
    int x = cell->x;
    int y = cell->y;

    if (x > 0 && !maze[x - 1][y].visited) // check left
        neighbours.push_back(&maze[x - 1][y]);
    if (x < width - 1 && !maze[x + 1][y].visited) // check right
        neighbours.push_back(&maze[x + 1][y]);
    if (y > 0 && !maze[x][y - 1].visited) // check up
        neighbours.push_back(&maze[x][y - 1]);
    if (y < height - 1 && !maze[x][y + 1].visited) // check down
        neighbours.push_back(&maze[x][y + 1]);

    if (neighbours.size() > 0) {
        return neighbours[rand() % neighbours.size()]; // pick random neighbor
    }
    return nullptr; // if neighbor vector is empty
}

void removewalls(Cell* current, Cell* next) {
    int xDiff = current->x - next->x;
    int yDiff = current->y - next->y;

    if (xDiff == 1) {
        current->walls[3] = false;
        next->walls[1] = false;
    } else if (xDiff == -1) {
        current->walls[1] = false;
        next->walls[3] = false;
    }
    if (yDiff == 1) {
        current->walls[0] = false;
        next->walls[2] = false;
    } else if (yDiff == -1) {
        current->walls[2] = false;
        next->walls[0] = false;
    }
}

void generate(int width, int height) {
    Cell* current = &maze[0][0];
    current->visited = true;
    cellStack.push(current); // add cell to stack

    while (cellStack.size() > 0) { // while stack not empty, take top cell
        current = cellStack.top();
        Cell* next = neighbours(current, width, height); // find unvisited neighbor

        if (next) { // if there is an unvisited neighbor
            next->visited = true;
            cellStack.push(next); // add it to stack
            removewalls(current, next); // remove walls
        } else { // if no unvisited neighbor found
            cellStack.pop(); // remove current cell and backtrack (DFS algorithm)
        }
    }
}

void print(int width, int height) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (maze[x][y].walls[0]) {
                cout << "+---";
            } else {
                cout << "+   ";
            }
        }
        cout << "+" << endl;
        for (int x = 0; x < width; ++x) {
            if (maze[x][y].walls[3]) {
                cout << "|   ";
            } else {
                cout << "    ";
            }
        }
        cout << "|" << endl;
    }
    for (int x = 0; x < width; ++x) {
        cout << "+---";
    }
    cout << "+" << endl;
}

int main(int argc, char *argv[]) {
    srand(time(0)); // current time as random seed
    int width;
    int height;
    width = 10;
    height = 20;

    initialize(width, height);
    generate(width, height);
    print(width, height);

    return 0;
}
