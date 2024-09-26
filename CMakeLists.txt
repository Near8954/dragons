cmake_minimum_required(VERSION 3.29)
project(dragons)

set(CMAKE_CXX_STANDARD 20)


if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native")


set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/SFML")
set(SFML_DIR "/usr/lib/x86_64-linux-gnu/cmake/SFML")


add_executable(dragons main.cpp
        src/Attacker/Attacker.cpp
        src/Attacker/Attacker.h
        src/Enemy/Enemy.cpp
        src/Enemy/Enemy.h
        src/Unit/Unit.cpp
        src/Unit/Unit.h
        src/Dragon/Dragon.cpp
        src/Dragon/Dragon.h
        src/RedDragon/RedDragon.cpp
        src/RedDragon/RedDragon.h
        src/Hero/Hero.cpp
        src/Hero/Hero.h
        src/Game/Game.cpp
        src/Game/Game.h
        src/BlueDragon/BlueDragon.cpp
        src/BlueDragon/BlueDragon.h
        src/BlackDragon/BlackDragon.cpp
        src/BlackDragon/BlackDragon.h)


include(CTest)

find_package(SFML 2.6.1 COMPONENTS network audio graphics window system REQUIRED)

target_link_libraries(${PROJECT_NAME}
        sfml-network
        sfml-audio
        sfml-graphics
        sfml-window
        sfml-system
)

