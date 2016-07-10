//Coded by Hechen Hu 
//Code of Multi-Thread Management
//Need to customize for Entry-Point Function(as DWORD WINAPI type) 
//Entry-Point Function use the format of THREADFUNC+original function name 
//Need to Change TerminateThread() Into Something Else Later
//Temporary variable use a prefix of TEMP
#include <iostream>
#include <map>
#include <iterator>
#incldue <windows.h>
using std::map;
class ThreadManager
{
	friend class Log;
	private:
		struct Handle;
		{
             HANDLE hThread;
             int Flag;//if it was set to 1,then the Thread will normally exit
		     char[] ThreadName;
		}
		map <Handle,int> ThreadIDMap;
		auto ThreadIDMapIter ;
		int CurrThreadNum = 0;
		int RunCount;
	public:
	int NewThread(auto THREADFUNCfunction(),nPriority Long Prior,string Name)
	{
        static int PID;
		static Handle ThreadHandle;
		if((ThreadHandle = CreateThread(NULL, 0, THREADFUNCfunction, NULL, 0, PID))&&
		SetThreadPriority(ThreadHandle,Priority))
		{
		CurrThreadNum++;
        ThreadIDMap[ThreaHandle] = PID ;
        ThreadIDMap[ThreadHandle].first.ThreadName = Name ;
		return 0; 
		}	
	} 
	int SetFlag(Handle TEMPThread,int TEMPFlagNum)
	{
        TEMPThread.Flag = TEMPFlagNum ;
        return TEMPFlagNum;
	}
    int CloseThread(Handle TEMPThread)
	{
		if(TEMPThread.hThread == NULL)
		{
		    ThreadIDMap.erase(ThreadIDMap.find(TEMPThread));	
		    CurrThreadNum--;
			return 0;
		}
		else if(TEMPThread.Flag == 0)
		{
           SetFlag(TEMPThread,1);
		}
	 } 
	 ~ThreadManager()
	 if(!ThreadIDMap.empty())
	 {
	 	for(ThreadIDMapIter = ThreadIDMap.begin();ThreadIDMapIter != ThreadIDMap.end();ThreadIDMapIter++)
        {
        	CloseThread((*begin).first.hThread);
        }
	 }	
}; 
