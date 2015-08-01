#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_SOUND;
inherit STD_TELL_LONG;

void create_object(void);
int  query_room_id(void);
void reset(int arg);
void init(void);
int  do_throw(string str);
void spirit_enters(void);
void drop_eq(object thrower);

object armour,weapon,spirit;
string *throwers = ({}); // Newbies can get some starting eq from the spirit
                         // of the pond once a reset
int telling;

void create_object(void)
{
  set_short("By a forest pond (wu)");
  set_long("You are standing by a small forest pond. The brook dances "+
           "merrily down the stony slope to the west and runs down into "+
           "the dark, deep pond here, far into the dark woods. There are "+
           "many trees growing near the pond, and their roots stretch down "+
           "into it. The ground here is as stony and moss-covered as it "+
           "is in the rest of the forest.\n");
  set_new_light(5);
  set_dragon_visibility(1);
  set_room_hint("Throw a coin into the pond and see what happens. The "+
                "water spirit in it is nice to generous newbies;)\n");

  add_item("forest|woods","The forest around you is old and dark");
  add_item("pond","The pond is very dark and looks very, very deep. You "+
           "think you hear some sounds coming from it. It sounds almost "+
           "like some sort of chanting..");
  add_item("water","The water in the pond is very dark, and the pond looks "+
           "very deep");
  add_item("chanting","You can't see the chanting, but you could listen "+
           "to it perhaps?");
  add_item("$to chanting|$chanting","It sounds as if it is beckoning you "+
           "to do something, like throwing a coin into the pond... Strange");
  add_item("brook","It dances merrily down into the pond. The sound of it "+
           "is pleasant, but you think you hear another sound coming from "+
           "the pond too");
  add_item("$|$sound|$to sound","Sounds like chanting coming from the pond");
  add_item("slope","The stony ground slopes upwards to the west");
  add_item("tree|trees","The trees here do not have as much moss on their "+
           "branches as the trees elsewhere in this forest have. Perhaps "+
           "it has something to do with them being able to get water from "+
            "the pond");
  add_item("branch|branches","For some reason the moss growing everywhere "+
           "else in the forest does not grow on the branches of these "+
           "trees..");
  add_item("root|roots","The trees get water from the pond through their "+
           "roots");
  add_item("ground","It is a stony and moss-covered here as everywhere else "+
           "in the forest");
  add_item("moss","The brown moss grows everywhere on the stony ground");

  add_exit(NROOM+"troll_woods6","westup");

  add_sounds(10,10,({"The pleasant sound of the brook running down into "+
                     "the pond is all that you hear.\n"}));

  reset(0);
}

// Trolls use this function to know which room they
// are in and which way to go when they return home
int query_room_id(void)
{
  return 7;
}

void reset(int arg)
{
    ::reset(arg);
    throwers = ({});
}

void init(void)
{
  add_action("do_throw","throw");
  ::init();
}

int do_throw(string str)
{
  if(str == "coin" || str == "coin into pond" || str == "coin in pond" ||
     str == "coin into the pond" || str == "coin in the pond" ||
     str == "a coin into the pond")
  {
    if(telling)
    {
      W("Better not do that right now. Something seems to be happening.\n");
      return 1;
    }

    if(member_array(TP->QRN,throwers) == -1)
    {
      if(TP->query_money())
      {
        if(TP->query_level() > 4 && TP->query_level() < LEVELS_NEWBIE)
    {
          W("Somehow you get the feeling that you are too big for that.\n");
          return 1;
        }

        W("You toss a coin into the pond to see what happens.\n");
        S(TP->QN+" tosses a coin into the pond.\n");
        telling = 1;
        tell_long_message(({"","The coin sends ripples across the surface "+
                            "of the pond...\n",
                            "Suddenly a light starts shining deep down in "+
                            "the pond...\n",
                            "The light comes closer to the surface...\n",
                            "Suddenly a water spirit splashes through the "+
                            "surface, turning to look at you...\n",
                            "The water spirit smiles and says: I do like "+
                            "generous adventurers. Here is a little token "+
                            "of my liking.\n"}),3.0,TO);
        TP->add_money(-1);
        set_alarm(13.0,0.0,"spirit_enters");
        set_alarm(19.0,0.0,"drop_eq",TP);
        throwers += ({ TP->QRN });
        return 1;
      }
      W("Who are you trying to scam? You have no coins to throw into the "+
        "pond.\n");
      return 1;
    }
    W("Since you've already done it not too long ago, you decide it would "+
      "be wisest not to disturb the spirit so soon again.\n");
    return 1;
  }
}

void spirit_enters(void)
{
  spirit = make(NMONSTER+"spirit");
}

void drop_eq(object thrower)
{
  tell_room(TO,"The spirit drops some things on the ground "+
            "and disappears with a *splash!* into the pond again.\n");
  armour = make(NARMOUR+"newbie_armour");
  armour->set_me_to_armour();
  armour = make(NARMOUR+"newbie_armour");
  weapon = make(NWEAPON+"newbie_weapon");
  spirit->destroy();
  telling = 0;
}
