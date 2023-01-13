//
// Created by Paul Keck on 12.01.23.
//

#include "Solarpanel.h"
#include "Holz.h"
#include "Kunststoff.h"
#include "Metall.h"

Solarpanel::Solarpanel() : Building("Solarpanel", 3, 3,
                                    {{new Kunststoff(), 4}, {new Metall(), 2}})
{

}