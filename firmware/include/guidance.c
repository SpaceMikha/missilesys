#include "guidance.h"
#include "navigation.h"
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81  // Gravity constant in m/s²
#define MAX_THRUST 5000.0  // Maximum thrust in Newtons
#define MAX_CORRECTION_ANGLE 30.0  // Max steering correction in degrees

static float target_latitude = 0.0;
static float target_longitude = 0.0;
static float target_altitude = 0.0;

void initialize_guidance() {
    printf("Initializing guidance system...\n");
    // Any setup needed for control algorithms
}

void set_target_position(float lat, float lon, float alt) {
    target_latitude = lat;
    target_longitude = lon;
    target_altitude = alt;
    printf("Target position set: Lat: %.6f, Lon: %.6f, Alt: %.2f m\n", target_latitude, target_longitude, target_altitude);
}

float compute_steering_angle() {
    float current_lat, current_lon, current_alt;
    get_current_position(&current_lat, &current_lon, &current_alt);

    float delta_lat = target_latitude - current_lat;
    float delta_lon = target_longitude - current_lon;
    float delta_alt = target_altitude - current_alt;

    float angle = atan2(delta_alt, sqrt(delta_lat * delta_lat + delta_lon * delta_lon)) * (180.0 / M_PI);
    if (angle > MAX_CORRECTION_ANGLE) angle = MAX_CORRECTION_ANGLE;
    if (angle < -MAX_CORRECTION_ANGLE) angle = -MAX_CORRECTION_ANGLE;

    printf("Computed steering angle: %.2f degrees\n", angle);
    return angle;
}

float compute_thrust_adjustment() {
    float current_alt;
    get_current_position(NULL, NULL, &current_alt);

    float altitude_error = target_altitude - current_alt;
    float thrust_adjustment = MAX_THRUST * (altitude_error / 1000.0);

    if (thrust_adjustment > MAX_THRUST) thrust_adjustment = MAX_THRUST;
    if (thrust_adjustment < 0) thrust_adjustment = 0;

    printf("Computed thrust adjustment: %.2f N\n", thrust_adjustment);
    return thrust_adjustment;
}
