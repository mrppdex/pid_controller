#ifndef PID_H
#define PID_H

#include <chrono>
#include <iostream>
#include <algorithm>
#include <cmath>

class PID {
public:
  /*
   * Timestamp
   */
  long last_timestamp;
  double last_cte;
  double cumsum_cte;
  double abs_cumsum_cte;
  bool learning = false;

  bool is_initialized = false;

  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */
  double Kp;
  double Ki;
  double Kd;

  double prev_cte = 0.0;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  /*
  * Get Timestamp
  */
  long GetTimestamp();
};

#endif /* PID_H */
