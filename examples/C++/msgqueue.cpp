//
//  Simple message queuing broker in C++
//  Same as request-reply broker but using QUEUE device
//

#include "zhelpers.hpp"

int main (int argc, char *argv[])
{
    zmq::context_t context(1);

    //  Socket facing clients
    zmq::socket_t frontend (context, ZMQ_ROUTER);
    frontend.bind("tcp://*:5559");

    //  Socket facing services
    zmq::socket_t backend (context, ZMQ_DEALER);
    backend.bind("tcp://*:5560");

    //  Start the proxy
    zmq::proxy(static_cast<void*>(frontend),
               static_cast<void*>(backend),
               nullptr);
    return 0;
}
