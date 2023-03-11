#include "raylib-cpp.hpp"
#include <LDtkLoader/Project.hpp>
#include "GameManager.hpp"

constexpr int SCREEN_WIDTH = 1024;
constexpr int SCREEN_HEIGHT = 768;
constexpr char const* WINDOW_TITLE= "DOKI DOKI MOUSE";

int main(void)
{
    ldtk::Project ldtk_project;
    const char* ldtk_filename = ASSETS_PATH"ldtk/Levels.ldtk";
    try {
        ldtk_project.loadFromFile(ldtk_filename);
        std::cout << "LDtk World \"" << ldtk_project.getFilePath() << "\" was loaded successfully." << std::endl;
    }
    catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    const auto& world = ldtk_project.getWorld();
    const auto& level = world.getLevel("Level_0");
    const auto& layer = level.getLayer("Ground");
    const auto& tiles_vector = layer.allTiles();

    
    raylib::Window window(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    //raylib::Window window(level.size.x * 4, level.size.y * 4, "LDtkLoader - Raylib");
    
    SetTargetFPS(60);

    GameManager gameManager;

    // Load the texture and the renderer.
    raylib::Texture texture(ASSETS_PATH"tilesets/tileset.png");
    raylib::RenderTexture renderer (level.size.x, level.size.y);

    // Draw all the tiles.
    renderer.BeginMode();
    //BeginTextureMode(renderer);
    ClearBackground(BLACK);
    for (const auto &tile : tiles_vector) {
        const auto& position = tile.getPosition();
        const auto& texture_rect = tile.getTextureRect();
        Vector2 dest = {
                static_cast<float>(position.x),
                static_cast<float>(position.y),
        };
        Rectangle src = {
                static_cast<float>(texture_rect.x),
                static_cast<float>(texture_rect.y),
                static_cast<float>(texture_rect.width) * (tile.flipX ? -1.0f : 1.0f),
                static_cast<float>(texture_rect.height) * (tile.flipY ? -1.0f : 1.0f)
        };
        DrawTextureRec(texture, src, dest, WHITE);
    }
    EndTextureMode();
    
    while (!window.ShouldClose())
    {

//        gameManager.Update(GetFrameTime());
//
//        BeginDrawing();
//        
//        //window.ClearBackground(RAYWHITE);
//        //gameManager.Draw();
//        EndDrawing();
//    }
    //CloseWindow();

        // Scale up the Renderer times 4.
        // NOTE: Render texture must be y-flipped due to default OpenGL coordinates (left-bottom)
        BeginDrawing();
        Rectangle src = {
                0,
                0,
                static_cast<float>(renderer.texture.width),
                -static_cast<float>(renderer.texture.height)
        };
        Rectangle dest = {
                0,
                0,
                static_cast<float>(renderer.texture.width) * 4,
                static_cast<float>(renderer.texture.height) * 4
        };
        DrawTexturePro(renderer.texture, src, dest, {0}, .0f, WHITE);
        EndDrawing();
    }

    // Unload everything before leaving.
    UnloadRenderTexture(renderer);
    UnloadTexture(texture);
    CloseWindow();

    return 0;
}