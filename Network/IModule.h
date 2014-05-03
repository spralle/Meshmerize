#ifndef __IMODULE_H__
#define __IMODULE_H__

class IModule
{
public:
	virtual bool init() = 0;
	virtual bool exit() = 0;
};

#endif //__IMODULE_H__