#include "Circulo.hpp"

Circulo::Circulo(const Punto& posicion_centro, float radio): posicion_centro(posicion_centro), radio(radio) {}

void Circulo::set_centro(const Punto& centro) {
    this->posicion_centro = centro;
}

void Circulo::set_radio(float radio) {
    this->radio = radio;
}

float Circulo::get_radio() const {
    return radio;
}

Punto Circulo::get_centro() const {
    return posicion_centro;
}