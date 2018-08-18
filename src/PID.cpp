#include "PID.h"

using namespace std::chrono;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  last_timestamp = GetTimestamp();
  last_cte = 0.0;
  cumsum_cte = 0.0;
  abs_cumsum_cte = 0.0;
}

void PID::UpdateError(double cte) {
  if (!is_initialized) {
    last_cte = cte;
    is_initialized = true;
  }
  long timestamp =GetTimestamp();
  p_error = cte;
  cumsum_cte += cte;
  abs_cumsum_cte += std::fabs(cte);

  double delta_t = 1.0*(timestamp - last_timestamp)/1.0e3;
  //std::cout << "delta_t = " << delta_t << std::endl;
  d_error = (cte-last_cte)/delta_t;
  i_error = cumsum_cte;

  last_cte = cte;
  last_timestamp = timestamp;

  // sgd parameters search
  if (learning) {
    double learning_rate = 1e-3;
    Kp -= std::max(0.0,p_error)*cte*learning_rate;
    Ki -= std::max(0.0,abs_cumsum_cte)*cte*learning_rate;
    Kd -= std::max(0.0,d_error)*cte*learning_rate;
    //std::cout << "Kp: " << Kp << " Ki: " << Ki << " Kd: " << Kd << std::endl;
  }

}

double PID::TotalError() {
  //return cumsum_cte;
  return -Kp*p_error - Kd*d_error - Ki*i_error;
}

long PID::GetTimestamp() {
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
