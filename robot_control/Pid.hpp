#pragma once

class PID
{
    public:

        PID();

        void setGain(double kp,double ki,double kd);

        double update(double target,double current,double dt);

        void reset();

    private:

        double kp_{0.0};

        double ki_{0.0};

        double kd_{0.0};

        double integral_{0.0};

        double last_error_{0.0};
};