cmake_minimum_required(VERSION 3.23)
project(8bitinfinityjam CXX)

set(CMAKE_CXX_STANDARD 14)

find_package(raylib REQUIRED)

include_directories(
        ${PROJECT_SOURCE_DIR}/sources
)

# Declaring our executable
add_executable(${PROJECT_NAME}
        sources/main.cpp sources/Player.cpp sources/Player.hpp sources/StateManager.cpp
        sources/StateManager.hpp sources/bullet.cpp sources/bullet.hpp sources/State.hpp sources/PlayState.cpp sources/PlayState.hpp sources/GameManager.cpp sources/GameManager.hpp sources/PauseState.cpp sources/PauseState.hpp sources/Animator.cpp sources/Animator.hpp)
#target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Setting ASSETS_PATH
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="./assets") # Set the asset path macro in release mode to a relative path that assumes the assets folder is in the same directory as the game executable
