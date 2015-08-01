//===========================================================================
// troll_master - Master file controlling the movements of the trolls.
//                They come out at night and wander randomly around the
//                forest until dawn when they start walking back. If a troll
//                child comes across a player at this time, it will stay 
//                in the room as long as the player does and peer at the
//                player deciding if it should take the player home for
//                dinner, and then perhaps turn to stone.
// Yoda 970930
//---------------------------------------------------------------------------
// Did some hacking here with the alarms to actually make it work as it
// should since set_event apparently won't work anymore
//
// Yoda 990416
//----------------------------------------------------------------------------
// Redid this crap completely since it sort of sucked. Moved the waking up
// and going home code to the troll so each troll takes care of itself.
// This object just keeps track of time and tells each troll to wake up
// or start going home when it's time now.
//
// Yoda 990417
//============================================================================
#pragma strict_types
#include "../def.h";
inherit STD_STDOBJ;

void create_object(void);
void test(int wake);
void add_troll(object troll);
void remove_troll(object troll);
void check_time(void);

int trolls_awake;      // 0 during the day, 1 during the night
object *trolls = ({}); // Array of the troll objects

void create_object(void)
{
  trolls_awake = 0;
  set_alarm(10.0,300.0,"check_time");
}

void test(int wake)
{
  int i;

  if(wake)
  {
    W("You wake up the trolls.\n");
    for(i = 0; i < sizeof(trolls); ++i)
    {
      trolls[i]->wake_up();
    }
    trolls_awake = 1;
  }
  else
  {
    W("You tell the trolls to go home.\n");
    for(i = 0; i < sizeof(trolls); ++i)
    {
      trolls[i]->go_home();
    }
    trolls_awake = 0;
  }
}

void add_troll(object troll)
{
  trolls += ({ troll });
}

void remove_troll(object troll)
{
  trolls -= ({ troll });
}

void check_time(void)
{
  int i;

  if(query_hour() >= 22 || query_hour() < 2)
  {
    if(!trolls_awake)
    {
      for(i = 0; i < sizeof(trolls); ++i)
      {
        trolls[i]->wake_up();
      }
      trolls_awake = 1;
      write_file(TROLL_LOG,sizeof(trolls) + " trolls woke up at "+
                 ctime(time()) + ".\n");
    }
  }
  else   
  if(query_hour() >= 3 && query_hour() < 22)
  {
    if(trolls_awake)
    {
      for(i = 0; i < sizeof(trolls); ++i)
      {
        trolls[i]->go_home();
      }
      trolls_awake = 0;
      write_file(TROLL_LOG,sizeof(trolls) + " trolls started going "+
                 "home at " + ctime(time()) + ".\n");
    }
  }
}
