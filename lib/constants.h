#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cmath>

const double P0 = 101325.0;  // Sea-level standard pressure (Pa)
const double T0 = 288.15;    // Sea-level standard temperature (K)
const double L = 0.0065;     // Temperature lapse rate (K/m)
const double R = 287.05;     // Specific gas constant for dry air (J/(kg·K))
const double g = 9.80665;    // Gravitational acceleration (m/s²)
const double M = 0.0289644;  // Molar mass of air (kg/mol)
const double R_star = 8.31432; // Universal gas constant (J/(mol·K))
const double pi = 3.14159265359;
const double deg2rad = pi/180.0;
const double rad2deg = 1.0/deg2rad;

#endif