#pragma once

#include<allegro5\allegro.h>
#include<allegro5\allegro_image.h>
#include<allegro5\allegro_font.h>
#include "InputManager.h"
#include<string>
using namespace std;
class Animation
{
	public:
		Animation();
		~Animation();

		virtual	void LoadContent(ALLEGRO_BITMAP *image, string text, float position[2]);
		virtual	void UnloadContent();
		virtual void Update(InputManager input);
		void Draw(ALLEGRO_DISPLAY *display);

		virtual void SetAlpha(float value);
		float GetAlpha();

		void SetIsActive(bool value);
		bool GetIsActive();

	protected:
		ALLEGRO_BITMAP *image, *sourceRect;
		ALLEGRO_FONT *font;
		string text;
		float position[2];
		float alpha;
		bool isActive; // if animation is active or not (dont want to create animation we dont want to use at a particular time)
};

