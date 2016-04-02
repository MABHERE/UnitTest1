#pragma once
//InputManager Header
#include<allegro5\allegro.h>
#include<allegro5\keyboard.h>
#include<vector>
#include<iostream>
using namespace std;

class InputManager
{
	private:
		ALLEGRO_KEYBOARD_STATE keystate;
	public:
		InputManager();
		~InputManager();

		bool IsKeyPressed(ALLEGRO_EVENT ev, int key);
		bool IsKeyPressed(ALLEGRO_EVENT ev, vector<int> keys);

		bool IsKeyReleased(ALLEGRO_EVENT ev, int key);
		bool IsKeyReleased(ALLEGRO_EVENT ev, vector<int> keys);
};

