#ifndef __LINK_INTERFACE_H__
#define __LINK_INTERFACE_H__

class ILinkInterface
{
public:
	virtual void init() = 0;
	virtual void destroy() = 0;

	virtual void powerUp() = 0;
	virtual void powerDown() = 0;

	//virtual void sendPacket() = 0;
	//virtual void createBrodcastLink() = 0;
	//virtual void createUnicastLink() = 0;
}

#endif //__LINK_INTERFACE_H__