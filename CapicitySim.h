//
// Created by Paul Keck on 12.01.23.
//

#ifndef CAPICITYNEW_CAPICITYSIM_H
#define CAPICITYNEW_CAPICITYSIM_H


#include "Building.h"
#include "Blueprint.h"
#include "FunktorVergleich.h"

#include <iostream>
#include <vector>

using namespace std;

class CapicitySim {

public:

    void hauptMenue();

    vector<Blueprint*> plaene;

    int aktuellePlanID;

    void start();



};



#endif //CAPICITYNEW_CAPICITYSIM_H
