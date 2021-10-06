#include <iostream>
#include "cpputils/graphics/image.h"
#include "game.h"

int main() {
  Game Driver;

  Driver.Init();
  Driver.UpdateScreen();
  Driver.Start();
}
