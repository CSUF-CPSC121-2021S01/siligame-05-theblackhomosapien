#include "game_element.h"
#include <iostream>
#include "cpputils/graphics/image.h"

void GameElement::Draw(graphics::Image &field) {
  graphics::Color black(0, 0, 0);
  field.DrawRectangle(x_, y_, 5, 5, black);
}

bool GameElement::IntersectsWith(GameElement *game) {
  return !(GetX() > game->GetX() + game->GetWidth() ||
           game->GetX() > x_ + GetWidth() ||
           GetY() > game->GetY() + game->GetHeight() ||
           game->GetY() > y_ + GetHeight());
}

bool GameElement::IsOutOfBounds(const graphics::Image &error) {
  return !((GetY() >= 0) && (error.GetHeight() > GetY() + GetHeight()) &&
           (GetX() >= 0) && (error.GetWidth() > GetX() + GetWidth()));
}

void GameElement::PadPoints(std::vector<int> &points, int scoreposition_x,
                            int scoreposition_y) {
  for (int i = 0; i < points.size(); i++) {
    if (i % 2 == 0) {
      points[i] += scoreposition_x;
    } else {
      points[i] += scoreposition_y;
    }
  }
}
