//
// Created by alfonso on 6/13/22.
//

#ifndef PUNTOPERTENENCIA_MANZANA_H
#define PUNTOPERTENENCIA_MANZANA_H


#include <vector>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point;


using std::string, std::vector;

struct Manzana{
    
    vector<Point> vpuntos;
    int npuntos;

    int estado_id;
    int municipio_id;
    int localidad_id;

};


#endif //PUNTOPERTENENCIA_MANZANA_H
