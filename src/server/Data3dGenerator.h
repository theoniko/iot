#ifndef DATA3D_GENERATOR_H
#define DATA3D_GENERATOR_H

constexpr double POSITION_LOWER_BOUND = 0.0;
constexpr double POSITION_UPPER_BOUND = 100.0;
constexpr double VELOCITY_LOWER_BOUND = -1.0;
constexpr double VELOCITY_UPPER_BOUND = 1.0;
constexpr double NOISE_LOWER_BOUND = -0.3;
constexpr double NOISE_UPPER_BOUND = 0.3;

struct Coordinates{
    double x_;
    double y_;
    double z_;
};

class PositionUpdater {
public:
    PositionUpdater(double dt = 1);
    Coordinates updatePosition(double x, double y, double z, double vx, double vy, double vz); 
private:
    double dt_;
};

class NoiseGenerator {
public:
    NoiseGenerator(double noise_lower_bound = NOISE_LOWER_BOUND, double noise_upper_bound = NOISE_UPPER_BOUND);
    Coordinates addNoise(double x, double y, double z);

private:
    double noise_lower_bound_;
    double noise_upper_bound_;
};

class Data3dGenerator {
public:
    Data3dGenerator();
    Data3dGenerator(PositionUpdater positionUpdater, NoiseGenerator noiseGenerator);
    // void initializePositions();
    Coordinates generateData3d(const Coordinates& current);
private:
    PositionUpdater positionUpdater_;
    NoiseGenerator noiseGenerator_;
};

#endif // DATA3D_GENERATOR_H