#include "MedicionBase.hpp"

MedicionBase::MedicionBase(float tiempo) : tiempoMedicion(make_unique<float>(tiempo)) {} 
//constructor con deep copy
MedicionBase::MedicionBase(const MedicionBase& other) : tiempoMedicion(make_unique<float>(*other.tiempoMedicion)) {}
// "other" es un objeto MedicionBase pasado por referencia.
// Accedo a su atributo "tiempoMedicion" (un unique_ptr),
// desreferencio el puntero con "*"" para obtener el float,
// y creo una nueva copia de ese valor con "make_unique".
float MedicionBase::getTiempo() const{
    return *tiempoMedicion;
}