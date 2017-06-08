//
// Created by boondaburrah on 01/06/17.
//

#include "Kontext.h"

bool Kontext::openDevice() {

    // OPEN THE KINECT
    if(this->api.enumerateDevices() <= 0){
        this->logger->log(this->logger->Error, "No kinects found.");
        return false;
    }
    this->device = api.openDefaultDevice();
    if(this->device == nullptr){
        this->logger->log(this->logger->Error, "Failed to open kinect.");
        return false;
    }
    this->logger->log(this->logger->Info, "Opened kinect with serial " + this->device->getSerialNumber());

    // CONFIGURE THE KINECT
    this->device->setColorFrameListener(this->listener);
    this->device->setIrAndDepthFrameListener(this->listener);
    this->logger->log(this->logger->Info, "Set listeners on kinect.");

    // OH BOY
    if(!this->device->start()){
        this->logger->log(this->logger->Error, "Failed to start kinect.");
        return false;
    }
    this->logger->log(this->logger->Info, "Kinect started.");

    return true;
}

bool Kontext::isDeviceOpen() {
    return (this->device != nullptr);
}



uint8_t* Kontext::getFrame() {

    if(!this->isDeviceOpen()){
        this->logger->log(this->logger->Warning, "Kinect not started. Start kinect before asking for frames.");
        return nullptr;
    }
    if(!this->listener->waitForNewFrame(this->frames, 1000)){
        this->logger->log(this->logger->Warning, "Timed out waiting for frames from the Kinect");
        return nullptr;
    }

    libfreenect2::Frame* rgb = this->frames[libfreenect2::Frame::Color];

    char sizedif[100];
    sprintf(sizedif, "Raw Data: %d, Calculated: %d", rgb->width * rgb->height * rgb->bytes_per_pixel, sizeof(rgb->data));
    this->logger->log(this->logger->Info, sizedif);

    int framesize = rgb->width * rgb->height * rgb->bytes_per_pixel;
    this->framedata = new uint8_t[framesize]; //(uint32_t*) malloc(rgb->width * rgb->height);

    switch(rgb->format){
        case libfreenect2::Frame::Format::RGBX:
            this->logger->log(this->logger->Info, "RGBX");
            std::copy(rgb->data, rgb->data + framesize, this->framedata);
            break;
        case libfreenect2::Frame::Format::BGRX:
            this->logger->log(this->logger->Info, "BGRX");
            std::copy(rgb->data, rgb->data + framesize, this->framedata);

            /*for(int i = 0; i < framesize; i += 4){
                this->framedata[i] = rgb->data[i+2];
                this->framedata[i+1] = rgb->data[i+1];
                this->framedata[i+2] = rgb->data[i];
                this->framedata[i+3] = 0x0;
            }*/
            break;
            //for(int i = 0; i < (rgb->width * rgb->height * rgb->bytes_per_pixel); i += 4){
            //    this->framedata[i/4] = 0x0;
            //    this->framedata[i/4] = (rgb->data[i + 2] << 24) & (rgb->data[i + 1] << 16) & (rgb->data[i + 0] << 8);
            //}
            break;
        case libfreenect2::Frame::Format::Float:
            this->logger->log(this->logger->Info, "Float");
            break;
        case libfreenect2::Frame::Format::Gray:
            this->logger->log(this->logger->Info, "Grey");
            break;
        case libfreenect2::Frame::Format::Raw:
            this->logger->log(this->logger->Info, "Raw");
            break;
        case libfreenect2::Frame::Format::Invalid:
            this->logger->log(this->logger->Info, "Invalid");
            break;
        default:
            this->logger->log(this->logger->Error, "Color frame is of no known format.");
            break;
    }

    //    if(this->framedata != nullptr){
    //        free(this->framedata);
    //    }


    this->listener->release(this->frames);
    return this->framedata;
}

Kontext::~Kontext() {
    if(this->isDeviceOpen()){
        this->device->stop();
        this->device->close();
    }
    delete this->listener;
}

Kontext::Kontext(){
    this->logger = libfreenect2::getGlobalLogger();
    this->listener = new libfreenect2::SyncMultiFrameListener(
            libfreenect2::Frame::Color | libfreenect2::Frame::Ir | libfreenect2::Frame::Depth
    );
    this->hasPointCloud = true;
    this->hasSeeThroughCamera = true;
}
