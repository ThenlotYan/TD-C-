#ifndef HELLO_H
#define HELLO_H

#include <string>

void afficher(const std::string& mot);

class my_class {
private:
    std::string mot;

public:
    my_class(std::string mot);
    void print_my_element();
};

#endif