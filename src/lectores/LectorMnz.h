//
// Created by alfonso on 6/13/22.
//

#ifndef PUNTOPERTENENCIA_LECTORMNZ_H
#define PUNTOPERTENENCIA_LECTORMNZ_H

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include "LectorINT.h"
#include "../objetos/Manzana.h"


class LectorMnz: public LectorINT{

public:

    LectorMnz(string& sarchivo, string sep, vector<Manzana>& vMnz): LectorINT(sarchivo, sep), vMnz(vMnz){}
    
    void parser(string scad) override;


private:
    vector<Manzana>& vMnz;

};


#endif //PUNTOPERTENENCIA_LECTORMNZ_H
