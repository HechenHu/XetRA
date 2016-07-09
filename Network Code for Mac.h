//code by Hechen Hu in July 9,2016
#include <iostream>
#include <socket.h>
#include <stdio.h>
#include <stdlib.h> 
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")  
class NETWORK
{
	private:

		const int Port;
		WORD Version = MAKEWORD(2,2);
		SOCKET SockServ;
		SOCKET SockConn;   
		SOCKADDR_IN AddrOfClient;				
		int    AddrLen = sizeof(SOCKADDR_IN);
		SOCKADDR_IN AddrOfServer;         
	public:		
		const NETWORK()
		{
			SockServ = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
            AddrOfServer.sin_family = AF_INET;//using TCP/IP protocol family;
            AddrOfServer.sin_port = htons(Port);//IP Address
            AddrOfServer.sin_addr.S_un.S_addr = htonl(INADDR_ANY); 
            bind(SockServ,(SOCKADDR*)&AddrOfServer,sizeof(SOCKADDR));
            listen(SockServ,5)
		}

		DWORD WINAPI THREADFUNCReceiveMsg()
		{
			 while (accept(SockServ,(SOCKADDR*)&AddrOfClient,&AddrLen))
           {
						char Buf1[2048];
						int number;
						while(number = recv(SockConn, Buf1, sizeof(Buf1), 0)))
						{
							Buf1[number] = '\0';  
						}
					} 
            
			
		   }
       } 
       DWORD WINAPI THREADFUNCSendMsg(char* Msg) 
       {
       	 send(SockConn,Msg,strlen(Msg)+1,0);
	   }
	  ~SERVER()
	   {
	   	closesocket(SockServ);
	   	closesocket(SockConn);
	   }
}; 
