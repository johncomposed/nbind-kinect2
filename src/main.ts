import * as nbind from 'nbind';
import VRContextWrapper from "./VRContextWrapper";

interface Options {
  electron?: boolean;
}

function initLib(options = {} as Options) {

  const lib = options.electron ? require('./nbind-electron.node') : require('./nbind.node'); 


  //  if (!window && global) global.window = _window;
  //  Object.keys(_window).forEach(k => window[k] = _window[k]);

  return lib;
}



// File called directly
if (require.main === module) {
  const lib = initLib();
  const Kinect = new lib.Kinect();


  console.log(Kinect.test());
} 


export default initLib;
