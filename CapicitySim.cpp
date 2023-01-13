//
// Created by Paul Keck on 12.01.23.
//


#include "CapicitySim.h"
#include "Building.h"
#include "Leer.h"
#include "Windkraftwerk.h"
#include "Wasserkraftwerk.h"
#include "Solarpanel.h"
#include "Blueprint.h"
#include <vector>


void CapicitySim::start() {

    aktuell.initialieserePlan();

    hauptMenue();


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

                        aktuell.gebaeudeSetzenMitTest(temp_startZeile, temp_startSpalte, temp_zeilenAnz,
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

                        aktuell.gebaeudeSetzenMitTest(temp_startZeile, temp_startSpalte, temp_zeilenAnz,
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

                        aktuell.gebaeudeSetzenMitTest(temp_startZeile, temp_startSpalte, temp_zeilenAnz,
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

                aktuell.gebaeudeSetzen(temp_startZeile, temp_startSpalte, temp_zeilenAnz,
                               temp_spaltenAnz, new Leer());

                break;

            case 3:
                cout << "Sie haben Ausgabe des aktuellen Bauplans gewählt\n" << endl;

                aktuell.printFlaeche();

                break;

            case 4:
                cout << "Sie haben Beenden gewählt" << endl;
                loop = false;
                break;
        }

    }

}


