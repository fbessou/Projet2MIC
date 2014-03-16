#ifndef _CANDY_COMMON_H_
#define _CANDY_COMMON_H_
#include <string>
typedef std::string string;
namespace Candy
{
#ifdef CANDY_DOUBLE_PRECISION
typedef double Real;
#else
typedef float Real;
#endif

};	
#endif
