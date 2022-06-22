//
// Created by alfonso on 6/18/22.
//

#ifndef PUNTOPERTENENCIA_LECTORENT_H
#define PUNTOPERTENENCIA_LECTORENT_H


#include "LectorINT.h"
#include "../objetos/Entidad.h"


class LectorEnt : public LectorINT {

public:

    LectorEnt(string &sarchivo, string sep, vector<Entidad> &vEnt) : LectorINT(sarchivo, sep), vEnt(vEnt) {}

    void parser(string scad) override;

private:

    vector<Entidad> &vEnt;

   

};


#endif //PUNTOPERTENENCIA_LECTORENT_H
