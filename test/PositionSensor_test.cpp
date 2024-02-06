
#include "gmock/gmock.h"
#include "../src/server/Sensor.h"
#include <cmath>

namespace testing 
{

TEST(PositionSensorTest, update) 
{
    PositionUpdater positionUpdater;
    NoiseGenerator  noiseGenerator;
    Data3dGenerator data3dGenerator(positionUpdater, noiseGenerator);
    PositionSensor positionSensor(42, data3dGenerator);
    
    Coordinates before_update = positionSensor.getCoordinates();
    positionSensor.update();
    Coordinates after_update = positionSensor.getCoordinates();

    EXPECT_LE(std::abs(after_update.x_ - before_update.x_), 1.3);
    EXPECT_LE(std::abs(after_update.y_ - before_update.y_), 1.3);
}

}