#include <string>
#include <iostream>
#include <thread>

// #include <signal.h>

#include "uv.h"
#include "nbind/api.h"
#include "nbind/nbind.h"

#include <libfreenect2/libfreenect2.hpp>
// using namespace libfreenect2;
// #include <libfreenect2/frame_listener_impl.h>
// #include <libfreenect2/registration.h>
// #include <libfreenect2/packet_pipeline.h>
// #include <libfreenect2/logger.h>


// class JS_Freenect2 : public libfreenect2::Freenect2 {
// public:
//     JS_Freenect2(): libfreenect2::Freenect2() {}
//     ~JS_Freenect2() {}


//   // public:
//   //   // int enumerateDevices


//     // Stuff goes here
// };


class JS_Freenect2 {
private:
  libfreenect2::Freenect2 freenect2;

public:
  JS_Freenect2() {}
  std::string test() { return "native module!"; }
  int enumerateDevices() { return freenect2.enumerateDevices(); }
};


namespace libfreenect2 {
  NBIND_CLASS(Freenect2) {
    construct<void*>();
    construct<>();

    // method(test);
    method(enumerateDevices);
  }



}









