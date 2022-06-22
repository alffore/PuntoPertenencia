//
// Created by alfonso on 6/18/22.
//

#ifndef PUNTOPERTENENCIA_ENTIDAD_H
#define PUNTOPERTENENCIA_ENTIDAD_H



#include <vector>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point;


using std::string, std::vector;


struct Entidad{

    vector<Point> vpuntos;

    int estado_id;

};


#endif //PUNTOPERTENENCIA_ENTIDAD_H
