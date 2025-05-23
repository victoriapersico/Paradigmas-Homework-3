#ifndef ELIPSE_HPP
#define ELIPSE_HPP

#include "Punto.hpp"

class Elipse {
    private:
        Punto posicion_centro;
        float a_mayor, b_menor;
    public:
        Elipse(const Punto& posicion_centro, float a_mayor, float b_menor);
        void set_centro(const Punto& centro);
        Punto get_centro() const;
        void set_a(float a);
        void set_b(float b);
        float get_a() const;
        float get_b() const;
};

#endif