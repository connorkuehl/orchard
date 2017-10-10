#ifndef ORCHARD_PLAY_SCENE_H
#define ORCHARD_PLAY_SCENE_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "engine/scene.h"
#include "spawner.h"
#include "player.h"

/**
 * @brief The PlayScene contains the actual game play. It has objects that maintain Player and Apple state.
 */
class PlayScene : public Scene
{
    public:
        /// @brief Constructs the PlayScene and attaches the RenderWindow and SceneManager to it.
        explicit PlayScene(sf::RenderWindow &window, SceneManager &sceneManager);
        ~PlayScene() override = default;

        /// @brief Handles player interaction.
        void interact() override;
        /// @brief Updates the game logic.
        void update(float elapsed) override;
        /// @brief Draws all drawable GameObjects.
        void draw() override;
    private:
        Spawner spawner_; ///< Spawns Apples.
        Player player_; ///< The Player object contains Player state in the Scene.
        sf::Sprite background_; ///< The background image.
        sf::Font font_; ///< The font to use.
        sf::Text scoreText_; ///< The text used to display user score.
        size_t score_; ///< The player's score.
};

#endif // ORCHARD_PLAY_SCENE_H

