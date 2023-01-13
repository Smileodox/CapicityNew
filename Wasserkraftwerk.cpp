//
// Created by Paul Keck on 12.01.23.
//

#include "Wasserkraftwerk.h"
#include "Holz.h"
#include "Kunststoff.h"
#include "Metall.h"

Wasserkraftwerk::Wasserkraftwerk() : Building("Wasserkraftwerk",1, 1,
                                              {{new Holz(), 2},
                                               {new Metall(), 3}, {new Kunststoff(), 1} })
{

}