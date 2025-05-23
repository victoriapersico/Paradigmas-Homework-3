#include "Punto.hpp"

Punto::Punto(float a, float b) : a(a), b(b) {}

void Punto::set_a(float a) {this->a = a;}
void Punto::set_b(float b) {this->b = b;}
float Punto::get_a() const {return a;}
float Punto::get_b() const {return b;}