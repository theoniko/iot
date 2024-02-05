#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <zmq.hpp>
#include <string>

class Publisher {
public:
    virtual void publish(const std::string& message) = 0;
    virtual ~Publisher() {}
};

class ZmqPublisher : public Publisher {
public:
    ZmqPublisher(zmq::context_t& context, const std::string& endpoint);
    void publish(const std::string& message) override;
private:
    zmq::socket_t socket;
};

#endif // PUBLISHER_H

