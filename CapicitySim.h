//
// Created by Paul Keck on 12.01.23.
//

#ifndef CAPICITYNEW_CAPICITYSIM_H
#define CAPICITYNEW_CAPICITYSIM_H


#include "Building.h"

#include <iostream>
#include <vector>

using namespace std;

class CapicitySim {

private:

    int reihen;
    int spalten;
    vector<vector<Building*>> gebaeude;


public:

    void printFlaeche();
    void gebaeudeSetzenMitTest(int startZeile, int startSpalte, int zeilenAnz, int spaltenAnz, Building* zuBauendesGebaeude);
    void gebaeudeSetzen(int startZeile, int startSpalte, int zeilenAnz, int spaltenAnz, Building* zuBauendesGebaeude);
    void hauptMenue();



    void start();



};



#endif //CAPICITYNEW_CAPICITYSIM_H
