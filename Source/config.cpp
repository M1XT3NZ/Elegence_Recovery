#include "stdafx.h"
#include "config.h"



config::config()
{
}


config::~config()
{
}

bool config::parser(char parse[])
{
	if (!strcmp(parse, "true")) {
		return true;
	}
	else
		return false;

}