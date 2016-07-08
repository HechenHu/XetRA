//the network code of the server

//code by Hechen Hu in July 3,2016
//edited by HF XetRA
//All Rights Reserved to The XetRA Enterprize
#include<iostream>
#include<winsock2.h>
#include<stdio.h>
#include <stdlib.h> 
#include<windows.h>
#pragma comment(lib, "ws2_32.lib")  
  
using namespace std;
class SERVER
{
	private:
		const int Port;
		int Type = SOCK_STREAM,Protocol = IPPROTO_TCP;
		WORD Version = MAKEWORD(2,2);
		SOCKET SockServ;
		SOCKET SockConn;   
		SOCKADDR_IN AddrOfClient;				
		int    AddrLen = sizeof(SOCKADDR_IN);
		SOCKADDR_IN AddrOfServer;         
	public:		
		int Init_Winsock_Lib()
		{
			WSADATA WsaData;
			return WSAStartup(Version,&WsaData);
			
		}
		
		SOCKET Init_Socket(int type,int protocol)
		{
            SockServ = socket(AF_INET,Type, Protocol);
			return SockServ;
		
		}  
       
	    int InitAddrAndBind(int Port)
        { 
			    AddrOfServer.sin_family = AF_INET;//using TCP/IP protocol family;
                AddrOfServer.sin_port = htons(Port);//IP Address
                AddrOfServer.sin_addr.S_un.S_addr = htonl(INADDR_ANY); 
                return bind(SockServ,(SOCKADDR*)&AddrOfServer,sizeof(SOCKADDR));
			   
		} 
			
		void ListenUsingSocket(int BackLog)
		{
			return listen(SockServ,BackLog);
			
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
       DWORD WINAPI SendMsg(char* Msg) 
       {
       	return send(SockConn,Msg,strlen(Msg)+1,0);
	   }
	  ~SERVER()
	   {
	   	closesocket(SockServ);
	   	closesocket(SockConn);
	   	WSACleanup();
	   }
}; 
