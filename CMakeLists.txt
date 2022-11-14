cmake_minimum_required(VERSION 3.22)
project(PuntoPertenencia)

find_package(CGAL)
find_package(PROJ CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(PuntoPertenencia src/main.cpp src/coordenadas/ITRF2CCL.cpp src/coordenadas/ITRF2CCL.h
        src/coordenadas/CCG2CCL.cpp src/coordenadas/CCG2CCL.h src/lectores/LectorINT.cpp src/lectores/LectorINT.h
        src/puntopertencia.h src/lectores/LectorRec.cpp src/lectores/LectorRec.h src/objetos/Recurso.h
        src/objetos/Manzana.h src/lectores/LectorMnz.cpp src/lectores/LectorMnz.h src/lectores/LectorEnt.cpp
        src/lectores/LectorEnt.h src/objetos/Entidad.h src/objetos/Municipio.h src/lectores/LectorMun.cpp src/lectores/LectorMun.h src/salidas.cpp src/objetos/Ageb.h src/lectores/LectorAgeb.cpp src/lectores/LectorAgeb.h)

target_link_libraries(PuntoPertenencia CGAL::CGAL PROJ::proj)
