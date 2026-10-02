#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Complexe.h"

Complexe2D::Complexe2D(double a, double b)
    : a(a), b(b)
{
}

Complexe2D::Complexe2D(double a)
    : a(a), b(a)
{
}

Complexe2D::Complexe2D(const Complexe2D& other)
    : a(other.a), b(other.b)
{
}

double Complexe2D::getReal() const
{
    return a;
}

double Complexe2D::getImag() const
{
    return b;
}

void Complexe2D::setReal(double a)
{
    this->a = a;
}

void Complexe2D::setImag(double b)
{
    this->b = b;
}

Complexe2D Complexe2D::add(const Complexe2D& other) const
{
    return Complexe2D(
        a + other.a,
        b + other.b
    );
}

Complexe2D Complexe2D::mult(const Complexe2D& other) const
{
    return Complexe2D(
        a * other.a - b * other.b,
        a * other.b + b * other.a
    );
}

Complexe2D Complexe2D::conj() const
{
    return Complexe2D(a, -b);
}

Complexe2D Complexe2D::scal(double n) const
{
    return Complexe2D(n * a, n * b);
}

Complexe2D Complexe2D::div(const Complexe2D& other) const
{
    double m2 = other.module2();

    if (m2 == 0) {
        throw std::runtime_error("Division par zero");
    }

    return mult(other.conj()).scal(1.0 / m2);
}

double Complexe2D::module() const
{
    return std::sqrt(a * a + b * b);
}

double Complexe2D::module2() const
{
    return a * a + b * b;
}

double Complexe2D::arg() const
{
    return std::atan2(b, a);
}

bool Complexe2D::plusGrand(const Complexe2D& other) const
{
    return module2() > other.module2();
}

bool Complexe2D::plusPetit(const Complexe2D& other) const
{
    return module2() < other.module2();
}

void Complexe2D::ToString() const
{
    if (b < 0) {
        std::cout << a << " - i" << -b << std::endl;
    }
    else {
        std::cout << a << " + i" << b << std::endl;
    }
}