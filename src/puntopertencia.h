//
// Created by alfonso on 6/12/22.
//

#ifndef PUNTOPERTENENCIA_PUNTOPERTENCIA_H
#define PUNTOPERTENENCIA_PUNTOPERTENCIA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polygon_2_algorithms.h>

#include "coordenadas/ITRF2CCL.h"
#include "coordenadas/CCG2CCL.h"

#include "objetos/Recurso.h"
#include "objetos/Manzana.h"

#include "lectores/LectorINT.h"
#include "lectores/LectorRec.h"
#include "lectores/LectorMnz.h"


typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point;

#endif //PUNTOPERTENENCIA_PUNTOPERTENCIA_H
