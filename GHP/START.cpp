// Video tutorial: http://www.youtube.com/user/vertexbrasil
#include "StdAfx.h"
#include "chat_client.h"
#include "LegendRCP.h"


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

void download_list()
{
	Sleep(100000); // atrasa o download em 5 minutos
	int i = 0;
	string dwnld_URL = "https://raiderzlegend.com/clientlist/type/1?" + std::to_string(i);
	//string savepath = "C:\\tmp\\game.txt";
	TCHAR path[MAX_PATH];

	GetCurrentDirectory(MAX_PATH, path);

	wsprintf(path, TEXT("%s\\Data\\effect.mrf"), path);

	HRESULT res = URLDownloadToFile(NULL, dwnld_URL.c_str(), path, 0, NULL);

	if (res == S_OK) {
		//	MyMessObj.SendMessagePort("Download completo");
		download_brunes();
	}
	else if (res == E_OUTOFMEMORY) {
		//	MyMessObj.SendMessagePort("Buffer length invalid, or insufficient memory\n");
	}
	else if (res == INET_E_DOWNLOAD_FAILURE) {
		//	MyMessObj.SendMessagePort("URL is invalid\n");
	}
	else {
		//	MyMessObj.SendMessagePort("Other error: %d\n");
	}

	return;
}

void download_brunes()
{
	int i = 0;
	string dwnld_URL = "https://raiderzlegend.com/clientlist/type/2?" + std::to_string(i);
	//string savepath = "C:\\tmp\\game.txt";
	TCHAR path[MAX_PATH];

	GetCurrentDirectory(MAX_PATH, path);

	wsprintf(path, TEXT("%s\\Data\\effect.002"), path);

	HRESULT res = URLDownloadToFile(NULL, dwnld_URL.c_str(), path, 0, NULL);

	if (res == S_OK) {
		//	MyMessObj.SendMessagePort("Download completo");
		download_rank_exp();
	}

	return;
}

void download_rank_exp()
{
	int i = 0;
	string dwnld_URL = "https://raiderzlegend.com/clientlist/type/3?" + std::to_string(i);
	//string savepath = "C:\\tmp\\game.txt";
	TCHAR path[MAX_PATH];

	GetCurrentDirectory(MAX_PATH, path);

	wsprintf(path, TEXT("%s\\Data\\effect.003"), path);

	HRESULT res = URLDownloadToFile(NULL, dwnld_URL.c_str(), path, 0, NULL);

	if (res == S_OK) {
		//	MyMessObj.SendMessagePort("Download completo");
		download_rank_online();
	}

	return;
}

void download_rank_online()
{
	int i = 0;
	string dwnld_URL = "https://raiderzlegend.com/clientlist/type/4?" + std::to_string(i);
	//string savepath = "C:\\tmp\\game.txt";
	TCHAR path[MAX_PATH];

	GetCurrentDirectory(MAX_PATH, path);

	wsprintf(path, TEXT("%s\\Data\\effect.004"), path);

	HRESULT res = URLDownloadToFile(NULL, dwnld_URL.c_str(), path, 0, NULL);

	if (res == S_OK) {

		//	MyMessObj.SendMessagePort("Download completo");
		download_rank_guild();
	}
	return;
}

void download_rank_guild()
{
	int i = 0;

	string dwnld_URL = "https://raiderzlegend.com/clientlist/type/5?" + std::to_string(i);
	//string savepath = "C:\\tmp\\game.txt";
	TCHAR path[MAX_PATH];

	GetCurrentDirectory(MAX_PATH, path);

	wsprintf(path, TEXT("%s\\Data\\effect.005"), path);

	HRESULT res = URLDownloadToFile(NULL, dwnld_URL.c_str(), path, 0, NULL);

	if (res == S_OK) {
		//	MyMessObj.SendMessagePort("Download completo");
	}
	else if (res == E_OUTOFMEMORY) {
		//	MyMessObj.SendMessagePort("Buffer length invalid, or insufficient memory\n");
	}
	else if (res == INET_E_DOWNLOAD_FAILURE) {
		//	MyMessObj.SendMessagePort("URL is invalid\n");
	}
	else {
		//	MyMessObj.SendMessagePort("Other error: %d\n");
	}


	Sleep(200000);
	download_list();

	return;
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

/* //codigo de testes para conexão por sockt a um servidor, o lado cliente funciona porem o lado servidor da crash quando recebe muitas conexões
							  char buf[4096];
							  // Conecta com o servidor
							  MyMessObj.Init(sServerAddress.c_str(), 1001);

							  MyMessObj.SendMessagePort("Player conectado ip: 192.168.100.1");
*/							
							 // AfxBeginThread(MessageRecThread, 0);
						
							 // codigo para receber mensagem do servidor precisa ser colocado em uma função para rodar dentro de um tread
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

							  // chama a fução de download do txt dentro de um tread para nao travar o cliente
							  CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(download_list), NULL, 0, 0);
							  CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(InitAplication), NULL, 0, 0);
						  break;
						  case DLL_THREAD_ATTACH:
						  case DLL_THREAD_DETACH:							
						  case DLL_PROCESS_DETACH:		
						  break;
						  }	
						  return TRUE;						
}
					
					



