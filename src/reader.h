#ifndef _READER_
#define _READER_

#include "parser.h"




#define MAX_LIDARS 8


struct LidarInfo {
	HParser parser;
	HPublish pub;
	char lidar_ip[32];
	int lidar_port;
};
void PublishData(HPublish, int, RawData**);

HReader StartUartReader(const char* type ,const char* port, int baudrate, int* rate_list, HParser, HPublish,bool isSaveLog,const char* logPath);
bool SendUartCmd(HReader, int len, char*);
bool SendVpcCmd(HReader hr, int len, char* cmd);


HReader StartUDPReader( unsigned short listen_port, bool is_group_listener, const char* group_ip,
	int lidar_count, const LidarInfo* lidars,bool isSaveLog,const char* logPath);


bool SendUdpCmd(HReader hr, int id, int len, char* cmd);

HReader StartTCPReader(const char* lidar_ip, unsigned short lidar_port, HParser hParser, HPublish hPub);

bool SendTcpCmd(HReader hr, int len, char* cmd);

void StopUartReader(HReader hr);
void StopUDPReader(HReader hr);
void StopTCPReader(HReader hr);
void saveLog(bool isSaveLog,const char*logPath,int type,const unsigned char*buf,unsigned int len);

#endif
