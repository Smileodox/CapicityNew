//
// Created by Paul Keck on 12.01.23.
//

#ifndef CAPICITYNEW_BUILDING_H
#define CAPICITYNEW_BUILDING_H

#include <string>
#include <vector>
#include "Material.h"



class Building {

public:
    Building(std::string name, int id, int gebPreis, std::vector<Material*> benMaterialien);

    std::string gebaeudeName;

    int gebaeudeID;

    int gebaeudePreis;


    int berechneKosten();

    std::string auflistung();

    std::vector<Material*> materialien;
};


#endif //CAPICITYNEW_BUILDING_H
