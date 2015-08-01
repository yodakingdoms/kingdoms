//======================================================================
// A weapon with a special attack that is really way to good for an avg
// weapon, but the special only happens if the player using it is below
// level 5, so it should be ok. It can be found in the trollcave.
// Yoda 970930
//----------------------------------------------------------------------
// Made uninnable. The mithril sack armour required this, so I figured
// i might as well do it to this thing too
// Yoda 990410
//======================================================================
#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void  create_object(void);
mixed query_prevent_login(void);
void  init(void);
int   do_kill(string str);
int   wielding_func(object ob);
mixed weapon_hit(object attacker);

void create_object(void)
{
  set_name("stick");
  add_id("wooden stick");
  set_short("A twisted wooden stick");
  set_long("A very twisted wooden stick. You can't think of anything this "+
           "stick could be good for, except perhaps be wielded as a very "+
           "poor weapon.\n");
  set_value(5);
  set_weight(1);
  set_type("blunt");
  set_class(5);
  set_material("wood");
  set_property(({"average","magic"}));
  set_wield_func(TO);
  set_hit_func(TO);
}

// Added 990410 - Yoda
mixed query_prevent_login(void)
{
  return 1;
}

void init(void)
{
  add_action("do_kill","kill");
  ::init();
}

int do_kill(string str)
{
  if(str && wielded_by == TP && wielded_by->query_level() < 5)
  {
    W("You feel a strange tingling in the hand you wield the stick in.\n");
  }
}

int wielding_func(object ob)
{
  if(TP->query_level() < 5)
  {
    W("Hmm, you feel a strange tingling in your arm.\n");
    return 1;
  }
  return 1;
}

mixed weapon_hit(object attacker)
{
  if(wielded_by->query_level() > 4)
  {
    return 0;
  }

  switch(random(20))
  {
    case 0 .. 4: W("The stick takes controll of itself and pokes your "+
                   "foe in an uncomfortable place!\n");
                 return 5;
      break;
    case 5 .. 7: W("The stick takes control of itself and pokes your "+
                   "foe in the eye!\n");
                  return 8;
      break;
    case 8 .. 9: W("You smack your enemy over the head and a bright flash "+
                   "comes from your stick!!!\nYou smell some burnt flesh.\n");
                 return 10;
      break;
    case 10: W("Suddenly the stick takes control of your mind. You recite "+
               "an ancient spell and see a glow appear around the stick as "+
               "you smash your enemy with strength you did not think you "+
               "had!\n");
              return 15;
      break;
    default: return 0;
      break;
  }
}

