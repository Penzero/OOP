#include "Test.h"
#include "../domain/Animal.h"
#include <iostream>
#include <cassert>

void Test::run_all_tests() {
    std::cout<<"beginning tests....\n";
    Animal a;
    Animal b{23,9000.1,"jordan"};
    Animal c;
    c = b;
    a = b = c;
    std::cout<<a<<"\n";
    std::cout<<"tests successfully finished!\n";
}