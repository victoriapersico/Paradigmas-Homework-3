#ifndef PROCESADORFIGURA_HPP
#define PROCESADORFIGURA_HPP

#include <iostream>
#include <cmath>
#include "Circulo.hpp"
#include "Elipse.hpp"
#include "Rectangulo.hpp"
#include "Punto.hpp"

using namespace std;

template <typename T>
class ProcesadorFigura {
    public:
        static float calcular_area(const T& figura){ //uso static float porque no hace falta instanciar a ProcesadorFigura para usar el método
            (void) figura; //le indica al procesador que no se usa el parametro
            cerr<<"No se puede calcular el área de esta figura."<<endl; //uso cerr para mostrar un mensaje de error
            return -1;
        }
};

template <>
class ProcesadorFigura<Circulo>{
    public:
        static float calcular_area(const Circulo& circle){
            return static_cast<float>(M_PI) * circle.get_radio() *circle.get_radio();
        }
};

template <>
class ProcesadorFigura<Elipse>{
    public:
        static float calcular_area(const Elipse& ellipse){
            return static_cast<float>(M_PI)*ellipse.get_a()*ellipse.get_b();
        }
};

template <>
class ProcesadorFigura<Rectangulo>{
    public:
        static float calcular_area(const Rectangulo& rectangle){
            return rectangle.get_ancho()*rectangle.get_largo();
        }
};

#endif