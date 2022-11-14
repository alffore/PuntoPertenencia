#include <thread>
#include "puntopertencia.h"


using namespace std;

vector<Recurso> vRec;

vector<Manzana> vMnz;
vector<Ageb> vAgeb;
vector<Entidad> vEnt;
vector<Municipio> vMun;

long long avance[] = {0, 0, 0, 0, 0, 0, 0, 0};

unsigned int NUM_HILOS = 8;
size_t tamrec = 0;

size_t tammnz = 0;
size_t tamagb =0;
size_t tament = 0;
size_t tammun = 0;

extern void imprimeSalidaCompleta(string sarchivo, vector<Recurso> &vRec, vector<Manzana> &vMnz);

extern void imprimeSalidaMnz(string sarchivo, vector<Recurso> &vRec, vector<Manzana> &vMnz);

extern void imprimeSalidaMun(string sarchivo, vector<Recurso> &vRec, vector<Municipio> &vMun);

extern void imprimeSalidaEnt(string sarchivo, vector<Recurso> &vRec, vector<Entidad> &vEnt);

/**
 *
 */
void imprimeAvance(double tam) {
    double vtot = 0;
    for (auto &v: avance) {
        cout << (double) v * 100.00 / tam << " ";
        vtot += v;
    }
    cout << vtot * 100.00 / tam << endl;
}


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
void checaPuntosMnz(int id) {

    for (size_t m = 0; m < tammnz; m++) {
        Manzana mnz = vMnz[m];

        for (size_t i = id; i < tamrec; i += NUM_HILOS) {
            avance[id]++;

            if (id == 0 && avance[id] % 100000 == 0) {
                imprimeAvance(tamrec * tammnz);
            }

            if (vRec[i].nestado_id == mnz.estado_id && vRec[i].nmunicipio_id == mnz.municipio_id) {
                int res = checa_posicion(vRec[i].p, mnz.vpuntos.begin(), mnz.vpuntos.end(), K());

                if (res > 0) {
                    vRec[i].id_mnz = m;

                    vRec[i].nmanzana_id = mnz.manzana_id;
                    continue;
                }
            }
        }

    }

}


void checaPuntoAgeb(int id){

    for (size_t a=0; a<tamagb; a++){
        Ageb agb = vAgeb[a];
        
        for(size_t i = id;i<tamrec; i+=NUM_HILOS){
            avance[id]++;

            if(id==0 && avance[id]%100000==0){
                imprimeAvance(tamrec*tamagb);
            }

            vRec[i].estado_id=vRec[i].nestado_id;
            vRec[i].municipio_id=vRec[i].nmunicipio_id;
            
            if(vRec[i].nestado_id == agb.estado_id && 
            vRec[i].nmunicipio_id== agb.municipio_id){
                int res = checa_posicion(vRec[i].p, agb.vpuntos.begin(), agb.vpuntos.end(), K());
                if(res>0){
                    vRec[i].nlocalidad_id = agb.localidad_id;
                    vRec[i].nsageb_id = agb.sageb_id;
                }
            }
        }

    }

}

/**
 * @brief 
 * 
 * @param id 
 */
void checaPuntosEnt(int id) {
    for (size_t e = 0; e < tament; e++) {
        Entidad ent = vEnt[e];
        for (size_t i = id; i < tamrec; i += NUM_HILOS) {
            avance[id]++;

            if (id == 0 && avance[id] % 10000 == 0) {
                imprimeAvance(tamrec * tament);
            }

            int res = checa_posicion(vRec[i].p, ent.vpuntos.begin(), ent.vpuntos.end(), K());

            if (res > 0) {
                vRec[i].id_ent = e;
                vRec[i].nestado_id = ent.estado_id;
                continue;
            }

        }
    }
}

/**
 * @brief 
 * 
 * @param id 
 */
void checaPuntosMun(int id) {
    for (size_t e = 0; e < tammun; e++) {
        Municipio mun = vMun[e];
        for (size_t i = id; i < tamrec; i += NUM_HILOS) {
            avance[id]++;

            if (id == 0 && avance[id] % 10000 == 0) {
                imprimeAvance(tamrec * tammun);
            }

            if (vRec[i].nestado_id == mun.estado_id) {
                int res = checa_posicion(vRec[i].p, mun.vpuntos.begin(), mun.vpuntos.end(), K());
                if (res > 0) {
                    vRec[i].id_mun = e;
                    vRec[i].nmunicipio_id = mun.municipio_id;
                    continue;
                }
            }

        }
    }
}

/**
 *
 * @return
 */
int main() {

    unsigned int n = thread::hardware_concurrency();

    if (n > 0) {
        NUM_HILOS = n;
    }

    cout << "Total de hilos posibles: " << NUM_HILOS << endl;

    string sp1 = "EPSG:4326";
    string sp2 = "EPSG:6372";

    CCG2CCL c2c(sp1, sp2);

    //Carga de recursos
    string sarchivo_rec = "/home/alfonso/devel/renic/renic.git/utiles/checa_iter_cg/ver2/origen/recursos_0.txt";
    //string sarchivo_rec = "/home/alfonso/devel/renic.git/renic.git/utiles/checa_iter_cg/ver2/origen/recursos_20.txt";
    //string sarchivo_rec = "/home/alfonso/devel/renic.git/renic.git/utiles/checa_iter_cg/ver2/origen/recursos_demo.txt";
    LectorRec lecrec(sarchivo_rec, "|", vRec, c2c);
    lecrec.inicia();
    cout << "Total de recursos: " << vRec.size() << endl;

    //Carga de entidades
    string sarchivo_ent = "/fhome/alfonso/devel/CPV2020/MGM/INTS/00ent.int";
    LectorEnt lecent(sarchivo_ent, "|", vEnt);
    lecent.inicia();
    cout << "Total de poligonos de entidades: " << vEnt.size() << endl;

    //Carga municipios
    string sarchivo_mun = "/fhome/alfonso/devel/CPV2020/MGM/INTS/00mun.int";
    LectorMun lecmun(sarchivo_mun, "|", vMun);
    lecmun.inicia();
    cout << "Total de poligonos de municipios: " << vMun.size() << endl;

    //Carga Ageb
    string sarchivo_ageb = "/fhome/alfonso/devel/CPV2020/MGM/ageb/00a.int";
    LectorAgeb lecageb(sarchivo_ageb,"|",vAgeb);
    lecageb.inicia();
    cout << "Total de poligonos de agebs: " << vAgeb.size() << endl;

    //Carga de manzanas
    string sarchivo_mnz = "/fhome/alfonso/devel/CPV2020/MGM/mnz/todos.int";
    //string sarchivo_mnz = "/fhome/alfonso/devel/CPV2020/MGM/mnz/20m.int";
    LectorMnz lecmnz(sarchivo_mnz, "|", vMnz);
    lecmnz.inicia();
    cout << "Total de poligonos de manzanas: " << vMnz.size() << endl;


    tamrec = vRec.size();
    tammnz = vMnz.size();
    tamagb = vAgeb.size();
    tament = vEnt.size();
    tammun = vMun.size();

    string sarchivo_sal = "problemas_ent.txt";

    //Multihilos
    cout << "Entidades..." << endl;
    vector<thread> vthreads;

    for (int i = 0; i < NUM_HILOS; i++) {

        vthreads.emplace_back(checaPuntosEnt, i);
    }

    for (auto &th: vthreads) {
        th.join();
    }

    imprimeSalidaEnt(sarchivo_sal, vRec, vEnt);

    for (auto &v: avance) {
        v = 0;
    }

    cout << "Municipios..." << endl;
    vthreads.clear();
    sarchivo_sal = "problemas_mun.txt";

    for (int i = 0; i < NUM_HILOS; i++) {
        vthreads.emplace_back(checaPuntosMun, i);
    }

    for (auto &th: vthreads) {
        th.join();
    }

    imprimeSalidaMun(sarchivo_sal, vRec, vMun);

    for (auto &v: avance) {
        v = 0;
    }

    cout << "Manzanas..." << endl;
    vthreads.clear();
    sarchivo_sal = "problemas_mnz.txt";

    for (int i = 0; i < NUM_HILOS; i++) {
        vthreads.emplace_back(checaPuntosMnz, i);
    }

    for (auto &th: vthreads) {
        th.join();
    }

    imprimeSalidaMnz(sarchivo_sal, vRec, vMnz);

    imprimeSalidaCompleta("salida_completa.txt",vRec,vMnz);

    return 0;
}

