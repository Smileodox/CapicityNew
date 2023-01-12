//
// Created by Paul Keck on 12.01.23.
//

#include "Building.h"
#include <sstream>

Building::Building(std::string name, int id, int gebPreis,
                   std::vector<Material*> benMaterialien ) :
        gebäudeName(name), gebäudeID(id), gebäudePreis(gebPreis), materialien(benMaterialien)
{

}



int Building::berechneKosten() {

    int result = gebäudePreis;

    for(auto material : materialien) {
        result += material->preis;
    }
    return result;
}

std::string Building::auflistung()
{
    std::stringstream details;
    details << gebäudeName << ": ";
    for (auto material : materialien) {
        details << material->materialName << "(" << material->preis << ") ";
    }
    details << "- Summe: " << berechneKosten();
    return details.str();
}
