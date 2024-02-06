#ifndef POSITION_SERVICE_H
#define POSITION_SERVICE_H

#include <vector>
#include "Sensor.h"
#include "Publisher.h"

class PositionService {
public:
    PositionService(ZmqPublisher& publisher);
    void registerSensor(PositionSensor& sensor);
    void update();
    void publish();
private:
    std::vector<PositionSensor> sensors;
    ZmqPublisher& publisher;
};

#endif // POSITION_SERVICE_H

