#include "Rectangulo.hpp"

Rectangulo::Rectangulo(const Punto& v_inf_izq, float ancho, float largo) : v_inf_izq(v_inf_izq), ancho(ancho), largo(largo) {}

void Rectangulo::set_posicion(const Punto& posicion) {
    this->v_inf_izq = posicion;
}

Punto Rectangulo::get_posicion() const {
    return v_inf_izq;
}

void Rectangulo::set_ancho(float a) {
    this->ancho = a;
}

void Rectangulo::set_largo(float l) {
    this->largo = l;
}

float Rectangulo::get_ancho() const {
    return ancho;
}

float Rectangulo::get_largo() const {
    return largo;
}
