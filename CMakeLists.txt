cmake_minimum_required(VERSION 3.23)
project(8bitinfinityjam CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

#find_package(raylib REQUIRED)
add_subdirectory(libs/LDtkLoader 1.2)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib
            GIT_REPOSITORY https://github.com/raysan5/raylib.git
            GIT_TAG 4.2.0
    )
    FetchContent_MakeAvailable(raylib)
endif()

include_directories(
        ${PROJECT_SOURCE_DIR}/sources
)

# Declaring our executable
add_executable(${PROJECT_NAME}
        sources/main.cpp sources/Player.cpp sources/Player.hpp sources/StateManager.cpp
        sources/StateManager.hpp sources/State.hpp sources/PlayState.cpp sources/PlayState.hpp sources/GameManager.cpp sources/GameManager.hpp sources/PauseState.cpp sources/PauseState.hpp sources/Animator.cpp sources/Animator.hpp sources/MainMenuState.cpp sources/MainMenuState.hpp sources/TileMap.cpp)
#target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib LDtkLoader)

# Setting ASSETS_PATH
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="./assets") # Set the asset path macro in release mode to a relative path that assumes the assets folder is in the same directory as the game executable

