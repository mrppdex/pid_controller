# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`.

## Reflections

Kp, Ki and Kd parameters were found by initializing them with some heuristic values (Kp=6.2, Ki=1e-4, Kd=0.005) and tuning them with SGD method. This method proved not to be very good for tweaking Ki using intermediate values. One of the solutions could be to use cte error within a certain timeframe, not over all training data. The resulting parameters are: Kp=4.5, Ki=2.0e-2, Kd=5.82.

Lower Kp causes the vehicle to follow smoother path, but also causes understeering on the bends which ends in the vehicle falling off the road. Higher Kp causes the vehicle to follow sinusoidal path, which may not be good for the passengers.

High Ki causes the vehicle to veer off the road and prevents it from recovery.

Lower Kd causes the path not to converge to the optimal path quickly enough. Higher Kd puts the vehicle into resonation, which results in the vehicle falling of the road.
