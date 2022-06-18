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

private:

    string &sarchivo;
};


#endif //PUNTOPERTENENCIA_LECTORINT_H
