#ifndef GUIDANCE_H
#define GUIDANCE_H

void initialize_guidance();
void set_target_position(float lat, float lon, float alt);
float compute_steering_angle();
float compute_thrust_adjustment();

#endif // GUIDANCE_H
