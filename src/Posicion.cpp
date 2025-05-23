#include "Posicion.hpp"

Posicion::Posicion(float lat, float lon, float alt, float t): MedicionBase(t), latitud(lat), longitud(lon), altitud(alt) {}

//constructor con deep copy
Posicion::Posicion(const Posicion& other) : MedicionBase(other), latitud(other.latitud), longitud(other.longitud), altitud(other.altitud) {}

void Posicion::imprimir() const {
    cout<<"TIEMPO MEDICIÓN: "<<getTiempo()<<endl;
    cout<<"LATITUD: "<<latitud<<endl;
    cout<<"LONGITUD: "<<longitud<<endl;
    cout<<"ALTITUD: "<<altitud<<endl;
}

void Posicion::serializar(ofstream& out) const {
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(latitud));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(altitud));
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(float));
}

void Posicion::deserializar(ifstream& in) {
    in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));
    in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(float));
}