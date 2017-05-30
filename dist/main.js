"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var lib = require('./nbind.node');
var Kinect = new lib.Freenect2();
exports.default = Kinect;
// File called directly
if (require.main === module) {
    console.log(Kinect.enumerateDevices());
}
// nbind.init(__dirname, (err: any, binding: nbind.Binding<any>) => {
//   if(err) throw(err);
//   const lib = binding.lib;
//   console.log('Platform: ' + lib.Kinect.test());
// });
