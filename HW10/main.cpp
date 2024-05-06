#include <iostream>
#include <vector>
#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"
using namespace std;

int main() {
    // Initialize the grid
    const int SIZE = 5;
    std::vector<std::vector<char>> grid(SIZE, std::vector<char>(SIZE, '-'));

    // Create doodlebug
    int doodleX, doodleY;
    std::cin >> doodleX >> doodleY;
    Doodlebug doodlebug(doodleX, doodleY);
    grid[doodleX][doodleY] = 'x';

    // Create ants
    int antx,anty;
    cin >> antx >> anty;
    Ant ant1(antx,anty);
    grid[antx][anty] = 'o';
    cin >> antx >> anty;
    Ant ant2(antx,anty);
    grid[antx][anty] = 'o';
    cin >> antx >> anty;
    Ant ant3(antx,anty);
    grid[antx][anty] = 'o';

    // Print the initial grid
    std::cout << "----time0----" << std::endl;
        for (int j = SIZE-1; j>=0; --j) {
            for (int i = 0; i < SIZE; ++i) {
                std::cout << grid[i][j];
            }
            std::cout << std::endl;
        }

    // Simulate time steps
    char command;
    int time = 1;
    while (std::cin >> command && command == 'n') {
        std::cout << "----time" << time++ << "----" << std::endl;

        // Move doodlebug
        doodlebug.move(grid);

        // Move ants
        ant3.move(grid);
        ant2.move(grid);
        ant1.move(grid);

        // Print the grid after moves
        for (int j = SIZE-1; j>=0; --j) {
            for (int i = 0; i < SIZE; ++i) {
                std::cout << grid[i][j];
            }
            std::cout << std::endl;
        }
    }

    return 0;
}

