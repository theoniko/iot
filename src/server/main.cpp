#include "Publisher.h"
#include "PositionService.h"

#include <iostream>
#include <thread>

int main()
{
    PositionUpdater positionUpdater;
    NoiseGenerator  noiseGenerator;
    Data3dGenerator data3dGenerator(positionUpdater, noiseGenerator);
    zmq::context_t context(1);
    ZmqPublisher zmqPublisher(context, "tcp://*:5555");


    PositionService positionService(zmqPublisher);
    for (size_t sensor_id = 0; sensor_id < 1; sensor_id++) 
    {
        PositionSensor positionSensor(sensor_id, data3dGenerator);
        positionService.registerSensor(positionSensor);
    }

    while (true)
    {
        positionService.update();
        positionService.publish();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}