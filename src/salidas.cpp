//
// Created by alfonso on 6/19/22.
//

#include "puntopertencia.h"

using namespace std;


/**
 * @brief 
 * 
 * @param sarchivo 
 */
void imprimeSalidaMnz(string sarchivo, vector<Recurso> &vRec, vector<Manzana> &vMnz) {

    ofstream ofs("/home/alfonso/devel/renic/renic.git/utiles/checa_iter_cg/ver2/salida/" + sarchivo);
    for (auto &rec: vRec) {
        if (rec.id_mnz > 0) {
            Manzana mnz = vMnz[rec.id_mnz];
            if (rec.localidad_id != mnz.localidad_id || rec.municipio_id != mnz.municipio_id ||
                rec.estado_id != mnz.estado_id) {
                ofs << rec.id << "|" << rec.stipo << "|" << rec.estado_id << "|" << rec.municipio_id << "|"
                    << rec.localidad_id << "|" << mnz.estado_id << "|" << mnz.municipio_id << "|" << mnz.localidad_id
                    << endl;
            }
        }
    }
    ofs.close();
}

/**
 * @brief 
 * 
 * @param sarchivo 
 */
void imprimeSalidaMun(string sarchivo, vector<Recurso> &vRec, vector<Municipio> &vMun) {

    ofstream ofs("/home/alfonso/devel/renic/renic.git/utiles/checa_iter_cg/ver2/salida/" + sarchivo);
    for (auto &rec: vRec) {
        if (rec.id_mun > 0) {
            Municipio mun = vMun[rec.id_mun];
            if (rec.municipio_id != mun.municipio_id ||
                rec.estado_id != mun.estado_id) {
                ofs << rec.id << "|" << rec.stipo << "|" << rec.estado_id << "|" << rec.municipio_id << "|"
                    << rec.localidad_id << "|" << mun.estado_id << "|" << mun.municipio_id << "|0" << endl;
            }
        }
    }
    ofs.close();
}

/**
 * @brief 
 * 
 * @param sarchivo 
 */
void imprimeSalidaEnt(string sarchivo, vector<Recurso> &vRec, vector<Entidad> &vEnt) {

    ofstream ofs("/home/alfonso/devel/renic/renic.git/utiles/checa_iter_cg/ver2/salida/" + sarchivo);
    for (auto &rec: vRec) {
        if (rec.id_ent > 0) {
            Entidad ent = vEnt[rec.id_ent];
            if (rec.estado_id != ent.estado_id) {
                ofs << rec.id << "|" << rec.stipo << "|" << rec.estado_id << "|" << rec.municipio_id << "|"
                    << rec.localidad_id << "|" << ent.estado_id << "|0|0" << endl;
            }
        }
    }
    ofs.close();
}

/**
 *
 * @param sarchivo
 * @param vRec
 * @param vMnz
 */
void imprimeSalidaCompleta(string sarchivo, vector<Recurso> &vRec, vector<Manzana> &vMnz){
        
    ofstream ofs("/home/alfonso/devel/renic/renic.git/utiles/checa_iter_cg/ver2/salida/" + sarchivo);
    for (auto &rec: vRec) {
        if (rec.id_mnz > 0) {
            Manzana mnz = vMnz[rec.id_mnz];
            
                ofs << rec.id << "|" << rec.stipo << "|" << rec.estado_id << "|" << rec.municipio_id << "|"
                    << rec.localidad_id << "|" << mnz.estado_id << "|" << mnz.municipio_id << "|" << mnz.localidad_id
                    <<"|"<< mnz.sageb <<"|"<<mnz.manzana_id << endl;
            
        }
    }
    ofs.close();
}