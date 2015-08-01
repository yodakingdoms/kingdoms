//=====================================================================
// troll - A generic troll for cloning the adult trolls. The trolls turn
//         to stone if they're outside when the sun comes up, and then
//         they will not be recloned when the room they should be in
//         resets
//=====================================================================
#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;
inherit MOD_TROLL;

// Keeps track of how many loops the troll
// has waited by the entrance for the children
// before it enters the cave itself
int waits;

void create_object(void);
void wake_up(void);
void go_home(void);

void create_object(void)
{
  set_name("troll");
  add_id("living_troll");
  add_id("adult_troll");
  set_short("An ugly troll");
  set_long("A really ugly troll. It is taller than you are and it has "+
           "long, stripy hair. It has hard, grey skin and it peers "+
           "nastily at you with its black eyes. This troll looks really "+
           "mean and ugly!\n");
  set_race("newbie island troll");
  set_al(-20);
  set_level(4);
  set_wc(10);
  set_new_ac(10);
  set_type("blunt");
  set_skill("blunt",40);
  set_skill("unarmed",40);
  set_unarmed(1);
  
  load_chat(10,({"The troll smells bad.\n",
                 "The troll grins evilly at you.\n",
                 "The troll says: I think we will have you for dinner "+
                 "this night, hehe.\n"}));
  load_a_chat(20,({"The troll says: Ack, why do you have to kill me? I just "+
                   "wanted to eat you.\n",
                   "The troll fights clumsily.\n",
                   "The troll staggers.\n"}));

  ::create_object();
}

void wake_up(void)
{
  float delay;

  switch(ENV(TO)->query_room_id())
  {
    case 13:
        init_command("southeast"); 
      break;
    case 12:
        if(!ENV(TO)->query_exit("out"))
	{
          init_command("move rock");
	}
        else
        {
          init_command("out");
	}
      break;
    case 11:
        init_command("south");
      break;
    default: 
        tell_room(ENV(TO),"The big troll looks a bit lost.\n");
      break;
  }
 
  if(ENV(TO)->query_room_id() >= 11)
  {
    delay = 2.0 + itof(random(5));
    set_alarm(delay,0.0,"wake_up");
  }
}

void go_home(void)
{
  switch(ENV(TO)->query_room_id())
  {
    case 1: case 3: case 6: case 10:
        init_command("north");
      break;
    case 2: case 5: case 9:
        init_command("northwest");
      break;
    case 4: case 8:
        init_command("northeast");
      break;
    case 7:
        init_command("westup");
      break;
    case 11:
        if(!ENV(TO)->query_rock_moved())
	{
          init_command("move rock");
	}
        else
	{ 
          if(waits >= 30)
	  {
            init_command("enter cave");
            waits = 0;
	  }
	}
        ++waits;
      break;
    case 12:
        if(ENV(TO)->query_exit("out"))
	{
          init_command("move rock");
	}
        else
	{
          init_command("northwest");
	}
      break;
  }

  if(ENV(TO)->query_room_id() != 13)
  {
    set_alarm(5.0,0.0,"go_home");
  }
}
