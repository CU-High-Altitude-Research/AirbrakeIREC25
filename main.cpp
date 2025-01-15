#include <iostream>
#include "lib/Rocket.h"

int main(){
    Rocket cursrIV = Rocket(100.0, 90.0, 1000.0);
    std::cout << cursrIV.predict_apogee_primitive() << '\n' << cursrIV.predict_apogee();
}