//Coded by Hechen Hu in July 7,2016
//belongs to XetRA enterprize
//Code of Multi-Thread Management
//Need to customize for Entry-Point Function(as DWORD WINAPI type) 
//Entry-Point Function use the format of THREADFUNC+original function name 
#include<iostream>
#incldue<windows.h>
using namespace std;
class ThreadManager
{
	private:
		HANDLE Thread[20];
		int ThreadID[20]
		int CurrThreadNum = 0;
		int MaxNumOfThread = 20;
	public:
	int NewThread(auto THREADFUNCfunction(),nPriority Long Prior)
	{
		if(CurrThreadHandle<MaxNumOfThread)
		{
			ThreadHandle[CurrThreadNum] = CreateThread(NULL, 0, THREADFUNCfunction, NULL, 0, ThreadID[CurrThreadNum]);
			SetThreadPriority(ThreadHandle[CurrThreadNum].Handle,Priority);
			Thread[CurrThreadNum].Priority = Prior;
		    CurrThreadNum++;
		    return 0; 
		}
	} 
    int KillThread(HANDLE Thread,DWORD ExitCode)
	{
		if(TerminateThread(  hThread, dwExitCode) = 0)
		{
			ThreadID[]
			return 0;
		}
	 } 
}; 
