//
// Created by Paul Keck on 12.01.23.
//

#include "Windkraftwerk.h"
#include "Holz.h"
#include "Kunststoff.h"
#include "Metall.h"

Windkraftwerk::Windkraftwerk() : Building("Windkraftwerk", 2, 2, {new Metall(), new Metall()})
{

}
