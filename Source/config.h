#pragma once
#include "stdafx.h"

class config
{
public:
	config();
	~config();

	char boolbuffer[50];
	LPCSTR configDir = ("./config.ini");

	bool triggerbot = GetPrivateProfileInt("features", "triggerbot", 0, configDir);
	bool bunnyhop = GetPrivateProfileInt("features", "bunnyhop", 0, configDir);



	bool parser(char parse[]);
};