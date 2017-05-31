#include <string>
#include <iostream>
#include <thread>
#include <typeinfo>

// #include <signal.h>

#include "uv.h"
#include "node_buffer.h"

#include "nbind/api.h"
#include "nbind/nbind.h"

#include <libfreenect2/libfreenect2.hpp>
#include <libfreenect2/frame_listener_impl.h>
#include <libfreenect2/registration.h>

// using namespace libfreenect2;

class Kinect {
private:
  libfreenect2::Freenect2 freenect2;
  libfreenect2::FrameMap frames;

  libfreenect2::Freenect2Device * dev;
  libfreenect2::Freenect2Device * devtopause;

  libfreenect2::PacketPipeline * pipeline;
  // libfreenect2::Registration * registration;
  libfreenect2::SyncMultiFrameListener * bananas;

  int types = 0;
  std::string serial;

  bool with_pipeline = false;
  bool initialized = false;
  // bool shutdown = false;
  bool paused = true;


  void togglePause() {

    if (devtopause == 0) return;

    if (paused) devtopause->start();
    else devtopause->stop();

    paused = !paused;
  }

public:
  int framecount = 0;

  Kinect() {
    if(freenect2.enumerateDevices() == 0) {
      printf("no device connected!\n");
      return;
    }

    serial = freenect2.getDefaultDeviceSerialNumber();
    if (with_pipeline) pipeline = new libfreenect2::CpuPacketPipeline();

    dev = with_pipeline ? freenect2.openDevice(serial, pipeline) : freenect2.openDevice(serial);
    
    // devtopause = dev;
    if(dev->stop()) {
      printf("Dev was running, stopped.\n");
    }

    types |= libfreenect2::Frame::Color | libfreenect2::Frame::Ir | libfreenect2::Frame::Depth;
    libfreenect2::SyncMultiFrameListener listener(types);
    bananas = &listener;

    dev->setColorFrameListener(bananas);
    dev->setIrAndDepthFrameListener(bananas);


    printf("Kinect initialized\n");
    initialized = true;
  }

  int test() {
    if (initialized) {
      printf("Starting Device Serial: %s\n", dev->getSerialNumber().c_str());
      // togglePause();
      if(!dev->start()) {
        dev->stop();
        dev->close();
      }
      
      // dev->stop();
      // dev->close();


      // std::this_thread::sleep_for(std::chrono::milliseconds(3000));

      // togglePause();


      // registration = new libfreenect2::Registration(
      //   dev->getIrCameraParams(), 
      //   dev->getColorCameraParams()
      // );

      // libfreenect2::Frame undistorted(512, 424, 4), registered(512, 424, 4);


      // Loop
    //   while(!shutdown) {
    //     if (!bananas->waitForNewFrame(frames, 10*1000)) {
          // std::cout << "timeout!" << std::endl;
    //       return -1;
    //     }

        // libfreenect2::Frame* rgb   = frames[libfreenect2::Frame::Color];
        // libfreenect2::Frame* ir    = frames[libfreenect2::Frame::Ir];
        // libfreenect2::Frame* depth = frames[libfreenect2::Frame::Depth];

    //     registration->apply(rgb, depth, &undistorted, &registered);
        
    //     framecount++;
    //     bananas->release(frames);

    //     // libfreenect2::this_thread::sleep_for(libfreenect2::chrono::milliseconds(100));
    //   }

    //   // Loop over
    //   dev->stop();
    //   dev->close();

    }
    return framecount;
  }


  // libfreenect2::FrameMap gimmeFrame() {
  //   togglePause();

  //   // libfreenect2::Frame* rgb   = frames[libfreenect2::Frame::Color];
  //   // libfreenect2::Frame* ir    = frames[libfreenect2::Frame::Ir   ];
  //   // libfreenect2::Frame* depth = frames[libfreenect2::Frame::Depth];

  //   return frames;
  // }



};



/* NBIND Bindings */


NBIND_CLASS(Kinect) {
  construct<>();


  method(test);
  // method(gimmeFrame);
  // method(openDefaultDevice);
}










