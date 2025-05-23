#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "Punto.hpp"
#include "Circulo.hpp"
#include "Elipse.hpp"
#include "Rectangulo.hpp"
#include "ProcesadorFigura.hpp"

using namespace std;

int main() {
    //Creo un punto para mostrar que no se puede calcular el área de una figura no especializada.
    Punto punto(3, 4);

    //Crea un círculo de radio 7 centrado en (23,8)
    Circulo circle(Punto(23, 8), 7);

    //Crea una elipse con semieje mayor 8.3 y semieje menor 5.1 centrada en (15.5,33.8)
    Elipse ellipse(Punto(15.5f, 33.8f), 8.3f, 5.1f);

    //Crea un rectángulo con vértice inferior izquierdo en (1.3,4.5), de ancho 6 y largo 3.444
    Rectangulo rectangle(Punto(1.3f, 4.5f), 6.f, 3.444f);

    // Calcula y muestra las áreas con ProcesadorFigura
    cout << "Área del círculo: " << ProcesadorFigura<Circulo>::calcular_area(circle) << endl;
    cout << "Área de la elipse: " << ProcesadorFigura<Elipse>::calcular_area(ellipse) << endl;
    cout << "Área del rectángulo: " << ProcesadorFigura<Rectangulo>::calcular_area(rectangle) << endl;
    cout << "Área del punto, esperado un -1: " << ProcesadorFigura<Punto>::calcular_area(punto) << endl;

    return 0;
}
