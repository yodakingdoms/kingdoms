//======================================================================
// This corpse is made when Woody the magic powder barrel dies. The
// standard corpse won't let me set start decay to 1 (=pile of dust)
// for some reason so I do it this way instead.
// Yoda - 20050123
//======================================================================
#pragma strict_types
#include "../def.h"
inherit SYS_CORPSE;

void reset(int arg);

void reset(int arg)
{
  ::reset(arg);
  set_name("woody");
  start_decay = 1;
}
