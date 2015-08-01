//======================================================================
// fishing_pole.c - Fishing pole for use in the fish tale quest
//======================================================================
// Changed to spam a bit less when fighting, per Shade's request
// Yoda - 990410
//----------------------------------------------------------------------
#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void  create_object(void);
void  init(void);
int   do_kill(string str);
int   wielding_func(object ob);
mixed weapon_hit(object attacker);

void create_object(void)
{
  set_name("fishingpole");
  add_id("fishing pole");
  add_id("pole");
  set_short("A fishing pole");
  set_long("A nice, long, wooden fishing pole. You bet you could catch some "+
           "fine fish with this pole wielded!\n");
  set_value(5);
  set_weight(1);
  set_type("blunt");
  set_class(5);
  set_material("wood");
  set_property("poor");
  set_wield_func(TO);
  set_hit_func(TO);
}

void init(void)
{
  add_action("do_kill","kill");
  ::init();
}

int do_kill(string str)
{
  if(str && wielded_by == TP)
  {
    W("You raise your fishing pole and yell: GONE FISHING!!!\n");
    S(TP->QN+" raises the fishing pole and yells: GONE FISHING!!!\n");
  }
}

int wielding_func(object ob)
{
  W("You feel a great urge to go fishing!\n");
  S(TP->QN+" mumbles something about this day being a good one for "+
    "fishing.\n");
  set_wielding_extra("With the fishing pole wielded, "+TP->QN+" promises "+
                     "to be a nightmare in any fishing contest.\n");
  return 1;
}

// Spam chance changed from random(6) to random(15)
// Yoda - 990410
mixed weapon_hit(object attacker)
{
  switch(random(15))
  {
    case 0: W("You wish you were somewhere else fishing instead of here.\n");
            S(C(query_wield()->QN)+" puts some bait on the hook of the "+
              "fishing pole.\n");
            return 0;
      break;
    case 1: W("You start telling your enemy a fish tale, hoping to "+
              "impress.\n");
            S(C(query_wield()->QN)+" says: Once I caught a fish that was so "+
              "big it ate my boat. I had to wrestle it and kill it with my "+
              "bare hands!\n");
            return 0;
      break;
    case 2: W("You start to think nostalgically of the one that got away...\n");
            S(C(query_wield()->QN)+" says: I once hooked a whale with this "+
              "pole. I would have caught it too, if only the line hadn't "+
              "snapped *ack*!\n");
            return 0;
      break;
    default: return 0;
      break;
  }
}

