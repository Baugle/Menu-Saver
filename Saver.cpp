#pragma once
#include <WinBase.h>
#include <cstdint>
#include <Types.hpp>
#include <ShlObj_core.h>
#include <string>
using namespace std;

//Position
static float PosX = 25.0;
static float PosY = 25.0;
//UI
static float UIWidth = 430.0;
static TCHAR Name[MAX_PATH] = "Baugle Menu VIP";
//Offsets
static float PaddingX = 7.0;
static float PaddingY = 11.0;
//Input
static int32_t  OpenDelay = 200;
static int32_t  BackDelay = 300;
static int32_t  EnterDelay = 300;
static int32_t  VerticalDelay = 120;
static int32_t  HorizontaDelay = 120;
//Header
static float HeaderHeight = 100.0;
static Color HeaderBackgroundColor = { 255,255,255,255 };
static Color HeaderTextColor = { 255,255,255,255 };
//SubmenuBar
static float SubmenuBarHeight = 45.0;
static Color SubmenuBarBackgroundColor = { 0,0,0,150 };
static Color SubmenuBarTextColor = { 255,255,255,255 };
//Options
static float OptionsHeight = 45.0;
static float RectWidth = 10.0;
static Color ToggleOnColor = { 130,214,157,255 };
static Color ToggleOffColor = { 200,55,80,255 };
static Color RectColor = { 94,94,94,180 };
static Color SelectedTextColor = { 0,0,0,255 };
static Color UnselectedTextColor = { 255,255,255,255 };
static Color SelectedBackgroundColor = { 255,255,255,255 };
static Color UnselectedBackgroundColor = { 0,0,0,120 };
//Footer
static float FooterHeight = 45.0;
static float SpriteSize = 0.025;
static Color BackgroundColor = { 0,0,0,150 };
static Color SpriteColor = { 255,255,255,255 };
static Color BaugleMenuVIP = { 248,200,220,255 };
//缓冲
static TCHAR Buffer[MAX_PATH] = { 0 };

static void ReadUIIni()
{
	char roamingPath[MAX_PATH];
	SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, roamingPath);
	string additionalPath = "\\Baugle\\UI.ini";
	string fullPath = string(roamingPath) + additionalPath;
	const char* CCFullPath = fullPath.c_str();


	GetPrivateProfileString("Position", // 配置项节名称
		"PosX", // 配置项名称
		"25.0", // 若指定的键不存在，该值作为读取的默认值
		Buffer, //  一个指向缓冲区的指针，接收读取的字符串
		MAX_PATH, // 上面那个缓冲区的大小
		CCFullPath); // 配置文件名
	PosX = stof(Buffer);

	GetPrivateProfileString("Position", "PosY", "25.0", Buffer, MAX_PATH, CCFullPath);
	PosY = stof(Buffer);

	GetPrivateProfileString("UI", "UIWidth", "430.0", Buffer, MAX_PATH, CCFullPath);
	UIWidth = stof(Buffer);

	GetPrivateProfileString("UI", "Name", "Baugle Menu VIP", Name, MAX_PATH, CCFullPath);

	GetPrivateProfileString("Offsets", "PaddingX", "7.0", Buffer, MAX_PATH, CCFullPath);
	PaddingX = stof(Buffer);

	GetPrivateProfileString("Offsets", "PaddingY", "11.0", Buffer, MAX_PATH, CCFullPath);
	PaddingY = stof(Buffer);

	GetPrivateProfileString("Input", "OpenDelay", "200", Buffer, MAX_PATH, CCFullPath);
	OpenDelay = stoi(Buffer);

	GetPrivateProfileString("Input", "BackDelay", "300", Buffer, MAX_PATH, CCFullPath);
	BackDelay = stoi(Buffer);

	GetPrivateProfileString("Input", "EnterDelat", "300", Buffer, MAX_PATH, CCFullPath);
	EnterDelay = stoi(Buffer);

	GetPrivateProfileString("Input", "VerticalDelat", "120", Buffer, MAX_PATH, CCFullPath);
	VerticalDelay = stoi(Buffer);

	GetPrivateProfileString("Input", "HorizontaDelay", "120", Buffer, MAX_PATH, CCFullPath);
	HorizontaDelay = stoi(Buffer);

	GetPrivateProfileString("Header", "HeaderHeight", "100.0", Buffer, MAX_PATH, CCFullPath);
	HeaderHeight = stof(Buffer);

	GetPrivateProfileString("Header", "HeaderBackgroundColorR", "255", Buffer, MAX_PATH, CCFullPath);
	HeaderBackgroundColor.r = stoi(Buffer);

	GetPrivateProfileString("Header", "HeaderBackgroundColorG", "255", Buffer, MAX_PATH, CCFullPath);
	HeaderBackgroundColor.g = stoi(Buffer);

	GetPrivateProfileString("Header", "HeaderBackgroundColorB", "255", Buffer, MAX_PATH, CCFullPath);
	HeaderBackgroundColor.b = stoi(Buffer);

	GetPrivateProfileString("Header", "HeaderBackgroundColorA", "255", Buffer, MAX_PATH, CCFullPath);
	HeaderBackgroundColor.a = stoi(Buffer);

	GetPrivateProfileString("Header", "HeaderTextColorR", "255", Buffer, MAX_PATH, CCFullPath);
	HeaderTextColor.r = stoi(Buffer);

	GetPrivateProfileString("Header", "HeaderTextColorG", "255", Buffer, MAX_PATH, CCFullPath);
	HeaderTextColor.g = stoi(Buffer);

	GetPrivateProfileString("Header", "HeaderTextColorB", "255", Buffer, MAX_PATH, CCFullPath);
	HeaderTextColor.b = stoi(Buffer);

	GetPrivateProfileString("Header", "HeaderTextColorA", "255", Buffer, MAX_PATH, CCFullPath);
	HeaderTextColor.a = stoi(Buffer);

	GetPrivateProfileString("SubmenuBar", "SubmenuBarHeight", "45.0", Buffer, MAX_PATH, CCFullPath);
	SubmenuBarHeight = stof(Buffer);

	GetPrivateProfileString("SubmenuBar", "SubmenuBarBackgroundColorR", "0", Buffer, MAX_PATH, CCFullPath);
	SubmenuBarBackgroundColor.r = stoi(Buffer);

	GetPrivateProfileString("SubmenuBar", "SubmenuBarBackgroundColorG", "0", Buffer, MAX_PATH, CCFullPath);
	SubmenuBarBackgroundColor.g = stoi(Buffer);

	GetPrivateProfileString("SubmenuBar", "SubmenuBarBackgroundColorB", "0", Buffer, MAX_PATH, CCFullPath);
	SubmenuBarBackgroundColor.b = stoi(Buffer);

	GetPrivateProfileString("SubmenuBar", "SubmenuBarBackgroundColorA", "150", Buffer, MAX_PATH, CCFullPath);
	SubmenuBarBackgroundColor.a = stoi(Buffer);

	GetPrivateProfileString("SubmenuBar", "SubmenuBarTextColorR", "255", Buffer, MAX_PATH, CCFullPath);
	SubmenuBarTextColor.r = stoi(Buffer);

	GetPrivateProfileString("SubmenuBar", "SubmenuBarTextColorG", "255", Buffer, MAX_PATH, CCFullPath);
	SubmenuBarTextColor.g = stoi(Buffer);

	GetPrivateProfileString("SubmenuBar", "SubmenuBarTextColorB", "255", Buffer, MAX_PATH, CCFullPath);
	SubmenuBarTextColor.b = stoi(Buffer);

	GetPrivateProfileString("SubmenuBar", "SubmenuBarTextColorA", "255", Buffer, MAX_PATH, CCFullPath);
	SubmenuBarTextColor.a = stoi(Buffer);

	GetPrivateProfileString("Options", "OptionsHeight", "45.0", Buffer, MAX_PATH, CCFullPath);
	OptionsHeight = stof(Buffer);

	GetPrivateProfileString("Options", "RectWidth", "10.0", Buffer, MAX_PATH, CCFullPath);
	RectWidth = stof(Buffer);

	GetPrivateProfileString("Options", "ToggleOnColorR", "130", Buffer, MAX_PATH, CCFullPath);
	ToggleOnColor.r = stoi(Buffer);

	GetPrivateProfileString("Options", "ToggleOnColorG", "214", Buffer, MAX_PATH, CCFullPath);
	ToggleOnColor.g = stoi(Buffer);

	GetPrivateProfileString("Options", "ToggleOnColorB", "157", Buffer, MAX_PATH, CCFullPath);
	ToggleOnColor.b = stoi(Buffer);

	GetPrivateProfileString("Options", "ToggleOnColorA", "255", Buffer, MAX_PATH, CCFullPath);
	ToggleOnColor.a = stoi(Buffer);

	GetPrivateProfileString("Options", "ToggleOffColorR", "200", Buffer, MAX_PATH, CCFullPath);
	ToggleOffColor.r = stoi(Buffer);

	GetPrivateProfileString("Options", "ToggleOffColorG", "55", Buffer, MAX_PATH, CCFullPath);
	ToggleOffColor.g = stoi(Buffer);

	GetPrivateProfileString("Options", "ToggleOffColorB", "80", Buffer, MAX_PATH, CCFullPath);
	ToggleOffColor.b = stoi(Buffer);

	GetPrivateProfileString("Options", "ToggleOffColorA", "255", Buffer, MAX_PATH, CCFullPath);
	ToggleOffColor.a = stoi(Buffer);

	GetPrivateProfileString("Options", "RectColorR", "94", Buffer, MAX_PATH, CCFullPath);
	RectColor.r = stoi(Buffer);

	GetPrivateProfileString("Options", "RectColorG", "94", Buffer, MAX_PATH, CCFullPath);
	RectColor.g = stoi(Buffer);

	GetPrivateProfileString("Options", "RectColorB", "94", Buffer, MAX_PATH, CCFullPath);
	RectColor.b = stoi(Buffer);

	GetPrivateProfileString("Options", "RectColorA", "180", Buffer, MAX_PATH, CCFullPath);
	RectColor.a = stoi(Buffer);

	GetPrivateProfileString("Options", "SelectedTextColorR", "0", Buffer, MAX_PATH, CCFullPath);
	SelectedTextColor.r = stoi(Buffer);

	GetPrivateProfileString("Options", "SelectedTextColorG", "0", Buffer, MAX_PATH, CCFullPath);
	SelectedTextColor.g = stoi(Buffer);

	GetPrivateProfileString("Options", "SelectedTextColorB", "0", Buffer, MAX_PATH, CCFullPath);
	SelectedTextColor.b = stoi(Buffer);

	GetPrivateProfileString("Options", "SelectedTextColorA", "255", Buffer, MAX_PATH, CCFullPath);
	SelectedTextColor.a = stoi(Buffer);

	GetPrivateProfileString("Options", "UnselectedTextColorR", "255", Buffer, MAX_PATH, CCFullPath);
	UnselectedTextColor.r = stoi(Buffer);

	GetPrivateProfileString("Options", "UnselectedTextColorG", "255", Buffer, MAX_PATH, CCFullPath);
	UnselectedTextColor.g = stoi(Buffer);

	GetPrivateProfileString("Options", "UnselectedTextColorB", "255", Buffer, MAX_PATH, CCFullPath);
	UnselectedTextColor.b = stoi(Buffer);

	GetPrivateProfileString("Options", "UnselectedTextColorA", "255", Buffer, MAX_PATH, CCFullPath);
	UnselectedTextColor.a = stoi(Buffer);

	GetPrivateProfileString("Options", "SelectedBackgroundColorR", "255", Buffer, MAX_PATH, CCFullPath);
	SelectedBackgroundColor.r = stoi(Buffer);

	GetPrivateProfileString("Options", "SelectedBackgroundColorB", "255", Buffer, MAX_PATH, CCFullPath);
	SelectedBackgroundColor.g = stoi(Buffer);

	GetPrivateProfileString("Options", "SelectedBackgroundColorG", "255", Buffer, MAX_PATH, CCFullPath);
	SelectedBackgroundColor.b = stoi(Buffer);

	GetPrivateProfileString("Options", "SelectedBackgroundColorA", "255", Buffer, MAX_PATH, CCFullPath);
	SelectedBackgroundColor.a = stoi(Buffer);

	GetPrivateProfileString("Options", "UnselectedBackgroundColorR", "0", Buffer, MAX_PATH, CCFullPath);
	UnselectedBackgroundColor.r = stoi(Buffer);

	GetPrivateProfileString("Options", "UnselectedBackgroundColorG", "0", Buffer, MAX_PATH, CCFullPath);
	UnselectedBackgroundColor.g = stoi(Buffer);

	GetPrivateProfileString("Options", "UnselectedBackgroundColorB", "0", Buffer, MAX_PATH, CCFullPath);
	UnselectedBackgroundColor.b = stoi(Buffer);

	GetPrivateProfileString("Options", "UnselectedBackgroundColorA", "120", Buffer, MAX_PATH, CCFullPath);
	UnselectedBackgroundColor.a = stoi(Buffer);

	GetPrivateProfileString("Footer", "FooterHeight", "45.0", Buffer, MAX_PATH, CCFullPath);
	FooterHeight = stof(Buffer);

	GetPrivateProfileString("Footer", "SpriteSize", "0.025", Buffer, MAX_PATH, CCFullPath);
	SpriteSize = stof(Buffer);

	GetPrivateProfileString("Footer", "BackgroundColorR", "0", Buffer, MAX_PATH, CCFullPath);
	BackgroundColor.r = stoi(Buffer);

	GetPrivateProfileString("Footer", "BackgroundColorG", "0", Buffer, MAX_PATH, CCFullPath);
	BackgroundColor.g = stoi(Buffer);

	GetPrivateProfileString("Footer", "BackgroundColorB", "0", Buffer, MAX_PATH, CCFullPath);
	BackgroundColor.b = stoi(Buffer);

	GetPrivateProfileString("Footer", "BackgroundColorA", "150", Buffer, MAX_PATH, CCFullPath);
	BackgroundColor.a = stoi(Buffer);

	GetPrivateProfileString("Footer", "SpriteColorR", "255", Buffer, MAX_PATH, CCFullPath);
	SpriteColor.r = stoi(Buffer);

	GetPrivateProfileString("Footer", "SpriteColorG", "255", Buffer, MAX_PATH, CCFullPath);
	SpriteColor.g = stoi(Buffer);

	GetPrivateProfileString("Footer", "SpriteColorB", "255", Buffer, MAX_PATH, CCFullPath);
	SpriteColor.b = stoi(Buffer);

	GetPrivateProfileString("Footer", "SpriteColorA", "255", Buffer, MAX_PATH, CCFullPath);
	SpriteColor.a = stoi(Buffer);

	GetPrivateProfileString("Footer", "BaugleMenuVIPR", "248", Buffer, MAX_PATH, CCFullPath);
	BaugleMenuVIP.r = stoi(Buffer);

	GetPrivateProfileString("Footer", "BaugleMenuVIPG", "200", Buffer, MAX_PATH, CCFullPath);
	BaugleMenuVIP.g = stoi(Buffer);

	GetPrivateProfileString("Footer", "BaugleMenuVIPB", "220", Buffer, MAX_PATH, CCFullPath);
	BaugleMenuVIP.b = stoi(Buffer);

	GetPrivateProfileString("Footer", "BaugleMenuVIPA", "255", Buffer, MAX_PATH, CCFullPath);
	BaugleMenuVIP.a = stoi(Buffer);


}

static void SaveDefultIni()
{
	char roamingPath[MAX_PATH];
	SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, roamingPath);
	string additionalPath = "\\Baugle\\UI.ini";
	string fullPath = string(roamingPath) + additionalPath;
	const char* CCFullPath = fullPath.c_str();

	// 写配置项
	WritePrivateProfileString("Position",  // 节名称
		"PosX", // 配置项名称
		to_string(PosX).c_str(), // 欲写入的值
		CCFullPath); // 配置文件名

	WritePrivateProfileString("Position", "PosY", to_string(PosY).c_str(), CCFullPath);

	WritePrivateProfileString("UI", "UIWidth", to_string(UIWidth).c_str(), CCFullPath);
	WritePrivateProfileString("UI", "Name", Name, CCFullPath);

	WritePrivateProfileString("Offsets", "PaddingX", to_string(PaddingX).c_str(), CCFullPath);
	WritePrivateProfileString("Offsets", "PaddingY", to_string(PaddingY).c_str(), CCFullPath);

	WritePrivateProfileString("Input", "UIWidth", to_string(OpenDelay).c_str(), CCFullPath);
	WritePrivateProfileString("Input", "UIWidth", to_string(BackDelay).c_str(), CCFullPath);
	WritePrivateProfileString("Input", "UIWidth", to_string(EnterDelay).c_str(), CCFullPath);
	WritePrivateProfileString("Input", "UIWidth", to_string(VerticalDelay).c_str(), CCFullPath);
	WritePrivateProfileString("Input", "UIWidth", to_string(HorizontaDelay).c_str(), CCFullPath);

	WritePrivateProfileString("Header", "HeaderHeight", to_string(HeaderHeight).c_str(), CCFullPath);
	WritePrivateProfileString("Header", "HeaderBackgroundColorR", to_string(HeaderBackgroundColor.r).c_str(), CCFullPath);
	WritePrivateProfileString("Header", "HeaderBackgroundColorG", to_string(HeaderBackgroundColor.g).c_str(), CCFullPath);
	WritePrivateProfileString("Header", "HeaderBackgroundColorB", to_string(HeaderBackgroundColor.b).c_str(), CCFullPath);
	WritePrivateProfileString("Header", "HeaderBackgroundColorA", to_string(HeaderBackgroundColor.a).c_str(), CCFullPath);
	WritePrivateProfileString("Header", "HeaderTextColorR", to_string(HeaderTextColor.r).c_str(), CCFullPath);
	WritePrivateProfileString("Header", "HeaderTextColorG", to_string(HeaderTextColor.g).c_str(), CCFullPath);
	WritePrivateProfileString("Header", "HeaderTextColorB", to_string(HeaderTextColor.b).c_str(), CCFullPath);
	WritePrivateProfileString("Header", "HeaderTextColorA", to_string(HeaderTextColor.a).c_str(), CCFullPath);

	WritePrivateProfileString("SubmenuBar", "SubmenuBarHeight", to_string(SubmenuBarHeight).c_str(), CCFullPath);
	WritePrivateProfileString("SubmenuBar", "SubmenuBarBackgroundColorR", to_string(SubmenuBarBackgroundColor.r).c_str(), CCFullPath);
	WritePrivateProfileString("SubmenuBar", "SubmenuBarBackgroundColorG", to_string(SubmenuBarBackgroundColor.g).c_str(), CCFullPath);
	WritePrivateProfileString("SubmenuBar", "SubmenuBarBackgroundColorB", to_string(SubmenuBarBackgroundColor.b).c_str(), CCFullPath);
	WritePrivateProfileString("SubmenuBar", "SubmenuBarBackgroundColorA", to_string(SubmenuBarBackgroundColor.a).c_str(), CCFullPath);
	WritePrivateProfileString("SubmenuBar", "SubmenuBarTextColorR", to_string(SubmenuBarTextColor.r).c_str(), CCFullPath);
	WritePrivateProfileString("SubmenuBar", "SubmenuBarTextColorG", to_string(SubmenuBarTextColor.g).c_str(), CCFullPath);
	WritePrivateProfileString("SubmenuBar", "SubmenuBarTextColorB", to_string(SubmenuBarTextColor.b).c_str(), CCFullPath);
	WritePrivateProfileString("SubmenuBar", "SubmenuBarTextColorA", to_string(SubmenuBarTextColor.a).c_str(), CCFullPath);

	WritePrivateProfileString("Options", "OptionsHeight", to_string(OptionsHeight).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "RectWidth", to_string(RectWidth).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "ToggleOnColorR", to_string(ToggleOnColor.r).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "ToggleOnColorG", to_string(ToggleOnColor.g).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "ToggleOnColorB", to_string(ToggleOnColor.b).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "ToggleOnColorA", to_string(ToggleOnColor.a).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "ToggleOffColorR", to_string(ToggleOffColor.r).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "ToggleOffColorG", to_string(ToggleOffColor.g).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "ToggleOffColorB", to_string(ToggleOffColor.b).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "ToggleOffColorA", to_string(ToggleOffColor.a).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "RectColorR", to_string(RectColor.r).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "RectColorG", to_string(RectColor.g).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "RectColorB", to_string(RectColor.b).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "RectColorA", to_string(RectColor.a).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "SelectedTextColorR", to_string(SelectedTextColor.r).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "SelectedTextColorG", to_string(SelectedTextColor.g).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "SelectedTextColorB", to_string(SelectedTextColor.b).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "SelectedTextColorA", to_string(SelectedTextColor.a).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "UnselectedTextColorR", to_string(UnselectedTextColor.r).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "UnselectedTextColorG", to_string(UnselectedTextColor.g).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "UnselectedTextColorB", to_string(UnselectedTextColor.b).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "UnselectedTextColorA", to_string(UnselectedTextColor.a).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "SelectedBackgroundColorR", to_string(SelectedBackgroundColor.r).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "SelectedBackgroundColorG", to_string(SelectedBackgroundColor.g).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "SelectedBackgroundColorB", to_string(SelectedBackgroundColor.b).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "SelectedBackgroundColorA", to_string(SelectedBackgroundColor.a).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "UnselectedBackgroundColorR", to_string(UnselectedBackgroundColor.r).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "UnselectedBackgroundColorG", to_string(UnselectedBackgroundColor.g).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "UnselectedBackgroundColorB", to_string(UnselectedBackgroundColor.b).c_str(), CCFullPath);
	WritePrivateProfileString("Options", "UnselectedBackgroundColorA", to_string(UnselectedBackgroundColor.a).c_str(), CCFullPath);

	WritePrivateProfileString("Footer", "FooterHeight", to_string(FooterHeight).c_str(), CCFullPath);
	WritePrivateProfileString("Footer", "SpriteSize", to_string(SpriteSize).c_str(), CCFullPath);
	WritePrivateProfileString("Footer", "BackgroundColorR", to_string(BackgroundColor.r).c_str(), CCFullPath);
	WritePrivateProfileString("Footer", "BackgroundColorG", to_string(BackgroundColor.g).c_str(), CCFullPath);
	WritePrivateProfileString("Footer", "BackgroundColorB", to_string(BackgroundColor.b).c_str(), CCFullPath);
	WritePrivateProfileString("Footer", "BackgroundColorA", to_string(BackgroundColor.a).c_str(), CCFullPath);
	WritePrivateProfileString("Footer", "SpriteColorR", to_string(SpriteColor.r).c_str(), CCFullPath);
	WritePrivateProfileString("Footer", "SpriteColorG", to_string(SpriteColor.g).c_str(), CCFullPath);
	WritePrivateProfileString("Footer", "SpriteColorB", to_string(SpriteColor.b).c_str(), CCFullPath);
	WritePrivateProfileString("Footer", "SpriteColorA", to_string(SpriteColor.a).c_str(), CCFullPath);
	WritePrivateProfileString("Footer", "BaugleMenuVIPR", to_string(BaugleMenuVIP.r).c_str(), CCFullPath);
	WritePrivateProfileString("Footer", "BaugleMenuVIPG", to_string(BaugleMenuVIP.g).c_str(), CCFullPath);
	WritePrivateProfileString("Footer", "BaugleMenuVIPB", to_string(BaugleMenuVIP.b).c_str(), CCFullPath);
	WritePrivateProfileString("Footer", "BaugleMenuVIPA", to_string(BaugleMenuVIP.a).c_str(), CCFullPath);


}
