cmake_minimum_required(VERSION 3.26)
project(TP_Tri C)

set(CMAKE_C_STANDARD 11)

add_executable(TP_Tri main.c
        triBulles.h
        triBullesAmeliore.h
        triSelection.h
        triInsertion.h
        triRapide.h
        fonctions.h
        initTab.h
        Liste.h
        triExtraction.h
)
