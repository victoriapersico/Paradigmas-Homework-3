#ifndef IMEDICIONES_HPP
#define IMEDICIONES_HPP

#include <fstream>

using namespace std;

class IMediciones {
    public:
        virtual ~IMediciones() = default;
        virtual void serializar(ofstream& out) const = 0; //no modifica al objeto
        virtual void deserializar(ifstream& in) = 0 ; //modifica al objeto
};

#endif