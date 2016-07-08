//network code for Mac

//code by Hechen Hu in July 3,2016
//edited by HF XetRA
//All Rights Reserved to The XetRA Enterprize
#include<iostream>
#include<netinet/in.h>
#include<stdio.h>
#include <stdlib.h>
#pragma comment(lib, "ws2_32.lib")  
  
using namespace std;
class SERVER
{
	public:
		int Port;
		int Type=SOCK_STREAM,Protocol=IPPROTO_TCP;
		char IP[15]; 
		int MinorVersionNumber = 2;
		int MajorVersionNumber = 2;
		WORD Version = MAKEWORD(MinorVersionNumber,MajorVersionNumber);
		  
		SOCKET SockServ;
		SOCKET SockConn;   
		SOCKADDR_IN AddrOfClient;				
		int    AddrLen = sizeof(SOCKADDR_IN);
		SOCKADDR_IN AddrOfServer;         
	public:		
		int Init_Winsock_Lib()
		{
			WSADATA WsaData;
			WSAStartup(Version,&WsaData)!=0
			
		}
		
		void Init_Socket()
		{
			cout<<"输入Type和Protocol类型"<<endl
			<<"帮助："<<endl
			<<"Type : 代表套接口类型，(SOCK_STREAM流套接字， SOCK_DGRAM数据报套接字)"<<endl
			<<"流套接字上数据进出是无边界的，可靠的。"<<endl
			<<"数据报套接字是有边界的，不可靠的（相对于流套接字而言）"<<endl
			<<"流套接字是速度慢，数据报套字速度快。"<<endl
			<<"流套接字是有序的，数据报套接字是无序的（后发的数据有可能先被接收到。）"<<endl
			<<"所以一般tcp 用流套接字，udp用数据报套接字"<<endl
			<<"请输入您要用的套接字类型和协议类型"<<endl
			<<"1:SOCK_STREAM流套接字"<<endl
			<<"2:SOCK_DGRAM数据报套接字"<<endl
			<<"6:IPPROTO_TCP使用TCP协议"<<endl
			<<"17:IPPROTO_UDP使用UDP协议"<<endl
			<<"eg:type=1 protocol=6 输入方式：输入1后回车后输入6然后再回车"<<endl;
			/*
			*这里开始输入
			*/ 
			cin>>Type>>Protocol;
			//输入判断 
			while((Type == 1 && Protocol != 6)||(Type == 2 && Protocol != 17)) 
			{		
				char Command;
				cout<<"Type与Protocol不为推荐配置！是否要重新输入？y/n" <<endl;
				cin>>Command;
				if(Command == 'n')
				    break;
				else if(Command == 'y') 
				{
					cout<<"请输入您要用的套接字类型和协议类型"<<endl
			        <<"1:SOCK_STREAM流套接字"<<endl
			        <<"2:SOCK_DGRAM数据报套接字"<<endl
			        <<"6:IPPROTO_TCP使用TCP协议"<<endl
			        <<"17:IPPROTO_UDP使用UDP协议"<<endl;
					cin>>Type>>Protocol;  
				}	     
			}
			//执行初始化 
			while((SockServ = socket(AF_INET,Type, Protocol))==0)
		{
			cout<<"初始化Socket失败!"<<endl<<"您或许可以重新尝试输入Type和Protocol类型"<<endl
			<<"帮助："<<endl
			<<"Type : 代表套接口类型，(SOCK_STREAM流套接字， SOCK_DGRAM数据报套接字)"<<endl
			<<"流套接字上数据进出是无边界的，可靠的。"<<endl
			<<"数据报套接字是有边界的，不可靠的（相对于流套接字而言）"<<endl
			<<"流套接字是速度慢，数据报套字速度快。"<<endl
			<<"流套接字是有序的，数据报套接字是无序的（后发的数据有可能先被接收到。）"<<endl
			<<"所以一般tcp 用流套接字，udp用数据报套接字"<<endl
			<<"请输入您要用的套接字类型和协议类型"<<endl
			<<"1:SOCK_STREAM流套接字"<<endl
			<<"2:SOCK_DGRAM数据报套接字"<<endl
			<<"6:IPPROTO_TCP使用TCP协议"<<endl
			<<"17:IPPROTO_UDP使用UDP协议"<<endl
			<<"eg:type=1 protocol=6 输入方式：输入1后回车后输入6然后再回车"<<endl;
			cin>>Type>>Protocol;
			while((Type == 1 && Protocol != 6)||(Type == 2 && Protocol != 17)) 
			{		
				char Command;
				cout<<"Type与Protocol不为推荐配置！是否要重新输入？y/n" <<endl;
				cin>>Command;
				if(Command == 'n')
				    break;
				else if(Command == 'y') 
				{
					cout<<"请输入您要用的套接字类型和协议类型"<<endl
			        <<"1:SOCK_STREAM流套接字"<<endl
			        <<"2:SOCK_DGRAM数据报套接字"<<endl
			        <<"6:IPPROTO_TCP使用TCP协议"<<endl
			        <<"17:IPPROTO_UDP使用UDP协议"<<endl;
					cin>>Type>>Protocol;  
				}	     
			}
		}   
		}  
       
	    void InitAddrAndBind()
        {        	int Backlog=5;
        	char Command='n';
			system("netstat -ano");
			cout<<"请输入您准备监听的端口号"<<endl<<"现在这些端口号是不可用的"<<endl
			<<"-----------------------"<<endl;
			int NotBinded=1;
			while(NotBinded)
			{
			    InputPort();
			    
			    system("ipconfig");
				cout<<"请输入您准备监听ip地址 000.000.000.000默认监听所有IP,"<<endl
			    <<"这些是IPCONFIG的内容"<<endl;
                cout<<"请输入IP地址"<<endl;		    
			    cout<<"您输入的ip："<<endl<<IP<<endl<<Port<<endl;
			    AddrOfServer.sin_family = AF_INET;//using TCP/IP protocol family;
                AddrOfServer.sin_port = htons(Port);//IP Address
                AddrOfServer.sin_addr.S_un.S_addr = htonl(INADDR_ANY); 
                if (SOCKET_ERROR ==  bind(SockServ,(SOCKADDR*)&AddrOfServer,sizeof(SOCKADDR)))
			    {
			   	cout <<"绑定失败错误代码:"<< WSAGetLastError() << endl
			    <<"请更改ip和端口号:"<<endl; 
			    }
				else
			    {
			     
			    NotBinded=0; 
				}	 
		    }
			   
                cout<<"初始化服务器地址信息和端口成功!使用端口 "<<Port<<"接收信息!"<<endl;
		} 
			
		void ListenUsingSocket(int BackLog)
		{
			cout << "输入listen的backlog值推荐为5"<<endl;
		    cin>>BackLog;
			while(listen(SockServ,BackLog) == (-1))
			{
				cout << "监听失败错误代码:" << WSAGetLastError() << endl
			    << "重新输入listen的backlog值" <<endl;
			    cin>>BackLog; 
			}
			cout << "等待客户端的请求" << endl
			<<"debug log:"<<"sizeof sockaddr_in:\t"<< sizeof(sockaddr_in) << "\tsizeof sockaddr\t"<< sizeof(sockaddr) << endl;
		}
		
		void InputPort()   //端口检查
		{   cin>>Port;
			while((1024 <= Port <= 65536) != true )
			{
				cout<<"端口号无效！请重新输入"<<endl;
				cin>>Port;
				continue;
			}
		}
	
		void ReceiveMsg()
		{
			 while (1)
           {
           	if (INVALID_SOCKET == accept(SockServ,(SOCKADDR*)&AddrOfClient,&AddrLen))
           		{ 
			    cout << "请求接收错误代码"<< WSAGetLastError() << endl<<"-----------------------------"<<endl;
				} 
					else
					{
						cout << "接收到连接请求从地址：" << inet_ntoa(AddrOfClient.sin_addr) << "\t"<< ntohs(AddrOfClient.sin_port) << endl;
						SYSTEMTIME sys;
						GetLocalTime(&sys);
						cout << "接收信息时本地时间："<<sys.wYear<<"年"<<sys.wMonth<<"月"<<sys.wDay<<"日"<<sys.wHour<<"时"<<sys.wMinute<<"分"<<sys.wSecond<<"秒"<<sys.wMilliseconds<<"毫秒"<<endl;
						char Buf1[1024];
						int number;
						if (SOCKET_ERROR == (number=recv(SockConn, Buf1, sizeof(Buf1), 0) ))
						{
						cout << "读取信息错误！错误代码\t" << WSAGetLastError() << endl;
						}
						else
						{
							Buf1[number] = '\0';  //添加结束
							cout <<"数据："<<endl<< Buf1 << endl;
						}
					} 
            
			
		   }
       } 
       int SendMsg(char* Msg) 
       {
       	return send(SockConn,Msg,strlen(Msg)+1,0);
	   }
	  ~SERVER()
	   {
	   	closesocket(SockServ);
	   	closesocket(SockConn);
	   	WSACleanup();
	   }
};//类的定义结束 
		


 int main()
 {
 	char Input='n';
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	cout<<"XetRA 工作组制作 All words are in Chinese please check wheather your plugins are oKay or not! 运行时间:"<<endl<<sys.wYear<<"年"<<sys.wMonth<<"月"<<sys.wDay<<"日"<<sys.wHour<<"时"<<sys.wMinute<<"分"<<sys.wSecond<<"秒"<<sys.wMilliseconds<<"毫秒"<<endl;
 	SERVER Server;
 	Server.Init_Winsock_Lib();
    Server.Init_Socket();
	Server.InitAddrAndBind(); 
	Server.ListenUsingSocket(5);
	Server.ReceiveMsg();
	Server.~SERVER();
	cout<<"已关闭！"<<endl; 
 }

