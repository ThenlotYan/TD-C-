#ifndef COMPLEXE_H
#define COMPLEXE_H

class Complexe2D {
private:
    double a;
    double b;

public:
    Complexe2D(double a, double b);
    Complexe2D(double a);
    Complexe2D(const Complexe2D& other);

    double getReal() const;
    double getImag() const;
    void setReal(double a);
    void setImag(double b);

    Complexe2D add(const Complexe2D& other) const;
    Complexe2D mult(const Complexe2D& other) const;
    Complexe2D conj() const;
    Complexe2D scal(double n) const;
    Complexe2D div(const Complexe2D& other) const;

    double module() const;
    double module2() const;
    double arg() const;

    bool plusGrand(const Complexe2D& other) const;
    bool plusPetit(const Complexe2D& other) const;

    void ToString() const;
};

#endif