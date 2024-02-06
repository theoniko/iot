#include "Sensor.h"
#include <chrono>
#include "position.pb.h"

PositionSensor::PositionSensor(uint64_t id, Data3dGenerator& dataGenerator)
    : dataGenerator_(dataGenerator)
{
    positionData.id_ = id;
    update();
}


std::string PositionSensor::sendMessage() 
{
    return serializeToString();
};

void PositionSensor::update() 
{
    positionData.timestamp_ = getCurrentTime();
    positionData.position_ = dataGenerator_.generateData3d(positionData.position_);
};

void PositionSensor::logToConsole()
{
        std::chrono::microseconds duration(positionData.timestamp_ );
        std::chrono::system_clock::time_point time_point(duration);
        std::time_t time_t_value = std::chrono::system_clock::to_time_t(time_point);
        std::cout << "Sent data from sensor " << positionData.id_ << " at timestamp " << std::ctime(&time_t_value);
        std::cout << " Position (x, y, z): (" << positionData.position_.x_ << ", " << positionData.position_.y_ << ", " << positionData.position_.z_ << ")" << std::endl;
};

std::string PositionSensor::serializeToString()
{
    Position position;
    position.set_sensorid(positionData.id_);
    position.set_timestamp_usec(positionData.timestamp_);
    Data3d* data = position.mutable_position();
    data->set_x(positionData.position_.x_);
    data->set_y(positionData.position_.y_);
    data->set_z(positionData.position_.z_);
    std::string message;
    position.SerializeToString(&message);
    return message;
};
    