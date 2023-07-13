#ifndef PLAYER_HH
#define PLAYER_HH
#include "game.hh"

struct Node {
  float UcbScore;
  shared_ptr<Node> parent;
  vector<shared_ptr<Node>> childNodes;
  shared_ptr<Game> game;
  float score;
  int visits;
};

class GameTree {
private:
  shared_ptr<Node> root;
  int treeSize;
public:
  GameTree(const Game& gameState);
  void addNode(const shared_ptr<Node>& parentNode);
  void removeNode(shared_ptr<Node>& node);
  shared_ptr<Node> getRoot();
  vector<shared_ptr<Node>> getChilds(const shared_ptr<Node>& node);
  int getTreeSize();

  float calculateUcb(const shared_ptr<Node>& node);
  shared_ptr<Node>  checkChildsUcb(const shared_ptr<Node>& node);
  shared_ptr<Node> selectExplorNode();
};



#endif
