#pragma once
//ScreenManager Header
#include<string>
#include"GameScreen.h"
#include"SplashScreen.h"
#include"TitleScreen.h"
#include"FadeAnimation.h"

#include<iostream>
using namespace std;

//Allegro Inits
#include<allegro5\allegro.h>
#include<allegro5\allegro_image.h>

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

		ALLEGRO_BITMAP *transitionImage;
		GameScreen *currentScreen, *newScreen;
		FadeAnimation transition;

		void Transition();

		bool startTransition;
	public:
		~ScreenManager();
		static ScreenManager &GetInstance();

		void AddScreen(GameScreen *screen);

		void Initialise();
		void LoadContent();
		void UnloadContent();
		void Update(ALLEGRO_EVENT ev);
		void Draw(ALLEGRO_DISPLAY *display);
};

