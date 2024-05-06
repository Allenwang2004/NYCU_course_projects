#ifndef ORGANISM_H
#define ORGANISM_H

#include <vector>

class Organism {
protected:
    int x, y;

public:
    Organism(int x, int y);
    virtual ~Organism() {}

    virtual void move(std::vector<std::vector<char>>& grid) = 0;
    int getX() const;
    int getY() const;
};

#endif // ORGANISM_H


