// Video tutorial: http://www.youtube.com/user/vertexbrasil
#include "StdAfx.h"
#include "chat_client.h"



CARREGAR carrega;
HANDLE m_DllModule;
//Global Message object
CIPMessage MyMessObj;
string sServerAddress;

extern  "C"  __declspec(dllexport) void __cdecl EntryProc()  // Função API (init) da dll
{
	carrega.TESTE       				= 0; 
	carrega.Splash_Screen = 1;

	sServerAddress = "127.0.0.1";
}


UINT  MessageRecThread(LPVOID pParam)
{
	while (1)
	{
		if (MyMessObj.RecMessagePort())
			break;
	}
	return 0;
}



BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	                        
	                          switch (ul_reason_for_call){
						      case DLL_PROCESS_ATTACH: m_DllModule = hModule;							 			  	
							  EntryProc(); //API funciton

							  //Splash Screen /////////////////////////////////////////////////////////////	
							  if(carrega.Splash_Screen == 1)
							  {
								SplashShow();
							  }	


							  char buf[4096];
							  // Conecta com o servidor
							  MyMessObj.Init(sServerAddress.c_str(), 1001);

							  MyMessObj.SendMessagePort("Player conectado ip: 192.168.100.1");
							
							 // AfxBeginThread(MessageRecThread, 0);
						  /*
							  if (!MyMessObj.IsConnected())
							  {
								  getch();
								  return 0;
							  }
			
							  *//*
							  while (gets_s(buf))
							  {
								  if (strlen(buf) == 0)
									  break;
								  if (MyMessObj.SendMessagePort(buf))
								  {
//									  cout << "Problem in connecting to server. Check whether server is running\n";
									  break;
								  }
							  }

							  getch();
*/

						  break;
						  case DLL_THREAD_ATTACH:
						  case DLL_THREAD_DETACH:							
						  case DLL_PROCESS_DETACH:		
						  break;
						  }	
						  return TRUE;						
}
					
					



