#include "../inc/player.hh"

int main() {
  Game game(MAP_FILE,STATUS_FILE);
  GameTree tree(game);
  auto node = tree.getRoot();
  tree.addNode(node);
  tree.addNode(node);
  tree.addNode(node);
  auto lista = tree.getChilds(node);
  tree.addNode(lista[0]);
  tree.addNode(lista[0]);
  tree.addNode(lista[1]);
  tree.addNode(lista[2]);
  tree.addNode(lista[1]);

  auto bestNode = tree.checkChildsUcb(node);
return 0;
}
