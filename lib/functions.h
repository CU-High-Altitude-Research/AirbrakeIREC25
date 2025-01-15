#ifndef FUNCTIONS_H
#define FUCTIONS_H

#include <math.h>
#include "constants.h"

double calculateAirDensity(double altitude) {
    // Calculate temperature at altitude
    double temperature = T0 - L * altitude;

    // Calculate pressure at altitude
    double exponent = (g * M) / (R_star * L);
    double pressure = P0 * std::pow(1 - (L * altitude / T0), exponent);

    // Calculate air density
    return pressure / (R * temperature);
}



#endif