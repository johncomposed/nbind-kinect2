export class NBindBase { free?(): void }

export class Kinect extends NBindBase {
	/** Kinect(int32_t); */
	constructor(p0: number);

	/** static std::string test(); */
	static test(): string;
}
