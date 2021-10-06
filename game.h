#include <iostream>
#include <vector>
#include "cpputils/graphics/image.h"
#include "game_element.h"
#include "opponent.h"
#include "player.h"

#ifndef GAME_H
#define GAME_H

class Game : public graphics::AnimationEventListener,
             public graphics::MouseEventListener {
 public:
  void Start() { field.ShowUntilClosed(); }
  Game() : Game(800, 600) {}
  Game(int width, int height)
      : width_(width), height_(height), field(width, height) {}

  std::vector<Opponent> &GetOpponents() { return Boss; }
  std::vector<OpponentProjectile> &GetOpponentProjectiles() { return Energy; }
  std::vector<PlayerProjectile> &GetPlayerProjectiles() { return Rock; }
  Player &GetPlayer() { return Protag; }

  graphics::Image &GetGameScreen() { return field; }
  void CreateOpponents();
  void CreateOpponentProjectiles();
  void CreatePlayerProjectiles();

  void OnAnimationStep() override;
  void OnMouseEvent(const graphics::MouseEvent &event) override;

  void MoveGameElements();
  void FilterIntersections();

  void Init();
  void UpdateScreen();

 private:
  int width_;
  int height_;
  graphics::Image field;
  std::vector<Opponent> Boss;
  std::vector<OpponentProjectile> Energy;
  std::vector<PlayerProjectile> Rock;
  Player Protag;
};
#endif
