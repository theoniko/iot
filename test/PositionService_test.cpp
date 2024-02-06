
#include "gmock/gmock.h"
#include "../src/server/PositionService.h"
#include "Mocks.h"

namespace testing 
{

TEST(PositionServiceTest, publish) {
    PositionUpdater positionUpdater;
    NoiseGenerator  noiseGenerator;
    Data3dGenerator data3dGenerator(positionUpdater, noiseGenerator);
    zmq::context_t context(1);
    MockZmqPublisher mockZmqPublisher(context, "tcp://*:5555");
    MockPositionSensor mockSensor(0, data3dGenerator);
    PositionService positionService(mockZmqPublisher);
    positionService.registerSensor(mockSensor);

    // EXPECT_CALL(mockSensor, sendMessage()).WillOnce(::testing::Return("Serialized message"));
    EXPECT_CALL(mockZmqPublisher, publish(_)).Times(1);

    positionService.publish();
}

}