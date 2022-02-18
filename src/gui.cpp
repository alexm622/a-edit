#include "gui.h"

#include <stdlib.h>
#include <iostream>

#include "ftxui/screen/terminal.hpp"
#include "ftxui/component/component.hpp"

std::vector<std::string>* Gui::input_strings = new std::vector<std::string>();
std::vector<std::string>* Gui::tab_names = new std::vector<std::string>();
std::vector<ftxui::Component> Gui::inputs = std::vector<ftxui::Component>();

int Gui::curr_tab = 0;


Gui::Gui() : screen(ftxui::ScreenInteractive::Fullscreen()), width(ftxui::Terminal::Size().dimx), height(ftxui::Terminal::Size().dimy) {
  input_strings->push_back("nothing at the moment");
  tab_names->push_back("tab 1");
}

void Gui::start()
{
  Gui::inputs.clear();
  for (int i = 0; i < (int)tab_names->size(); i++) {
    input_strings->push_back(std::to_string(std::rand()));
    Gui::inputs.push_back(ftxui::Input(&input_strings->at(i), "nothing"));
  }

  auto toggle = ftxui::Toggle(tab_names, &Gui::curr_tab);
  ftxui::Component input = ftxui::Input(&input_strings->at(0), "nothing");
  Gui::inputs.push_back(input);
  auto buttons = ftxui::Container::Horizontal(
      {ftxui::Button("new tab", [&] { 
          screen.ExitLoopClosure();
          tab_names->push_back(std::to_string(std::rand()));
          this->start();
      }),
       ftxui::Button("quit", screen.ExitLoopClosure())});

  auto tab_container = ftxui::Container::Tab(Gui::inputs, &Gui::curr_tab);
    auto container = ftxui::Container::Vertical({
        toggle,
        tab_container,
        buttons
      });

  auto tab_toggle = ftxui::Toggle(tab_names, &Gui::curr_tab);
  renderer = ftxui::Renderer(container, [&] {
      return ftxui::vbox({
          ftxui::paragraph("test"),
          toggle->Render(),
          ftxui::separator(),
          tab_container->Render(),
          buttons->Render()
          }) | ftxui::border;
      });
  screen.Loop(renderer); 
}

/*
 * TODO this will probably be the later format for addTab
 * void Gui::addTab(std::string title, std::string content) {
}
*/

void Gui::addTab() {
  int r1 = std::rand();
  int r2 = std::rand();
  input_strings->push_back(std::to_string(r1));
  tab_names->push_back(std::to_string(r2));
  inputs.push_back(ftxui::Input(&input_strings->at(input_strings->size() - 1), ""));
}
