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
	PARTICLE_LAYER = 0,
	BONUS_LAYER = 1,
	BULLET_LAYER = 2,
	SHIP_LAYER =3

};

};
#endif
