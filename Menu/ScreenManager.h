#pragma once

#include<string>
#include"GameScreen.h"
#include"SplashScreen.h"
#include"TitleScreen.h"

#include<iostream>
using namespace std;

//Allegro Inits
#include<allegro5\allegro.h>

#define ScreenWidth 800
#define ScreenHeight 600

class ScreenManager
{
	private:
		ScreenManager();
		ScreenManager(ScreenManager const&);
		void operator =(ScreenManager const&);

		string text;
		
	public:
		~ScreenManager();
		static ScreenManager &GetInstance();

		void AddScreen(GameScreen *screen);

		void Initialise();
		void LoadContent();
		void Update(ALLEGRO_EVENT ev);
		void Draw(ALLEGRO_DISPLAY *display);
};

