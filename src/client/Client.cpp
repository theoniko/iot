
#include <iostream>
#include <chrono>
#include <zmq.hpp>
#include <random>
#include <thread>
#include "position.pb.h"

int main() {
// Client-side code (SUB socket)
zmq::context_t context(1);
zmq::socket_t socket(context, ZMQ_SUB);
socket.connect("tcp://localhost:5555"); // Connect to the same address

// Subscribe to all topics (empty filter)
socket.setsockopt(ZMQ_SUBSCRIBE, "", 0);

while (true) {
    zmq::message_t received_msg;
    socket.recv(&received_msg); // Receive the message

    // Deserialize the received message (assuming it's a Position message)
    Position position;
    if (position.ParseFromArray(received_msg.data(), received_msg.size())) {
        // Successfully deserialized
        int sensor_id = position.sensorid();
        uint64_t timestamp = position.timestamp_usec();
        double x = position.position().x();
        double y = position.position().y();
        double z = position.position().z();

        // Process the data as needed (e.g., store in a data structure, display, etc.)
        // ...

        // Print some information (you can replace this with your actual processing logic)
        // Create a time_point from the timestamp
        std::chrono::microseconds duration(timestamp);
        std::chrono::system_clock::time_point time_point(duration);

         // Convert to std::time_t
        std::time_t time_t_value = std::chrono::system_clock::to_time_t(time_point);


        std::cout << "Received data from sensor " << sensor_id << " at timestamp " << std::ctime(&time_t_value) << std::endl;
        std::cout << "Position (x, y, z): (" << x << ", " << y << ", " << z << ")" << std::endl;
    } else {
        // Failed to deserialize
        std::cerr << "Error: Failed to deserialize the received message." << std::endl;
    }
}

}