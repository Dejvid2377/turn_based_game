#include "../inc/game.hh"

int main() {

    Game game(MAP_FILE,STATUS_FILE); //status file SHOULDN'T exist on that moment
    bool game_status = true;
    
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