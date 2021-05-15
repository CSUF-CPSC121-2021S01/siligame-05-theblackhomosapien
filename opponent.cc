#include "opponent.h"
#include <iostream>
#include "cpputils/graphics/image.h"

void Opponent::Draw(graphics::Image &field) {
  graphics::Image Boss;
  Boss.Load("opponent.bmp");
  for (int i = 0; i < width_; i++) {
    for (int j = 0; j < height_; j++) {
      graphics::Color color = Boss.GetColor(i, j);
      field.SetColor(x_ + i, y_ + j, color);
    }
  }
}

void Opponent::Move(const graphics::Image &field) {
  SetX(GetX() + 1);
  SetY(GetY() + 1);
  if (IsOutOfBounds(field)) {
    SetIsActive(false);
  }
}

void OpponentProjectile::Draw(graphics::Image &field) {
  graphics::Image Energy;
  Energy.Load("energy.bmp");
  for (int i = 0; i < width_; i++) {
    for (int j = 0; j < height_; j++) {
      graphics::Color color = Energy.GetColor(i, j);
      field.SetColor(x_ + i, y_ + j, color);
    }
  }
}

void OpponentProjectile::Move(const graphics::Image &screen) {
  SetX(GetX() + 1);
  SetY(GetY() + 1);
  if (IsOutOfBounds(screen)) {
    SetIsActive(false);
  }
}
