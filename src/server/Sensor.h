#ifndef SENSOR_H
#define SENSOR_H

#include <cstdint>
#include <string>
#include <chrono>
#include "Data3dGenerator.h"
#include "Macro.h"

static uint64_t getCurrentTime() {
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

struct PositionData
 {
    uint64_t id_;
    uint64_t timestamp_;
    Coordinates position_;
};

class Sensor {
public:
    virtual std::string sendMessage() = 0;
    virtual void update() = 0;
    virtual ~Sensor() {}
};

class PositionSensor : public Sensor
{
public:
    PositionSensor(uint64_t id, Data3dGenerator& dataGenerator);
    std::string sendMessage() override;
    void update() override;
    void logToConsole();
private:
    PositionData positionData;
    Data3dGenerator& dataGenerator_;

    std::string serializeToString();

};

#endif // SENSOR_H