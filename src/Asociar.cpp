#ifndef ASOCIAR_CPP
#define ASOCIAR_CPP

#include "../headers/Asociar.hpp"

template<typename T>
void Asociar<T>::add(const string&etiqueta, const T&value){
    if (!elements.count(etiqueta)) { //es true si no existe esa etiqueta en el map 
        elements[etiqueta] = make_unique<Generar_vectores<T>>(); 
    }
    elements[etiqueta]->agregar_valor(value);
}

template<typename T>
void Asociar<T>::procesar_json()const{
    for (const auto&[etiqueta, puntero] : elements){
        puntero->procesar(etiqueta);
    }
}

#endif