#ifndef PRESION_HPP
#define PRESION_HPP

#include "MedicionBase.hpp"

class Presion : public MedicionBase {
    public:
        float presionEstatica;
        float presionDinamica;
    
        Presion(float p = 0.0f, float q = 0.0f, float t = 0.0f);
        Presion(const Presion& other);
    
        void serializar(ofstream& out) const override;
        void deserializar(ifstream& in) override;
        void imprimir() const override;
};

#endif