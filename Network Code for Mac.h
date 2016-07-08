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
			cout<<"����Type��Protocol����"<<endl
			<<"������"<<endl
			<<"Type : �����׽ӿ����ͣ�(SOCK_STREAM���׽��֣� SOCK_DGRAM���ݱ��׽���)"<<endl
			<<"���׽��������ݽ������ޱ߽�ģ��ɿ��ġ�"<<endl
			<<"���ݱ��׽������б߽�ģ����ɿ��ģ���������׽��ֶ��ԣ�"<<endl
			<<"���׽������ٶ��������ݱ������ٶȿ졣"<<endl
			<<"���׽���������ģ����ݱ��׽���������ģ��󷢵������п����ȱ����յ�����"<<endl
			<<"����һ��tcp �����׽��֣�udp�����ݱ��׽���"<<endl
			<<"��������Ҫ�õ��׽������ͺ�Э������"<<endl
			<<"1:SOCK_STREAM���׽���"<<endl
			<<"2:SOCK_DGRAM���ݱ��׽���"<<endl
			<<"6:IPPROTO_TCPʹ��TCPЭ��"<<endl
			<<"17:IPPROTO_UDPʹ��UDPЭ��"<<endl
			<<"eg:type=1 protocol=6 ���뷽ʽ������1��س�������6Ȼ���ٻس�"<<endl;
			/*
			*���￪ʼ����
			*/ 
			cin>>Type>>Protocol;
			//�����ж� 
			while((Type == 1 && Protocol != 6)||(Type == 2 && Protocol != 17)) 
			{		
				char Command;
				cout<<"Type��Protocol��Ϊ�Ƽ����ã��Ƿ�Ҫ�������룿y/n" <<endl;
				cin>>Command;
				if(Command == 'n')
				    break;
				else if(Command == 'y') 
				{
					cout<<"��������Ҫ�õ��׽������ͺ�Э������"<<endl
			        <<"1:SOCK_STREAM���׽���"<<endl
			        <<"2:SOCK_DGRAM���ݱ��׽���"<<endl
			        <<"6:IPPROTO_TCPʹ��TCPЭ��"<<endl
			        <<"17:IPPROTO_UDPʹ��UDPЭ��"<<endl;
					cin>>Type>>Protocol;  
				}	     
			}
			//ִ�г�ʼ�� 
			while((SockServ = socket(AF_INET,Type, Protocol))==0)
		{
			cout<<"��ʼ��Socketʧ��!"<<endl<<"������������³�������Type��Protocol����"<<endl
			<<"������"<<endl
			<<"Type : �����׽ӿ����ͣ�(SOCK_STREAM���׽��֣� SOCK_DGRAM���ݱ��׽���)"<<endl
			<<"���׽��������ݽ������ޱ߽�ģ��ɿ��ġ�"<<endl
			<<"���ݱ��׽������б߽�ģ����ɿ��ģ���������׽��ֶ��ԣ�"<<endl
			<<"���׽������ٶ��������ݱ������ٶȿ졣"<<endl
			<<"���׽���������ģ����ݱ��׽���������ģ��󷢵������п����ȱ����յ�����"<<endl
			<<"����һ��tcp �����׽��֣�udp�����ݱ��׽���"<<endl
			<<"��������Ҫ�õ��׽������ͺ�Э������"<<endl
			<<"1:SOCK_STREAM���׽���"<<endl
			<<"2:SOCK_DGRAM���ݱ��׽���"<<endl
			<<"6:IPPROTO_TCPʹ��TCPЭ��"<<endl
			<<"17:IPPROTO_UDPʹ��UDPЭ��"<<endl
			<<"eg:type=1 protocol=6 ���뷽ʽ������1��س�������6Ȼ���ٻس�"<<endl;
			cin>>Type>>Protocol;
			while((Type == 1 && Protocol != 6)||(Type == 2 && Protocol != 17)) 
			{		
				char Command;
				cout<<"Type��Protocol��Ϊ�Ƽ����ã��Ƿ�Ҫ�������룿y/n" <<endl;
				cin>>Command;
				if(Command == 'n')
				    break;
				else if(Command == 'y') 
				{
					cout<<"��������Ҫ�õ��׽������ͺ�Э������"<<endl
			        <<"1:SOCK_STREAM���׽���"<<endl
			        <<"2:SOCK_DGRAM���ݱ��׽���"<<endl
			        <<"6:IPPROTO_TCPʹ��TCPЭ��"<<endl
			        <<"17:IPPROTO_UDPʹ��UDPЭ��"<<endl;
					cin>>Type>>Protocol;  
				}	     
			}
		}   
		}  
       
	    void InitAddrAndBind()
        {        	int Backlog=5;
        	char Command='n';
			system("netstat -ano");
			cout<<"��������׼�������Ķ˿ں�"<<endl<<"������Щ�˿ں��ǲ����õ�"<<endl
			<<"-----------------------"<<endl;
			int NotBinded=1;
			while(NotBinded)
			{
			    InputPort();
			    
			    system("ipconfig");
				cout<<"��������׼������ip��ַ 000.000.000.000Ĭ�ϼ�������IP,"<<endl
			    <<"��Щ��IPCONFIG������"<<endl;
                cout<<"������IP��ַ"<<endl;		    
			    cout<<"�������ip��"<<endl<<IP<<endl<<Port<<endl;
			    AddrOfServer.sin_family = AF_INET;//using TCP/IP protocol family;
                AddrOfServer.sin_port = htons(Port);//IP Address
                AddrOfServer.sin_addr.S_un.S_addr = htonl(INADDR_ANY); 
                if (SOCKET_ERROR ==  bind(SockServ,(SOCKADDR*)&AddrOfServer,sizeof(SOCKADDR)))
			    {
			   	cout <<"��ʧ�ܴ������:"<< WSAGetLastError() << endl
			    <<"�����ip�Ͷ˿ں�:"<<endl; 
			    }
				else
			    {
			     
			    NotBinded=0; 
				}	 
		    }
			   
                cout<<"��ʼ����������ַ��Ϣ�Ͷ˿ڳɹ�!ʹ�ö˿� "<<Port<<"������Ϣ!"<<endl;
		} 
			
		void ListenUsingSocket(int BackLog)
		{
			cout << "����listen��backlogֵ�Ƽ�Ϊ5"<<endl;
		    cin>>BackLog;
			while(listen(SockServ,BackLog) == (-1))
			{
				cout << "����ʧ�ܴ������:" << WSAGetLastError() << endl
			    << "��������listen��backlogֵ" <<endl;
			    cin>>BackLog; 
			}
			cout << "�ȴ��ͻ��˵�����" << endl
			<<"debug log:"<<"sizeof sockaddr_in:\t"<< sizeof(sockaddr_in) << "\tsizeof sockaddr\t"<< sizeof(sockaddr) << endl;
		}
		
		void InputPort()   //�˿ڼ��
		{   cin>>Port;
			while((1024 <= Port <= 65536) != true )
			{
				cout<<"�˿ں���Ч������������"<<endl;
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
			    cout << "������մ������"<< WSAGetLastError() << endl<<"-----------------------------"<<endl;
				} 
					else
					{
						cout << "���յ���������ӵ�ַ��" << inet_ntoa(AddrOfClient.sin_addr) << "\t"<< ntohs(AddrOfClient.sin_port) << endl;
						SYSTEMTIME sys;
						GetLocalTime(&sys);
						cout << "������Ϣʱ����ʱ�䣺"<<sys.wYear<<"��"<<sys.wMonth<<"��"<<sys.wDay<<"��"<<sys.wHour<<"ʱ"<<sys.wMinute<<"��"<<sys.wSecond<<"��"<<sys.wMilliseconds<<"����"<<endl;
						char Buf1[1024];
						int number;
						if (SOCKET_ERROR == (number=recv(SockConn, Buf1, sizeof(Buf1), 0) ))
						{
						cout << "��ȡ��Ϣ���󣡴������\t" << WSAGetLastError() << endl;
						}
						else
						{
							Buf1[number] = '\0';  //��ӽ���
							cout <<"���ݣ�"<<endl<< Buf1 << endl;
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
};//��Ķ������ 
		


 int main()
 {
 	char Input='n';
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	cout<<"XetRA ���������� All words are in Chinese please check wheather your plugins are oKay or not! ����ʱ��:"<<endl<<sys.wYear<<"��"<<sys.wMonth<<"��"<<sys.wDay<<"��"<<sys.wHour<<"ʱ"<<sys.wMinute<<"��"<<sys.wSecond<<"��"<<sys.wMilliseconds<<"����"<<endl;
 	SERVER Server;
 	Server.Init_Winsock_Lib();
    Server.Init_Socket();
	Server.InitAddrAndBind(); 
	Server.ListenUsingSocket(5);
	Server.ReceiveMsg();
	Server.~SERVER();
	cout<<"�ѹرգ�"<<endl; 
 }

