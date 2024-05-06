#include "Doodlebug.h"
#include <algorithm>
#include <iostream>
using namespace std;

Doodlebug::Doodlebug(int x, int y) : Organism(x, y) {}

void Doodlebug::move(std::vector<std::vector<char>>& grid) {
    // Try to eat ant first
    for (int d = 0; d < 4; ++d) {
        int newX = x,newY = y;
        switch (d) {
            case 0: newY++; break;
            case 1: newX++; break;
            case 2: newY--; break;
            case 3: newX--; break;
        }
        // Check if the new position is valid and contains an ant
        if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == 'o') {
            grid[x][y] = '-'; // Clear the current position
            x = newX;        // Update the position
            y = newY;
            grid[x][y] = 'x'; // Place the doodlebug in the new position
            return;
        }
    }
    // If no ant nearby, move like an ant
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
            grid[x][y] = 'x'; // Place the ant in the new position
            return;
        }
    }
}

