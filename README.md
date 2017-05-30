nbind-kinect2
=======================
# Install

First install libfreenect2 according to https://github.com/OpenKinect/libfreenect2 .
Then run `npm install`.

Everything should build and link because of the `postinstall` script ([how npm scripts work](https://docs.npmjs.com/misc/scripts)), but if not call `npm run build -s`.


## Plans to match the webAR standard
The tricky bit is going to be the fact that the original WebAR standard [overloads gl.texImage2D](https://github.com/googlevr/chromium-webar#overview-of-the-webar-apis) to work with [VRSeeThroughCamera](https://github.com/googlevr/chromium-webar/blob/9a29f2cab9dd67453d860d14d2ee4be6717cdb1f/chromium/src/third_party/WebKit/Source/modules/webgl/WebGLRenderingContextBase.cpp#L4876). In doing so they also do a bunch of funky stuff using non-standard OpenGl extensions in webgl. 

Our VRSeeThroughCamera contains an additional method called `createImageBitmap` that creates an [ImageBitmap](https://developer.mozilla.org/en-US/docs/Web/API/ImageBitmap) that can be passed into `gl.texImage2D` normally. To keep the API otherwise the same, we're (hopefully) transparently monkeypatching gl.texImage2D to also accept a `VRSeeThroughCamera` and get the underlying ImageBitmap from it.  


