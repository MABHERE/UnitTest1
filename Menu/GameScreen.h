#pragma once
//GameScreen header
#include<allegro5\allegro.h>
class GameScreen
{
public:
	GameScreen();
	~GameScreen();

	virtual void LoadContent();
	virtual void UnloadContent();
	virtual void Update(ALLEGRO_EVENT ev);
	virtual void Draw(ALLEGRO_DISPLAY *display);
};

