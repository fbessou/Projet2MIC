#ifndef _CANDY_COMMON_H_
#define _CANDY_COMMON_H_
#include <string>
namespace Candy
{
#ifdef CANDY_DOUBLE_PRECISION
typedef double Real;
#else
typedef float Real;
#endif

enum TransformSpace
{
	TS_WORLD,
	TS_LOCAL
};
/**
 * @todo move it appart from the library
 */
enum Layer
{
	PARTICLE_LAYER = 4,
	BONUS_LAYER = 3,
	BULLET_LAYER = 2,
	SHIP_LAYER =1

};
	//forward declarations
	class Actor;
	class ActorComparator;
	class BasicWeapon;
	class Body;
	class Bullet;
	class Game;
	class MeasureBar;
	class Particle;
	class Play;
	class Settings;
	class Ship;
	class Team;
	class TextureManager;
	class Weapon;
	class Vector;
	class World;
};
#endif
