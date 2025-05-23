#ifndef RECTANGULO_HPP
#define RECTANGULO_HPP

#include "Punto.hpp"

class Rectangulo {
    private:
        Punto v_inf_izq;
        float ancho, largo;
    public:
        Rectangulo(const Punto& v_inf_izq, float ancho, float largo);
        void set_posicion(const Punto& posicion);
        Punto get_posicion() const;
        void set_ancho(float a);
        void set_largo(float l);
        float get_ancho() const;
        float get_largo() const;
    };

#endif