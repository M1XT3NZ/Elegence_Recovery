#pragma once
#include <iostream> 
#include <string>
#include "Math.h"
#include "stdafx.h"
#include "script.h"

extern enum SubMenus;


enum eKeys
{
	KEY_EXIT,
	KEY_MENU,
	KEY_MENU_UP,
	KEY_MENU_DOWN,
	KEY_MENU_LEFT,
	KEY_MENU_RIGHT,
	KEY_MENU_SELECT,
	KEY_MENU_BACK,
	KEY_MENU_TAB_NEXT,
	KEY_MENU_TAB_PREV,
	KEY_MENU_SAVE,
	KEY_HOT_TELEPORT,
	KEY_HOT_NOCLIP,
	KEY_HOT_EDITOR,
	KEY_HOT_HEALTH,
	KEY_SUPERRUN,
	KEY_NOCLIP_FORWARD,
	KEY_NOCLIP_BACK,
	KEY_NOCLIP_LEFT,
	KEY_NOCLIP_RIGHT,
	KEY_NOCLIP_UP,
	KEY_NOCLIP_DOWN,
	KEY_EDITOR_ACTION,
	KEY_EDITOR_DELETE,
	KEYS_END
};











typedef struct VECTOR2 {
	float x, y;
};
typedef struct VECTOR2_2 {
	float w, h;
};
typedef struct RGBAF {
	int r, g, b, a, f;
};
typedef struct RGBA {
	int r, g, b, a;
};
typedef struct RGB {
	int r, g, b;
};

static fpFileRegister file_register = (fpFileRegister)(Memory::pattern("48 89 5C 24 ? 48 89 6C 24 ? 48 89 7C 24 ? 41 54 41 56 41 57 48 83 EC 50 48 8B EA 4C 8B FA 48 8B D9 4D 85 C9").count(1).get(0).get<decltype(file_register)>());

bool FileExists(const std::string& fileName)
{
	struct stat buffer;
	return (stat(fileName.c_str(), &buffer) == 0);
}
void xD()
{
	std::string path = "Elegence/";
	std::string name = "Elegence.ytd";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath))
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
}

/*


namespace MenuVariables {


	extern float MenuXCoord;
}
*/

class Menu {



public:


	static void Text(char* text, int font, float x, float y, float scaleX, float scaleY, int red, int green, int blue, int alpha, bool center);
	static void Texture(char* streamedTexture, char* textureName, float x, float y, float width, float height, float rotation, int red, int green, int blue, int alpha);

	static bool				m_bFgWnd;
	static bool initialze(std::string szIniDir, std::string szIniName);
	static void Title(char* tittle);
	static void SubTitle(char* subTitle);
	static void AddSmallInfo(char* text, short line);
	static bool Option(char* option);
	static bool Option2(char* option);
	static bool OptionBrk(char* option);
	static void Text2(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center, bool rightAlign = false, bool outline = true);
	static void AddSmallInfo2(char* text, short line);
	//static bool ToggleOption(char* option, bool *toggle);
	static bool ToggleOption(char * option, bool *toggle);
	static void Rect6(RGBA rgba, VECTOR2 position, VECTOR2_2 size);
	static void AddSmallTitle(char* text);


	


	static bool IntOption(char* option, int* var, int changeBy, int minimumValue, int maximumValue);
	static bool FloatOption(char* option, float* var, float changeBy, float minimumValue, float maximumValue);
	static void PlayerOption(char* option, int playerNumber, int* selecterPlayer, char** holdName);
	static void TeleportOptionC(char* option, float x, float y, float z);
	static void Submenu(char* option, char* menuName);

	static void SetActiveSubmenu(char* menu, int pos);
	static void MenuBack();
	static void ChangeSubmenu(char* newMenuName);
	static void EndMenu();

	static void AboveMapNotification(char* message, BOOL blink);

	static void MenuSounds(char* soundName, char* soundDict);

	static bool HasEnteredNewMenu();
	static void SetOptionCount(int count);
	static char* GetOwnerSubAtPos(int pos); // position is the number of submenus in. For example MainMenu = pos 0; Player Menu = 1; because its 
	static char* GetActiveMenu();
	static bool IsOptionPressed();
	static int GetCurrentOption();
	static bool HasBeenOpened();
	static bool IsMenuOpen();

	


	static void MenuControls();
	//static void LoadInfoplayer(char * playerName, Player p);








};




namespace MenuVariables {

	bool OptionsCenter = true;
	//float MenuXCoord = 0.850f; // old = 0.850
	extern int maxVisOptions;

};
namespace settings
{
	extern RGBAF count;
	extern RGBA optionRect;
	extern bool DrawTextOutline;
	extern int titleRectTexture;
	extern RGBAF titleText;
	extern RGBA titleRect;
	extern RGBAF breakText;
	extern RGBAF optionText;
	extern RGBA selectedText;
	extern RGBAF arrow;
	extern RGBAF integre;
	extern RGBA scroller;
	extern RGBA line;
	extern RGBA primary;
	extern RGBA secondary;
	extern RGBAF menunameText;
	extern RGBAF subnameText;
	extern RGBAF selectedTextClrs;
	extern RGBA titleEnd;
	extern RGBA headerRect;
	extern float menuX;
	extern float menuXscale;
	extern float checkBoxPos;
}
float MenuXCoord = 0.850f; // old = 0.850







int MenuVariables::maxVisOptions = 16;
//Titlebox
int TitleBoxRed = 255;
int TitleBoxGreen = 255;
int TitleBoxBlue = 255;
int TitleBoxALPHA = 255;
bool TitleCenter = true;

//TittleText
int TitleTextRed = 255;
int TitleTextGreen = 255;
int TitleTextBlue = 255;
int TitleTextALPHA = 255;
int TitleFont = 7;
int SubTitleFont = 7;


//Background
int BackgroundRed = 255;
int BackgroundGreen = 255;
int BackgroundBlue = 255;
int BackgroundALPHA = 255;
//options
int OptionsRed = 255;
int OptionsGreen = 255;
int OptionsBlue = 255;
int OptionsALPHA = 255;
float OptionsScale = 0.5f;
int OptionsFont = 6;
//Pausa
int OptionsRedBrk = 255;
int OptionsGreenBrk = 255;
int OptionsBlueBrk = 255;
int OptionsALPHABrk = 255;
float OptionsScaleBrk = 0.5f;
int OptionsFontBrk = 6;

//Scroller
int ScrollerRed = 160;
int ScrollerGreen = 160;
int ScrollerBlue = 160;
int ScrollerALPHA = 190;
//Menu
float MenuWidth = 0.22f;
int OptionCount = 0;
int CurrentOption = 1;
int LastOption[100];
int MenuLevel = 0;
/////////////////////
bool NewMenu = false;
///////////////////////////////
char* CurrentMenu;
char* LastMenu[100];
bool MenuOpen = false;
bool MenuHasBeenOpened = false;
bool OptionPressed = false;
bool LeftPressed = false;
bool RightPressed = false;
bool LeftRightOption = false;
bool KeyPressed = false;
bool AutoScroll = false;
int AutoScrollKeyNumber = 0;
static int DelayTime_AutoScroll = 25;
DWORD UpdateTime_AutoScroll;


void Menu::Text(char* text, int font, float x, float y, float scaleX, float scaleY, int red, int green, int blue, int alpha, bool center) {

	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scaleX, scaleY);
	UI::SET_TEXT_COLOUR(red, green, blue, alpha);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_OUTLINE();
	UI::_SET_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	UI::_DRAW_TEXT(x, y);
}
void Menu::Texture(char* streamedTexture, char* textureName, float x, float y, float width, float height, float rotation, int red, int green, int blue, int alpha) {



	if (GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(streamedTexture))
		GRAPHICS::DRAW_SPRITE(streamedTexture, textureName, x, y, width, height, rotation, red, green, blue, alpha);
	else
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(streamedTexture, false);

}

bool settings::DrawTextOutline = false;
void Menu::Text2(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center, bool rightAlign, bool outline)
{
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_COLOUR(rgbaf.r, rgbaf.g, rgbaf.b, rgbaf.a);
	UI::SET_TEXT_FONT(rgbaf.f);
	UI::SET_TEXT_SCALE(size.w, size.h);
	if (outline&& settings::DrawTextOutline) {
		UI::SET_TEXT_DROPSHADOW(1, 0, 0, 0, 0);
		UI::SET_TEXT_EDGE(1, 0, 0, 0, 0);
		UI::SET_TEXT_OUTLINE();
	}
	if (rightAlign) {
		UI::SET_TEXT_RIGHT_JUSTIFY(TRUE);
		UI::SET_TEXT_WRAP(MenuXCoord, MenuXCoord + 0.085f);//0.078f);
	}
	UI::_SET_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)text);
	UI::_DRAW_TEXT(position.x, position.y);
}





RGBAF settings::count{ 255, 255, 255, 255, 6 };
RGBA settings::titleRect{ 255, 255, 255, 255 };
RGBAF settings::titleText{ 0, 0, 0, 0, 0 };

void Menu::AddSmallInfo(char* text, short line)
{
	if (MenuXCoord < 0.78f)
	{
		if (line == 1) {

			GRAPHICS::DRAW_RECT(MenuXCoord, (((OptionCount * 0.035f) / 2) + 0.159f), MenuWidth, (OptionCount * 0.035f), BackgroundRed, BackgroundGreen, BackgroundBlue, BackgroundALPHA);
		}		
		Menu::Text2(text, settings::count, { MenuXCoord + 0.120f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1) {
			GRAPHICS::DRAW_RECT(MenuXCoord, (((OptionCount * 0.035f) / 2) + 0.159f), MenuWidth, (OptionCount * 0.035f), BackgroundRed, BackgroundGreen, BackgroundBlue, BackgroundALPHA);
		}
		Menu::Text2(text, settings::count, { MenuXCoord - 0.228f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
}
void Menu::Rect6(RGBA rgba, VECTOR2 position, VECTOR2_2 size)
{
	GRAPHICS::DRAW_RECT(position.x, position.y, size.w, size.h, rgba.r, rgba.g, rgba.b, rgba.a);
}
/*
void Menu::AddSmallInfo2(char* text, short line)
{
	if (MenuXCoord < 0.78f)
	{
		if (line == 1) {
			Rect6(settings::optionRect, { MenuXCoord + 0.175f, ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
		}
		Menu::Text2(text, settings::count, { MenuXCoord + 0.120f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1) {
			Rect6(settings::optionRect, { MenuXCoord - 0.175f, ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
		}
		Menu::Text2(text, settings::count, { MenuXCoord - 0.228f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
}
*/
void Menu::AddSmallTitle(char* text)
{
	if (MenuXCoord < 0.78f)
	{
		Menu::Text2(text, settings::titleText, { MenuXCoord + 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
		Texture("CommonMenu", "", MenuXCoord - 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 0, settings::titleRect.r, settings::titleRect.g, settings::titleRect.b, settings::titleRect.a);
		//Texture("Elegence", "elegence", MenuXCoord + 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 0, settings::titleRect.r, settings::titleRect.g, settings::titleRect.b, settings::titleRect.a);
	}
	else
	{
		Menu::Text2(text, settings::titleText, { MenuXCoord - 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
		Texture("CommonMenu", "", MenuXCoord - 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 0, settings::titleRect.r, settings::titleRect.g, settings::titleRect.b, settings::titleRect.a);
		//Texture("Elegence", "elegence", MenuXCoord - 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 0, settings::titleRect.r, settings::titleRect.g, settings::titleRect.b, settings::titleRect.a);
	}
}
























void notify_above_map(const std::string& text)
{
	UI::SET_TEXT_OUTLINE();
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(const_cast<char*>(text.c_str()));
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_FACEBOOK", "CHAR_FACEBOOK", 1, 7, "~b~Revenge! Menu", "~c~Welcome", 1, "___GTA*", 9);
	UI::_DRAW_NOTIFICATION(true, false);

}


void Menu::Title(char* Tittle) {

	Text(Tittle, TitleFont, MenuXCoord, 0.09f, 0.80f, 0.80f, TitleTextRed, TitleTextGreen, TitleTextBlue, TitleTextALPHA, TitleCenter); // if needed this can be changed to title x coords
	//Texture("CommonMenu", "interaction_bgd", MenuXCoord, 0.1175f, MenuWidth, 0.085f, 180, TitleBoxRed, TitleBoxGreen, TitleBoxBlue, TitleBoxALPHA);
	Texture("Elegence", "elegence", MenuXCoord, 0.1175f, MenuWidth, 0.085f, 0, TitleBoxRed, TitleBoxGreen, TitleBoxBlue, TitleBoxALPHA);

	if (NewMenu) {
		OptionCount = 0;
		NewMenu = false;
	}

}
void Menu::SubTitle(char* SubTitle) {

	Text(SubTitle, 6, MenuXCoord, 0.132f, 0.50f, 0.40f, TitleTextRed, TitleTextGreen, TitleTextBlue, TitleTextALPHA, TitleCenter);
}
bool Menu::Option(char* Option) {

	OptionCount++;
	if (CurrentOption <= 16 && OptionCount <= 16) {
		if (MenuVariables::OptionsCenter)
			Text(Option, OptionsFont, MenuXCoord, (OptionCount * 0.035f + 0.125f), OptionsScale, OptionsScale, OptionsRed, OptionsGreen, OptionsBlue, OptionsALPHA, true);
		else
			Text(Option, OptionsFont, (MenuXCoord - 0.1f), (OptionCount * 0.035f + 0.125f), OptionsScale, OptionsScale, OptionsRed, OptionsGreen, OptionsBlue, OptionsALPHA, false);
	}
	else if ((OptionCount > (CurrentOption - 16)) && OptionCount <= CurrentOption) {
		if (MenuVariables::OptionsCenter)
			Text(Option, OptionsFont, MenuXCoord, ((OptionCount - (CurrentOption - 16)) * 0.035f + 0.125f), OptionsScale, OptionsScale, OptionsRed, OptionsGreen, OptionsBlue, OptionsALPHA, true);
		else
			Text(Option, OptionsFont, (MenuXCoord - 0.1f), ((OptionCount - (CurrentOption - 16)) * 0.035f + 0.125f), OptionsScale, OptionsScale, OptionsRed, OptionsGreen, OptionsBlue, OptionsALPHA, false);
	}
	if (CurrentOption == OptionCount && OptionPressed) {
		return true;
	}

	else
		return false;
}

bool Menu::OptionBrk(char* Option)
{

	OptionCount++;
	if (CurrentOption <= 16 && OptionCount <= 16) {

		if (MenuVariables::OptionsCenter)
			Text(Option, OptionsFontBrk, MenuXCoord, (OptionCount * 0.035f + 0.125f), OptionsScaleBrk, OptionsScaleBrk, OptionsRedBrk, OptionsGreenBrk, OptionsBlueBrk, OptionsALPHABrk, true);
		else
			Text(Option, OptionsFontBrk, (MenuXCoord - 0.1f), (OptionCount * 0.035f + 0.125f), OptionsScaleBrk, OptionsScaleBrk, OptionsRedBrk, OptionsGreenBrk, OptionsBlueBrk, OptionsALPHABrk, false);
	}

	else if ((OptionCount > (CurrentOption - 16)) && OptionCount <= CurrentOption) {
		if (MenuVariables::OptionsCenter)
			Text(Option, OptionsFontBrk, MenuXCoord, ((OptionCount - (CurrentOption - 16)) * 0.035f + 0.125f), OptionsScaleBrk, OptionsScaleBrk, OptionsRedBrk, OptionsGreenBrk, OptionsBlueBrk, OptionsALPHABrk, true);
		else
			Text(Option, OptionsFontBrk, (MenuXCoord - 0.1f), ((OptionCount - (CurrentOption - 16)) * 0.035f + 0.125f), OptionsScaleBrk, OptionsScaleBrk, OptionsRedBrk, OptionsGreenBrk, OptionsBlueBrk, OptionsALPHABrk, false);
	}





	if (CurrentOption == OptionCount && OptionPressed) {
		return true;
	}

	else
		return false;

}
bool Menu::ToggleOption(char * option, bool *toggle) {


	bool ToggleBool = Option(option);

	if (CurrentOption <= 16 && OptionCount <= 16)
		Text((*toggle ? "~g~ON" : "~r~OFF"), OptionsFont, (MenuXCoord + 0.08f), (OptionCount * 0.035f + 0.125f), OptionsScale, OptionsScale, OptionsRed, OptionsGreen, OptionsBlue, OptionsALPHA, false);
	else if ((OptionCount > (CurrentOption - 16)) && OptionCount <= CurrentOption)
		Text((*toggle ? "~g~ON" : "~r~OFF"), OptionsFont, (MenuXCoord + 0.08f), ((OptionCount - (CurrentOption - 16)) * 0.035f + 0.125f), OptionsScale, OptionsScale, OptionsRed, OptionsGreen, OptionsBlue, OptionsALPHA, false);


	if (ToggleBool) {
		if (*toggle)
			*toggle = false;
		else if (*toggle == false)
			*toggle = true;
		return true;
	}

	return false;
	
}

bool Menu::IntOption(char* option, int* var, int changeBy, int minimumValue, int maximumValue) {

	LeftRightOption = true;
	bool Pressed = Option(option);

	char buff[40];
	_snprintf_s(buff, sizeof(buff), "%i", *var);
	if (CurrentOption <= 16 && OptionCount <= 16)
		Text(buff, OptionsFont, (MenuXCoord + 0.08f), (OptionCount * 0.035f + 0.125f), OptionsScale, OptionsScale, OptionsRed, OptionsGreen, OptionsBlue, OptionsALPHA, false);
	else if ((OptionCount > (CurrentOption - 16)) && OptionCount <= CurrentOption)
		Text(buff, OptionsFont, (MenuXCoord + 0.08f), ((OptionCount - (CurrentOption - 16)) * 0.035f + 0.125f), OptionsScale, OptionsScale, OptionsRed, OptionsGreen, OptionsBlue, OptionsALPHA, false);

	if (CurrentOption == OptionCount) {

		if (RightPressed) {
			if (*var >= maximumValue)
				*var = minimumValue;
			else
				*var = *var + changeBy;
			RightPressed = false;
		}

		if (LeftPressed) {
			if (*var <= minimumValue)
				*var = maximumValue;
			else
				*var = *var - changeBy;
			LeftPressed = false;
		}
	}

	if (Pressed)
		return true;
	return false;
}
bool Menu::FloatOption(char* option, float* var, float changeBy, float minimumValue, float maximumValue) {

	LeftRightOption = true;
	bool Pressed = Option(option);

	char buff[40];
	_snprintf_s(buff, sizeof(buff), "%.2f", *var);
	if (CurrentOption <= 16 && OptionCount <= 16)
		Text(buff, OptionsFont, (MenuXCoord + 0.08f), (OptionCount * 0.035f + 0.125f), OptionsScale, OptionsScale, OptionsRed, OptionsGreen, OptionsBlue, OptionsALPHA, false);
	else if ((OptionCount > (CurrentOption - 16)) && OptionCount <= CurrentOption)
		Text(buff, OptionsFont, (MenuXCoord + 0.08f), ((OptionCount - (CurrentOption - 16)) * 0.035f + 0.125f), OptionsScale, OptionsScale, OptionsRed, OptionsGreen, OptionsBlue, OptionsALPHA, false);

	if (CurrentOption == OptionCount) {

		if (RightPressed) {
			if (*var >= maximumValue)
				*var = minimumValue;
			else
				*var = *var + changeBy;
			RightPressed = false;
		}

		if (LeftPressed) {
			if (*var <= minimumValue)
				*var = maximumValue;
			else
				*var = *var - changeBy;
			LeftPressed = false;
		}
	}

	if (Pressed)
		return true;
	return false;
}



void Menu::PlayerOption(char* option, int playerNumber, int* selecterPlayer, char** holdName) {

	//char buff[38];
	//_snprintf_s(buff, sizeof(buff), "%s   ~r~->", option);


	bool CallChange = Option(option);

	if (CurrentOption <= 16 && OptionCount <= 16)
		Text("~b~>", OptionsFont, (MenuXCoord + 0.08f), (OptionCount * 0.035f + 0.125f), OptionsScale, OptionsScale, OptionsRed, OptionsGreen, OptionsBlue, OptionsALPHA, false);
		//Texture("Elegence", "arrow_right", (MenuXCoord + 0.08f), (OptionCount * 0.035f + 0.125f), OptionsScale, OptionsScale, OptionsRed, OptionsGreen, OptionsBlue, OptionsALPHA, false);
	else if ((OptionCount > (CurrentOption - 16)) && OptionCount <= CurrentOption)
		Text("~b~>", OptionsFont, (MenuXCoord + 0.08f), ((OptionCount - (CurrentOption - 16)) * 0.035f + 0.125f), OptionsScale, OptionsScale, OptionsRed, OptionsGreen, OptionsBlue, OptionsALPHA, false);
		//Texture("Elegence", "arrow_right", (MenuXCoord + 0.08f), ((OptionCount - (CurrentOption - 16)) * 0.035f + 0.125f), OptionsScale, OptionsScale, OptionsRed, OptionsGreen, OptionsBlue, OptionsALPHA, false);
	if (CallChange) {
		*selecterPlayer = playerNumber;
		*holdName = option;
		//ChangeSubmenu("PlayerOptions");
	}
}
namespace MenuLevelHandler {
	void MoveMenu(SubMenus menu);
}





#define playerPed PLAYER::PLAYER_PED_ID()
void Menu::TeleportOptionC(char* option, float x, float y, float z) {

	if (Option(option)) {
		if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, FALSE))
			ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_USING(playerPed), x, y, z, TRUE, FALSE, FALSE, TRUE);
		else
			ENTITY::SET_ENTITY_COORDS(playerPed, x, y, z, TRUE, FALSE, FALSE, TRUE);
	}
}
void Menu::Submenu(char* option, char* menuName) {

	//char buff[38];
	//_snprintf_s(buff, sizeof(buff), "%s   ~r~->", option);

	bool CallChange = Option(option);

	if (CurrentOption <= 16 && OptionCount <= 16)
		Text("~r~>~w~>", OptionsFont, (MenuXCoord + 0.08f), (OptionCount * 0.035f + 0.125f), OptionsScale, OptionsScale, OptionsRed, OptionsGreen, OptionsBlue, OptionsALPHA, false);
		
	else if ((OptionCount > (CurrentOption - 16)) && OptionCount <= CurrentOption)
		
		Text("~r~>~w~>", OptionsFont, (MenuXCoord + 0.08f), ((OptionCount - (CurrentOption - 16)) * 0.035f + 0.125f), OptionsScale, OptionsScale, OptionsRed, OptionsGreen, OptionsBlue, OptionsALPHA, false);

	if (CallChange)
		ChangeSubmenu(menuName);

}
void Menu::SetActiveSubmenu(char* menu, int pos) {

	NewMenu = true;
	CurrentMenu = menu;
	MenuLevel = pos;
	CurrentOption = 1;
}
void Menu::MenuBack() {
	NewMenu = true;
	MenuLevel--;
	CurrentOption = LastOption[MenuLevel];
	CurrentMenu = LastMenu[MenuLevel];
	LastMenu[MenuLevel] = ""; // dont need to do it for the option as it is just an int
}
void Menu::ChangeSubmenu(char* newMenuName) {

	NewMenu = true;
	OptionPressed = false;
	LastMenu[MenuLevel] = CurrentMenu;
	LastOption[MenuLevel] = CurrentOption;
	CurrentOption = 1;
	CurrentMenu = newMenuName;
	MenuLevel++;
}
void Menu::EndMenu() {


	if (OptionCount > 16) {

		Texture("mpentry", "birdsandbees_flat", MenuXCoord, (((16 * 0.035f) / 2) + 0.159f), MenuWidth, (16 * 0.035f), 0, BackgroundRed, BackgroundGreen, BackgroundBlue, BackgroundALPHA);
		//					GRAPHICS::DRAW_RECT(MenuXCoord, (((16 * 0.035f) / 2) + 0.159f), MenuWidth, (16 * 0.035f), BackgroundRed, BackgroundGreen, BackgroundBlue, BackgroundALPHA);
		if (CurrentOption > 16)
			Texture("mpentry", "birdsandbees_flat", MenuXCoord, ((16 * 0.035f) + 0.1415f), MenuWidth, 0.035f, 0, ScrollerRed, ScrollerGreen, ScrollerBlue, ScrollerALPHA);
		//					GRAPHICS::DRAW_RECT(MenuXCoord, ((16 * 0.035f) + 0.1415f), MenuWidth, 0.035f, ScrollerRed, ScrollerGreen, ScrollerBlue, ScrollerALPHA);
		else
			Texture("mpentry", "birdsandbees_flat", MenuXCoord, ((CurrentOption * 0.035f) + 0.1415f), MenuWidth, 0.035f, 0, ScrollerRed, ScrollerGreen, ScrollerBlue, ScrollerALPHA);
		//					GRAPHICS::DRAW_RECT(MenuXCoord, ((CurrentOption * 0.035f) + 0.1415f), MenuWidth, 0.035f, ScrollerRed, ScrollerGreen, ScrollerBlue, ScrollerALPHA);
	}

	else if (OptionCount > 0) {
		Texture("mpentry", "birdsandbees_flat", MenuXCoord, (((OptionCount * 0.035f) / 2) + 0.159f), MenuWidth, (OptionCount * 0.035f), 0, BackgroundRed, BackgroundGreen, BackgroundBlue, BackgroundALPHA);
		//GRAPHICS::DRAW_RECT(MenuXCoord, (((OptionCount * 0.035f) / 2) + 0.159f), MenuWidth, (OptionCount * 0.035f), BackgroundRed, BackgroundGreen, BackgroundBlue, BackgroundALPHA);
		GRAPHICS::DRAW_RECT(MenuXCoord, ((CurrentOption * 0.035f) + 0.1415f), MenuWidth, 0.035f, ScrollerRed, ScrollerGreen, ScrollerBlue, ScrollerALPHA);
	}
	char buff[38];
	_snprintf_s(buff, sizeof(buff), "%i / %i", CurrentOption, OptionCount);
	if (OptionCount > 16) {
		Text(buff, TitleFont, (MenuXCoord + 0.08f), (17 * 0.035f + 0.130f), 0.3f, 0.3f, TitleTextRed, TitleTextGreen, TitleTextBlue, TitleTextALPHA, TitleCenter);//(17 * 0.035f + 0.125f)
		Texture("CommonMenu", "interaction_bgd", MenuXCoord, (17 * 0.035f + 0.140f), MenuWidth, 0.035f, 0, TitleBoxRed, TitleBoxGreen, TitleBoxBlue, TitleBoxALPHA); // was interaction_bgd
	}
	else {
		Text(buff, TitleFont, (MenuXCoord + 0.08f), ((OptionCount + 1) * 0.035f + 0.130f), 0.3f, 0.3f, TitleTextRed, TitleTextGreen, TitleTextBlue, TitleTextALPHA, TitleCenter);
		Texture("CommonMenu", "interaction_bgd", MenuXCoord, ((OptionCount + 1) * 0.035f + 0.140f), MenuWidth, 0.035f, 0, TitleBoxRed, TitleBoxGreen, TitleBoxBlue, TitleBoxALPHA);
	}

	OptionPressed = false;
}




void Menu::AboveMapNotification(char* message, BOOL blink) {

	UI::SET_TEXT_OUTLINE();
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(&message[0u]);
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 7, "~b~Dev:", "~c~Welcome", 1, "___GTA*", 8);
	UI::_DRAW_NOTIFICATION(blink, FALSE);
}

void Menu::MenuSounds(char* soundName, char* soundDict) {
	AUDIO::PLAY_SOUND_FRONTEND(-1, soundName, soundDict, 0);
}
bool Menu::HasEnteredNewMenu() {
	return NewMenu;
}
void Menu::SetOptionCount(int count) {
	OptionCount = count;
}
char* Menu::GetOwnerSubAtPos(int pos) {

	return LastMenu[pos];
}
char* Menu::GetActiveMenu() {
	return CurrentMenu;
}
bool Menu::IsOptionPressed() {
	return OptionPressed;
}
int Menu::GetCurrentOption() {
	return CurrentOption;
}
bool Menu::HasBeenOpened() {
	return MenuHasBeenOpened;
}
bool Menu::IsMenuOpen() {
	return MenuOpen;
}












void ResetAutoScroll() {
	AutoScroll = false;
	KeyPressed = false;
	AutoScrollKeyNumber = 0;
	ResetKeyBoardTimer();
}
bool FirstOrLastOption(int keyNumber) {
	if (((CurrentOption - 1) < 1) && keyNumber == 8) {
		CurrentOption = OptionCount;
		return true;
	}
	if (((CurrentOption + 1) > OptionCount) && keyNumber == 2) {
		CurrentOption = 1;
		return true;
	}
	return false;
}
void SetAutoScrollActive(int scrollKey) {
	AutoScroll = true;
	AutoScrollKeyNumber = scrollKey;
}


//int Down = GetPrivateProfileInt("config", "Sleep", 1, INI_path);

//char *temp = iniReader.ReadString("config", "Sleep", 1, INI_path);




void Menu::MenuControls() {

	//CIniReader iniReader("keys.ini"); // Opens delmarker.ini
	//char *temp = iniReader.ReadString("config", "Down", "VK_NUMPAD5"); // Gets the key and stores it in a char
	//DWORD Sleep = strtol(Down, NULL, 0); // Converts the char into a DWORD



	int kk1 = VK_NUMPAD1;
	int kk2 = VK_NUMPAD2;
	int kk3 = VK_NUMPAD3;
	int kk4 = VK_NUMPAD4;
	int kk5 = VK_NUMPAD5;
	int kk6 = VK_NUMPAD6;
	int kk7 = VK_NUMPAD7;
	int kk8 = VK_NUMPAD8;
	int kk9 = VK_NUMPAD9;
	int kk0 = VK_NUMPAD0;

	
	if (KeyJustUp(VK_F12))
	{
		Hooking::Cleanup();
	}
			
		
	if (KeyJustUp(VK_F5)) {

		if (!MenuHasBeenOpened) {
			MenuHasBeenOpened = true;
			MenuSounds("Hack_Success", "DLC_HEIST_BIOLAB_PREP_HACKING_SOUNDS");
			MenuSounds("Mission_Pass_Notify", "DLC_HEISTS_GENERAL_FRONTEND_SOUNDS");

		}

		MenuOpen = !MenuOpen;

		if (MenuOpen) {
			OptionPressed = false;
			CurrentOption = 1;
			CurrentMenu = "MainMenu";
			MenuLevel = 0;
			MenuSounds("SELECT", "HUD_FRONTEND_DEFAULT_SOUNDSET");
			ResetAutoScroll();
		}

		else if (!MenuOpen)
			MenuSounds("BACK", "HUD_FRONTEND_DEFAULT_SOUNDSET");

	}

	if (MenuOpen) {

		if (KeyJustUp(VK_NUMPAD5) && !KeysPressed(5)) {
			OptionPressed = true;
			MenuSounds("SELECT", "HUD_FRONTEND_DEFAULT_SOUNDSET");
			AutoScroll = false;
			AutoScrollKeyNumber = 0;
		}

		if (KeyJustUp(VK_NUMPAD0)) { // dont need key check here

			if (CurrentMenu == "MainMenu")
				MenuOpen = false;

			else {
				AutoScroll = false;
				AutoScrollKeyNumber = 0;
				MenuBack();
			}

			MenuSounds("BACK", "HUD_FRONTEND_DEFAULT_SOUNDSET");
		}


		if (KeyDown(VK_NUMPAD8) && !KeysPressed(8)) {

			if (!KeyPressed) {
				KeyBoardTimer(400);
				KeyPressed = true;
				if (!FirstOrLastOption(8))
					CurrentOption--;
				MenuSounds("NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET");
			}

			if (KeyBoardTimerReady())
				SetAutoScrollActive(8);

		}

		if (KeyDown(VK_NUMPAD2) && !KeysPressed(2)) {

			if (!KeyPressed) {
				KeyBoardTimer(400);
				KeyPressed = true;
				if (!FirstOrLastOption(2))
					CurrentOption++;
				MenuSounds("NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET");
			}

			if (KeyBoardTimerReady())
				SetAutoScrollActive(2);
		}

		if (LeftRightOption) {

			if (KeyDown(VK_NUMPAD4) && !KeysPressed(4)) {

				if (!KeyPressed) {
					KeyBoardTimer(400);
					KeyPressed = true;
					LeftPressed = true;
					MenuSounds("NAV_LEFT_RIGHT", "HUD_FRONTEND_DEFAULT_SOUNDSET");
				}

				if (KeyBoardTimerReady())
					SetAutoScrollActive(4);
			}

			if (KeyDown(VK_NUMPAD6) && !KeysPressed(6)) {

				if (!KeyPressed) {
					KeyBoardTimer(400);
					KeyPressed = true;
					RightPressed = true;
					MenuSounds("NAV_LEFT_RIGHT", "HUD_FRONTEND_DEFAULT_SOUNDSET");
				}

				if (KeyBoardTimerReady())
					SetAutoScrollActive(6);
			}
		}

		if (KeyJustUp(VK_NUMPAD8) || KeyJustUp(VK_NUMPAD2) || KeyJustUp(VK_NUMPAD4) || KeyJustUp(VK_NUMPAD6))
			ResetAutoScroll();


		if (AutoScroll) {

			if (UpdateTime_AutoScroll + DelayTime_AutoScroll < GetTickCount()) {
				UpdateTime_AutoScroll = GetTickCount();

				if (AutoScrollKeyNumber == 8) {
					if (!FirstOrLastOption(8))
						CurrentOption--;
					MenuSounds("NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET");
				}

				if (AutoScrollKeyNumber == 2) {
					if (!FirstOrLastOption(2))
						CurrentOption++;
					MenuSounds("NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET");
				}

				if (AutoScrollKeyNumber == 4) {
					LeftPressed = true;
					MenuSounds("NAV_LEFT_RIGHT", "HUD_FRONTEND_DEFAULT_SOUNDSET");
				}

				if (AutoScrollKeyNumber == 6) {
					RightPressed = true;
					MenuSounds("NAV_LEFT_RIGHT", "HUD_FRONTEND_DEFAULT_SOUNDSET");
				}
			}

		}

	}

	if (LeftRightOption)
		LeftRightOption = false;



}

