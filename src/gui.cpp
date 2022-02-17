#include "gui.h"

#include <stdlib.h>
#include <iostream>

#include "ftxui/screen/terminal.hpp"
#include "ftxui/component/component.hpp"

std::vector<std::string>* Gui::input_strings = new std::vector<std::string>();
std::vector<std::string>* Gui::tab_names = new std::vector<std::string>();
int Gui::curr_tab = 0;


Gui::Gui() : screen(ftxui::ScreenInteractive::Fullscreen()), width(ftxui::Terminal::Size().dimx), height(ftxui::Terminal::Size().dimy) {

}

void Gui::start()
{
  ftxui::Component renderer;

  input_strings->push_back("nothing at the moment");
  tab_names->push_back("tab 1");

  auto toggle = ftxui::Toggle(tab_names, &Gui::curr_tab);
  ftxui::Component input = ftxui::Input(&input_strings->front(), "nothing");
  auto tab_container = ftxui::Container::Tab({
        input
      }, &Gui::curr_tab);
  auto container = ftxui::Container::Vertical({
        toggle,
        tab_container
      });

  auto tab_toggle = ftxui::Toggle(tab_names, &Gui::curr_tab);
  renderer = ftxui::Renderer(container, [&] {
      return ftxui::vbox({
          ftxui::paragraph("test"),
          toggle->Render(),
          ftxui::separator(),
          tab_container->Render()
          }) | ftxui::border;
      });
  screen.Loop(renderer); 

}

