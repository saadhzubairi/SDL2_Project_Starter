cmake_minimum_required(VERSION 3.26)
project(SDL2_Project)

set(CMAKE_CXX_STANDARD 17)
set(SDL2_INCLUDE_DIR C:\\src\\SDL\\include)
set(SDL2_LIB_DIR C:\\src\\SDL\\lib\\x64)

set(SDL2_INCLUDE_DIR2 C:\\src\\SDL2_image\\include)
set(SDL2_LIB_DIR2 C:\\src\\SDL2_image\\lib\\x64)

set(SDL2_INCLUDE_DIR3 C:\\src\\SDL2_ttf\\include)
set(SDL2_LIB_DIR3 C:\\src\\SDL2_ttf\\lib\\x64)

set(SDL2_INCLUDE_DIR4 C:\\src\\SDL2_mixer\\include)
set(SDL2_LIB_DIR4 C:\\src\\SDL2_mixer\\lib\\x64)


include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_INCLUDE_DIR2})
include_directories(${SDL2_INCLUDE_DIR3})
include_directories(${SDL2_INCLUDE_DIR4})

link_directories(${SDL2_LIB_DIR})
link_directories(${SDL2_LIB_DIR2})
link_directories(${SDL2_LIB_DIR3})
link_directories(${SDL2_LIB_DIR4})

add_executable(SDL2_Project main.cpp
        Game/game.cpp
        Game/game.h
        Game/game.h
        Game/GameObject/GameObject.cpp
        Game/GameObject/GameObject.h
        Game/GameObject/GameObject.h
        Game/TextureManager/TextureManager.cpp
        Game/TextureManager/TextureManager.h
        Game/TextureManager/TextureManager.h
        Game/Utilities/Counters.cpp
        Game/Utilities/Counters.h)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image SDL2_ttf SDL2_mixer)