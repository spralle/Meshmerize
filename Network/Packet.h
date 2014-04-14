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
	int TF:2;		// Traffic Class
	int NH:1;		// Next Header
	int HLim:2;		// Hop Limit
	int CID:1;		// Context Identifier Extension
	int SAC:1;		// Source Address Compression
	int SAM:2;		// Source Address Mode
	int M:1;		// Multicast Compression
	int DAC:1;		// Destination Address Compression
	int DAM:2;		// Destination Address Mode

	//int 

} PacketHeader;


#endif //__PACKET_H__