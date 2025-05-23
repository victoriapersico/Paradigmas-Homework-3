#include "SaveFlightData.hpp"

SaveFlightData::SaveFlightData(const Posicion& p, const Presion& q): posicion(p), presion(q) {}

void SaveFlightData::imprimir(){
    cout<<"FLIGHT DATA - SPANISH: "<<endl;
    posicion.imprimir();
    presion.imprimir();
}

void SaveFlightData::serializar(ofstream& out) const{
    posicion.serializar(out);
    presion.serializar(out);
}

void SaveFlightData::deserializar(ifstream& in) {
    posicion.deserializar(in);
    presion.deserializar(in);
}