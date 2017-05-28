#include <string>
#include <iostream>
#include <thread>

// #include <signal.h>

#include "uv.h"
#include "nbind/api.h"
#include "nbind/nbind.h"

#include <libfreenect2/libfreenect2.hpp>


class Kinect {
private:
 
public:
  static std::string test() { return "native module!"; }

  Kinect(const int user_device_number) {
    printf("Hello World (kinect)\n");

  }
};





#ifdef NBIND_CLASS

NBIND_CLASS(Kinect) {
  construct<int>();

  method(test);
}

#endif



