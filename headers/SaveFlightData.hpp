#ifndef SAVEFLIGHTDATA_HPP
#define SAVEFLIGHTDATA_HPP

#include "Posicion.hpp"
#include "Presion.hpp"

class SaveFlightData {
    public:
        Posicion posicion;
        Presion presion;
    
        SaveFlightData(const Posicion& p = Posicion(), const Presion& q = Presion());
    
        void imprimir();
        void serializar(ofstream& out) const;
        void deserializar(ifstream& in);
};

#endif