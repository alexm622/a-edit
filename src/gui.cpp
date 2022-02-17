#include "gui.h"

#include <stdlib.h>
#include <iostream>

#include "ftxui/screen/terminal.hpp"
#include "ftxui/component/component.hpp"

#include "menu.h"

Gui::Gui() : screen(ftxui::ScreenInteractive::Fullscreen()), width(ftxui::Terminal::Size().dimx), height(ftxui::Terminal::Size().dimy)
{
}

void Gui::drawGui()
{
  if (renderer_defined)
  {
    screen.Print();
  }
}

void Gui::drawLoop()
{
  if (renderer_defined)
  {

    screen.Loop(renderer);
  }
  else
  {
    auto btn_quit = ftxui::Button("Quit", screen.ExitLoopClosure());

    auto layout = ftxui::Container::Horizontal({
      btn_quit,
    });

    auto renderer_new = ftxui::Renderer(layout, [ & ] {
      auto explanation = ftxui::paragraph(
        "renderer is empty");
      auto element = ftxui::vbox({
        explanation | ftxui::borderEmpty,
        ftxui::hbox({
          ftxui::filler(),
          btn_quit -> Render(),
        }),
      });
      element = element | ftxui::borderEmpty | ftxui::border | ftxui::size(ftxui::WIDTH, ftxui::LESS_THAN, 80) |
        ftxui::size(ftxui::HEIGHT, ftxui::LESS_THAN, 20) | ftxui::center;
      return element;
    });
    screen.Loop(renderer_new);
  }
}

ftxui::Component buildUI()
{
  // for now just build a basic ui
  return nullptr;
}
