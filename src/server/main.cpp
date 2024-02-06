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
    constexpr auto NUMBER_OF_SENSORS = 10;
    for (size_t sensor_id = 0; sensor_id < NUMBER_OF_SENSORS; sensor_id++)
    {
        PositionSensor positionSensor(sensor_id, data3dGenerator);
        positionService.registerSensor(positionSensor);
    }

    constexpr auto SENSOR_SAMPLING_IN_MS = 1000;
    while (true)
    {
        std::cout << "Sending ..." << std::endl;
        positionService.update();
        positionService.publish();
        std::this_thread::sleep_for(std::chrono::milliseconds(SENSOR_SAMPLING_IN_MS));
        std::cout << "..." << std::endl;
    }
}