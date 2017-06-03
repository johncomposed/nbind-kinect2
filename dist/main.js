"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
function initLib(options) {
    if (options === void 0) { options = {}; }
    var lib = options.electron ? require('./nbind-electron.node') : require('./nbind.node');
    //  if (!window && global) global.window = _window;
    //  Object.keys(_window).forEach(k => window[k] = _window[k]);
    return lib;
}
// File called directly
if (require.main === module) {
    var lib = initLib();
    var Kinect = new lib.Kinect();
    console.log(Kinect.test());
}
exports.default = initLib;
