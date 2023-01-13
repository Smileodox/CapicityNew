//
// Created by Paul Keck on 13.01.23.
//

#ifndef CAPICITYNEW_FUNKTORVERGLEICH_H
#define CAPICITYNEW_FUNKTORVERGLEICH_H


#include "Blueprint.h"

class FunktorVergleich {

public:
    bool istIdent = false;
    bool operator()(Blueprint* geb1, Blueprint* geb2);

};


#endif //CAPICITYNEW_FUNKTORVERGLEICH_H
