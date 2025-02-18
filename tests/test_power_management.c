#include "power_management.h"
#include <stdio.h>
#include <assert.h>

void test_power_management() {
    initialize_power_management();
    assert(get_battery_level() == 100.0);

    update_battery_level(20.0);
    assert(get_battery_level() == 80.0);

    update_battery_level(75.0);
    assert(get_battery_level() <= 5.0); // Critical shutdown threshold

    printf("Power management test passed!\n");
}

int main() {
    test_power_management();
    return 0;
}
