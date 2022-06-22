//
// Created by alfonso on 6/12/22.
//

#ifndef PUNTOPERTENENCIA_LECTORINT_H
#define PUNTOPERTENENCIA_LECTORINT_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point;


using namespace std;

using std::ifstream;

class LectorINT {


public:

    LectorINT(string &sarchivo, string sep) : sarchivo(sarchivo), sep(sep) {}

    static void split(vector <string> &theStringVector,
                      const string &theString, const string &theDelimiter);

    void inicia();

    virtual void parser(string scad);

protected:

    string sep;

    void creaPoligono(string scad, vector<Point>& vpuntos);

private:

    string &sarchivo;
};


#endif //PUNTOPERTENENCIA_LECTORINT_H
