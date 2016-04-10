//Title cpp
#include "TitleScreen.h"
TitleScreen::TitleScreen()
{
}

TitleScreen::~TitleScreen()
{
}

void TitleScreen::LoadContent()
{
	al_init_font_addon();
	al_init_ttf_addon();
	font = al_load_font("xcelv3i.ttf", 30, NULL);
}

void TitleScreen::UnloadContent()
{
	al_destroy_font(font);
}

void TitleScreen::Update(ALLEGRO_EVENT ev)
{
	if (input.IsKeyPressed(ev, ALLEGRO_KEY_ENTER))
		ScreenManager::GetInstance().AddScreen(new SplashScreen);
}

void TitleScreen::Draw(ALLEGRO_DISPLAY *display)
{
	al_draw_text(font, al_map_rgb(255, 255, 255), 100, 100, NULL, "TitleScreen");
}