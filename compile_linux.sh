#!/bin/bash
cd SimonGame
g++ -Wall -Wextra -std=c++11 -pthread Devices.cpp Devices.h Sensors.cpp Sensors.h Actuators.cpp Actuators.h
