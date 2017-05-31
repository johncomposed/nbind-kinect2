/*
So _context represents all the useful stuff that the freenect wrapper is providing, mostly through getters.
Eventually I'll give _context it's own type. 
Right now all the properties of _context are stubs, and completely in flux. 


Calling a new VR~whatever~ should just be providing info about the updating context. 
I think this makes sense with how the docs have all these classes with nothing to be passed into the constructor. 

Also, I wonder if I need to explicity export these classes in order to do instanceof in JS world. That could get funky.
*/

export default function VRContextWrapper(_context: any) {

  class VRDisplayCapabilities {
    readonly hasPointCloud: Boolean
    readonly hasSeeThroughCamera: Boolean;

    constructor() {
      this.hasPointCloud = _context.hasPointCloud;
      this.hasSeeThroughCamera = _context.hasSeeThroughCamera;
    }
  }


  class VRPickingPointAndPlane {
    readonly plane: Float32Array;
    readonly point: Float32Array;

    constructor() {
      this.plane = _context.plane;
      this.point = _context.point;
    }
  }

  class VRPointCloud {
    readonly numberOfPoints: Number; /*long*/
    readonly points: Float32Array;

    constructor() {
      this.numberOfPoints = _context.numberOfPoints;
      this.points = _context.points;
    }
  }

  class VRSeeThroughCamera {
    readonly focalLengthX: Number; /*double*/
    readonly focalLengthY: Number; /*double*/
    
    readonly height: Number; /*long*/
    readonly width: Number; /*long*/
    readonly orientation: Number; /*long*/
    
    readonly pointX: Number; /*double*/
    readonly pointY: Number; /*double*/
    
    readonly textureHeight: Number; /*long*/
    readonly textureWidth: Number; /*long*/

    constructor() {
      this.focalLengthX= _context.CAMERA_focalLengthX; this.focalLengthY= _context.CAMERA_focalLengthY;
      this.height= _context.CAMERA_height; this.width= _context.CAMERA_width; this.orientation= _context.CAMERA_orientation; 
      this.pointX= _context.CAMERA_pointX; this.pointY= _context.CAMERA_pointY; 
      this.textureHeight= _context.CAMERA_textureHeight; this.textureWidth= _context.CAMERA_textureWidth;
    }
  }

  class VRDisplay {
    constructor() {}

    getMaxNumberOfPointsInPointCloud() : Number {
      return _context.getMaxNumberOfPointsInPointCloud() || 0;
    } /*long*/

    getPickingPointAndPlaneInPointCloud(x: Number /*float*/, y: Number /*float*/) : VRPickingPointAndPlane {
      return _context.getPickingPointAndPlaneInPointCloud(x, y) || new VRPickingPointAndPlane();
    }

    getPointCloud(pointCloud: VRPointCloud, justUpdatePointCloud: Boolean, pointsToSkip: Number) : VRPointCloud | null {
      return _context.getPointCloud(pointCloud, justUpdatePointCloud, pointsToSkip) || null;
    }

    getSeeThroughCamera() : VRSeeThroughCamera | null{
      return _context.getSeeThroughCamera() || null;
    }
  }

  return {
    VRDisplayCapabilities,
    VRPickingPointAndPlane,
    VRPointCloud,
    VRSeeThroughCamera,
    VRDisplay
  }

}
