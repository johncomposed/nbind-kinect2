export class NBindBase { free?(): void }

export class Kinect extends NBindBase {
	/** Kinect(); */
	constructor();

	/** uint32_t test(); */
	test(): number;
}
