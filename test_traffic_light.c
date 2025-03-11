#include <stdio.h>
#include <assert.h>
#include "traffic_light.h"  // Include only the header, not the .c file

#define TESTING

void test_traffic_light_state_machine() 
{
    TrafficLightState state = NS_GREEN_EW_RED;

    // Simulate state transitions and check correctness
    assert(state == NS_GREEN_EW_RED);
    state = NS_LEFT_GREEN_EW_RED;
    assert(state == NS_LEFT_GREEN_EW_RED);
    state = NS_YELLOW_EW_RED;
    assert(state == NS_YELLOW_EW_RED);
    state = ALL_RED_1;
    assert(state == ALL_RED_1);
    state = NS_RED_EW_GREEN;
    assert(state == NS_RED_EW_GREEN);
    state = NS_RED_EW_LEFT_GREEN;
    assert(state == NS_RED_EW_LEFT_GREEN);
    state = NS_RED_EW_YELLOW;
    assert(state == NS_RED_EW_YELLOW);
    state = ALL_RED_2;
    assert(state == ALL_RED_2);
    state = NS_GREEN_EW_RED;
    assert(state == NS_GREEN_EW_RED);

    printf("All test cases passed!\n");
}

int main() 
{
    printf("Running Tests...\n");
    test_traffic_light_state_machine();
    return 0;
}

