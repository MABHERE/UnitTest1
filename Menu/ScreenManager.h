#pragma once
//ScreenManager Header
#include<string>
#include"GameScreen.h"
#include"SplashScreen.h"
#include"TitleScreen.h"

#include<iostream>
using namespace std;

//Allegro Inits
#include<allegro5\allegro.h>

//Screen Width and Heigth
#define ScreenWidth 800
#define ScreenHeight 600

class ScreenManager
{
	private:
		ScreenManager();
		ScreenManager(ScreenManager const&);
		void operator =(ScreenManager const&);

		string text;
		GameScreen *currentScreen;
	public:
		~ScreenManager();
		static ScreenManager &GetInstance();

		void AddScreen(GameScreen *screen);

		void Initialise();
		void LoadContent();
		void Update(ALLEGRO_EVENT ev);
		void Draw(ALLEGRO_DISPLAY *display);
};

