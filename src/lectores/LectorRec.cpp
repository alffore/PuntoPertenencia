//
// Created by alfonso on 6/12/22.
//

#include "LectorRec.h"

void LectorRec::parser(string scad) {
    vector<string> vc;

    split(vc, scad, sep);

    Recurso rec;

    rec.lon = atof(vc[0].c_str());
    rec.lat = atof(vc[1].c_str());

    double este;
    double norte;

    //std::cout <<rec.lon<<" "<<rec.lat <<endl;

    ccg.convierte(rec.lon, rec.lat, este, norte);

    rec.p = Point(este, norte);

    rec.id = atoi(vc[2].c_str());

    rec.stipo = vc[3];

    rec.estado_id = atoi(vc[4].c_str());
    rec.municipio_id = atoi(vc[5].c_str());
    rec.localidad_id = atoi(vc[6].c_str());
    rec.nmanzana_id = -1;


    rec.id_mnz = -1;
    rec.id_ent = -1;
    rec.id_mun = -1;
    rec.id_agb = -1;

    rec.nestado_id = -1;
    rec.nmunicipio_id = -1;
    rec.nlocalidad_id = -1;
    rec.nmanzana_id = -1;
    rec.sageb_id = "";


    vRec.push_back(rec);
}
