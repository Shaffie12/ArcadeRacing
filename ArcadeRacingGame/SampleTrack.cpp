#include "SampleTrack.h"

SampleTrack::SampleTrack()
{
	colors = {
		std::make_pair("grassLight",sf::Color::Green),
		std::make_pair("grassDark",sf::Color(55, 154, 84)),
		std::make_pair("roadLight",sf::Color(178, 195, 183)),
		std::make_pair("roadDark",sf::Color(188, 205, 190)),
		std::make_pair("rumble1",sf::Color::Red),
		std::make_pair("rumble2",sf::Color::White)
	};
	segments =
	{
		Segment(0,0,100),
		
	
	};
	objects =
	{

	};

	calculateTotalLength();
}