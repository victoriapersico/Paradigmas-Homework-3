#ifndef ASOCIAR_HPP
#define ASOCIAR_HPP
#include "Generar_vectores.hpp"
#include <map>
#include <memory>
#include <string>

using namespace std;

template <typename T>
class Asociar {
    private:
        map<string, unique_ptr<Generar_vectores<T>>> elements;
    public:
        void add(const string& etiqueta, const T& value);
        void procesar_json() const;
};
    
#include "../src/Asociar.cpp"

#endif