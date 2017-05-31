"use strict";
/*
So _context represents all the useful stuff that the freenect wrapper is providing, mostly through getters.
Eventually I'll give _context it's own type.
Right now all the properties of _context are stubs, and completely in flux.


Calling a new VR~whatever~ should just be providing info about the updating context.
I think this makes sense with how the docs have all these classes with nothing to be passed into the constructor.

Also, I wonder if I need to explicity export these classes in order to do instanceof in JS world. That could get funky.
*/
Object.defineProperty(exports, "__esModule", { value: true });
function VRContextWrapper(_context) {
    var VRDisplayCapabilities = (function () {
        function VRDisplayCapabilities() {
            this.hasPointCloud = _context.hasPointCloud;
            this.hasSeeThroughCamera = _context.hasSeeThroughCamera;
        }
        return VRDisplayCapabilities;
    }());
    var VRPickingPointAndPlane = (function () {
        function VRPickingPointAndPlane() {
            this.plane = _context.plane;
            this.point = _context.point;
        }
        return VRPickingPointAndPlane;
    }());
    var VRPointCloud = (function () {
        function VRPointCloud() {
            this.numberOfPoints = _context.numberOfPoints;
            this.points = _context.points;
        }
        return VRPointCloud;
    }());
    var VRSeeThroughCamera = (function () {
        function VRSeeThroughCamera() {
            this.focalLengthX = _context.CAMERA_focalLengthX;
            this.focalLengthY = _context.CAMERA_focalLengthY;
            this.height = _context.CAMERA_height;
            this.width = _context.CAMERA_width;
            this.orientation = _context.CAMERA_orientation;
            this.pointX = _context.CAMERA_pointX;
            this.pointY = _context.CAMERA_pointY;
            this.textureHeight = _context.CAMERA_textureHeight;
            this.textureWidth = _context.CAMERA_textureWidth;
        }
        return VRSeeThroughCamera;
    }());
    var VRDisplay = (function () {
        function VRDisplay() {
        }
        VRDisplay.prototype.getMaxNumberOfPointsInPointCloud = function () {
            return _context.getMaxNumberOfPointsInPointCloud() || 0;
        }; /*long*/
        VRDisplay.prototype.getPickingPointAndPlaneInPointCloud = function (x /*float*/, y /*float*/) {
            return _context.getPickingPointAndPlaneInPointCloud(x, y) || new VRPickingPointAndPlane();
        };
        VRDisplay.prototype.getPointCloud = function (pointCloud, justUpdatePointCloud, pointsToSkip) {
            return _context.getPointCloud(pointCloud, justUpdatePointCloud, pointsToSkip) || null;
        };
        VRDisplay.prototype.getSeeThroughCamera = function () {
            return _context.getSeeThroughCamera() || null;
        };
        return VRDisplay;
    }());
    return {
        VRDisplayCapabilities: VRDisplayCapabilities,
        VRPickingPointAndPlane: VRPickingPointAndPlane,
        VRPointCloud: VRPointCloud,
        VRSeeThroughCamera: VRSeeThroughCamera,
        VRDisplay: VRDisplay
    };
}
exports.default = VRContextWrapper;
