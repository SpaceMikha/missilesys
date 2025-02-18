#include "system_init.h"
#include "hardware_abstraction.h"
#include <stdio.h>

void system_init() {
    printf("Initializing system...\n");
    configure_clock();
    initialize_gpio();
    setup_peripherals();
    printf("System initialization complete.\n");
}
