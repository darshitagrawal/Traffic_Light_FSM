#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "traffic_light.h"

// Define time durations (in seconds)
#define GREEN_TIME 5
#define YELLOW_TIME 2
#define RED_TIME 1
#define LEFT_TURN_TIME 3
#define ALL_RED_TIME 1

// Function to print traffic light state
void printState(TrafficLightState state) 
{
    switch (state) 
    {
        case NS_GREEN_EW_RED:
            printf("NS: GREEN | EW: RED\n");
            break;
        case NS_LEFT_GREEN_EW_RED:
            printf("NS: LEFT GREEN | EW: RED\n");
            break;
        case NS_YELLOW_EW_RED:
            printf("NS: YELLOW | EW: RED\n");
            break;
        case ALL_RED_1:
        case ALL_RED_2:
            printf("ALL DIRECTIONS: RED\n");
            break;
        case NS_RED_EW_GREEN:
            printf("NS: RED | EW: GREEN\n");
            break;
        case NS_RED_EW_LEFT_GREEN:
            printf("NS: RED | EW: LEFT GREEN\n");
            break;
        case NS_RED_EW_YELLOW:
            printf("NS: RED | EW: YELLOW\n");
            break;
    }
}

// Traffic light state machine function
void runTrafficLightSystem(int cycles) 
{
    TrafficLightState state = NS_GREEN_EW_RED;
    for (int i = 0; i < cycles; i++) 
    {
        printState(state);
        switch (state) 
        {
            case NS_GREEN_EW_RED:
                sleep(GREEN_TIME);
                state = NS_LEFT_GREEN_EW_RED;
                break;
            case NS_LEFT_GREEN_EW_RED:
                sleep(LEFT_TURN_TIME);
                state = NS_YELLOW_EW_RED;
                break;
            case NS_YELLOW_EW_RED:
                sleep(YELLOW_TIME);
                state = ALL_RED_1;
                break;
            case ALL_RED_1:
                sleep(ALL_RED_TIME);
                state = NS_RED_EW_GREEN;
                break;
            case NS_RED_EW_GREEN:
                sleep(GREEN_TIME);
                state = NS_RED_EW_LEFT_GREEN;
                break;
            case NS_RED_EW_LEFT_GREEN:
                sleep(LEFT_TURN_TIME);
                state = NS_RED_EW_YELLOW;
                break;
            case NS_RED_EW_YELLOW:
                sleep(YELLOW_TIME);
                state = ALL_RED_2;
                break;
            case ALL_RED_2:
                sleep(ALL_RED_TIME);
                state = NS_GREEN_EW_RED;
                break;
        }
    }
}

#ifndef TESTING
int main() 
{
    printf("Starting Traffic Light System for a 4-Way Intersection...\n");
    runTrafficLightSystem(10);
    return 0;
}
#endif

