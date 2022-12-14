#include "TitleState.h"



TitleState::TitleState() : menu(GameGlobals::GAME_W, 177, 3, {"START", "LEADERBOARD", "OPTIONS"}),track(sample.colors, sample.segments,sample.totalTrackLength)
{
	userName = TextInput();
	bgFill = sf::Color::Cyan;

	titleText.setString("ARCADE RACER LITE");
	titleText.setFont(FontsManager::GetInstance()->font_title);
	titleText.setFillColor(sf::Color::Black);
	titleText.setPosition(GameGlobals::GAME_W/2-titleText.getGlobalBounds().width/2, (GameGlobals::GAME_H/2-titleText.getGlobalBounds().height/2)-100);
	titleText.setScale(sf::Vector2f(1, 1));		

}

void TitleState::handleInput(sf::Event& e)
{
	if (e.type == sf::Event::KeyPressed)
	{
		if (menu.enabled)
		{
			if (e.key.code == sf::Keyboard::W)
			{
				if (menu.getSelected() == 0)
				{
					menu.enabled = false;
					for (sf::Text t : menu.menuTexts)
					{
						t.setFillColor(sf::Color::Black);
					}
					SoundManager::GetInstance()->menuNavigate.play();
				}	
				else
					menu.MoveUp();
			}
			else if (e.key.code == sf::Keyboard::S)
			{
				if (menu.getSelected() == menu.getNumberOfElements()-1)
					menu.enabled = false;
				else
					menu.MoveDown();
			}
			else if (e.key.code == sf::Keyboard::Enter && menu.getSelected() == 0)
			{
				SoundManager::GetInstance()->menuSelect.play();
				quit();
			}
		}
		else
		{
			if (e.key.code == sf::Keyboard::Down || e.key.code == sf::Keyboard::Enter)
			{
				menu.enabled = true;
				userName.text.setFillColor(sf::Color::Black);
				SoundManager::GetInstance()->menuNavigate.play();
			}
				
	
		}
		
				
	}
	if (e.type == sf::Event::TextEntered)
	{
		if (!menu.enabled)
		{
			userName.handleInput(e);
		}
	}
		
	

}

void TitleState::update(const float& dt)
{
	if (menu.enabled)
	{
		menu.update(dt);
	}	
	else
	{
		userName.update(dt);
	}
		

	track.acceleration += 1 * dt;
	track.update(dt);
}

void TitleState::drawToTexture(Renderer& renderer)
{
	renderer.rtx->clear();
	bg.drawElement(*renderer.rtx);
	renderer.rtx->draw(titleText);
	track.drawElement(*renderer.rtx);
	menu.drawElement(*renderer.rtx);
	userName.drawElement(*renderer.rtx);
	

	renderer.rtx->display();
	renderer.sprite->setTexture(renderer.rtx->getTexture());
	renderer.sprite->setScale(sf::Vector2f(2, 2));
}

int TitleState::nextState()
{
	return 0;
}

void TitleState::quit()
{
	exited = true;
}
