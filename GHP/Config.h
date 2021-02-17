#ifndef CONFIG_H
#define CONFIG_H

#define RCP_FILENAME "Data\\rcp.bin"
#define DFT_STATE "Playing Raiderz Legend"
#define DFT_DETAILS "In Login"
#define DFT_NULL_STR ""

class Config
{
    public:
        Config();
        void Update();
        virtual ~Config();
		char  state[256],
			  details[256],

			  smallImageKey[256],
			  smallImageText[256];
};

#endif // CONFIG_H
