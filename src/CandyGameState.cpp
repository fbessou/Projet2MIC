#include "CandyGameState.h"

using namespace Candy;
using namespace sf;

GameState::GameState(Game * game, RenderWindow * window):mWindow(window),mGame(game)
{
	
}
GameState::~GameState(){
}

void GameState::onLostFocus()
{
	
}

void GameState::onGainFocus()
{

}
