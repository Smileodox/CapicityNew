//
// Created by Paul Keck on 13.01.23.
//

#include "FunktorVergleich.h"

bool FunktorVergleich::operator()(Blueprint *geb1, Blueprint *geb2) {

    if(geb1->reihen == geb2->reihen && geb1->spalten == geb2->spalten) {

        for(int i = 0; i < geb1->reihen;i++) {
            for(int j = 0; j < geb1->spalten; j++){
                if(geb1->gebaeude[i][j]->gebaeudeID != geb2->gebaeude[i][j]->gebaeudeID) {
                    return false;
                }
            }
        }

    } else{
        return false;
    }
    return true;
}
