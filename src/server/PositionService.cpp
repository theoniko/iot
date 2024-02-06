#include "PositionService.h"
#include <thread>

PositionService::PositionService(ZmqPublisher& publisher) : publisher(publisher){};

void PositionService::registerSensor(PositionSensor& sensor)
{
    sensors.emplace_back(sensor);
};

void PositionService::update()
{
    for(auto& sensor: sensors)
    {
        sensor.update();
    }
};

void PositionService::publish()
{
    for(auto& sensor: sensors)
    {
       const std::string serialized_message = sensor.sendMessage();
       publisher.publish(serialized_message);
       // TODo: Check publish result and then log
       sensor.logToConsole();
    }
};

