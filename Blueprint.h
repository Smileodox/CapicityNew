//
// Created by Paul Keck on 13.01.23.
//

#ifndef CAPICITYNEW_BLUEPRINT_H
#define CAPICITYNEW_BLUEPRINT_H

#include "Building.h"
#include <vector>

using namespace std;

class Blueprint {
    
public:

    Blueprint(int neueID, std::string name);

    int planID;

    std::string planName;

    int reihen;
    int spalten;
    
    vector<vector<Building*>> gebaeude;

    void initialieserePlan();
    void printFlaeche();
    void gebaeudeSetzenMitTest(int startZeile, int startSpalte, int zeilenAnz, int spaltenAnz, Building* zuBauendesGebaeude);
    void gebaeudeSetzen(int startZeile, int startSpalte, int zeilenAnz, int spaltenAnz, Building* zuBauendesGebaeude);

    static std::string auffordernName();

};


#endif //CAPICITYNEW_BLUEPRINT_H
