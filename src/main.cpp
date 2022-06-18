#include <thread>
#include "puntopertencia.h"


using namespace std;

vector<Recurso> vRec;
vector<Manzana> vMnz;

const int NUM_HILOS = 8;
int tamrec = 0;
int tammnz = 0;

/**
 * @brief 
 * 
 * @param p 
 * @param p_inicio 
 * @param p_fin 
 * @param traits 
 * @return int 
 */
int checa_posicion(Point p, vector<Point>::iterator p_inicio, vector<Point>::iterator p_fin, K traits) {
    switch (CGAL::bounded_side_2(p_inicio, p_fin, p, traits)) {
        case CGAL::ON_BOUNDED_SIDE:
            return 1;

        case CGAL::ON_BOUNDARY:
            return 2;

        case CGAL::ON_UNBOUNDED_SIDE:
            return 0;
    }
    return -1;
}


/**
 * Función que checa si un punto esta contenido en algun poligono
 * @param id
 */
void checaPuntos(int id) {

    for (int m = 0; m < tammnz; m++) {
        Manzana mnz = vMnz[m];

        for (int i = id; i < tamrec; i += NUM_HILOS) {
            int res = checa_posicion(vRec[i].p, mnz.vpuntos.begin(), mnz.vpuntos.end(), K());

            if (res > 0) {
                vRec[i].id_mnz = m;
            }
        }

    }

}


void imprimeSalida() {

    ofstream ofs("/home/alfonso/devel/renic.git/renic.git/utiles/checa_iter_cg/ver2/salida/problemas.txt");
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

}


/**
 *
 * @return
 */
int main() {

    string sp1 = "EPSG:4326";
    string sp2 = "EPSG:6372";

    CCG2CCL c2c(sp1, sp2);

    //Carga de recursos
    string sarchivo_rec = "/home/alfonso/devel/renic.git/renic.git/utiles/checa_iter_cg/ver2/origen/recursos.txt";
    //string sarchivo_rec = "/home/alfonso/devel/renic.git/renic.git/utiles/checa_iter_cg/ver2/origen/recursos_demo.txt";
    LectorRec lecrec(sarchivo_rec, "|", vRec, c2c);
    lecrec.inicia();
    cout << "Total de recursos: " << vRec.size() << endl;

    //Carga de manzanas
    string sarchivo_mnz = "/fhome/alfonso/devel/CPV2020/MGM/mnz/todos.int";
    //string sarchivo_mnz = "/fhome/alfonso/devel/CPV2020/MGM/mnz/01m.int";
    LectorMnz lecmnz(sarchivo_mnz, "|", vMnz);
    lecmnz.inicia();
    cout << "Total de manzanas: " << vMnz.size() << endl;


    tamrec = vRec.size();
    tammnz = vMnz.size();

    //Multihilos
    vector<thread> vt;

    for (int i = 0; i < NUM_HILOS; i++) {
        vt.emplace_back(checaPuntos, i);
    }

    for (auto &th: vt) {
        th.join();
    }

    imprimeSalida();

    return 0;
}

