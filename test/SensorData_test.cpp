
#include "gmock/gmock.h"
#include "../src/server/Sensor.h"

namespace testing 
{

/*
class MockData3dGenerator : public Data3dGenerator {
public:
    Coordinates generateData3d() override {
        // Return a fixed Data3d for testing purposes
        return Coordinates{1.0, 2.0, 3.0};
    }
};

class SensorDataTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Create a mock Data3dGenerator
        dataGenerator_ = std::make_unique<MockData3dGenerator>();
    }

    std::unique_ptr<MockData3dGenerator> dataGenerator_;
};

TEST_F(SensorDataTest, UpdateSensorData) {
    SensorData sensorData(42, *dataGenerator_);
    sensorData.updateSensorData();

    // Verify that timestamp and position are updated
    ASSERT_GT(sensorData.getTimestamp(), 0);
    ASSERT_EQ(sensorData.getPosition().x_, 1.0);
    ASSERT_EQ(sensorData.getPosition().y_, 2.0);
    ASSERT_EQ(sensorData.getPosition().z_, 3.0);
}*/

/*TEST(SensorDataTest, serializeToString)
{
    PositionUpdater positionUpdater;
    NoiseGenerator  noiseGenerator;
    Data3dGenerator data3dGenerator(positionUpdater, noiseGenerator);
    SensorData sensorData(0, data3dGenerator);

    std::string expected = " ";
    auto actual = sensorData.serializeToString();
    EXPECT_EQ(actual, expected);
}


TEST(SensorDataTest, SerializeToString) {
    PositionUpdater mockPositionUpdater;
    NoiseGenerator mockNoiseGenerator;
    Data3dGenerator dataGenerator(mockPositionUpdater, mockNoiseGenerator);

    SensorData sensorData(42, dataGenerator);
    sensorData.updateSensorData();
    std::string serialized = sensorData.serializeToString();

    // Verify that the serialized string is not empty
    ASSERT_FALSE(serialized.empty());
}*/

}