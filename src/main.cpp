#include "../inc/game.hh"
vector<Game> runThread(const Game& game, std::atomic<int>& n,vector<Game> &newVec);

int main() {
    Game game(MAP_FILE,STATUS_FILE);
    bool game_status = false;
    while (game_status) {
        game.createStatus(STATUS_FILE);
        system ("./player1 mapa.txt status.txt rozkazy.txt");
        if (!game.executeOrders("rozkazy.txt"))
            game_status = false;
        game.createStatus(STATUS_FILE);
        system ("./player2 mapa.txt status.txt rozkazy.txt");
        if (!game.executeOrders("rozkazy.txt"))
            game_status = false;
    }
    return 0;
}



vector<Game> runThread(const Game& game, std::atomic<int>& n,vector<Game> & newVec){
    auto start = std::chrono::system_clock::now();
    const int numThreads = std::thread::hardware_concurrency();

    std::thread threads[numThreads];
    cout << endl;

    auto threadFunc = [&n, &game, &newVec]() {
        while (n.fetch_sub(1, std::memory_order_relaxed) > 0) {
            Game game1(game);
            shared_ptr<UnitModel> unitModel = make_shared<UnitModel>(UnitType::Archer);
            //game1.addUnit(2,unitModel);
            cout << unitModel->getID() << " ";
        }
    };

    for (int i = 0; i < numThreads; i++) {
        threads[i] = std::thread(threadFunc);
    }

    for (int i = 0; i < numThreads; i++) {
        threads[i].join();
    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;
    double durationTime = diff.count();

    std::cout << "Czas tworzenia: " << durationTime << " s" << std::endl;
    return newVec;
}

