#pragma once
#include "../Common.hpp"
#include "../ImGui/imgui.h"
#include "../ImGui/imgui_internal.h"
#include "AbstractSubmenu.hpp"
#include "../GTA/Invoker/Types.hpp"
#include"../Utility/Function/ReadINI.hpp"


namespace Base::UserInterface
{
	class UIManager
	{
	public:
	
	public:
		std::mutex m_Mutex;

		bool m_Opened = false;
		bool m_MouseLocked = false;
		float m_PosX = PosX;//25.f
		float m_PosY = PosY;//25.f
		float m_Test = 0.f;
		float m_Width = UIWidth;//430.f
		std::size_t m_OptionsPerPage = 13;
		bool m_Sounds = true;
		bool m_BoolOption = false;
		float m_header_width = 0.0f;
		char* Footername = Name;//Baugle Menu VIP

		// Offsets
		float m_PaddingX = PaddingX;//7.f
		float m_PaddingY = PaddingY;//11.f
		
		// Input
		std::int32_t m_OpenDelay = OpenDelay;//200
		std::int32_t m_BackDelay = BackDelay;//300
		std::int32_t m_EnterDelay = EnterDelay;//300
		std::int32_t m_VerticalDelay = VerticalDelay;//120
		std::int32_t m_HorizontalDelay = HorizontaDelay;//120

		// Header
		float m_HeaderHeight = HeaderHeight;//100.f
		Color m_HeaderBackgroundColor = HeaderBackgroundColor;//{ 255, 255, 255, 222 }
		Color m_HeaderTextColor = HeaderTextColor;//{ 255, 255, 255, 222 }

		// Submenu bar
		float m_SubmenuBarHeight = SubmenuBarHeight;//45.f
		Color m_SubmenuBarBackgroundColor = SubmenuBarBackgroundColor;//{ 0, 0, 0, 150 }
		Color m_SubmenuBarTextColor = SubmenuBarTextColor;//{ 255, 255, 255, 222 }

		// Options
		float m_OptionHeight = OptionsHeight;//45.f
		float m_SubmenuRectWidth = RectWidth;//10.f
		Color m_ToggleOnColor = ToggleOnColor;//{ 130, 214, 157, 255 }
		Color m_ToggleOffColor = ToggleOffColor;//{ 200, 55, 80, 255 }
		Color m_SubmenuRectColor= RectColor;//{94, 94, 94, 180 }
		Color m_OptionSelectedTextColor = SelectedTextColor;//{ 0, 0, 0, 222 }
		Color m_OptionUnselectedTextColor = UnselectedTextColor;//{ 255, 255, 255, 222 }
		Color m_OptionSelectedBackgroundColor = SelectedBackgroundColor;//{ 255, 255, 255, 222 }
		Color m_OptionUnselectedBackgroundColor = UnselectedBackgroundColor;//{ 0, 0, 0, 120 }

		// Smooth Scrolling
		float lerp(float a, float b, float t)
		{
			return a + t * (b - a);
		}

		float m_CurrentCoord = m_PosY;

		// Footer
		float m_FooterHeight = FooterHeight;//45.f
		float m_FooterSpriteSize = SpriteSize;//0.025f
		Color m_FooterBackgroundColor = BackgroundColor;//{ 0, 0, 0, 150 }
		Color m_FooterSpriteColor = SpriteColor;//{ 255, 255, 255, 222 }
		Color m_Baugle_Menu_VIP = BaugleMenuVIP;//{ 248, 200, 220,255 }

		void SaveIni()
		{
			char roamingPath[MAX_PATH];
			SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, roamingPath);
			string additionalPath = "\\Baugle\\UI.ini";
			string fullPath = string(roamingPath) + additionalPath;
			const char* CCFullPath = fullPath.c_str();

			// 写配置项
			WritePrivateProfileString("Position",  // 节名称
				"PosX", // 配置项名称
				to_string(m_PosX).c_str(), // 欲写入的值
				CCFullPath); // 配置文件名

			WritePrivateProfileString("Position", "PosY", to_string(m_PosY).c_str(), CCFullPath);

			WritePrivateProfileString("UI", "UIWidth", to_string(m_Width).c_str(), CCFullPath);
			WritePrivateProfileString("UI", "Name", Name, CCFullPath);

			WritePrivateProfileString("Offsets", "PaddingX", to_string(m_PaddingX).c_str(), CCFullPath);
			WritePrivateProfileString("Offsets", "PaddingY", to_string(m_PaddingY).c_str(), CCFullPath);

			WritePrivateProfileString("Input", "UIWidth", to_string(m_OpenDelay).c_str(), CCFullPath);
			WritePrivateProfileString("Input", "UIWidth", to_string(m_BackDelay).c_str(), CCFullPath);
			WritePrivateProfileString("Input", "UIWidth", to_string(m_EnterDelay).c_str(), CCFullPath);
			WritePrivateProfileString("Input", "UIWidth", to_string(m_VerticalDelay).c_str(), CCFullPath);
			WritePrivateProfileString("Input", "UIWidth", to_string(m_HorizontalDelay).c_str(), CCFullPath);

			WritePrivateProfileString("Header", "HeaderHeight", to_string(m_HeaderHeight).c_str(), CCFullPath);
			WritePrivateProfileString("Header", "HeaderBackgtoundColorR", to_string(m_HeaderBackgroundColor.r).c_str(), CCFullPath);
			WritePrivateProfileString("Header", "HeaderBackgtoundColorG", to_string(m_HeaderBackgroundColor.g).c_str(), CCFullPath);
			WritePrivateProfileString("Header", "HeaderBackgtoundColorB", to_string(m_HeaderBackgroundColor.b).c_str(), CCFullPath);
			WritePrivateProfileString("Header", "HeaderBackgtoundColorA", to_string(m_HeaderBackgroundColor.a).c_str(), CCFullPath);
			WritePrivateProfileString("Header", "HeaderTextColorR", to_string(m_HeaderTextColor.r).c_str(), CCFullPath);
			WritePrivateProfileString("Header", "HeaderTextColorG", to_string(m_HeaderTextColor.g).c_str(), CCFullPath);
			WritePrivateProfileString("Header", "HeaderTextColorB", to_string(m_HeaderTextColor.b).c_str(), CCFullPath);
			WritePrivateProfileString("Header", "HeaderTextColorA", to_string(m_HeaderTextColor.a).c_str(), CCFullPath);

			WritePrivateProfileString("SubmenuBar", "SubmenuBarHeight", to_string(m_SubmenuBarHeight).c_str(), CCFullPath);
			WritePrivateProfileString("SubmenuBar", "SubmenuBarBackgtoundColorR", to_string(m_SubmenuBarBackgroundColor.r).c_str(), CCFullPath);
			WritePrivateProfileString("SubmenuBar", "SubmenuBarBackgtoundColorG", to_string(m_SubmenuBarBackgroundColor.g).c_str(), CCFullPath);
			WritePrivateProfileString("SubmenuBar", "SubmenuBarBackgtoundColorB", to_string(m_SubmenuBarBackgroundColor.b).c_str(), CCFullPath);
			WritePrivateProfileString("SubmenuBar", "SubmenuBarBackgtoundColorA", to_string(m_SubmenuBarBackgroundColor.a).c_str(), CCFullPath);
			WritePrivateProfileString("SubmenuBar", "SubmenuBarTextColorR", to_string(m_SubmenuBarTextColor.r).c_str(), CCFullPath);
			WritePrivateProfileString("SubmenuBar", "SubmenuBarTextColorG", to_string(m_SubmenuBarTextColor.g).c_str(), CCFullPath);
			WritePrivateProfileString("SubmenuBar", "SubmenuBarTextColorB", to_string(m_SubmenuBarTextColor.b).c_str(), CCFullPath);
			WritePrivateProfileString("SubmenuBar", "SubmenuBarTextColorA", to_string(m_SubmenuBarTextColor.a).c_str(), CCFullPath);

			WritePrivateProfileString("Options", "OptionsHeight", to_string(m_OptionHeight).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "RectWidth", to_string(m_SubmenuRectWidth).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "ToggleOnColorR", to_string(m_ToggleOnColor.r).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "ToggleOnColorG", to_string(m_ToggleOnColor.g).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "ToggleOnColorB", to_string(m_ToggleOnColor.b).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "ToggleOnColorA", to_string(m_ToggleOnColor.a).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "ToggleOffColorR", to_string(m_ToggleOffColor.r).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "ToggleOffColorG", to_string(m_ToggleOffColor.g).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "ToggleOffColorB", to_string(m_ToggleOffColor.b).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "ToggleOffColorA", to_string(m_ToggleOffColor.a).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "RectColorR", to_string(m_SubmenuRectColor.r).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "RectColorG", to_string(m_SubmenuRectColor.g).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "RectColorB", to_string(m_SubmenuRectColor.b).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "RectColorA", to_string(m_SubmenuRectColor.a).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "SelectedTextColorR", to_string(m_OptionSelectedTextColor.r).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "SelectedTextColorG", to_string(m_OptionSelectedTextColor.g).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "SelectedTextColorB", to_string(m_OptionSelectedTextColor.b).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "SelectedTextColorA", to_string(m_OptionSelectedTextColor.a).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "UnselectedTextColorR", to_string(m_OptionUnselectedTextColor.r).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "UnselectedTextColorG", to_string(m_OptionUnselectedTextColor.g).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "UnselectedTextColorB", to_string(m_OptionUnselectedTextColor.b).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "UnselectedTextColorA", to_string(m_OptionUnselectedTextColor.a).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "SelectedBackgroundColorR", to_string(m_OptionSelectedBackgroundColor.r).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "SelectedBackgroundColorG", to_string(m_OptionSelectedBackgroundColor.g).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "SelectedBackgroundColorB", to_string(m_OptionSelectedBackgroundColor.b).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "SelectedBackgroundColorA", to_string(m_OptionSelectedBackgroundColor.a).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "UnselectedBackgroundColorR", to_string(m_OptionUnselectedBackgroundColor.r).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "UnselectedBackgroundColorG", to_string(m_OptionUnselectedBackgroundColor.g).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "UnselectedBackgroundColorB", to_string(m_OptionUnselectedBackgroundColor.b).c_str(), CCFullPath);
			WritePrivateProfileString("Options", "UnselectedBackgroundColorA", to_string(m_OptionUnselectedBackgroundColor.a).c_str(), CCFullPath);

			WritePrivateProfileString("Footer", "FooterHeight", to_string(m_FooterHeight).c_str(), CCFullPath);
			WritePrivateProfileString("Footer", "SpriteSize", to_string(m_FooterSpriteSize).c_str(), CCFullPath);
			WritePrivateProfileString("Footer", "BackgroundColorR", to_string(m_FooterBackgroundColor.r).c_str(), CCFullPath);
			WritePrivateProfileString("Footer", "BackgroundColorG", to_string(m_FooterBackgroundColor.g).c_str(), CCFullPath);
			WritePrivateProfileString("Footer", "BackgroundColorB", to_string(m_FooterBackgroundColor.b).c_str(), CCFullPath);
			WritePrivateProfileString("Footer", "BackgroundColorA", to_string(m_FooterBackgroundColor.a).c_str(), CCFullPath);
			WritePrivateProfileString("Footer", "SpriteColorR", to_string(m_FooterSpriteColor.r).c_str(), CCFullPath);
			WritePrivateProfileString("Footer", "SpriteColorG", to_string(m_FooterSpriteColor.g).c_str(), CCFullPath);
			WritePrivateProfileString("Footer", "SpriteColorB", to_string(m_FooterSpriteColor.b).c_str(), CCFullPath);
			WritePrivateProfileString("Footer", "SpriteColorA", to_string(m_FooterSpriteColor.a).c_str(), CCFullPath);
			WritePrivateProfileString("Footer", "BaugleMenuVIPR", to_string(m_Baugle_Menu_VIP.r).c_str(), CCFullPath);
			WritePrivateProfileString("Footer", "BaugleMenuVIPG", to_string(m_Baugle_Menu_VIP.g).c_str(), CCFullPath);
			WritePrivateProfileString("Footer", "BaugleMenuVIPB", to_string(m_Baugle_Menu_VIP.b).c_str(), CCFullPath);
			WritePrivateProfileString("Footer", "BaugleMenuVIPA", to_string(m_Baugle_Menu_VIP.a).c_str(), CCFullPath);


		}

	private:
	

}
