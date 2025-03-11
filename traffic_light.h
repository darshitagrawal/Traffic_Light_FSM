#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

// Define states of traffic light for a 4-way intersection
typedef enum {
    NS_GREEN_EW_RED,
    NS_LEFT_GREEN_EW_RED,
    NS_YELLOW_EW_RED,
    ALL_RED_1,
    NS_RED_EW_GREEN,
    NS_RED_EW_LEFT_GREEN,
    NS_RED_EW_YELLOW,
    ALL_RED_2
} TrafficLightState;

// Function prototypes
void printState(TrafficLightState state);
void runTrafficLightSystem(int cycles);

#endif // TRAFFIC_LIGHT_H

