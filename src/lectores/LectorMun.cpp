//
// Created by alfonso on 6/18/22.
//

#include "LectorMun.h"

void LectorMun::parser(string scad) {
    vector<string> vc;

    split(vc, scad, sep);

    Municipio mun;

    creaPoligono(vc[2].c_str(), mun.vpuntos);

    mun.estado_id = atoi(vc[4].c_str());
    mun.municipio_id = atoi(vc[5].c_str());

    vMun.push_back(mun);
}
