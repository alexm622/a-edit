#ifndef GUI_HPP
#define GUI_HPP

#include <stdbool.h>

#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>



class Gui {
public:
  Gui();
  ~Gui();
  void start();
  static std::vector<std::string> *input_strings;
  static std::vector<std::string> *tab_names;
  static int curr_tab;
  private:
    ftxui::ScreenInteractive screen;
    int width, height;
    ftxui::Component renderer;  
    bool renderer_defined = false;
};
#endif
