cmake_minimum_required(VERSION 3.10)
project(game)

set(CMAKE_CXX_STANDARD 17)

# Add the include directory
include_directories(inc)

add_library(game_lib STATIC
    src/unit.cpp
    src/unitModel.cpp
    src/unitBase.cpp
    src/game.cpp
    src/player.cpp
)

# executable mediator program
add_executable(mediator src/main.cpp)
target_link_libraries(mediator PRIVATE game_lib)

# exacutable player1 program
add_executable(player1 src/hello.cpp)
target_link_libraries(player1 PRIVATE game_lib)

# exacutable player2 program (same as player1)
add_executable(player2 src/hello.cpp)
target_link_libraries(player2 PRIVATE game_lib)

add_custom_target(run
    COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --yellow "Linkowanie..."
    COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --green "Linkowanie zakonczone sukcesem."
    COMMAND ./mediator
    DEPENDS mediator
    COMMENT "Running mediator program"
)

add_custom_target(clean_game
    COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --yellow "Czyszczenie..."
    COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_BINARY_DIR}/main1
    COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_BINARY_DIR}/main2
    COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --green "Czyszczenie zakonczone sukcesem."
)

add_custom_target(help_game
    COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --red "src: ${SOURCE}"
    COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --red "obj: ${OBJECT}"
)

add_custom_target(info_game
    COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --yellow "Uniwersalny plik CMakeLists.txt do budowy programu w jezyku C++"
    COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --yellow "Do poprawnego działania wymagane jest zachowanie struktury modulowej programu"
    COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --yellow "inc - katalog na pliki naglowkowe"
    COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --yellow "src - katalog na pliki zrodlowe"
    COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --yellow "obj - katalog na pliki wynikowe (na wejsciu pusty)"
)

# Make 'run' the default target
set_property(DIRECTORY PROPERTY
    VS_STARTUP_PROJECT "run"
)
