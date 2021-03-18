#pragma once
#include <Windows.h>

#ifndef	MediaCoreApi_H
#define MediaCoreApi_H

#ifdef MediaCoreApiDll
#define MediaCoreApi extern "C" _declspec(dllexport)
#else
#define MediaCoreApi extern "C" _declspec(dllimport)
#endif

//���ܣ����ݲ�����ʼ��һ��ȫ�ֲɼ����� 
//������type ��ʾ���÷�ʽ��//1:dxgi,3:readGpu,4:gdi 0���Զ��ģ�����1 3 4 ��˳������ƥ�䡣
//���أ�0�ɹ���-1ʧ��
MediaCoreApi int  CreateCapture(int type);

//���ܣ�����ȫ�ֲɼ�����
MediaCoreApi void DestroyCapture();

//���ܣ�����һ���ɼ�����
//�������������
//���أ��ɹ�һ������ID >=0,ʧ�ܷ���<0.
MediaCoreApi int  CreateRegion(int x, int y, int width, int height);

//���ܣ�����һ��rtsp server.
//������ID:��Ӧ����ID��name��·����, port: rtsp�˿ڡ�����rtsp://ip:port/name
//���أ��ɹ�һ������ID >=0,ʧ�ܷ���<0.
MediaCoreApi int StartRtspServer(int ID, const char * name, int port);

//���ܣ�����rtmp
//������ID:��Ӧ����ID��addr ������rtmp�����ַ
//���أ��ɹ�һ������ID >=0,ʧ�ܷ���<0.
MediaCoreApi int StartRtmpPush(int ID, const char * addr);

//���ܣ�����һ��tcp server
//������ID:��Ӧ����ID��port���˿�
//���أ��ɹ�һ������ID >=0,ʧ�ܷ���<0.
MediaCoreApi int StartTcpServer(int ID, int port);

//���ܣ�����һ��udp server
//������ID:��Ӧ����ID��port���˿�
//���أ��ɹ�һ������ID >=0,ʧ�ܷ���<0.
MediaCoreApi int StartUdpServer(int ID, int port);

//���ܣ���udp server�������ӣ���ȡ��Ƶ����
//������ip �Ͷ˿�
//���أ��ɹ�һ����������ָ�룬ʧ�ܷ���NULL
MediaCoreApi void* StartUdpClient(int port, const char * ip);	//����Udp�ͻ��ˣ��������ݲ���

//���ܣ��ڴ����ϻط�udp ��Ƶ
//������client,udp ����hwnd��Ƶ��ʾ���ھ��
//���أ��ɹ�һ����������ָ�룬ʧ�ܷ���NULL
MediaCoreApi int  StartUdpClientPlayer(void* client, long long hwnd);

//���ܣ�����ĳ������� ���뷽ʽ
//��������ID:��Ӧ����ID��encoderType:���ñ��뷽ʽ 1:x264,2:qsv,3:nvenc 0���Զ�ƥ�䣬����3��2��1��˳��
//���أ���
MediaCoreApi void SetEncoderType(int ID, int encoderType);

//���ܣ�����ĳ������� ���������
//��������ID:��Ӧ����ID��rate:������
//���أ���
MediaCoreApi void SetBitRate(int ID, int rate);

//���ܣ�����ĳ������� �������ͼƬ��С��������ԭͼ���
//������ID:��Ӧ����ID��width �� height
//���أ���
MediaCoreApi void SetOutSize(int ID, int width, int height);

//���ܣ�������Ƶ������Դ
//������ID:��Ӧ����ID: Դid
//���أ���
MediaCoreApi void SetAudioSampleId(int ID, int id);

//���ܣ�������Ƶ��������
//������ID:��Ӧ����ID: quality������
//���أ���
MediaCoreApi void SetQuality(int ID, int quality);

//���ܣ���ʼ�ɼ�
//��������
//���أ���
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