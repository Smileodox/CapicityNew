//
// Created by Paul Keck on 12.01.23.
//

#include "Building.h"
#include <sstream>
#include <map>

Building::Building(std::string name, int id, int gebPreis,
                   std::map<Material*, int> benMaterialien ) :
        gebaeudeName(name), gebaeudeID(id), gebaeudePreis(gebPreis), materialien(benMaterialien)
{

}



int Building::berechneKosten() {

    int result = gebaeudePreis;

    for(std::pair<Material*, int> paar : materialien) {
        result += paar.first->preis * paar.second;
    }
    return result;
}

std::string Building::auflistung()
{
    std::stringstream details;
    details << gebaeudeName << ": ";
    for (std::pair<Material*, int> paar : materialien) {
        details << paar.first->materialName << "(" << paar.first->preis << ") ";
    }
    details << "- Summe: " << berechneKosten();
    return details.str();
}
