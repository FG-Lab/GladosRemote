#pragma once


namespace gldr
{
    class Gyro
    {
    public:
        Gyro(int min_accel, int max_accel);
        double getX();
        double getY();
        double getZ();

    protected:
        int _min_accel;
        int _max_accel;
        int _rotX;
        int _rotY;
        int _rotZ;
    };
}

