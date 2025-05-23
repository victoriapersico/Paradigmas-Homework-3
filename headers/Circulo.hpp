#ifndef CIRCULO_HPP
#define CIRCULO_HPP

#include "Punto.hpp"

class Circulo {
    private:
        Punto posicion_centro;
        float radio;
    public:
        Circulo(const Punto& posicion_centro, float radio);
        void set_centro(const Punto& centro);
        void set_radio(float radio);
        float get_radio() const;
        Punto get_centro() const;
};

#endif