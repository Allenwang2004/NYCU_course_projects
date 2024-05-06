#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "Organism.h"

class Doodlebug : public Organism {
public:
    Doodlebug(int x, int y);

    void move(std::vector<std::vector<char>>& grid) override;
};

#endif // DOODLEBUG_H

