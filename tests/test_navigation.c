#include "navigation.h"
#include <stdio.h>
#include <assert.h>

void test_navigation() {
    float lat, lon, alt;

    initialize_navigation();
    update_position(40.7128, -74.0060, 2000.0);
    get_current_position(&lat, &lon, &alt);

    assert(lat == 40.7128);
    assert(lon == -74.0060);
    assert(alt == 2000.0);

    printf("Navigation test passed!\n");
}

int main() {
    test_navigation();
    return 0;
}
