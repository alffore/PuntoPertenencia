//
// Created by alfonso on 11/13/22.
//

#ifndef PUNTOPERTENENCIA_AGEB_H
#define PUNTOPERTENENCIA_AGEB_H

#include <vector>
#include <string>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point;


using std::string, std::vector;

struct Ageb{
    
    vector<Point> vpuntos;
    int npuntos;

    int estado_id;
    int municipio_id;
    int localidad_id;

    string sageb_id;


};


#endif //PUNTOPERTENENCIA_AGEB_H
