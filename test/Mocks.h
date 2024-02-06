#ifndef MOCKS_H
#define MOCKS_H

#include "gmock/gmock.h"
#include "../src/server/Publisher.h"
#include "../src/server/Sensor.h"

namespace testing 
{
    
class MockPositionSensor : public PositionSensor {
public:

    MockPositionSensor(uint64_t id, Data3dGenerator& dataGenerator) : PositionSensor(id, dataGenerator) {}

    MOCK_METHOD(std::string, sendMessage, (), (override));
    // MOCK_METHOD(void, update, (), (override));
     // MOCK_METHOD(void, logToConsole, (), (override));
    // MOCK_METHOD(std::string, serializeToString, (), (override));
};


class MockZmqPublisher : public ZmqPublisher {
public:
    MockZmqPublisher(zmq::context_t& context, const std::string& endpoint) : ZmqPublisher(context, endpoint){};
    MOCK_METHOD(void, publish, (const std::string&), (override));
};

}

#endif // MOCKS_H