#include "SplashScreen.h"


InputManager splashInput;

SplashScreen::SplashScreen()
{
}


SplashScreen::~SplashScreen()
{
}

void SplashScreen::LoadContent()
{
	al_init_font_addon();
	al_init_ttf_addon();
	font = al_load_font("Xcelsion.ttf", 30, NULL);
}

void SplashScreen::UnloadContent()
{
	al_destroy_font(font);
}

void SplashScreen::Update(ALLEGRO_EVENT ev)
{
	if (splashInput.IsKeyPressed(ev, ALLEGRO_KEY_Z))
		ScreenManager::GetInstance().AddScreen(new TitleScreen);
}

void SplashScreen::Draw(ALLEGRO_DISPLAY *display)
{
	al_draw_text(font, al_map_rgb(0, 0, 255), 100, 100, NULL, "SplashScreen");
}