#ifndef DEVICES_H_
#define DEVICES_H_

class Devices {
	protected:
		static int nbDevices;
	public:
	Devices();
	virtual void WhoAmI();
};

#endif
