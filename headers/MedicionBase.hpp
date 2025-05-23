#ifndef MEDICIONBASE_HPP
#define MEDICIONBASE_HPP

#include "IMediciones.hpp"
#include <memory>
#include <iostream>

class MedicionBase : public IMediciones {
    protected:
        unique_ptr<float> tiempoMedicion;
    public:
        MedicionBase(float tiempo=0.0f);
        MedicionBase(const MedicionBase& other);
        virtual ~MedicionBase() = default;

        float getTiempo() const;
        virtual void imprimir() const = 0;
};

#endif