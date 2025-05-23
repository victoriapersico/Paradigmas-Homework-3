#include "Elipse.hpp"

Elipse::Elipse(const Punto& posicion_centro, float a_mayor, float b_menor)
    : posicion_centro(posicion_centro), a_mayor(a_mayor), b_menor(b_menor) {}

void Elipse::set_centro(const Punto& centro) {
    this->posicion_centro = centro;
}

Punto Elipse::get_centro() const {
    return posicion_centro;
}

void Elipse::set_a(float a) {
    this->a_mayor = a;
}

void Elipse::set_b(float b) {
    this->b_menor = b;
}

float Elipse::get_a() const {
    return a_mayor;
}

float Elipse::get_b() const {
    return b_menor;
}