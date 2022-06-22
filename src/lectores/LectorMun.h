//
// Created by alfonso on 6/18/22.
//

#ifndef PUNTOPERTENENCIA_LECTORMUN_H
#define PUNTOPERTENENCIA_LECTORMUN_H

#include "LectorINT.h"
#include "../objetos/Municipio.h"

class LectorMun : public LectorINT{

public:

    LectorMun(string &sarchivo, string sep, vector<Municipio> &vMun) : LectorINT(sarchivo, sep), vMun(vMun) {}

    void parser(string scad) override;

private:

    vector<Municipio> &vMun;

};


#endif //PUNTOPERTENENCIA_LECTORMUN_H
