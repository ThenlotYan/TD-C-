#ifndef MATRICES_HPP
#define MATRICES_HPP

#include <iostream>
#include <vector>
#include <math.h>

template <typename T>
class MatrixBase {
protected:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    MatrixBase();
    MatrixBase(size_t r, size_t c);
    MatrixBase(size_t r, size_t c, const T& valeur);
    MatrixBase(const std::vector<std::vector<T>>& d);
    virtual ~MatrixBase();

    void addElement(size_t i, size_t j, const T& valeur);
    T getElement(size_t i, size_t j) const;
    size_t getRows() const;
    size_t getCols() const;
    void Display() const;
};

template <typename T>
class MatrixNumerical : public MatrixBase<T> {
public:
    MatrixNumerical();
    MatrixNumerical(size_t r, size_t c);
    MatrixNumerical(size_t r, size_t c, const T& valeur);
    MatrixNumerical(const std::vector<std::vector<T>>& d);

    MatrixNumerical<T> getMineure(size_t ligne, size_t colonne) const;
    T getDeterminant() const;
    MatrixNumerical<double> enDouble() const;
    MatrixNumerical<double> getInverse() const;

    MatrixNumerical<T> operator+(const MatrixNumerical<T>& autre) const;
    MatrixNumerical<T> operator-(const MatrixNumerical<T>& autre) const;
    MatrixNumerical<T> operator*(const MatrixNumerical<T>& autre) const;
    MatrixNumerical<double> operator/(const MatrixNumerical<T>& autre) const;

    static MatrixNumerical<T> getIdentity(int taille);
};

template <typename T>
MatrixNumerical<T> getCoFactor(const MatrixNumerical<T>& m);

template <typename T>
MatrixBase<T>::MatrixBase() : data(), rows(0), cols(0) {}

template <typename T>
MatrixBase<T>::MatrixBase(size_t r, size_t c)
    : data(r, std::vector<T>(c)), rows(r), cols(c) {}

template <typename T>
MatrixBase<T>::MatrixBase(size_t r, size_t c, const T& valeur)
    : data(r, std::vector<T>(c, valeur)), rows(r), cols(c) {}

template <typename T>
MatrixBase<T>::MatrixBase(const std::vector<std::vector<T>>& d)
    : data(d), rows(d.size()), cols(0) {
    if (!d.empty()) {
        cols = d[0].size();
        for (size_t i = 0; i < d.size(); ++i) {
            if (d[i].size() != cols) {
                std::cerr << "Erreur : lignes de tailles differentes" << std::endl;
                data.clear();
                rows = 0;
                cols = 0;
                return;
            }
        }
    }
}

template <typename T>
MatrixBase<T>::~MatrixBase() {}

template <typename T>
void MatrixBase<T>::addElement(size_t i, size_t j, const T& valeur) {
    if (i >= rows || j >= cols) {
        std::cerr << "Erreur : indice hors limites" << std::endl;
        return;
    }
    data[i][j] = valeur;
}

template <typename T>
T MatrixBase<T>::getElement(size_t i, size_t j) const {
    if (i >= rows || j >= cols) {
        std::cerr << "Erreur : indice hors limites" << std::endl;
        return T(0);
    }
    return data[i][j];
}

template <typename T>
size_t MatrixBase<T>::getRows() const {
    return rows;
}

template <typename T>
size_t MatrixBase<T>::getCols() const {
    return cols;
}

template <typename T>
void MatrixBase<T>::Display() const {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            std::cout << data[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

template <typename T>
MatrixNumerical<T>::MatrixNumerical() : MatrixBase<T>() {}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(size_t r, size_t c) : MatrixBase<T>(r, c, T(0)) {}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(size_t r, size_t c, const T& valeur)
    : MatrixBase<T>(r, c, valeur) {}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(const std::vector<std::vector<T>>& d) : MatrixBase<T>(d) {}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getMineure(size_t ligne, size_t colonne) const {
    size_t n = this->rows;
    if (n == 0 || this->rows != this->cols) {
        std::cerr << "Erreur : la matrice doit etre carree et non vide" << std::endl;
        return MatrixNumerical<T>();
    }
    MatrixNumerical<T> resultat(n - 1, n - 1);
    size_t ri = 0;
    for (size_t i = 0; i < n; ++i) {
        if (i == ligne) continue;
        size_t rj = 0;
        for (size_t j = 0; j < n; ++j) {
            if (j == colonne) continue;
            resultat.addElement(ri, rj, this->data[i][j]);
            ++rj;
        }
        ++ri;
    }
    return resultat;
}

template <typename T>
T MatrixNumerical<T>::getDeterminant() const {
    if (this->rows != this->cols) {
        std::cerr << "Erreur : la matrice doit etre carree" << std::endl;
        return T(0);
    }
    size_t n = this->rows;
    if (n == 0) return T(1);
    if (n == 1) return this->data[0][0];
    if (n == 2) {
        return this->data[0][0] * this->data[1][1] - this->data[0][1] * this->data[1][0];
    }
    T det = T(0);
    for (size_t j = 0; j < n; ++j) {
        T signe = (j % 2 == 0) ? T(1) : T(-1);
        det += signe * this->data[0][j] * getMineure(0, j).getDeterminant();
    }
    return det;
}

template <typename T>
MatrixNumerical<double> MatrixNumerical<T>::enDouble() const {
    MatrixNumerical<double> resultat(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->cols; ++j) {
            resultat.addElement(i, j, static_cast<double>(this->data[i][j]));
        }
    }
    return resultat;
}

template <typename T>
MatrixNumerical<double> MatrixNumerical<T>::getInverse() const {
    if (this->rows != this->cols) {
        std::cerr << "Erreur : la matrice doit etre carree" << std::endl;
        return MatrixNumerical<double>();
    }
    double det = static_cast<double>(getDeterminant());
    if (fabs(det) < 1e-12) {
        std::cerr << "Erreur : matrice non inversible" << std::endl;
        return MatrixNumerical<double>();
    }
    MatrixNumerical<T> cof = getCoFactor(*this);
    size_t n = this->rows;
    MatrixNumerical<double> resultat(n, n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            resultat.addElement(i, j, static_cast<double>(cof.getElement(j, i)) / det);
        }
    }
    return resultat;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T>& autre) const {
    if (this->rows != autre.rows || this->cols != autre.cols) {
        std::cerr << "Erreur : dimensions incompatibles pour l'addition" << std::endl;
        return MatrixNumerical<T>();
    }
    MatrixNumerical<T> resultat(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->cols; ++j) {
            resultat.data[i][j] = this->data[i][j] + autre.data[i][j];
        }
    }
    return resultat;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical<T>& autre) const {
    if (this->rows != autre.rows || this->cols != autre.cols) {
        std::cerr << "Erreur : dimensions incompatibles pour la soustraction" << std::endl;
        return MatrixNumerical<T>();
    }
    MatrixNumerical<T> resultat(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->cols; ++j) {
            resultat.data[i][j] = this->data[i][j] - autre.data[i][j];
        }
    }
    return resultat;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical<T>& autre) const {
    if (this->cols != autre.rows) {
        std::cerr << "Erreur : dimensions incompatibles pour la multiplication" << std::endl;
        return MatrixNumerical<T>();
    }
    MatrixNumerical<T> resultat(this->rows, autre.cols);
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < autre.cols; ++j) {
            T somme = T(0);
            for (size_t k = 0; k < this->cols; ++k) {
                somme += this->data[i][k] * autre.data[k][j];
            }
            resultat.data[i][j] = somme;
        }
    }
    return resultat;
}

template <typename T>
MatrixNumerical<double> MatrixNumerical<T>::operator/(const MatrixNumerical<T>& autre) const {
    return enDouble() * autre.getInverse();
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(int taille) {
    if (taille < 0) {
        std::cerr << "Erreur : la taille doit etre positive" << std::endl;
        return MatrixNumerical<T>();
    }
    size_t n = static_cast<size_t>(taille);
    MatrixNumerical<T> resultat(n, n);
    for (size_t i = 0; i < n; ++i) {
        resultat.addElement(i, i, T(1));
    }
    return resultat;
}

template <typename T>
MatrixNumerical<T> getCoFactor(const MatrixNumerical<T>& m) {
    if (m.getRows() != m.getCols()) {
        std::cerr << "Erreur : la matrice doit etre carree" << std::endl;
        return MatrixNumerical<T>();
    }
    size_t n = m.getRows();
    MatrixNumerical<T> resultat(n, n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            T signe = ((i + j) % 2 == 0) ? T(1) : T(-1);
            resultat.addElement(i, j, signe * m.getMineure(i, j).getDeterminant());
        }
    }
    return resultat;
}

#endif