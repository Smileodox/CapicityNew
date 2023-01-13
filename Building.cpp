//
// Created by Paul Keck on 12.01.23.
//

#include "Building.h"
#include <sstream>

Building::Building(std::string name, int id, int gebPreis,
                   std::vector<Material*> benMaterialien ) :
        gebaeudeName(name), gebaeudeID(id), gebaeudePreis(gebPreis), materialien(benMaterialien)
{

}



int Building::berechneKosten() {

    int result = gebaeudePreis;

    for(auto material : materialien) {
        result += material->preis;
    }
    return result;
}

std::string Building::auflistung()
{
    std::stringstream details;
    details << gebaeudeName << ": ";
    for (auto material : materialien) {
        details << material->materialName << "(" << material->preis << ") ";
    }
    details << "- Summe: " << berechneKosten();
    return details.str();
}
