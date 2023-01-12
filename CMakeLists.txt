cmake_minimum_required(VERSION 3.24)
project(CapicityNew)

set(CMAKE_CXX_STANDARD 14)

add_executable(CapicityNew
        CapicitySim.cpp CapicitySim.h Building.cpp Building.h Holz.cpp Holz.h Kunststoff.cpp Kunststoff.h Leer.cpp Leer.h Material.cpp Material.h Metall.cpp Metall.h Solarpanel.cpp Solarpanel.h Wasserkraftwerk.cpp Wasserkraftwerk.h Windkraftwerk.cpp Windkraftwerk.h CapicityMain.cpp)
