"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var lib = require('./nbind.node');
var Kinect = new lib.Kinect();
// export class Kinect {
//   constructor() {
//   }
// }
function stub() {
    console.log('stub');
}
exports.default = stub;
// File called directly
if (require.main === module) {
    console.log(Kinect.test());
    // console.log(Freenect.enumerateDevices())  
}
