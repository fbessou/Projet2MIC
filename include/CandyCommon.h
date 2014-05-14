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

};	
#endif
