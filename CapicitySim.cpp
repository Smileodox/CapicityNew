//
// Created by Paul Keck on 12.01.23.
//


#include "CapicitySim.h"
#include "Leer.h"
#include "Windkraftwerk.h"
#include "Wasserkraftwerk.h"
#include "Solarpanel.h"
#include "Blueprint.h"
#include <algorithm>
#include <vector>


void CapicitySim::start() {

    aktuellePlanID = 0;

    plaene.push_back(new Blueprint(aktuellePlanID, Blueprint::auffordernName()));

    plaene[aktuellePlanID]->initialieserePlan();



    hauptMenue();


}


void CapicitySim::hauptMenue() {

    FunktorVergleich verg;
    bool loop = true;
    int choice, choice_gebaeude, temp_startZeile, temp_startSpalte, temp_zeilenAnz, temp_spaltenAnz;
    int tempIDermittlung = -1;



    while(loop == true) {
        cout << "Bitte wählen Sie ihre nächste Aktion\n" << endl;
        cout << "\t1. Gebäude setzen" << endl;
        cout << "\t2. Bereich löschen" << endl;
        cout << "\t3. Ausgaben des aktuellen Bauplans" << endl;
        cout << "\t4. Ausgabe ALLER Baupläne" << endl;
        cout << "\t5. Neuen Bauplan erstellen" << endl;
        cout << "\t6. Bauplan auswählen" << endl;
        cout << "\t7. Beenden\n" << endl;

        cin >> choice;

        switch (choice) {

            case 1: {
                cout << "Sie haben Gebäude setzen gewählt" << endl;

                cout << "Bitte Gebäudeart wählen" << endl;
                cout << "\t1. WASSERKRAFTWERK" << endl;
                cout << "\t2. WINDKRAFTWERK" << endl;
                cout << "\t3. SOLARPANEL\n" << endl;
                cin >> choice_gebaeude;

                switch (choice_gebaeude) {

                    case 1: {
                        cout << "Sie haben Wasserkraftwerk gewählt\n" << endl;

                        cout << "Bitte Startzeile (oberes linkes Gebäudeeck) eingeben\n";
                        cin >> temp_startZeile;

                        cout << "Bitte Startspalte (oberes linkes Gebäudeeck) eingben\n";
                        cin >> temp_startSpalte;

                        cout << "Bitte ZeilenAnzahl des Gebäudes eingben\n";
                        cin >> temp_zeilenAnz;

                        cout << "Bitte Spaltenanzahl des Gebäudes eingeben\n";
                        cin >> temp_spaltenAnz;

                        plaene[aktuellePlanID]->gebaeudeSetzenMitTest<Wasserkraftwerk>(temp_startZeile, temp_startSpalte, temp_zeilenAnz,
                                                                      temp_spaltenAnz);
                        break;
                    }
                    case 2: {
                        cout << "Sie haben Windkraftwerk gewählt\n" << endl;

                        cout << "Bitte Startzeile (oberes linkes Gebäudeeck) eingeben\n";
                        cin >> temp_startZeile;

                        cout << "Bitte Startspalte (oberes linkes Gebäudeeck) eingben\n";
                        cin >> temp_startSpalte;

                        cout << "Bitte ZeilenAnzahl des Gebäudes eingben\n";
                        cin >> temp_zeilenAnz;

                        cout << "Bitte Spaltenanzahl des Gebäudes eingeben\n";
                        cin >> temp_spaltenAnz;

                        plaene[aktuellePlanID]->gebaeudeSetzenMitTest<Windkraftwerk>(temp_startZeile, temp_startSpalte, temp_zeilenAnz,
                                                                      temp_spaltenAnz);

                        break;
                    }
                    case 3: {
                        cout << "Sie haben Solarpanel gewählt\n" << endl;

                        cout << "Bitte Startzeile (oberes linkes Gebäudeeck) eingeben\n";
                        cin >> temp_startZeile;

                        cout << "Bitte Startspalte (oberes linkes Gebäudeeck) eingben\n";
                        cin >> temp_startSpalte;

                        cout << "Bitte ZeilenAnzahl des Gebäudes eingben\n";
                        cin >> temp_zeilenAnz;

                        cout << "Bitte Spaltenanzahl des Gebäudes eingeben\n";
                        cin >> temp_spaltenAnz;

                        plaene[aktuellePlanID]->gebaeudeSetzenMitTest<Solarpanel>(temp_startZeile, temp_startSpalte, temp_zeilenAnz,
                                                                      temp_spaltenAnz);

                        break;
                    }
                }

                break;
            }

            case 2: {
                cout << "Sie haben Bereich löschen gewählt" << endl;

                cout << "Bitte Startzeile (oberes linkes Gebäudeeck) eingeben\n";
                cin >> temp_startZeile;

                cout << "Bitte Startspalte (oberes linkes Gebäudeeck) eingben\n";
                cin >> temp_startSpalte;

                cout << "Bitte ZeilenAnzahl des Gebäudes eingben\n";
                cin >> temp_zeilenAnz;

                cout << "Bitte Spaltenanzahl des Gebäudes eingeben\n";
                cin >> temp_spaltenAnz;


                plaene[aktuellePlanID]->gebaeudeSetzen<Leer>(temp_startZeile, temp_startSpalte, temp_zeilenAnz,
                                                       temp_spaltenAnz);

                break;
            }

            case 3: {
                cout << "Sie haben Ausgabe des aktuellen Bauplans gewählt\n" << endl;

                plaene[aktuellePlanID]->printFlaeche();

                break;
            }

            case 4: {

                cout << "Sie haben Ausgabe ALLER Pläne gewählt" << endl;


                vector<Blueprint *> plaeneKopie = plaene;

                std::sort(plaeneKopie.begin(), plaeneKopie.end(), [](Blueprint* p1, Blueprint* p2)
                -> bool { return p1->kennzahl() > p2->kennzahl();});

                for(int i = 0; i < plaeneKopie.size(); i++){
                    plaeneKopie[i]->printFlaeche();
                }


                break;
            }

            case 5: {
                cout << "Sie haben erstellen eines neuen Bauplans gewählt\n" << endl;

                for (Blueprint *plan: plaene) {
                    if (plan != plaene[aktuellePlanID] && verg(plaene[aktuellePlanID], plan)) {

                        cout
                                << "Der aktuelle Plan ist identisch zu einem bereits vorhandenen, der aktuelle Plan wird gelöscht\n";
                        verg.istIdent = true;
                        break;
                    }
                }

                if (verg.istIdent) {
                    delete plaene[aktuellePlanID];
                    plaene.pop_back();
                }

                for (Blueprint* plan: plaene) {
                    if (plan->planID > tempIDermittlung)
                        tempIDermittlung = plan->planID;
                }
                aktuellePlanID = tempIDermittlung + 1;

                plaene.push_back(new Blueprint(aktuellePlanID, Blueprint::auffordernName()));

                plaene[aktuellePlanID]->initialieserePlan();

                verg.istIdent = false;

                tempIDermittlung = -1;

                break;
        }

            case 6: {

                cout << "Sie haben Bauplan auswählen gewählt\n" << endl;

                for (Blueprint *plan: plaene) {

                    cout << plan->planName << "\t" << plan->planID << endl;

                }

                cout << "\nBitte PlanID des gewählten Plans eingeben";
                cin >> aktuellePlanID;


                break;
            }

            case 7: {
                cout << "Sie haben Beenden gewählt" << endl;
                loop = false;
                break;
            }
        }

    }

}




