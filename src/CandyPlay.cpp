#include "CandyPlay.h"
#include "CandyPause.h"
#include "CandyShip.h"
#include "CandyBonus.h"
#include "CandyWorld.h"
#include "CandyAsteroid.h"

using namespace Candy;
using namespace sf;

Play::Play(Game * game, RenderWindow * window):
	GameState(game,window),
	mNextAsteroidPopDate(2),
	mEnded(false),
	mGameOverText("",game->getFont(),60),
	mGameOverSubText("",game->getFont(),45),
	mWorld(window),
	mClock(0)
{
	
	sf::FloatRect rect = mGameOverText.getLocalBounds();
	mGameOverText.setOrigin(rect.left+rect.width/2.0f,rect.top+rect.height/2.0f);
	mGameOverText.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f));

	rect = mGameOverSubText.getLocalBounds();
	mGameOverSubText.setOrigin(rect.left+rect.width/2.0f,rect.top+rect.height/2.0f+150);
	mGameOverSubText.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f));
	/* On met une jolie texture de ciel etoile*/
	mBackground.setTexture(TextureManager::getInstance().getTexture("NightSky"));
	mBackground.setTextureRect(IntRect(0,0,800,600));

	/*On cree chaque equipe*/
	mTeam1 = new Team(sf::Color(255,27,11,255),Vector(400,70),Vector::UNIT_Y,game->getSettings().mBinding1);
	mTeam2 = new Team(sf::Color(10,106,255,255),Vector(400,530),-Vector::UNIT_Y,game->getSettings().mBinding2);
	mTeam1->setOpponent(mTeam2);
	mTeam2->setOpponent(mTeam1);
	/*On rajoute les vaisseaux*/
	
	mWorld.addActor( mTeam1->getShip());
	mWorld.addActor( mTeam2->getShip());
}

Play::~Play(){
delete mTeam1;
delete mTeam2;
}

void Play::enter(){
	/* On redefini le titre */
	mWindow->setTitle("Candy Saga");
}

void Play::leave(){}

void Play::showOverlays() const
{
	mWindow->draw(mTeam1->getShip()->getLifeBar());
	mWindow->draw(mTeam2->getShip()->getLifeBar());
}

bool Play::update(const Real & timeSinceLastFrame)
{
	mClock+=timeSinceLastFrame;
	//update background
	auto rect = mBackground.getTextureRect();
	rect.left= 1000*sin(mClock/5);
	rect.top = 10000*sin(mClock/50);
	mBackground.setTextureRect(rect);
	mWindow->clear();
	mWindow->draw(mBackground);

	//update only if we are not in pause state
	if(timeSinceLastFrame!=0)
	{

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			mGame->changeState(new Pause(mGame,mWindow,this));
		
		}
		else if(!mEnded)
		{
			//update logic
			asteroidGeneration(timeSinceLastFrame);
			mWorld.step(timeSinceLastFrame);
			if(mTeam1->getShip()->getLife()==0)
			{
				mGameOverText.setString("Le joueur bleu gagne!");
				mGameOverSubText.setString("Rouge : "+std::to_string(mTeam1->getScore())+"\nBleu : "+std::to_string(mTeam2->getScore()));
				mEnded=true;
			}
			else if(mTeam2->getShip()->getLife()==0)
			{
				mGameOverText.setString("Le joueur rouge gagne!");
				mGameOverSubText.setString("Rouge : "+std::to_string(mTeam1->getScore())+"\nBleu : "+std::to_string(mTeam2->getScore()));
				mEnded=true;
			}
		}

	}
	//On affiche la scene
	mWorld.render();
	//On affiche les overlays
	showOverlays();
	if(mEnded && timeSinceLastFrame>0)
	{
		sf::FloatRect rect = mGameOverText.getLocalBounds();
		mGameOverText.setOrigin(rect.left+rect.width/2.0f,rect.top+rect.height/2.0f);
		mGameOverText.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f));

		rect = mGameOverSubText.getLocalBounds();
		mGameOverSubText.setOrigin(rect.left+rect.width/2.0f,rect.top+rect.height/2.0f-150);
		mGameOverSubText.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f));
		mWindow->draw(mGameOverText);
		mWindow->draw(mGameOverSubText);
	}

	return true;
}

void Play::updateSettings()
{
	mTeam1->keys=mGame->getSettings().mBinding1;
	mTeam2->keys=mGame->getSettings().mBinding2;
}

void Play::onLostFocus()
{
	mGame->changeState(new Pause(mGame,mWindow,this));
}

void Play::asteroidGeneration(const Real & timeSinceLastFrame)
{
	if(mClock>mNextAsteroidPopDate)
	{
		bool screenPart = Math::IntURNG::randomByte()%2;

		Vector w = mWindow->getSize();
		Vector pos = Vector(0,
				Math::RealURNG::normalised()*400-200);
		pos+=Vector(0,w.y/2);
		Vector velocity;
		if(screenPart)
		{
			pos-=Vector(50,0);
			velocity=Vector(40+Math::RealURNG::normalised()*40,0);
		}else
		{
			pos+=Vector(w.x+50,0);
			velocity=Vector(-40-Math::RealURNG::normalised()*40,0);
		}
		mWorld.addActor(new Asteroid(&mWorld,pos,velocity));
		mNextAsteroidPopDate=mClock+Math::RealURNG::normalised()*1.5;
	}

}
