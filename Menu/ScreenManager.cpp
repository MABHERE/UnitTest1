#include "ScreenManager.h"

ScreenManager &ScreenManager::GetInstance()
{
	static ScreenManager instance;
	return instance;
}

ScreenManager::ScreenManager()
{
}


ScreenManager::~ScreenManager()
{
}

void ScreenManager::AddScreen(GameScreen *screen)
{
	newScreen = screen;
	currentScreen->UnloadContent();
	currentScreen = newScreen;
	currentScreen->LoadContent();
}

void ScreenManager::Initialise()
{
	currentScreen = new SplashScreen();
}

void ScreenManager::LoadContent()
{
	currentScreen->LoadContent();
}

void ScreenManager::Update(ALLEGRO_EVENT ev)
{
	currentScreen->Update(ev);
}

void ScreenManager::Draw(ALLEGRO_DISPLAY *display)
{
	currentScreen->Draw(display);
}