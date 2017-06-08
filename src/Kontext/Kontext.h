//
// Created by boondaburrah on 01/06/17.
//

#ifndef NEKKT_KONTEXT_H
#define NEKKT_KONTEXT_H

#include <libfreenect2/logger.h>
#include <libfreenect2/libfreenect2.hpp>
#include <libfreenect2/frame_listener_impl.h>
#include <libfreenect2/registration.h>

class Kontext {
private:
    libfreenect2::Freenect2 api;
    libfreenect2::Freenect2Device* device;
    libfreenect2::Logger* logger;
    libfreenect2::SyncMultiFrameListener* listener;
    libfreenect2::FrameMap frames;
    uint8_t* framedata;
public:
    bool isDeviceOpen();
    bool hasPointCloud;
    bool hasSeeThroughCamera;
    bool openDevice();
    uint8_t* getFrame();
    virtual ~Kontext();
    Kontext();
};


#endif //NEKKT_KONTEXT_H
