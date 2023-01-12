//
// Created by Paul Keck on 12.01.23.
//

#include "Wasserkraftwerk.h"
#include "Holz.h"
#include "Kunststoff.h"
#include "Metall.h"

Wasserkraftwerk::Wasserkraftwerk() : Building("Wasserkraftwerk",1, 1, { new Kunststoff(), new Holz(), new Holz(), new Metall() })
{

}