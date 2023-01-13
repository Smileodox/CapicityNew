//
// Created by Paul Keck on 12.01.23.
//

#ifndef CAPICITYNEW_BUILDING_H
#define CAPICITYNEW_BUILDING_H

#include <string>
#include <map>              //Kapitel 3: Lösung mit Maps in den Buildings realisiert,
#include "Material.h"                           //erschien mir ehrlich gesagt einfacher





class Building {

public:
    Building(std::string name, int id, int gebPreis, int leistung, std::map<Material*, int> benMaterialien);

    std::string gebaeudeName;

    int gebaeudeID;

    int gebaeudePreis;

    int gebaudeLeistung;


    int berechneKosten();

    std::string auflistung();


    std::map<Material*, int> materialien;


};


#endif //CAPICITYNEW_BUILDING_H
