#include "Presion.hpp"

Presion::Presion(float p, float q, float t) : MedicionBase(t), presionEstatica(p), presionDinamica(q) {}

//constructor con deep copy
//llamo explicitamente al constructor de copia de la clase base MedicionBase, 
//se crea una copia (deep copy) del atributo tiempoMedicion
Presion::Presion(const Presion& other) : MedicionBase(other), presionEstatica(other.presionEstatica), presionDinamica(other.presionDinamica) {}

void Presion::serializar(ofstream& out) const {
    out.write(reinterpret_cast<const char*>(&presionEstatica),sizeof(presionEstatica));
    out.write(reinterpret_cast<const char*>(&presionDinamica),sizeof(presionDinamica));
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()),sizeof(float));
}

void Presion::deserializar(ifstream& in){ 
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
    in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(float));
}

void Presion::imprimir() const{
    cout<<"TIEMPO MEDICIÓN: "<<getTiempo()<<endl;
    cout<<"PRESIÓN ESTÁTICA: "<<presionEstatica<<endl;
    cout<<"PRESIÓN DINÁMICA: "<<presionDinamica<<endl;
}