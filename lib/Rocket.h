#ifndef ROCKET_H
#define ROCKET_H

#include "functions.h"

class Rocket {
private:
    double dryMass = 17.785; // kg
    double altitude = 0; // meters
    double elevation = 90; // degree (angle from horizontal)
    double referenceArea = 0.0774371; // idk
    double dragCoefficient = 0.3; // this should be a function vs mach number
    double velocity = 0.0;

public:
    Rocket(double velocity, double elevation, double altitude) :
    velocity(velocity), elevation(elevation), altitude(altitude)
    {

    }

    // Function to calculate drag force
    double calculateDrag() {
        // Calculate air density at the given altitude
        double airDensity = calculateAirDensity(altitude);

        // Calculate drag using the drag equation
        double dragForce = 0.5 * dragCoefficient * referenceArea * airDensity * velocity * velocity;
        
        return dragForce;
    }

    // energy model neglecting drag
    double predict_apogee_primitive(){
        double v_y = velocity * sin(elevation);

        double apogee = altitude + (v_y * v_y) / (2.0 * g);

        return apogee;
    }

    // simulate flight to predict apogee
    double predict_apogee(){
        double v_y = velocity * sin(elevation);
        double v_x = velocity * cos(elevation);
        double apogee = altitude;

        // TODO: move timestep somewhere else
        double timestep = 0.1; // sec
        while(v_y > 0){
            apogee += v_y * timestep;

            double dragForce = calculateDrag();
            
            double F_x = - dragForce * cos(elevation);
            double F_y = - dragForce * sin(elevation) - dryMass * g;

            v_x += (F_x / dryMass) * timestep;
            v_y += (F_y / dryMass) * timestep;
        }
        return apogee;
    }
};

#endif