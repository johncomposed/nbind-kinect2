interface VRDisplayCapabilities {
  readonly hasPointCloud: Boolean;
  readonly hasSeeThroughCamera: Boolean;
}

interface VRPickingPointAndPlane {
  readonly plane: Float32Array;
  readonly point: Float32Array;
}

interface VRPointCloud {
  readonly numberOfPoints: Number; /*long*/
  readonly points: Float32Array;
}


interface VRSeeThroughCamera {
  readonly focalLengthX: Number; /*double*/
  readonly focalLengthY: Number; /*double*/
  
  readonly height: Number; /*long*/
  readonly width: Number; /*long*/
  readonly orientation: Number; /*long*/
  
  readonly pointX: Number; /*double*/
  readonly pointY: Number; /*double*/
  
  readonly textureHeight: Number; /*long*/
  readonly textureWidth: Number; /*long*/
}

interface VRDisplay {
  getMaxNumberOfPointsInPointCloud(): Number; /*long*/
  getPickingPointAndPlaneInPointCloud(x: Number /*float*/, y: Number /*float*/): VRPickingPointAndPlane;
  getPointCloud(pointCloud: VRPointCloud, justUpdatePointCloud: Boolean, pointsToSkip: Number): VRPointCloud | null;
  getSeeThroughCamera(): VRSeeThroughCamera | null;
}
