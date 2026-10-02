#include <iostream>
#include "Hello.h"

void afficher(const std::string& mot){
    std::cout << mot << std::endl;
}

my_class::my_class(std::string mot): mot(mot){}

void my_class::print_my_element(){
    std::cout << mot << std::endl;
}