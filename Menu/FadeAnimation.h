#pragma once
#include "Animation.h"

class FadeAnimation : public Animation
{
	public:
		FadeAnimation();
		~FadeAnimation();

		void LoadContent(ALLEGRO_BITMAP *image, string text, float position[2]);
		void UnloadContent();
		void Update(InputManager input);

		void SetAlpha(int value);
	private:
		float fadespeed;
		bool increase;
};

