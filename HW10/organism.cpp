#include "Organism.h"

Organism::Organism(int x, int y) : x(x), y(y) {}

int Organism::getX() const {
    return x;
}

int Organism::getY() const {
    return y;
}

