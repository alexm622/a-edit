#ifndef GUI_HPP
#define GUI_HPP

#include <stdbool.h>

#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>



class Gui {
public:
  Gui();
  ~Gui();
  void drawGui();
  void drawLoop();
  void setRenderer(ftxui::Component renderer);
  ftxui::Component buildUI();
  private:
    ftxui::ScreenInteractive screen;
    int width, height;
    ftxui::Component renderer;  
    bool renderer_defined = false;
};
#endif
