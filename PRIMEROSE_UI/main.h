#pragma once 

#include "Font.h"
#include "Edit.h"
#include "imgui/imgui_internal.h"

// Resources 
static int selectedResource = NULL;
std::vector<const char*> resources = {
	"_cfx_internal","fivem","hardcap","anti-cheese","esx_mafia","esx_gopostal","esx_jail","mysql-async","es_admin2",
	"async","es_extended","esx_barbershop","esx_clotheshop","esx_datastore","esx_garage","esx_identity","esx_lscustom",
	"esx_menu_default","esx_menu_dialog","esx_menu_list","esx_property","esx_shops","esx_sit","esx_vehicleshop","esx_weashops",
	"es_camera","instance","skinchanger","mellotrainer","bob74_ipl","coordsaver","loadingscreen"
};

namespace MewnuSeparator
{
	void Seperator(const std::string id, float width = ImGui::GetContentRegionAvail().x, float height = 1, bool visible = true)
	{
		ImGui::BeginChild(id.c_str(), ImVec2(width, height), visible);
		ImGui::EndChild();
	}

	void SetGetPosX(float value)
	{
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + value);
	}

	void SetGetPosY(float value)
	{
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() + value);
	}

	void SetPosX(float value)
	{
		ImGui::SetCursorPosX(value);
	}

	void SetPosY(float value)
	{
		ImGui::SetCursorPosY(value);
	}
}

void SaveScript()
{
	//ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, ImVec2(0.3, 0));
	if (ImGui::Button("Save All Resources", ImVec2(ImGui::GetContentRegionAvailWidth(), 33)))
	{

	}
}

namespace GUI
{

	static bool showui = true;

	static int Resource = 0;
	static int MenuItem = 0;

	void Render()
	{
		ImGui::Begin("Cloud Executor", &showui, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBringToFrontOnFocus);
		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::MenuItem(ICON_FA_CODE" Executor"))
			{
				MenuItem = 1;
			}
			if (ImGui::MenuItem(ICON_FA_DOWNLOAD" Resources"))
			{
				MenuItem = 2;
			}
			if (ImGui::MenuItem(ICON_FA_BOOK" Menus"))
			{
				MenuItem = 3;
			}
			if (ImGui::MenuItem(ICON_FA_COGS" Settings"))
			{
				MenuItem = 4;
			}

			ImGui::MenuItem("Welcome: To Cloud | Bulid: Dec 29 2021");
			ImGui::EndMainMenuBar();
		}

		if (MenuItem == 1)
		{
			auto size = ImGui::GetWindowSize();
			static TextEditor editor;

			editor.Render("TextEditor", ImVec2(size.x - 5, size.y - 88), true);
			editor.SetPalette(TextEditor::GetDarkPalette());
			editor.SetShowWhitespaces(false);
			editor.SetReadOnly(false);

			ImGui::Spacing();

			if (ImGui::Button(ICON_FA_CHECK" Execute")) {}

			ImGui::SameLine();

			if (ImGui::Button(ICON_FA_FILE" Execute from file")) {}

			ImGui::End();
		}
		if (MenuItem == 2)
		{
			static ImGuiTextFilter Filter;
			// static fx::Resource* resource;

			if (ImGui::Button(ICON_FA_DOWNLOAD" Dumper", ImVec2(ImGui::GetWindowWidth() / 3, 33)))
			{
				Resource = 1;
			}

			ImGui::SameLine();

			if (ImGui::Button(ICON_FA_DATABASE" Manager", ImVec2(ImGui::GetWindowWidth() / 3, 33)))
			{
				Resource = 2;
			}

			ImGui::SameLine();

			if (ImGui::Button(ICON_FA_TAGS" Events", ImVec2(ImGui::GetContentRegionAvail().x, 33)))
			{
				Resource = 3;
			}

			ImGui::Separator();


			if (MenuItem == 3)
			{

			}

			if (MenuItem == 4)
			{

			}

			if (Resource == 1)
			{
				static TextEditor dumper;
				ImGui::PushStyleColor(ImGuiCol_FrameBg, IM_COL32(0, 0, 0, 0));
				ImGui::ListBoxHeader("##DumperServer", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetWindowSize().y - 134));

				for (int i = 0; i < resources.size(); i++)
				{
					if (ImGui::CollapsingHeader(resources[i]))
					{
						if (resources[i] == "_cfx_internal" || resources[i] == "fivem")
						{
							std::string _error = resources[i];
							ImGui::TextColored(ImColor(255, 0, 0, 255), _error.append(" Doesn't have any files.").c_str());
						}
						else {
							std::string dumperText = "-- successfully dump server... \n";
							dumper.Render("##DumperServer", ImVec2(ImGui::GetWindowSize().x - 16, 200));
							dumper.SetText(dumperText.append(resources[i]).append("."));
						}
					}
				}
				ImGui::ListBoxFooter();
				ImGui::PopStyleColor();
				MewnuSeparator::Seperator("##saveresourcesbutton");
				SaveScript();
				ImGui::End();
			}

			else if (Resource == 2)
			{

			}

			else if (Resource == 3)
			{
				ImGui::Spacing();

				ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(32, 32, 32, 255));
				ImGui::BeginChild("##LeftBlocker", ImVec2(ImGui::GetContentRegionAvail().x / 2, ImGui::GetContentRegionAvail().y - 14));

				ImGui::EndChild();
				ImGui::PopStyleColor();

				ImGui::SameLine();
				ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical);
				ImGui::SameLine();

				ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 0));
				ImGui::BeginChild("##Blocker", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y - 14));
				{
				ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(4, 4));
				ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);
				ImGui::PopItemWidth();

				ImGuiTextFilter Filter;
				Filter.Draw("##Filter", 400);

				if (ImGui::Button("Add", ImVec2(ImGui::GetContentRegionAvail().x, 33))) {}
				if (ImGui::Button("Remove", ImVec2(ImGui::GetContentRegionAvail().x, 33))) {}

				ImGui::PopStyleVar();
				}
				ImGui::EndChild();
				ImGui::PopStyleColor();
			}
		}
	}
}

void StyleMenu()
{
	auto& style = ImGui::GetStyle();

	style.WindowMinSize = ImVec2(800, 450);

	style.FrameBorderSize = 0;
	style.WindowRounding = 0;
	style.WindowPadding = ImVec2(16, 8);
	style.TabRounding = 0;
	style.ScrollbarRounding = 0;
	style.FramePadding = ImVec2(8, 6);
	style.WindowTitleAlign = ImVec2(0.0f, 0.5f);

	style.Colors[ImGuiCol_ChildBg] = ImColor(32, 32, 32);

	style.Colors[ImGuiCol_TitleBg] = ImColor(32, 148, 186, 255);
	style.Colors[ImGuiCol_TitleBgActive] = ImColor(32, 148, 186, 255);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(15, 15, 15, 50);

	style.Colors[ImGuiCol_WindowBg] = ImColor(12, 12, 12, 255);
	style.Colors[ImGuiCol_Border] = ImColor(0, 0, 0, 0);

	style.Colors[ImGuiCol_Button] = ImColor(24, 25, 24, 255);
	style.Colors[ImGuiCol_ButtonActive] = ImColor(44, 44, 44, 255);
	style.Colors[ImGuiCol_ButtonHovered] = ImColor(44, 44, 44, 255);

	style.Colors[ImGuiCol_CheckMark] = ImColor(255, 255, 255, 255);

	style.Colors[ImGuiCol_FrameBg] = ImColor(36, 37, 36, 255);
	style.Colors[ImGuiCol_FrameBgActive] = ImColor(36, 37, 36, 255);
	style.Colors[ImGuiCol_FrameBgHovered] = ImColor(36, 37, 36, 255);

	style.Colors[ImGuiCol_Header] = ImColor(54, 56, 54, 255);
	style.Colors[ImGuiCol_HeaderActive] = ImColor(54, 56, 54, 255);
	style.Colors[ImGuiCol_HeaderHovered] = ImColor(54, 56, 54, 255);

	style.Colors[ImGuiCol_ResizeGrip] = ImColor(51, 49, 50, 255);	
	style.Colors[ImGuiCol_ResizeGripActive] = ImColor(54, 53, 55);	
	style.Colors[ImGuiCol_ResizeGripHovered] = ImColor(51, 49, 50, 255);

	style.Colors[ImGuiCol_SliderGrab] = ImColor(249, 79, 49, 255);
	style.Colors[ImGuiCol_SliderGrabActive] = ImColor(249, 79, 49, 255);

	style.Colors[ImGuiCol_Border] = ImColor(54, 54, 54);
	style.Colors[ImGuiCol_Separator] = ImColor(54, 54, 54);
	style.Colors[ImGuiCol_SeparatorActive] = ImColor(54, 54, 54);
	style.Colors[ImGuiCol_SeparatorHovered] = ImColor(54, 54, 54);
}