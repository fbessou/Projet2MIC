#include "CandyTeam.h"

using namespace Candy;
using namespace sf;

Team::Team(const Vector & base,const Vector & dir, const KeyBinding & keyConf):mScore(0),shipBase(base),direction(dir), keys(keyConf)
{

}
