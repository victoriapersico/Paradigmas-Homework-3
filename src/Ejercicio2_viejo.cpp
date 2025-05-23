// #define _USE_MATH_DEFINES
// #include <iostream>
// #include <cmath>
// using namespace std;

// class Punto{
//     private:
//         float a, b;
//     public:
//         Punto(float a=0, float b=0):a(a),b(b){}
//         void set_a(float a){
//             this->a=a;
//         }
//         void set_b(float b){
//             this->b=b;
//         }
//         float get_a() const{
//             return a;
//         }
//         float get_b() const{
//             return b;
//         }
// };

// class Circulo{
//     private:
//         Punto posicion_centro;
//         float radio;
//     public:
//         Circulo(const Punto& posicion_centro, float radio): posicion_centro(posicion_centro), radio(radio){}
//         void set_centro(const Punto&centro){
//             this->posicion_centro = centro;
//         }
//         void set_radio(float radio){
//             this->radio = radio;
//         }
//         float get_radio()const{
//             return radio;
//         }
//         Punto get_centro()const{
//             return posicion_centro;
//         }

// };

// class Elipse{
//     private:
//         Punto posicion_centro;
//         float a_mayor, b_menor;
//     public:
//         Elipse(const Punto& posicion_centro, float a_mayor, float b_menor):posicion_centro(posicion_centro), a_mayor(a_mayor),b_menor(b_menor){}
//         void set_centro(const Punto&centro){
//             this->posicion_centro = centro;
//         }
//         Punto get_centro()const{
//             return posicion_centro;
//         }
//         void set_a(float a){
//             this->a_mayor=a;
//         }
//         void set_b(float b){
//             this->b_menor=b;
//         }
//         float get_a() const{
//             return a_mayor;
//         }
//         float get_b() const{
//             return b_menor;
//         }
// };

// class Rectangulo{
//     private:
//         Punto v_inf_izq;
//         float ancho, largo;
//     public:
//         Rectangulo(const Punto& v_inf_izq, float ancho, float largo) : v_inf_izq(v_inf_izq), ancho(ancho), largo(largo) {}
//         void set_posicion(const Punto& posicion){
//             this->v_inf_izq=posicion;
//         }
//         Punto get_posicion()const{
//             return v_inf_izq;
//         }
//         void set_ancho(float a){
//             this->ancho=a;
//         }
//         void set_largo(float l){
//             this->largo=l;
//         }
//         float get_ancho() const{
//             return ancho;
//         }
//         float get_largo() const{
//             return largo;
//         }
// };

// template <typename T>
// class ProcesadorFigura {
//     public:
//         static float calcular_area(const T& figura){ //uso static float porque no hace falta instanciar a ProcesadorFigura para usar el método
//             cerr<<"No se puede calcular el área de esta figura."<<endl; //uso cerr para mostrar un mensaje de error
//             return -1;
//         }
// };

// template <>
// class ProcesadorFigura<Circulo>{
//     public:
//         static float calcular_area(const Circulo& circle){
//             return M_PI * circle.get_radio() *circle.get_radio();
//         }
// };

// template <>
// class ProcesadorFigura<Elipse>{
//     public:
//         static float calcular_area(const Elipse& ellipse){
//             return M_PI*ellipse.get_a()*ellipse.get_b();
//         }
// };

// template <>
// class ProcesadorFigura<Rectangulo>{
//     public:
//         static float calcular_area(const Rectangulo& rectangle){
//             return rectangle.get_ancho()*rectangle.get_largo();
//         }
// };

// int main() {

//     //Creo un punto para mostrar que no se puede calcular el área de una figura no especializada.
//     Punto punto(3, 4);

//     //Crea un círculo de radio 7 centrado en (23,8)
//     Circulo circle(Punto(23, 8), 7);

//     //Crea una elipse con semieje mayor 8.3 y semieje menor 5.1 centrada en (15.5,33.8)
//     Elipse ellipse(Punto(15.5, 33.8), 8.3, 5.1);

//     //Crea un rectángulo con vértice inferior izquierdo en (1.3,4.5), de ancho 6 y largo 3.444
//     Rectangulo rectangle(Punto(1.3, 4.5), 6, 3.444);

//     // Calcula y muestra las áreas con ProcesadorFigura
//     cout << "Área del círculo: " << ProcesadorFigura<Circulo>::calcular_area(circle) << endl;
//     cout << "Área de la elipse: " << ProcesadorFigura<Elipse>::calcular_area(ellipse) << endl;
//     cout << "Área del rectángulo: " << ProcesadorFigura<Rectangulo>::calcular_area(rectangle) << endl;
//     cout << "Área del punto, esperado un -1: " << ProcesadorFigura<Punto>::calcular_area(punto) << endl;

//     return 0;
// }