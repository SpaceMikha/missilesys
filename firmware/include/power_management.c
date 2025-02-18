#include "power_management.h"
#include <stdio.h>

#define MAX_BATTERY_LEVEL 100.0  // Maximum battery capacity in percentage
#define LOW_BATTERY_THRESHOLD 20.0  // Warning level in percentage
#define CRITICAL_BATTERY_THRESHOLD 5.0  // Critical shutdown level

static float battery_level = MAX_BATTERY_LEVEL;

void initialize_power_management() {
    printf("Initializing power management system...\n");
    battery_level = MAX_BATTERY_LEVEL;
}

void update_battery_level(float consumption) {
    battery_level -= consumption;
    if (battery_level < 0) battery_level = 0;

    printf("Battery level: %.2f%%\n", battery_level);

    if (battery_level <= CRITICAL_BATTERY_THRESHOLD) {
        printf("CRITICAL: Battery depleted! Shutting down non-essential systems.\n");
        shutdown_non_critical_systems();
    } else if (battery_level <= LOW_BATTERY_THRESHOLD) {
        printf("WARNING: Low battery! Consider energy-saving mode.\n");
    }
}

void shutdown_non_critical_systems() {
    printf("Disabling non-essential systems to conserve power...\n");
    // Logic to disable non-essential systems (e.g., reducing sensor polling rate)
}

float get_battery_level() {
    return battery_level;
}
