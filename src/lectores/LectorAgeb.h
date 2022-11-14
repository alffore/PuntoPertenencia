//
// Created by alfonso on 11/13/22.
//

#ifndef PUNTOPERTENENCIA_LECTORAGEB_H
#define PUNTOPERTENENCIA_LECTORAGEB_H

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include "LectorINT.h"
#include "../objetos/Ageb.h"


class LectorAgeb: public LectorINT {

public:
    LectorAgeb(string& sarchivo, string sep, vector<Ageb>& vAgeb): LectorINT(sarchivo, sep), vAgeb(vAgeb){}
    
    void parser(string scad) override;

private:
    vector<Ageb>& vAgeb;
};


#endif //PUNTOPERTENENCIA_LECTORAGEB_H
