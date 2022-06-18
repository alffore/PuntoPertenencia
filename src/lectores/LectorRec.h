//
// Created by alfonso on 6/12/22.
//

#ifndef PUNTOPERTENENCIA_LECTORREC_H
#define PUNTOPERTENENCIA_LECTORREC_H

#include "LectorINT.h"
#include "../objetos/Recurso.h"
#include "../coordenadas/CCG2CCL.h"

class LectorRec: public LectorINT{

public:
    LectorRec(string& sarchivo,string sep,vector<Recurso>& vRec,CCG2CCL& ccg): LectorINT(sarchivo,sep),vRec(vRec),ccg(ccg){}

    void parser(string scad) override;

private:
    vector<Recurso>& vRec;
    CCG2CCL& ccg;
};


#endif //PUNTOPERTENENCIA_LECTORREC_H
