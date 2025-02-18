#ifndef NAVIGATION_H
#define NAVIGATION_H

void initialize_navigation();
void update_position(float lat, float lon, float alt);
void update_velocity(float speed, float direction);
void get_current_position(float *lat, float *lon, float *alt);
void get_current_velocity(float *speed, float *direction);

#endif // NAVIGATION_H
