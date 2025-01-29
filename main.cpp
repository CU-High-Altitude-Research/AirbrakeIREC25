#include <iostream>
#include "lib/Rocket.h"

int main(){
    Rocket cursrIV = Rocket(600.33, 83.1, 1598.54+1401);
    std::cout << cursrIV.predict_apogee();
}