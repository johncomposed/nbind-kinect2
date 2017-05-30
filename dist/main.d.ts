export class NBindBase { free?(): void }

export class Freenect2 extends NBindBase {
	/** Freenect2(void *); */
	constructor(p0: any);

	/** Freenect2(); */
	constructor();

	/** int32_t enumerateDevices(); */
	enumerateDevices(): number;
}
