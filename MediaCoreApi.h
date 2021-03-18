#pragma once
#include <Windows.h>

#ifndef	MediaCoreApi_H
#define MediaCoreApi_H

#ifdef MediaCoreApiDll
#define MediaCoreApi extern "C" _declspec(dllexport)
#else
#define MediaCoreApi extern "C" _declspec(dllimport)
#endif

//功能：根据参数初始化一个全局采集对象 
//参数：type 表示设置方式，//1:dxgi,3:readGpu,4:gdi 0：自动的，按照1 3 4 的顺序优先匹配。
//返回：0成功，-1失败
MediaCoreApi int  CreateCapture(int type);

//功能：销毁全局采集对象
MediaCoreApi void DestroyCapture();

//功能：创建一个采集区域
//参数：区域参数
//返回：成功一个区域ID >=0,失败返回<0.
MediaCoreApi int  CreateRegion(int x, int y, int width, int height);

//功能：创建一个rtsp server.
//参数：ID:对应区域ID，name：路径名, port: rtsp端口。比如rtsp://ip:port/name
//返回：成功一个区域ID >=0,失败返回<0.
MediaCoreApi int StartRtspServer(int ID, const char * name, int port);

//功能：推流rtmp
//参数：ID:对应区域ID，addr 对流的rtmp服务地址
//返回：成功一个区域ID >=0,失败返回<0.
MediaCoreApi int StartRtmpPush(int ID, const char * addr);

//功能：创建一个tcp server
//参数：ID:对应区域ID，port：端口
//返回：成功一个区域ID >=0,失败返回<0.
MediaCoreApi int StartTcpServer(int ID, int port);

//功能：创建一个udp server
//参数：ID:对应区域ID，port：端口
//返回：成功一个区域ID >=0,失败返回<0.
MediaCoreApi int StartUdpServer(int ID, int port);

//功能：跟udp server链接连接，获取视频数据
//参数：ip 和端口
//返回：成功一个返回连接指针，失败返回NULL
MediaCoreApi void* StartUdpClient(int port, const char * ip);	//设置Udp客户端，接收数据播放

//功能：在窗口上回放udp 视频
//参数：client,udp 对象，hwnd视频显示窗口句柄
//返回：成功一个返回连接指针，失败返回NULL
MediaCoreApi int  StartUdpClientPlayer(void* client, long long hwnd);

//功能：设置某个区域的 编码方式
//参数：：ID:对应区域ID，encoderType:设置编码方式 1:x264,2:qsv,3:nvenc 0：自动匹配，按照3，2，1的顺序。
//返回：无
MediaCoreApi void SetEncoderType(int ID, int encoderType);

//功能：设置某个区域的 编码比特率
//参数：：ID:对应区域ID，rate:比特率
//返回：无
MediaCoreApi void SetBitRate(int ID, int rate);

//功能：设置某个区域的 编码输出图片大小，不设置原图输出
//参数：ID:对应区域ID，width 和 height
//返回：无
MediaCoreApi void SetOutSize(int ID, int width, int height);

//功能：设置音频采样来源
//参数：ID:对应区域ID: 源id
//返回：无
MediaCoreApi void SetAudioSampleId(int ID, int id);

//功能：设置视频编码质量
//参数：ID:对应区域ID: quality：质量
//返回：无
MediaCoreApi void SetQuality(int ID, int quality);

//功能：开始采集
//参数：无
//返回：无
MediaCoreApi void StartSampler();

MediaCoreApi void SetVideoSampleId(int id);

MediaCoreApi void SetAudioSampleId(int index, int id);

MediaCoreApi int GetVideoSourceNum();

MediaCoreApi int GetAudioSourceNum();

MediaCoreApi int GetVideoSourceNameById(int id, char * name);

MediaCoreApi int GetAudioSourceNameById(int id, char * name);

MediaCoreApi int OpenLog();

MediaCoreApi void SetLogLevel(int level);

MediaCoreApi void WriteLog(int level, const char * fmt, ...);

#endif