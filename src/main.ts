import * as nbind from 'nbind';
import VRContextWrapper from "./VRContextWrapper";
const lib = require('./nbind.node'); 

const Kinect = new lib.Kinect();


// export class Kinect {
//   constructor() {

//   }
// }





export default function stub() {
  console.log('stub');
}





// File called directly
if (require.main === module) {
  console.log(Kinect.test());
  // console.log(Freenect.enumerateDevices())  
}



