//=====================================================================
// troll - A generic troll for cloning troll children. The trolls turn
//         to stone if they're outside when the sun comes up, and then
//         they will not be recloned when the room they should be in
//         resets
//=====================================================================
#pragma strict_types
#include "../def.h"
inherit STD_MOV_MONSTER;
inherit MOD_TROLL;

string *short_descs = ({"A small troll child","A fat troll child",
                        "A tall troll child","An ugly troll child",
                        "A smelly troll child","A stinking troll child"});
string *long_descs = ({"This is a really small troll child. It's as ugly "+
                       "as they usually are anyway. It has grey skin, red, "+
                       "nasty eyes and a big, ugly nose and stripy hair.",
                       "This is a fat troll child, it has a huge belly, "+
                       "which it no doubt would like to fill with you even "+
                       "if it is just a child.",
                       "This troll is tall for being a child. Its red, "+
                       "nasty eyes are almost at the same level as yours "+
                       "are. It grins evilly at you.",
                       "This troll child has to be the ugliest thing you "+
                       "have ever seen, even by troll standards. Yeack, "+
                       "you don't even want to look at for long enough "+
                       "to be able to describe it properly.",
                       "Hold your nose. This troll child smells as bad as "+
                       "all the other troll children put together, even "+
                       "if they all smell pretty bad too!",
                       "This troll child is pretty ugly, but what's worse "+
                       "is that it seems to have rolled around in some "+
                       "garbage, making it stink really badly. The sad thing "+
                       "is that you're happy the stink obscures the normal "+
                       "troll smell."});

void create_object(void);
void wake_up(void);
void go_home(void);

void create_object(void)
{
  int desc = random(6);         
  set_name("troll");
  add_id("child");
  add_id("troll_child");
  add_id("troll child");
  add_id("living_troll");
  set_short(short_descs[desc]);
  set_long(long_descs[desc]+" You can't even tell if it is a boy or a girl "+
           "troll child.\n");
  set_race("newbie island troll");
  set_al(-20);
  set_level(2);
  set_str(10);
  set_dex(10);
  set_hp(100);
  set_wc(10);
  set_new_ac(10);
  set_type("blunt");
  set_skill("blunt",20);
  set_skill("unarmed",20);
  set_unarmed(1);
  set_time_slice(20);
  
  load_chat(10,({"The troll smells bad.\n",
                 "The troll grins evilly at you.\n",
                 "The troll says: I think we will have you for dinner "+
                 "this night, hehe.\n"}));
  load_a_chat(20,({"The troll says: Ack, why do you have to kill me? I just "+
                   "wanted to eat you.\n",
                   "The troll fights clumsily.\n",
                   "The troll staggers.\n",
                   "The troll says: My father will eat you for this.\n"}));

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
       init_command("out");
      break;
    case 11:
       init_command("south");
      break;
    default: 
       tell_room(ENV(TO),"The troll looks a bit lost.\n");
      break;
  }
 
  if(ENV(TO)->query_room_id() >= 11)
  {
    delay = 5.0 + itof(random(5));
    set_alarm(delay,0.0,"wake_up");
  }
  else
  {
    set_walking();
  }
}

void go_home(void)
{
  float delay;

  if(!present_player(ENV(TO)))
  {
    switch(ENV(TO)->query_room_id())
    {
      case 1: case 3: case 6: case 10:
          init_command("north");
        break;
      case 2: case 5: case 9: case 12:
          init_command("northwest");
        break;
      case 4: case 8:
          init_command("northeast");
        break;
      case 7:
          init_command("westup");
        break;
      case 11:
          if(ENV(TO)->query_rock_moved())
	  {
            init_command("enter cave");
	  }
          else
	  { 
            tell_room(ENV(TO),"The troll tries to move the "+
                      "rock to enter its home but it is too weak.\n"+
                      "The troll sobs and cries and looks frightened.\n");
	  }
        break;
      default:
          tell_room(ENV(TO),"The troll looks a bit lost.\n");
          init_command("northeast");
          init_command("southdown");
        break;
    }
  }
  else
  {
    if(ENV(TO)->query_room_id() == 11)
    {
       if(!ENV(TO)->query_rock_moved())
       {
         tell_room(ENV(TO),"The troll tries to move the "+
                   "rock to enter its home but it is too weak.\n"+
                   "The troll sobs and cries and looks frightened.\n");
       }
       else
       {
         init_command("enter cave");
       }
    }
    else
    {
      tell_room(ENV(TO),"The troll grins nastily at you and "+
                "scratches its head in an evil way.\n");
    }
  }

  if(ENV(TO)->query_room_id() != 13)
  {
    delay = 5.0 + itof(random(5));
    set_alarm(delay,0.0,"go_home");
  }
  else
  {
    stop_walking();
  }
}
