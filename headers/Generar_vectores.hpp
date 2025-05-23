#ifndef GENERAR_VECTORES_HPP
#define GENERAR_VECTORES_HPP

#include <iostream>
#include <type_traits>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class Generar_vectores {
    private:
        vector<T> data;
    public:
        void agregar_valor(const T& value);
        void procesar(const string& etiqueta) const;
};
    
#include "../src/Generar_vectores.cpp" 

#endif