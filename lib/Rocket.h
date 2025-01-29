#ifndef ROCKET_H
#define ROCKET_H

#include "functions.h"

class Rocket {
private:
    double mass = 17.785; // kg
    double altitude = 0; // meters
    double elevation = 90; // degree (angle from horizontal)
    double referenceArea = 194.0/10000.0; // m/s^2 idk
    double velocity = 0.0; // initial velocity

public:
    /**
     * @brief Constructs a Rocket object with specified initial conditions.
     * @param velocity Initial velocity of the rocket in meters per second.
     * @param elevation Initial angle from horizontal in degrees.
     * @param altitude Initial altitude of the rocket in meters.
     */
    Rocket(double velocity, double elevation, double altitude) :
    velocity(velocity), elevation(elevation), altitude(altitude)
    {

    }

    /**
     * @brief Calculates the drag force acting on the rocket.
     * TODO: Replace this with a lookup table or polynomial fit for drag coefficient vs Mach number
     * @return Drag force in newtons.
     */
    double getDragCoefficient(double machNumber) {
        return 0.3; // Default placeholder value
    }

    /**
     * @brief Calculates the drag force acting on the rocket.
     * @return Drag force in newtons.
     */
    double calculateDrag(double altitude, double velocity) {
        // Calculate drag using the drag equation
        double dragForce = 0.5 * getDragCoefficient(69) * referenceArea * calculateAirDensity(altitude) * velocity * velocity;
        return dragForce;
    }

    /**
     * @brief Predicts the apogee using a simplified energy model (neglects drag).
     * @return Predicted apogee in meters.
     */
    double predict_apogee_primitive(){
        double v_y = velocity * sin(elevation);

        double apogee = altitude + (v_y * v_y) / (2.0 * g);

        return apogee;
    }

    /**
     * @brief Simulates the rocket's flight to predict its apogee.
     *        Considers drag and gravitational forces.
     * @return Predicted apogee in meters.
     */
    double predict_apogee(){
        double v_x = velocity * cos(elevation);
        double v_y = velocity * sin(elevation);
        double apogee = altitude;

        // TODO: move timestep somewhere else
        double timestep = 0.5; // sec
        while(v_y > 0){
            apogee += v_y * timestep;

            double dragForce = calculateDrag(apogee, sqrt(v_y*v_y + v_x*v_x));
            
            double F_x = - dragForce * (v_x / sqrt(v_y*v_y + v_x*v_x));
            double F_y = - dragForce * (v_y / sqrt(v_y*v_y + v_x*v_x)) - mass * g;

            v_x += (F_x / mass) * timestep;
            v_y += (F_y / mass) * timestep;

            //printf("Zenith:%.2f\n", rad2deg*atan(v_y/v_x));
        }
        return apogee;
    }
};

#endif