#include <iostream>
#include <math.h>
#include "Hello.h"
#include "Complexe.h"

int main(){
    double a = sqrt(2)/2;
    Complexe2D c1(0, -a);
    Complexe2D c2(a, a);
    Complexe2D c3 = c1.add(c2);
    
    c3.ToString();  
    std::cout << "Module: " << c3.module() << std::endl;
    std::cout << "Argument: " << c3.arg() << std::endl;

    my_class obj("Hello, World!");
    obj.print_my_element();
    
}