class JointController
{
public:

    void setTargetPosition(double pos);

    void update();

    double position() const;

    double velocity() const;

private:

    double current_position_;

    double target_position_;

    double current_velocity_;

    bool enabled_;
};