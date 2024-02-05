#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../src/server/Data3dGenerator.h"

namespace testing 
{

TEST(PositionUpdaterTest, updatePosition) {
    PositionUpdater positionUpdater;
    constexpr double x = 10.0, y = 20.0, z = 30.0;
    constexpr double vx = 1.0, vy = 2.0, vz = 3.0;

    Coordinates coords = positionUpdater.updatePosition(x, y, z, vx, vy, vz);

    EXPECT_DOUBLE_EQ(coords.x_, 11.0);
    EXPECT_DOUBLE_EQ(coords.y_, 22.0);
    EXPECT_DOUBLE_EQ(coords.z_, 33.0);
}

TEST(NoiseGeneratorTest, addNoise) {
    NoiseGenerator noiseGenerator;
    constexpr double x = 10.0, y = 20.0, z = 30.0;

    Coordinates coords = noiseGenerator.addNoise(x, y, z);

    EXPECT_GE(coords.x_, x + NOISE_LOWER_BOUND);
    EXPECT_LE(coords.x_, x + NOISE_UPPER_BOUND);
}

TEST(Data3dGeneratorTest, generateData3dWithinRange) {
    PositionUpdater mockPositionUpdater;
    NoiseGenerator mockNoiseGenerator;
    Data3dGenerator dataGenerator(mockPositionUpdater, mockNoiseGenerator);
    Coordinates current{1.0, 2.0, 3.0};
    Coordinates coords = dataGenerator.generateData3d(current);

    EXPECT_GE(coords.x_, POSITION_LOWER_BOUND);
    EXPECT_LE(coords.x_, POSITION_UPPER_BOUND);
    EXPECT_GE(coords.y_, POSITION_LOWER_BOUND);
    EXPECT_LE(coords.y_, POSITION_UPPER_BOUND);
    EXPECT_GE(coords.z_, POSITION_LOWER_BOUND);
    EXPECT_LE(coords.y_, std::numeric_limits<double>::max());   
}

}