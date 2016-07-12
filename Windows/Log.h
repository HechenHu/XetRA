//Coded by Hechen Hu in July 10,2016
//The Code of Log system
//Log File is a Text File
//Need to Declare this class as a friend class
//Each Class(Thread) will have its Log File Name(char [] Name) and RunCount(int)
//Need To Simplify The Code
#include <stdio.h>
#include <map>
#include <fstream>
using namespace std;
extern ThreadManager;
class LogManager
{
  private:
  	struct FileInfo
  	{
  		FCB *FileControlBlock ;
  		char[] FileName ;
  	}
      map<FileInfo,FILE*> LogFileHandle;//use char[] to Store a Thread Name and the Pointer to Store Log Data
      auto LogFileHandleIter ; 
  public:
  	  int GetCurrThreadNum(const class ThreadManager)
  	  {
  	  	return ThreadManager.CurrThreadNum ;
  	  }
      DWORD WINAPI InitLogFile()
      {
      	int TEMPCount;
        static FILE *FileHandle;
      	for(TEMPCount = 0;TEMPCount < GetCurrThreadNum(ThreadManager),TEMPCount++)
      	{
            *FileHandle = fopen(*(ThreadManager.TEMPIter).first.ThreadName,"w＋") ;
      		LogFile[*(ThreadManager.TEMPIter).first.ThreadName] = FileHandle ;
      	}
      }
      DWORD WINAPI WriteLogFile(const class CLASSLOGDATA)//Use This Function to Write Log Data.Using The Parameter to know which Class Wants to Write its Log Data
      {
       ofstream OFileStream(LogFileHandle[CLASSLOGDATA.Name].first.FileControlBlock[LogFileHandle[CLASSLOGDATA.Name].fd],ios::app） ;
       OFileStream<<"RunCount:"<<CLASSLOGDATA.RunCount<</*The Data You Want To Store*/<<endl;
      }
      ~LogManager()
      {
      	if(!LogFileHandle.empty())
      	{
      		for(LogFileHandleIter = LogFileHandle.begin();LogFileHandleIter != LogFileHandle.end();LogFileHandleIter++)
      		{
      			fclose(*(LogFileHandleIter).second);
      		}
      	}
      }
};