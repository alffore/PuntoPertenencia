//
// Created by alfonso on 6/13/22.
//

#include "LectorMnz.h"

/**
 *
 * @param scad
 */
void LectorMnz::parser(string scad) {
    vector<string> vc;

    split(vc, scad, sep);

    Manzana mnz;

    mnz.npuntos = atoi(vc[1].c_str());

    creaPoligono(vc[2].c_str(), mnz.vpuntos);

    mnz.estado_id = atoi(vc[4].c_str());
    mnz.municipio_id = atoi(vc[5].c_str());
    mnz.localidad_id = atoi(vc[6].c_str());

    mnz.sageb_id = vc[7];
    mnz.manzana_id= atoi(vc[8].c_str());

    vMnz.push_back(mnz);
}


