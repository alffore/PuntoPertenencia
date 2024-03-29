//
// Created by alfonso on 6/12/22.
//

#ifndef PUNTOPERTENENCIA_RECURSO_H
#define PUNTOPERTENENCIA_RECURSO_H

#include <string>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point;

using std::string;

struct Recurso{
    double lon;
    double lat;

    Point p;
    int id;

    string stipo;
    int itipo;

    int estado_id;
    int municipio_id;
    int localidad_id;
    int manzana_id;
    string sageb_id;


    int id_mnz;
    int id_ent;
    int id_mun;
    int id_agb;


    int nestado_id;
    int nmunicipio_id;
    int nlocalidad_id;
    int nmanzana_id;
    string nsageb_id;
};

#endif //PUNTOPERTENENCIA_RECURSO_H
