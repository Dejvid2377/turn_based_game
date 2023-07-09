#include "libraries.hh"
#include "unitBase.hh"
#include "unitModel.hh"
#include "game.hh"

int main() {

    Game game(MAP_FILE,STATUS_FILE); //status file SHOULDN'T exist on that moment
    bool game_status = true;
    
    while (game_status) {
        game.createStatus(STATUS_FILE);
        ////system ("./player_one mapa.txt status.txt rozkazy.txt")
        if (!game.executeOrders("rozkazy.txt"))
            game_status = false;
        game.createStatus(STATUS_FILE);
        ////system ("./player_two mapa.txt status.txt rozkazy.txt")
        if (!game.executeOrders("rozkazy.txt"))
            game_status = false;
    }

    return 0;
}