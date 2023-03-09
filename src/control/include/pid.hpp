#ifndef PID_H
#define PID_H
#define PID_INT_MAX 10

struct Pid_para{
   double kp;
   double ki;
   double kd;
};

class  PID {
 private:
    double target;
    double actual;
    double error;
    double error_pre;
    double integral;

 public:
    double kp;
    double ki;
    double kd;
    PID(const double p, const double i, const double d);
    double outputSignal(double tar, double act);
};

#endif // PID_H
