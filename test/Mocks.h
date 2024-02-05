#ifndef MOCKS_H
#define MOCKS_H

#include "gmock/gmock.h"
#include "Publisher.h"

namespace testing 
{

class MockZmqPublisher : public ZmqPublisher {
public:
    MockZmqPublisher(zmq::context_t& context, const std::string& endpoint) : ZmqPublisher(context, endpoint){};
    MOCK_METHOD(void, publish, (const std::string&), (override));
};

}

#endif // MOCKS_H