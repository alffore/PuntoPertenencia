//
// Created by alfonso on 6/18/22.
//

#ifndef PUNTOPERTENENCIA_MUNICIPIO_H
#define PUNTOPERTENENCIA_MUNICIPIO_H


#include <vector>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point;


using std::string, std::vector;

struct Municipio{

    vector<Point> vpuntos;

    int estado_id;
    int municipio_id;
    
};

#endif //PUNTOPERTENENCIA_MUNICIPIO_H
