#ifndef POWER_MANAGEMENT_H
#define POWER_MANAGEMENT_H

void initialize_power_management();
void update_battery_level(float consumption);
void shutdown_non_critical_systems();
float get_battery_level();

#endif // POWER_MANAGEMENT_H
