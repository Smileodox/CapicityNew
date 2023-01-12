//
// Created by Paul Keck on 12.01.23.
//

#ifndef CAPICITYNEW_MATERIAL_H
#define CAPICITYNEW_MATERIAL_H

#include <string>

class Material {

public:
    Material(std::string name, int preis);

    std::string materialName;
    int preis;


};


#endif //CAPICITYNEW_MATERIAL_H
