#include "telemetry.h"
#include "navigation.h"
#include "control.h"
#include "communication.h"
#include <stdio.h>

#define TELEMETRY_INTERVAL 1000 // Telemetry transmission interval in ms

void initialize_telemetry() {
    printf("Initializing telemetry system...\n");
}

void transmit_telemetry() {
    float lat, lon, alt, speed, heading;
    get_current_position(&lat, &lon, &alt);
    get_current_velocity(&speed, &heading);

    char message[256];
    snprintf(message, sizeof(message), 
        "Telemetry Data: Lat=%.6f, Lon=%.6f, Alt=%.2f m, Speed=%.2f m/s, Heading=%.2f degrees",
        lat, lon, alt, speed, heading);

    send_data(message);
}
