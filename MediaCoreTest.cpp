#include "stdafx.h"
#include <Windows.h>
#include "./MediaCoreApi.h"
#pragma comment(lib,"../out/MediaCore.lib")
//#include "../share_sample/src/capturer/FfReader.h"
//#include "../share_sample/src/capturer/ffmpeg.h"

#include <memory>
#include <string>


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0); //一定要加啊
		break;
	default:
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}


DWORD WINAPI playWindow(void* param)
{
	WNDCLASS ws = { 0 };
	ws.cbClsExtra = sizeof(ws);
	ws.lpfnWndProc = WndProc;
	ws.lpszClassName = TEXT("PlayWindow");
	if (!::RegisterClass(&ws))
		return NULL;
	HWND hWnd = ::CreateWindow(TEXT("PlayWindow"), TEXT("PlayWindow"), WS_OVERLAPPEDWINDOW
		, 100, 100, 960, 540, NULL, NULL, NULL, NULL);
	if (!hWnd)
		return NULL;

	ShowWindow(hWnd, SW_SHOW);
	StartUdpClientPlayer(StartUdpClient(3000, "192.168.10.45"), (long long)hWnd);
	MSG msg;
	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	OpenLog();
	//server demo
	CreateCapture(0);
	int index = CreateRegion(0, 0, 1024, 768);
	SetAudioSampleId(index, 0);
	StartRtspServer(index, "test", 6880);
	StartUdpServer(index, 3000);
	//SetEncoderType(index, 1);
	StartSampler();

	getchar();
	DestroyCapture();
	

	//client demo
	//HANDLE temp = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)playWindow, NULL, 0, NULL);

	getchar();
	return 0;
}

