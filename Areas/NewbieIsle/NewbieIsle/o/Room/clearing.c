#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void   create_object(void);
void   fire_dies(void);
void   init(void);
void   reset(int arg);
int    do_rest(string str);
int    do_light(string str);
int    do_break(string str);
int    do_extinguish(string str);
string long_fun(void);
void   fireplace_desc(void);
void   fire_desc(void);

int fire_lit,branches_left,alarm;

void create_object(void)
{
  set_short("Clearing (wd/e)");
  set_long("#long_fun");
  set_new_light(5);
  set_dragon_visibility(3);

  add_exit(NROOM+"slope","westdown");
  add_exit(NROOM+"path1","east");
//  add_exit(NROOM+"adv_guild","climb");

  add_item("clearing","A nice place to rest before exploring the rest "+
           "of the island");
  add_item("trees","Tall, green trees grow around you. You think "+
           "you can see the ocean through the ones to the west");
/*
  Removing this since there's a guild in Hazeldown now
  -- Yoda 040415
  add_item("tree","A huge tree. There is a platform up there, and a rope "+
           "ladder hanging down from the platform makes it easy to get up "+
           "there. You notice a small sign by the tree");
  add_item("sign|@sign","It says:\n\n" +
                        "  Second Floor: The Newbie Island Adventurer's "+
                        "Guild");
  add_item("platform|wooden platform","A wooden platform up there in the "+
           "tree");
  add_item("rope ladder|ladder","You could climb it to get up to the "+
           "platform");
*/
  add_item("ocean|sea","Yes, you see the grey/blue sea through the trees "+
           "to the west");
  add_item("campsite","Well, it looks like a campsite since there is what "+
           "appears to be a fireplace, and some logs to sit on here");
  add_item("grass","The grass here is short and looks well trodden upon");
  add_item("ground","The ground is covered with short grass that looks " +
           "well trodden upon");
  add_item("circle|stones|fireplace","#fireplace_desc");
  add_item("remains|fire","#fire_desc");
  add_item("stone","It is a flat, gray stone on the ground next to other "+
           "flat, gray stones");
  add_item("log|logs","They look just like the kind of logs that people "+
           "sit on when they need a rest. Perhaps making use of them would "+
           "be nice after all the work you've done lately?");
  add_item("bush|bushes","Bushes grow around the clearing. Their branches "+
           "look a bit short and thin though");
  add_item("branch|branches","It looks as if people have been breaking off "+
           "branches to use as firewood in the fireplace. Perhaps you "+
           "could too if the fire is out?");
  add_item("path","Winds it's way between trees to the east, and down "+
           "towards the shore to the west");
  add_item("shore","You can't quite see the shore from here, only a glance "+
           "of the sea through the trees to the west");
  add_item("slope","The steep slope down towards the shore");

  fire_lit = 1;
  alarm = set_alarm(600.0,0.0,"fire_dies");
  reset(0);
}

void fire_dies(void)
{
  tell_room(TO,"The wood in the fireplace has burnt out and the fire "+
            "slowly dies.\n");
  fire_lit = 0;
}

void reset(int arg)
{
  branches_left = 5;
}

void init(void)
{
  add_multi_action("do_rest","sit|rest");
  add_action("do_light","light");
  add_multi_action("do_break","break|use");
  add_multi_action("do_extinguish","stomp|put|extinguish");
}

int do_rest(string str)
{
  if(str == "log" || str == "on log")
  {
    if(fire_lit)
    {
      W("You sit down on one of the logs and rest for a while, looking "+
        "at the fire.\n");
      S(TP->QN+" sits down on one of the logs for a while, looking at the "+
        "fire.\n");
    }
    else
    {
      W("You sit down on one of the logs and rest for a while, wishing "+
        "there was a fire in the fireplace.\n");
      S(TP->QN+" sits down on one of the logs for a while.\n");
    }
    return 1;
  }
  W(C(query_verb())+" where?\n");
  return 1;
}

int do_light(string str)
{
  object fuel;

  if(str == "fire")
  {
    if(fire_lit)
    {
      W("The fire is already lit!\n");
      return 1;
    }

    fuel = present("firewood");
    if(!fuel) fuel = present("firewood",TP);

    if(!fuel)
    {
      W("Hmm, you need to get some wood for the fire first.\n");
      S(TP->QN+" seems to think "+TP->QPR+" can start a fire without "+
        "any firewood. It would only be fitting if you mocked "+TP->QN+
        " right now.\n");
      return 1;
    }
    else
    {
      if(present(fuel,TP))
      {
        TP->command("drop firewood");
      }
      W("FOOOM!!!\n"+
	"The firewood catches fire and starts to burn nicely.\n");
      // Has the player done barbeque quest? ;)
      if(TP->test_flag(803))
      {
        W("Hmmm, this situation seems familiar to you...\n");
      }
      S(TP->QN+" lights a fire.\n"+
        "FOOOM!!!\n"+
	"The firewood catches fire and starts to burn nicely.\n");
      fire_lit = 1;
      fuel->destroy();
      alarm = set_alarm(600.0,0.0,"fire_dies");
      return 1;
    }
  }
}

int do_break(string str)
{
  if(str == "branches" || str == "off branches" || str == "branch" ||
     str == "off branch" || str == "branches as firewood" ||
     str == "branch as firewood")
  {
    if(!branches_left)
    {
      W("Looks like someone has broken all the branches off the poor "+
        "bushes already.\n");
       return 1;
    }

    if(fire_lit)
    {
      W("There's a fire burning in the fireplace already.\n");
      return 1;
    }
    else
    {
      W("You break off a few branches, stack them nicely in the "+
        "fireplace and light the fire.\n"+
        "FOOOM!!!\n"+
        "The firewood catches fire and starts to burn nicely.\n");
      // Has the player done barbeque quest? ;)
      if(TP->test_flag(803))
      {
        W("Hmmm, this situation seems familiar to you...\n");
      }
      S(TP->QN+" breaks off a few branches from the bushes nearby and lights "+
        "a fire.\n"+
        "FOOOM!!!\n"+
        "The firewood catches fire and starts to burn nicely.\n");
      fire_lit = 1;
      --branches_left;
      alarm = set_alarm(600.0,0.0,"fire_dies");
      return 1;
    }
  }
  notify_fail(C(query_verb())+" what?\n");
}

int do_extinguish(string str)
{
  if(str == "fire" || str == "on fire" || str == "fire out")
  {
    if(fire_lit)
    {
      W("You stomp on the burning twigs for a while until the flames "+
        "die out.\n");
      S(TP->QN+" stomps on the burning twigs for a while until the "+
        "fire goes out.\n");
      fire_lit = 0;
      remove_alarm(alarm);
      return 1;
    }
    return 0;
  }

  if(query_verb() != "put" && fire_lit)
  {
    W(C(query_verb())+" what?\n");
    return 1;
  }
}

string long_fun(void)
{
  if(fire_lit)
  {
    return "You are in a clearing among the trees. This place looks like "+
           "a frequently used campsite. The grass on the ground is short and "+
           "looks walked upon. In the centre of the clearing is a circle of "+
           "stones, in which a small fire is burning merrily. There are two "+
           "logs on the ground next to the fireplace. There are bushes and "+
           "trees all around here, and the path winds its way between them "+
           "east from here and to the west down the slope.\n";
  }
  else
  {
    return "You are in a clearing among the trees. This place looks like "+
           "a frequently used campsite. The grass on the ground is short and "+
	   "looks walked upon. In the centre of the clearing is a circle of "+
	   "stones, where the remains of a fire can be seen. There are two "+
	   "logs on the ground next to the fireplace. There are bushes and "+
	   "trees all around here, and the path winds its way between them "+
           "east from here and to the west down the slope.\n";
  }
}

void fireplace_desc(void)
{
  if(fire_lit)
  {
    W("A few stones have been laid on the ground in a circle. A "+
      "small fire is burning merrily in it.\n");
  }
  else
  {
    W("A few stones have been laid on the ground in a circle. There is "+
      "no fire there right now though, but perhaps you could light one?\n");
  }
}

void fire_desc(void)
{
  if(fire_lit)
  {
    W("The fire is actually burning merrily!! Yes, a merrily burning fire, "+
      "odd. If it bothers you, you could stomp on it or put it out or "+
      "something to extinguish it.\n");
  }
  else
  {
    W("There's no fire in the fireplace now, only some remains of a fire. "+
      "if you're cold it might be nice to light a new one.\n");
  }
}

