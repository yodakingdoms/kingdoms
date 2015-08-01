//=====================================================================
// troll_mod - Module containing the 'turn to stone' code for the 
//             trolls. Inherited by troll.c and troll_child.c
//=====================================================================
#pragma strict_types
#include "../def.h"

void create_object(void);
void destroy_object(void);
void catch_tell(string message);
void sunrise(int line);
void turn_to_stone(void);

void create_object(void)
{
  // Add the troll to the objects seing the sunrise message
  SYS_SUN->add_notify_object(TO);
  // Add the trolls to the trolls controlled by the trollmaster
  TROLL_MASTER->add_troll(TO);
}

void destroy_object(void)
{
  // Remove it when it is killed
  SYS_SUN->remove_notify_object(TO);
  TROLL_MASTER->remove_troll(TO);
}

void catch_tell(string message)
{
  string junk;
  if(sscanf(message,"The sun appears over the eastern horizon%s",junk) == 1 ||
     sscanf(message,"The sun rises high into the sky%s",junk) == 1)
  {
    set_alarm(3.0,0.0,"sunrise",0);
  }
}

void sunrise(int line)
{
  string *turns_to_stone = ({"The troll spins around with a terrified look "+
                             "on its face.\n",
                             "The troll gasps in horror as it realizes it "+
                             "has stayed out too long.\n",
                             "The troll raises its arms, as if trying to "+
                             "shield itself from the suns rays, but the "+
                             "curse of its race is unforgiving...\n"});

  tell_room(ENV(TO),turns_to_stone[line]);
  ++line;
  if(line < 3)
  {
    set_alarm(3.0,0.0,"sunrise",line);
  }
  else
  {
    set_alarm(3.0,0.0,"turn_to_stone");
  }
}

void turn_to_stone(void)
{
  int i;
  object statue;
  object *players;

  tell_room(ENV(TO),"The troll turns to stone.\n");
  statue = TO->make(NOBJECT+"stone_troll",ENV(TO));
  switch(TO->query_level())
  {
    case 2: statue->set_long("This stone statue is what is left of a "+
                             "little troll child that stayed outdoors for "+
                             "too long and was turned to stone by the sun "+
                             "at dawn. You can still see the terror it must "+
                             "have felt when it realized dawn was coming in "+
                             "the stony features of the statues face.\n");
      break;
    default: statue->set_long("This stone statue is what is left of a "+
                              "big island troll that stayed outdoors for "+
                              "too long and was turned to stone by the sun "+
                              "at dawn. You can still see the terror it must "+
                              "have felt when it realized dawn was coming in "+
                              "the stony features of the statues face.\n");
      break;
  }

  // This will only be logged for a while to see how often it happens
  // and if it was worth the effort -- Yoda Nov 9 1997
  write_file(TROLL_LOG,"A troll got stoned at "+ctime(time())+".\n");
  write_file(TROLL_LOG,"  This happened in " + name_file(ENV(TO)) + ".\n");
  if(present_player(ENV(TO)))
  {
    write_file(TROLL_LOG,"  There was actually somebody there to see it!\n");
    players = ENV(TO)->query_players_here();
    for(i = 0; i < sizeof(players); ++i)
    {
      write_file(TROLL_LOG,"  " + C(players[i]->QRN) + " witnessed the "+
                 "stoning!\n");
    }    
  }
  else
  {
    write_file(TROLL_LOG,"  But nobody was there to see it.\n");
  }
  TO->destroy();
}


