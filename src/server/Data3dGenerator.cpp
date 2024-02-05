#include "Data3dGenerator.h"
#include <random>
#include <limits>

double getRandomValue(double lower_bound = 0, double upper_bound = std::numeric_limits<double>::max()) 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(lower_bound, upper_bound);
    return dist(gen);
}


PositionUpdater::PositionUpdater(double dt) : dt_(dt) {}

Coordinates PositionUpdater::updatePosition(double x, double y, double z, double vx, double vy, double vz) 
{
    x += vx * dt_;
    y += vy * dt_;
    z += vz * dt_;
    return {x, y, z};
}

NoiseGenerator::NoiseGenerator(double noise_lower_bound, double noise_upper_bound)
    : noise_lower_bound_(noise_lower_bound),
      noise_upper_bound_(noise_upper_bound) 
{}

Coordinates NoiseGenerator::addNoise(double x, double y, double z) 
{
    const double noise_x = getRandomValue(noise_lower_bound_, noise_upper_bound_);
    const double noise_y = getRandomValue(noise_lower_bound_, noise_upper_bound_);
    const double noise_z = getRandomValue();
    const double noisy_x = x + noise_x;
    const double noisy_y = y + noise_y;
    const double noisy_z = z + noise_z;
    return {noisy_x, noisy_y, noisy_z};
}

Data3dGenerator::Data3dGenerator(){}

Data3dGenerator::Data3dGenerator(PositionUpdater positionUpdater, NoiseGenerator noiseGenerator)
    : positionUpdater_(positionUpdater), noiseGenerator_(noiseGenerator) {
    //initializePositions();
}

/*
void Data3dGenerator::initializePositions() {
    // Initialize positions randomly within the specified range (0 to 100 meters)
    coordinates_.x_ = getRandomValue(POSITION_LOWER_BOUND, POSITION_UPPER_BOUND);
    coordinates_.y_ = getRandomValue(POSITION_LOWER_BOUND, POSITION_UPPER_BOUND);
    coordinates_.z_ = getRandomValue();
}*/

double clamp(double val, double low = POSITION_LOWER_BOUND, double high = POSITION_UPPER_BOUND) {
    return std::min(std::max(val, low), high);
}

Coordinates Data3dGenerator::generateData3d(const Coordinates& current)
{
    const double vx = getRandomValue(VELOCITY_LOWER_BOUND, VELOCITY_UPPER_BOUND); 
    const double vy = getRandomValue(VELOCITY_LOWER_BOUND, VELOCITY_UPPER_BOUND);
    const double vz = getRandomValue();
    Coordinates newCoordinates = positionUpdater_.updatePosition(current.x_, current.y_, current.z_, vx, vy, vz);
    Coordinates newNoisyCoordinates = noiseGenerator_.addNoise(newCoordinates.x_, newCoordinates.y_, newCoordinates.z_);
    return {clamp(newNoisyCoordinates.x_), clamp(newNoisyCoordinates.y_), newNoisyCoordinates.z_};
}