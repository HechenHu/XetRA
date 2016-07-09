//Coded by Hechen Hu 
//Code of Multi-Thread Management
//Need to customize for Entry-Point Function(as DWORD WINAPI type) 
//Entry-Point Function use the format of THREADFUNC+original function name 
//Need to Change TerminateThread() Into Something Else Later
#include <iostream>
#include <map>
#include <iterator>
#incldue <windows.h>
using std::map;
class ThreadManager
{
	private:
		map<HANDLE,int> ThreadIDMap;
		int CurrThreadNum = 0;
	public:
	int NewThread(auto THREADFUNCfunction(),nPriority Long Prior)
	{
        static int PID;
		static HANDLE ThreadHandle;
		if((ThreadHandle = CreateThread(NULL, 0, THREADFUNCfunction, NULL, 0, PID))&&
		SetThreadPriority(ThreadHandle,Priority))
		{
		CurrThreadNum++;
        ThreadIDMap[ThreadHandle] = PID ;
		return 0; 
		}	
	} 
    int KillThread(HANDLE Thread)
	{
		if(TerminateThread( Thread, ExitCode) = 0)
		{
		    ThreadIDMap.erase(ThreadIDMap.find(Thread));	
		    CurrThreadNum--;
			return 0;
		}
	 } 
	 ~ThreadManager()
	 { 
	  auto begin = ThreadIDMap.begin() ;
      while(begin != ThreadIDMap.end())
      {
        KillThread((*begin).first);
      }
       delete ThreadIDMap;
	 }
}; 
