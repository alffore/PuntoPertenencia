//
// Created by alfonso on 6/18/22.
//

#include "LectorEnt.h"

/**
 * @brief 
 * 
 * @param scad 
 */
void LectorEnt::parser(string scad) {
    vector<string> vc;

    split(vc, scad, sep);

    Entidad ent;

    creaPoligono(vc[2].c_str(), ent.vpuntos);

    ent.estado_id = atoi(vc[3].c_str());

    vEnt.push_back(ent);
}



