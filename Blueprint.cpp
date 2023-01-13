//
// Created by Paul Keck on 13.01.23.
//

#include "Blueprint.h"
#include "Building.h"
#include "Leer.h"
#include <iostream>

void Blueprint::initialieserePlan() {

    std::cout <<"Bitte ZeilenAnzahl der zu simulierenten Fläche eingeben\n";
    std::cin >> reihen;

    std::cout <<"Bitte SpaltenAnzahl der zu simulierenten Fläche eingeben\n";
    std::cin >> spalten;

    //Flächen Vektor initialisieren

    gebaeude = vector<vector<Building*>>(reihen, vector<Building*>(spalten));

    for(int i = 0; i < gebaeude.size(); i++) {
        for(int j = 0; j < gebaeude[i].size(); j++) {
            gebaeude[i][j] = new Leer();
        }
    }

}

void Blueprint::printFlaeche() {

    int temp = 0;

    kpi = kennzahl();

    for(int i = 0; i < gebaeude.size(); i++) {
        for(int j = 0; j < gebaeude[i].size(); j++) {
            std::cout << gebaeude[i][j]->gebaeudeName; std::cout << "\t\t";
        }
        std::cout << "\n\n";
    }

    for(int i = 0; i < gebaeude.size(); i++) {
        for(int j = 0; j < gebaeude[i].size(); j++) {
            if(gebaeude[i][j]->gebaeudeID != 0) {
                temp += gebaeude[i][j]->berechneKosten();
                cout << "[" << i << "][" << j << "]" << gebaeude[i][j]->auflistung() << endl;
            }
        }
    }
    std::cout << "\n\nGesamtkosten:     " << temp<<"\n"<<endl;
    std::cout << "\n\nKennzahl:     " << kpi<<"\n"<<endl;


}

void Blueprint::gebaeudeSetzenMitTest(int startZeile, int startSpalte, int zeilenAnz, int spaltenAnz,
                                      Building *zuBauendesGebaeude){

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

    if(test == true) {

        cout << "Gebäude kollidiert mit anderen Gebäuden, Vorgang wird abgebrochen\n" << endl;

    } else if(outOfBounds != true){

        for(int i = startZeile - 1; i < startZeile - 1 + zeilenAnz; i++){
            for(int j = startSpalte - 1; j < startSpalte - 1 + spaltenAnz; j++){
                gebaeude[i][j] = zuBauendesGebaeude;
            }
        }

    }


}

void Blueprint::gebaeudeSetzen(int startZeile, int startSpalte, int zeilenAnz, int spaltenAnz,
                               Building *zuBauendesGebaeude) {

    for(int i = startZeile - 1; i < startZeile - 1 + zeilenAnz; i++){
        for(int j = startSpalte - 1; j < startSpalte - 1 + spaltenAnz; j++){
            gebaeude[i][j] = zuBauendesGebaeude;
        }
    }

}

Blueprint::Blueprint(int neueID, std::string name) : planID(neueID), planName(name)
{

}

std::string Blueprint::auffordernName() {
    std::string temp;
    cout<<"\tBitte Namen für neuen Plan eingeben\n"<<endl;
    cin>> temp;
    return temp;
}

float Blueprint::kennzahl() {

    int gesLeistung=0, gesKosten=0, anzFelder=0;
    float kennzahl=0;

    for(int i = 0; i < gebaeude.size(); i++) {
        for(int j = 0; j < gebaeude[i].size(); j++) {
          gesLeistung += gebaeude[i][j]->getLeistung();
          gesKosten += gebaeude[i][j]->berechneKosten();
          anzFelder += 1;
        }
    }

    kennzahl =(float) gesLeistung/(gesKosten*anzFelder);


    return kennzahl;
}


