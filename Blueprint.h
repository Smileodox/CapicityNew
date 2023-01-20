//
// Created by Paul Keck on 13.01.23.
//

#ifndef CAPICITYNEW_BLUEPRINT_H
#define CAPICITYNEW_BLUEPRINT_H

#include "Building.h"
#include <vector>
#include <iostream>


using namespace std;

class Blueprint {
    
public:

    ~Blueprint();

    Blueprint(int neueID, std::string name);

    int planID;

    std::string planName;
    float kpi;
    int reihen;
    int spalten;
    
    vector<vector<Building*>> gebaeude;

    void initialieserePlan();
    void printFlaeche();

    template<typename B>
    void gebaeudeSetzenMitTest(int startZeile, int startSpalte, int zeilenAnz, int spaltenAnz);

    template<typename B>
    void gebaeudeSetzen(int startZeile, int startSpalte, int zeilenAnz, int spaltenAnz);

    static std::string auffordernName();

    float kennzahl();

};

template<typename B>
void Blueprint::gebaeudeSetzenMitTest(int startZeile, int startSpalte, int zeilenAnz, int spaltenAnz){

    bool test = false;
    bool outOfBounds = false;


    if(startZeile > gebaeude.size() || startSpalte > gebaeude[0].size()
       || (startSpalte - 1 + spaltenAnz) > gebaeude[0].size() || (startZeile - 1 + zeilenAnz) >
                                                                 gebaeude.size()){

        std::cout<< "Gebäude ist out of Bounds\n"<<endl;
        outOfBounds = true;


    }else{
        for (int i = startZeile - 1; i < startZeile - 1 + zeilenAnz; i++) {
            for (int j = startSpalte - 1; j < startSpalte - 1 + spaltenAnz; j++) {
                if (gebaeude[i][j]->gebaeudeID != 0){
                    test = true;

                }
            }
        }


    }

    if(test) {

        cout << "Gebäude kollidiert mit anderen Gebäuden, Vorgang wird abgebrochen\n" << endl;

    } else if(!outOfBounds){

        gebaeudeSetzen<B>(startZeile, startSpalte, zeilenAnz, spaltenAnz);

    }


}

template<typename B>
void Blueprint::gebaeudeSetzen(int startZeile, int startSpalte, int zeilenAnz, int spaltenAnz) {

    for(int i = startZeile - 1; i < startZeile - 1 + zeilenAnz; i++){
        for(int j = startSpalte - 1; j < startSpalte - 1 + spaltenAnz; j++){
            delete gebaeude[i][j];
            gebaeude[i][j] = new B();
        }
    }

}


#endif //CAPICITYNEW_BLUEPRINT_H
