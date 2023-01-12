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

    void printFläche();
    void gebäudeSetzenMitTest(int startZeile, int startSpalte, int zeilenAnz, int spaltenAnz, Building* zuBauendesGebäude);
    void gebäudeSetzen(int startZeile, int startSpalte, int zeilenAnz, int spaltenAnz, Building* zuBauendesGebäude);
    void hauptMenü();



    void start();



};



#endif //CAPICITYNEW_CAPICITYSIM_H
