#include <iostream>
#include <vector>
#include <map>

using namespace std;

enum Gebäude {
    LEER,
    WASSERKRAFTWERK,
    WINDKRAFTWERK,
    SOLARPANEL
};



int main() {

    map<Gebäude, string> gebäude_map{
            {Gebäude::LEER, "leer"},
            {Gebäude::WASSERKRAFTWERK, "Wasserkraftwerk"},
            {Gebäude::WINDKRAFTWERK, "Windkraftwerk"},
            {Gebäude::SOLARPANEL, "Solarpanel"}

    };

    int rows, columns, choice;
    bool loop = true;
    bool help = false;
    int startZeile, startSpalte, zeilenAnz, spaltenAnz, choice_gebäude;
    Gebäude g;

    std::cout <<"Bitte ZeilenAnzahl der zu simulierenten Fläche eingeben\n";
    std::cin >> rows;

    std::cout <<"Bitte SpaltenAnzahl der zu simulierenten Fläche eingeben\n";
    std::cin >> columns;

    std::vector<std::vector<Gebäude>> fläche(rows, std::vector<Gebäude>(columns,LEER));



    // Printe die Fläche
    for(int i = 0; i < fläche.size(); i++) {
        for(int j = 0; j < fläche[i].size();j++) {
            cout << gebäude_map[fläche[i][j]]; cout << "\t\t";
        }
        cout << "\n\n";
    }

    while(loop == true){
        cout<< "Bitte wählen Sie ihre nächste Aktion\n"<<endl;
        cout<< "\t1. Gebäude setzen"<<endl;
        cout<< "\t2. Bereich löschen"<<endl;
        cout<< "\t3. Ausgaben des aktuellen Bauplans"<<endl;
        cout<< "\t4. Beenden\n"<<endl;

        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Sie haben Gebäude setzen gewählt" <<endl;

                cout<<"Bitte Gebäudeart wählen"<<endl;
                cout<< "\t1. WASSERKRAFTWERK"<<endl;
                cout<< "\t2. WINDKRAFTWERK"<<endl;
                cout<< "\t3. SOLARPANEL\n"<<endl;
                cin >> choice_gebäude;

                switch(choice_gebäude) {

                    case 1:
                        cout << "Sie haben Wasserkraftwerk gewählt\n" <<endl;
                        g = WASSERKRAFTWERK;
                        break;

                    case 2:
                        cout << "Sie haben Windkraftwerk gewählt\n" <<endl;
                        g = WINDKRAFTWERK;
                        break;

                    case 3:
                        cout << "Sie haben Solarpanel gewählt\n" <<endl;
                        g = SOLARPANEL;
                        break;

                }




                cout<<"Bitte Startspalte (oberes linkes Gebäudeeck) eingeben\n";
                cin>> startSpalte;

                cout<<"Bitte Startzeile (oberes linkes Gebäudeeck) eingben\n";
                cin>> startZeile;

                cout<<"Bitte Spaltenanzahl des Gebäudes eingben\n";
                cin>> spaltenAnz;

                cout<<"Bitte Zeilenanzahl des Gebäudes eingeben\n";
                cin>> zeilenAnz;

                if(startZeile >= fläche.size() || startSpalte >= fläche[0].size()
                   || (startSpalte + spaltenAnz) >= fläche.size() || (startZeile + zeilenAnz) >= fläche[0].size()) {
                    cout<<"out of bounds\n"<<endl;
                    break;
                }

                for(int i = startZeile - 1; i < startZeile - 1 + zeilenAnz; i++) {
                    for(int j = startSpalte - 1; j < startSpalte - 1 + spaltenAnz;j++) {
                        if(fläche[i][j] != LEER) {

                            cout << "Teile des Gebäudes kollidieren mit anderen Gebäuden,vorgang wird beendet\n"<<endl;
                            help = true;
                            break;

                        }
                    }
                    if(help == true)
                        break;

                }

                if(help == true)
                    break;

                for(int i = startZeile - 1; i < startZeile - 1 + zeilenAnz; i++) {
                    for(int j = startSpalte - 1; j < startSpalte - 1 + spaltenAnz;j++) {
                        fläche[i][j] = g;
                    }
                }



                break;

            case 2:
                cout << "Sie haben Bereich löschen gewählt" <<endl;

                cout<<"Bitte Startspalte eingeben\n";
                cin>> startSpalte;

                cout<<"Bitte Startzeile eingben\n";
                cin>> startZeile;

                cout<<"Bitte Spaltenanzahl des zu löschenden Bereichs eingben\n";
                cin>> spaltenAnz;

                cout<<"Bitte Zeilenanzahl zu löschenden Bereichs eingeben\n";
                cin>> zeilenAnz;

                for(int i = startZeile - 1; i < startZeile - 1 + zeilenAnz; i++) {
                    for(int j = startSpalte - 1; j < startSpalte - 1 + spaltenAnz;j++) {
                        fläche[i][j] = LEER;
                    }
                }

                break;

            case 3:
                cout << "Sie haben Ausgabe des aktuellen Bauplans gewählt\n" <<endl;

                for(int i = 0; i < fläche.size(); i++) {
                    for(int j = 0; j < fläche[i].size();j++) {
                        cout << gebäude_map[fläche[i][j]]; cout << "\t\t";
                    }
                    cout << "\n\n";
                }

                break;

            case 4:
                cout << "Sie haben Beenden gewählt" <<endl;
                loop = false;
                break;
        }



    };

    return 0;
}