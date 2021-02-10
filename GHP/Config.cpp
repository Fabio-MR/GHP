#include "Config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Config::Config():
	state(DFT_STATE),
	details(DFT_DETAILS),
	smallImageKey(DFT_NULL_STR),
	smallImageText(DFT_NULL_STR)
{
    Update();
}

void Config::Update()
{
    FILE* file = fopen(RCP_FILENAME, "r");
    char str[256];
    char *atrib, *param;

    if (file)
    {
        while(fgets(str, 256, file)!= NULL)
        {
            atrib = strtok(str, "=");
            param = strtok(NULL, "\"");

            if(strcmp("state", atrib) == 0) strcpy_s(state, param);
            else if(strcmp("details", atrib) == 0) strcpy_s(details, param);
            else if(strcmp("smallImageKey", atrib) == 0) strcpy_s(smallImageKey, param);
            else if(strcmp("smallImageText", atrib) == 0) strcpy_s(smallImageText, param);
        }
        fclose(file);
    }
	file = fopen(RCP_FILENAME, "w");
	if (file)
		fclose(file);
}

Config::~Config()
{
    //dtor
}
