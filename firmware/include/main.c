#include "system_init.h"
#include "navigation.h"
#include "guidance.h"
#include "control.h"
#include "telemetry.h"
#include "communication.h"
#include "diagnostics.h"
#include "power_management.h"
#include <stdio.h>
#include <unistd.h> // For sleep()

int main() {
    printf("Missile Embedded System Booting...\n");

    // Initialize all subsystems
    system_init();
    initialize_navigation();
    initialize_guidance();
    initialize_control();
    initialize_telemetry();
    initialize_communication();
    initialize_diagnostics();
    initialize_power_management();

    // Set initial target position (example coordinates)
    set_target_position(35.6895, 139.6917, 1000.0);  // Tokyo, 1000m altitude

    while (get_battery_level() > 5.0) { // Run until critical battery shutdown
        execute_control_loop();
        transmit_telemetry();
        update_battery_level(0.5);  // Simulated battery consumption

        sleep(1); // Simulate real-time execution
    }

    printf("Missile System Shutting Down...\n");
    return 0;
}
