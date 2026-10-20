#include "SearchingAlgorithm.h"
#include "MatrixeBase.h"

int main() {
    MatrixNumerical<int> a({{1, 2, 3}, {0, 1, 4}, {5, 6, 0}});
    MatrixNumerical<int> b({{2, 0, 1}, {1, 3, 2}, {0, 1, 1}});

    std::cout << "Matrice A :" << std::endl;
    a.Display();

    std::cout << "Matrice B :" << std::endl;
    b.Display();

    std::cout << "Lignes de A : " << a.getRows() << ", colonnes de A : " << a.getCols() << std::endl;
    std::cout << "Element (1,2) de A : " << a.getElement(1, 2) << std::endl;

    std::cout << "Determinant de A : " << a.getDeterminant() << std::endl;

    std::cout << "A + B :" << std::endl;
    (a + b).Display();

    std::cout << "A - B :" << std::endl;
    (a - b).Display();

    std::cout << "A * B :" << std::endl;
    (a * b).Display();

    std::cout << "Cofacteurs de A :" << std::endl;
    getCoFactor(a).Display();

    std::cout << "Inverse de A :" << std::endl;
    a.getInverse().Display();

    std::cout << "A / B :" << std::endl;
    (a / b).Display();

    std::cout << "Identite 4x4 :" << std::endl;
    MatrixNumerical<int>::getIdentity(4).Display();

    MatrixNumerical<double> c(2, 2);
    c.addElement(0, 0, 4.0);
    c.addElement(0, 1, 7.0);
    c.addElement(1, 0, 2.0);
    c.addElement(1, 1, 6.0);
    std::cout << "Inverse de C :" << std::endl;
    c.getInverse().Display();

    return 0;
}