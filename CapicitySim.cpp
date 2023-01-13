//
// Created by Paul Keck on 12.01.23.
//


#include "CapicitySim.h"
#include "Building.h"
#include "Leer.h"
#include "Windkraftwerk.h"
#include "Wasserkraftwerk.h"
#include "Solarpanel.h"
#include <vector>


void CapicitySim::start() {


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




    //Test
    printFlaeche();

    hauptMenue();


}


void CapicitySim::gebaeudeSetzenMitTest(int startZeile, int startSpalte, int zeilenAnz, int spaltenAnz,
                                        Building* zuBauendesGebaeude)
{
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

void CapicitySim::printFlaeche() {

    int temp = 0;

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


}

void CapicitySim::hauptMenue() {

    bool loop = true;
    int choice, choice_gebäude, temp_startZeile, temp_startSpalte, temp_zeilenAnz, temp_spaltenAnz;



    while(loop == true) {
        cout << "Bitte wählen Sie ihre nächste Aktion\n" << endl;
        cout << "\t1. Gebäude setzen" << endl;
        cout << "\t2. Bereich löschen" << endl;
        cout << "\t3. Ausgaben des aktuellen Bauplans" << endl;
        cout << "\t4. Beenden\n" << endl;

        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Sie haben Gebäude setzen gewählt" << endl;

                cout << "Bitte Gebäudeart wählen" << endl;
                cout << "\t1. WASSERKRAFTWERK" << endl;
                cout << "\t2. WINDKRAFTWERK" << endl;
                cout << "\t3. SOLARPANEL\n" << endl;
                cin >> choice_gebäude;

                switch (choice_gebäude) {

                    case 1:
                        cout << "Sie haben Wasserkraftwerk gewählt\n" << endl;

                        cout << "Bitte Startzeile (oberes linkes Gebäudeeck) eingeben\n";
                        cin >> temp_startZeile;

                        cout << "Bitte Startspalte (oberes linkes Gebäudeeck) eingben\n";
                        cin >> temp_startSpalte;

                        cout << "Bitte ZeilenAnzahl des Gebäudes eingben\n";
                        cin >> temp_zeilenAnz;

                        cout << "Bitte Spaltenanzahl des Gebäudes eingeben\n";
                        cin >> temp_spaltenAnz;

                        gebaeudeSetzenMitTest(temp_startZeile, temp_startSpalte, temp_zeilenAnz,
                                              temp_spaltenAnz, new Wasserkraftwerk());
                        break;

                    case 2:
                        cout << "Sie haben Windkraftwerk gewählt\n" << endl;

                        cout << "Bitte Startzeile (oberes linkes Gebäudeeck) eingeben\n";
                        cin >> temp_startZeile;

                        cout << "Bitte Startspalte (oberes linkes Gebäudeeck) eingben\n";
                        cin >> temp_startSpalte;

                        cout << "Bitte ZeilenAnzahl des Gebäudes eingben\n";
                        cin >> temp_zeilenAnz;

                        cout << "Bitte Spaltenanzahl des Gebäudes eingeben\n";
                        cin >> temp_spaltenAnz;

                        gebaeudeSetzenMitTest(temp_startZeile, temp_startSpalte, temp_zeilenAnz,
                                              temp_spaltenAnz, new Windkraftwerk());

                        break;

                    case 3:
                        cout << "Sie haben Solarpanel gewählt\n" << endl;

                        cout << "Bitte Startzeile (oberes linkes Gebäudeeck) eingeben\n";
                        cin >> temp_startZeile;

                        cout << "Bitte Startspalte (oberes linkes Gebäudeeck) eingben\n";
                        cin >> temp_startSpalte;

                        cout << "Bitte ZeilenAnzahl des Gebäudes eingben\n";
                        cin >> temp_zeilenAnz;

                        cout << "Bitte Spaltenanzahl des Gebäudes eingeben\n";
                        cin >> temp_spaltenAnz;

                        gebaeudeSetzenMitTest(temp_startZeile, temp_startSpalte, temp_zeilenAnz,
                                              temp_spaltenAnz, new Solarpanel());

                        break;

                }

                break;

            case 2:
                cout << "Sie haben Bereich löschen gewählt" << endl;

                cout << "Bitte Startzeile (oberes linkes Gebäudeeck) eingeben\n";
                cin >> temp_startZeile;

                cout << "Bitte Startspalte (oberes linkes Gebäudeeck) eingben\n";
                cin >> temp_startSpalte;

                cout << "Bitte ZeilenAnzahl des Gebäudes eingben\n";
                cin >> temp_zeilenAnz;

                cout << "Bitte Spaltenanzahl des Gebäudes eingeben\n";
                cin >> temp_spaltenAnz;

                //Delete die Instanz vom vorherigen Builing solange der Pointer noch existiert --> keine MemoryLeaks
                //for(int i = temp_startZeile - 1; i < temp_startZeile - 1 + temp_zeilenAnz; i++){
                //for(int j = temp_startSpalte - 1; j < temp_startSpalte - 1 + temp_spaltenAnz; j++){
                //delete gebaeude[i][j] ;
                //}
                //}

                gebaeudeSetzen(temp_startZeile, temp_startSpalte, temp_zeilenAnz,
                               temp_spaltenAnz, new Leer());

                break;

            case 3:
                cout << "Sie haben Ausgabe des aktuellen Bauplans gewählt\n" << endl;

                printFlaeche();

                break;

            case 4:
                cout << "Sie haben Beenden gewählt" << endl;
                loop = false;
                break;
        }

    }

}

void
CapicitySim::gebaeudeSetzen(int startZeile, int startSpalte, int zeilenAnz, int spaltenAnz, Building* zuBauendesGebaeude) {

    for(int i = startZeile - 1; i < startZeile - 1 + zeilenAnz; i++){
        for(int j = startSpalte - 1; j < startSpalte - 1 + spaltenAnz; j++){
            gebaeude[i][j] = zuBauendesGebaeude;
        }
    }

}
