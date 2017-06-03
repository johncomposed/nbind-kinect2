export class NBindBase { free?(): void }

export class Kinect extends NBindBase {
	/** Kinect(); */
	constructor();

	/** int32_t test(); */
	test(): number;
}
