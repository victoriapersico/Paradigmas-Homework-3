#ifndef PUNTO_HPP
#define PUNTO_HPP

class Punto {
    private:
        float a, b;
    public:
        Punto(float a = 0, float b = 0);
        void set_a(float a);
        void set_b(float b);
        float get_a() const;
        float get_b() const;
};

#endif