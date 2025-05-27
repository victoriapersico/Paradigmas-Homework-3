#ifndef ASOCIAR_CPP
#define ASOCIAR_CPP

#include "../headers/Asociar.hpp"

// agrega un valor asociado a una etiqueta determinada.
// si esaetiqueta no existe en el map, crea una nueva instancia de Generar_vectores<T>.
template<typename T>
void Asociar<T>::add(const string&etiqueta, const T&value){
    if (!elements.count(etiqueta)) { //es true si no existe esa etiqueta en el map 
        elements[etiqueta] = make_unique<Generar_vectores<T>>(); 
    }
    elements[etiqueta]->agregar_valor(value); // agrega el valor al vector data que está en la instancia de la clase Generar_vectores<T>.
}
//procesa todos los elementos del mapa en formato JSON
//llamando a procesar() de cada Generar_vectores<T>, pasando como argumento la etiqueta correspondiente.
template<typename T>
void Asociar<T>::procesar_json()const{
    for (const auto&[etiqueta, puntero] : elements){
        puntero->procesar(etiqueta); //usa el método procesar() según la etiqueta
    }
}

#endif