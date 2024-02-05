#include "Publisher.h"

ZmqPublisher::ZmqPublisher(zmq::context_t& context, const std::string& endpoint)
    : socket(context, ZMQ_PUB)
{
    socket.bind(endpoint);
}

void ZmqPublisher::publish(const std::string& message)
{
    zmq::message_t zmq_message(message.size());
    memcpy(zmq_message.data(), message.data(), message.size());
    auto res = socket.send(zmq_message, zmq::send_flags::none);
}
