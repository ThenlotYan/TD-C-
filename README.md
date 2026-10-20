# Travaux dirigés de C++

Ce dépôt rassemble tous les exercices réalisés en C++. Chaque dossier contient un programme indépendant, avec son propre `main`.

## Contenu

### TD1 — Complexes et classes

- `TD1/Complexe.h` et `TD1/Complexe.cpp` définissent la classe `Complexe2D` : opérations sur les nombres complexes, module, argument et affichage.
- `TD1/Hello.h` et `TD1/Hello.cpp` contiennent une fonction d'affichage et la classe `my_class`.
- `TD1/main.cpp` illustre leur utilisation.

### TD2 — Matrices et recherche

- `TD2/MatrixeBase.h` définit les classes de matrices `MatrixBase` et `MatrixNumerical`, avec notamment l'addition, la soustraction, la multiplication, le déterminant, l'inverse et la matrice identité.
- `TD2/main.cpp` présente des exemples de calculs matriciels.
- `TD2/SearchingAlgorithm.h` et `TD2/SearchingAlgorithm.cpp` contiennent des éléments autour du tri rapide et des recherches linéaire, par sauts et binaire.

### TD3 — 


## Prérequis

- Un compilateur C++ prenant en charge C++11 ou une version ultérieure, par exemple `g++`.
- Un terminal ouvert à la racine du dépôt.

## Compiler et exécuter

Chaque exercice se compile séparément, car chacun possède son propre point d'entrée (`main`).

Avec `g++`, depuis la racine du dépôt :

```sh
# TD1
g++ -std=c++11 TD1/main.cpp TD1/Complexe.cpp TD1/Hello.cpp -o TD1/td1
./TD1/td1

# TD2
g++ -std=c++11 TD2/main.cpp -o TD2/td2
./TD2/td2

# TD3
g++ -std=c++11 TD3/main.cpp -o TD3/td3
./TD3/td3
```

Sous Windows, les exécutables générés peuvent être lancés depuis PowerShell avec `.\TD1\td1.exe`, `.\TD2\td2.exe` et `.\TD3\td3.exe`.