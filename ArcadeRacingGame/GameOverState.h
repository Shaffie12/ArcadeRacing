#ifndef _GAMEOVER_STATE_H_
#define _GAMEOVER_STATE_H_
#include "State.h"
#include "Renderer.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class GameOverState : public State
{
public:
	GameOverState();
	void handleInput(const float& dt) override;
	void update(const float& dt) override;
	void drawToTexture(Renderer& renderer) override;
	void quit() override;
private:
	sf::Text gameOverText;
	sf::Font textFont;
	sf::Color bgFill;
	sf::Color textFill;

};
#endif