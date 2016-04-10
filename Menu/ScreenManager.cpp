#include "ScreenManager.h"
//ScreenMangaer cpp
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
	transition.SetAlpha(0);
	startTransition = true;
	newScreen = screen;
	transition.SetIsActive(true);
}

void ScreenManager::Initialise()
{
	currentScreen = new SplashScreen();
}

void ScreenManager::LoadContent()
{
	currentScreen->LoadContent();
	transitionImage = al_load_bitmap("image1.png");
	float position[2] = { 0, 0 };
	transition.LoadContent(transitionImage,"",position);
	startTransition = false;
}
void ScreenManager::UnloadContent()
{
	al_destroy_bitmap(transitionImage);
	transition.UnloadContent();
}
void ScreenManager::Update(ALLEGRO_EVENT ev)
{
	if (!startTransition)
		currentScreen->Update(ev);
	else
		Transition();
}

void ScreenManager::Draw(ALLEGRO_DISPLAY *display)
{
	currentScreen->Draw(display);
	if (startTransition)
		transition.Draw(display);

}

void ScreenManager::Transition()
{
	transition.Update(currentScreen->GetInput());
	if (transition.GetAlpha() >= 255)
	{
		transition.SetAlpha(255);

		currentScreen->UnloadContent();
		delete currentScreen;
		currentScreen = newScreen;
		currentScreen->LoadContent();

		al_rest(1.0);
	}
	else if (transition.GetAlpha() <= 0)
	{
		startTransition = false;
		transition.SetIsActive(false);
	}
}