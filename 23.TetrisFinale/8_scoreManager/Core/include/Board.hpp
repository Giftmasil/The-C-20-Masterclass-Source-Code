#pragma once
#include <vector>
#include "Tetromino.hpp"

class Board {
public:
  static const int WIDTH = 10;
  static const int HEIGHT = 20;

  Board();
  bool isCollision(const Tetromino& tetromino) const;
  void placeTetromino(const Tetromino& tetromino);
  int clearLines();
  bool isGameOver() const;

  const std::vector<std::vector<int>>& getGrid() const { return grid; }

private:
  std::vector<std::vector<int>> grid;
};