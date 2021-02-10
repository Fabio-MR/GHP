

#include <discord_register.h>
#include <discord_rpc.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <tlhelp32.h>
#include "Config.h"

bool connected = false;
char login[256] = "";
Config CRcp;

bool CheckIfProgramIsRunning()
{
	HANDLE m_hEvent = CreateEvent(NULL, TRUE, FALSE, "rcp");

	switch (GetLastError())
	{
		// app is already running
	case ERROR_ALREADY_EXISTS:
	{
		CloseHandle(m_hEvent);

		return true;
		// break;
	}

	// this is the first instance of the app
	case ERROR_SUCCESS:
	{
		// global event created and new instance of app is running,
		// continue on, don't forget to clean up m_hEvent on exit
		return false;
		//break;
	}
	}
	return false;
}

void HandleDiscordReady(const DiscordUser* requester)
{
	printf("logado como %s\n", requester->username);
	strcpy(login, requester->username);
	connected = true;
}


void handleDiscordDisconnected(int errcode, const char *message) {
	printf("\nDiscord: disconnected (%d: %s)\n", errcode, message);
	connected = false;
}


void Init()
{
	DiscordEventHandlers handle;

	memset(&handle, 0, sizeof(handle));
	handle.ready = HandleDiscordReady;
	handle.disconnected = handleDiscordDisconnected;
	Discord_Initialize("805952684196233216", &handle, 1, NULL);
	//return true;
}


DWORD FindProcessId(char* processName)
{
	// strip path

	char* p = strrchr(processName, '\\');
	if (p)
		processName = p + 1;

	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);

	HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, (DWORD)NULL);
	if (processesSnapshot == INVALID_HANDLE_VALUE)
		return 0;

	Process32First(processesSnapshot, &processInfo);
	if (!strcmp(processName, processInfo.szExeFile))
	{
		CloseHandle(processesSnapshot);
		return processInfo.th32ProcessID;
	}

	while (Process32Next(processesSnapshot, &processInfo))
	{
		if (!strcmp(processName, processInfo.szExeFile))
		{
			CloseHandle(processesSnapshot);
			return processInfo.th32ProcessID;
		}
	}

	CloseHandle(processesSnapshot);
	return 0;
}

DiscordRichPresence CreateRCP()
{
	time_t ctime = time(NULL);

	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.state = "Playing Raiderz Legend";
	discordPresence.details = "In Login Screen";
	discordPresence.startTimestamp = (int64_t)ctime;
	//discordPresence.endTimestamp = NULL;
	discordPresence.largeImageKey = "icon_raiderz";
	discordPresence.largeImageText = "Raiderz Legend";
	discordPresence.smallImageKey = "icon_defender";
	discordPresence.smallImageText = "defender";
	discordPresence.partyId = "ae488379-351d-4a4f-ad32-2b9b01c91657";
	//discordPresence.partySize = 1;
	//discordPresence.partyMax = 5;
	//discordPresence.joinSecret = "MTI4NzM0OjFpMmhuZToxMjMxMjM= ";

	return discordPresence;
}


bool UpdateRcp(DiscordRichPresence* dRcp)
{
	char log[1024] = "";
	
	CRcp.Update();
	
	dRcp->state = CRcp.state;
	dRcp->details = CRcp.details;
	dRcp->smallImageKey = CRcp.smallImageKey;
	dRcp->smallImageText = CRcp.smallImageText;
	return true;

}
void LOG(char* str)
{
	char* filename = "LegendRCP.txt";
	FILE* arq = fopen(filename, "a+");

	if (!arq) {
		arq = fopen(filename, "w+");
	}

	if (arq)
	{
		fprintf(arq, "%s\n", str);
		fclose(arq);
	}
}
int InitAplication()
{
	DiscordRichPresence dRcp;
	DWORD PID = 0;
	char log[1024] = "";

	Init();
	dRcp = CreateRCP();
	while (true) {
		
		UpdateRcp(&dRcp);
		/*sprintf(log,"atualizou rcp");
		LOG(log);
		sprintf(log, "login: %s, %s, %s, %s, %s, %s, %s", login,dRcp.details, dRcp.state, dRcp.largeImageKey, dRcp.largeImageKey, dRcp.smallImageKey, dRcp.smallImageText);
		LOG(log);*/
		Discord_UpdatePresence(&dRcp);
		Discord_RunCallbacks();
			
		Sleep(3000);
	}
	return 0;
}