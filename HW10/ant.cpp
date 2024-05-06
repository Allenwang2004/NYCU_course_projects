#include "Ant.h"

Ant::Ant(int x, int y) : Organism(x, y) {}

void Ant::move(std::vector<std::vector<char>>& grid) {
    if( grid[x][y] != 'o')
    {
        return;
    }
    // Try moving in each direction based on priority
    for (int d = 0; d < 4; ++d) {
        int newX = x, newY = y;
        switch (d) {
            case 0: newY++; break;
            case 1: newX++; break;
            case 2: newY--; break;
            case 3: newX--; break;
        }
        
        // Check if the new position is valid and empty
        if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == '-') {
            grid[x][y] = '-'; // Clear the current position
            x = newX;        // Update the position
            y = newY;
            grid[x][y] = 'o'; // Place the ant in the new position
            return;
        }
    }
}

