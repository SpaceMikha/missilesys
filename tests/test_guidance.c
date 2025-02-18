#include "guidance.h"
#include <stdio.h>
#include <assert.h>

void test_guidance() {
    initialize_guidance();
    set_target_position(51.5074, -0.1278, 5000.0);
    
    float angle = compute_steering_angle();
    assert(angle >= -30.0 && angle <= 30.0);

    float thrust = compute_thrust_adjustment();
    assert(thrust >= 0 && thrust <= 5000.0);

    printf("Guidance test passed!\n");
}

int main() {
    test_guidance();
    return 0;
}
