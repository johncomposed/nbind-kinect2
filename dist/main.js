"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var nbind = require("nbind");
var lib = nbind.init(__dirname).lib;
function default_1() {
    console.log('Platform: ' + lib.Kinect.test());
}
exports.default = default_1;
// nbind.init(__dirname, (err: any, binding: nbind.Binding<any>) => {
//   if(err) throw(err);
//   const lib = binding.lib;
//   console.log('Platform: ' + lib.Kinect.test());
// });
