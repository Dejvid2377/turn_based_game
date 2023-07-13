#include "../inc/player.hh"

GameTree::GameTree(const Game& gameState) {
  root = make_shared<Node>();
  root->game = make_shared<Game>(gameState);
  root->parent = nullptr;
  root->UcbScore = 0.0;
  root->visits = 0;
  root->score = 0.0;
  treeSize = 1;

}

void GameTree::addNode(const shared_ptr<Node>& parentNode) {
  shared_ptr<Node> newNode = make_shared<Node>();
  newNode->score = 0;
  newNode->UcbScore = parentNode->UcbScore;
  newNode->game = make_shared<Game>(*parentNode->game);
  newNode->parent = parentNode;
  newNode->UcbScore = 0;
  newNode->visits = 0;
  parentNode->childNodes.push_back(newNode);
  treeSize++;
}

//improvment required
void GameTree::removeNode(shared_ptr<Node>& node) {
  if (node == nullptr) {
    return;
  }

  for (auto& child : node->childNodes) {
    removeNode(child);
  }

  if (node->parent != nullptr) {
    auto& parentChildNodes = node->parent->childNodes;
    parentChildNodes.erase(std::remove(parentChildNodes.begin(), parentChildNodes.end(), node), parentChildNodes.end());
  }

  treeSize--;
}


shared_ptr<Node> GameTree::getRoot()
{
  if (root != nullptr)
    return root;
  return nullptr;
}

vector<shared_ptr<Node>> GameTree::getChilds(const shared_ptr<Node>& node)
{
  if (node != nullptr)
    return node->childNodes;

  return vector<shared_ptr<Node>>();
}

int GameTree::getTreeSize()
{
  return treeSize;
}

float GameTree::calculateUcb(const shared_ptr<Node>& node)
{
  static const float explorationParam = 1.41;

  float ucbScore = node->UcbScore;
  int parentVisits = node->parent->visits;
  int visits = node->visits;

  if (visits == 0) {
    return numeric_limits<float>::infinity();
  }

  float exploitationTerm = ucbScore / visits;
  float explorationTerm = explorationParam * sqrt(log(parentVisits) / visits);
  return exploitationTerm + explorationTerm;
}

shared_ptr<Node> GameTree::checkChildsUcb(const shared_ptr<Node>& node)
{
  shared_ptr<Node> ptr = node;

  if (!GameTree::getChilds(node).empty()) {
    for (auto const & branch : GameTree::getChilds(node)) {
      auto bestNode = GameTree::checkChildsUcb(branch);
      cout << "najlepszy wynik potomków: " << bestNode->UcbScore << endl;
      if (bestNode->UcbScore > ptr->UcbScore) {
        cout << "potomek pokonal rodzica! "<< endl;
        cout << "potomek: " << bestNode->UcbScore << endl;
        cout << "rodzic: " << ptr->UcbScore << endl;
        ptr = bestNode;

      }
    }
  }
  else {
    node->UcbScore = GameTree::calculateUcb(node);
    cout << "obliczony ucb: " << node->UcbScore << endl;
    return node;
  }

  return ptr;
}

shared_ptr<Node> GameTree::selectExplorNode()
{
  float bestUCB = - numeric_limits<float>::infinity();

}

