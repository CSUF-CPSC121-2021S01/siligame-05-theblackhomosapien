#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H
#include <iostream>
#include "cpputils/graphics/image.h"

class GameElement {
 public:
  GameElement() : GameElement(0, 0, 50, 50) {}
  GameElement(const int &x, const int &y, const int &width, const int &height)
      : x_(x), y_(y), width_(width), height_(height) {}

  void SetX(int x) { x_ = x; }
  void SetY(int y) { y_ = y; }
  int GetX() const { return x_; }
  int GetY() const { return y_; }
  int GetWidth() const { return width_; }
  int GetHeight() const { return height_; }

  virtual void Draw(graphics::Image &field) = 0;

  bool GetIsActive() { return is_active_; }
  void SetIsActive(bool is_active) { is_active_ = is_active; }

  virtual void Move(const graphics::Image &field) = 0;

  bool IntersectsWith(GameElement *game);
  bool IsOutOfBounds(const graphics::Image &error);

 protected:
  void PadPoints(std::vector<int> &points, int scoreposition_x,
                 int scoreposition_y);
  int x_;
  int y_;
  int width_;
  int height_;
  bool is_active_ = true;
};
#endif
