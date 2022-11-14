//
// Created by alfonso on 11/13/22.
//

#include "LectorAgeb.h"

void LectorAgeb::parser(string scad){
    vector<string> vc;

    split(vc, scad, sep);


    Ageb agb;

    agb.npuntos = atoi(vc[1].c_str());

    creaPoligono(vc[2].c_str(), agb.vpuntos);
    
    agb.estado_id= atoi(vc[4].c_str());
    agb.municipio_id= atoi(vc[5].c_str());
    agb.localidad_id= atoi(vc[6].c_str());

    agb.sageb_id=vc[7];

    vAgeb.push_back(agb);
}