#ifndef __PACKET_H__
#define __PACKET_H__

/*
 * Frame is the lowest level structure representing what is sent over the physical layer
 */
typedef struct Frame
{
	//source
	//destination 
	//length
	//payload
	//crc
} Frame;

/*
 * µ6LowPAN based on 6LowPAN (http://tools.ietf.org/html/rfc6282)
 */
typedef struct PacketHeader
{
	int trafficClass:2;		// Traffic Class
	int nextHeader:1;		// Next Header
	int hopLimit:2;		// Hop Limit
	int contextIdentifierExtension:1;		// Context Identifier Extension
	int sourceAddressCompression:1;		// Source Address Compression
	int sourceAddressMode:2;		// Source Address Mode
	int multicastCompression:1;		// Multicast Compression
	int destinationAddressCompression:1;		// Destination Address Compression
	int destinationAddressMode:2;		// Destination Address Mode

	//int 

} PacketHeader;


#endif //__PACKET_H__