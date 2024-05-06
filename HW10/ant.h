#ifndef ANT_H
#define ANT_H

#include "Organism.h"

class Ant : public Organism {
public:
    Ant(int x, int y);

    void move(std::vector<std::vector<char>>& grid) override;
};

#endif // ANT_H

