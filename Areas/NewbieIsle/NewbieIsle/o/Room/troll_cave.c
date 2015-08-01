#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
int  query_room_id(void);
void reset(int arg);
void init(void);
int  do_search(string str);

object sack,stick;
object troll1, troll2, troll3, troll4, troll5, troll6, troll7;
int sack_found,stick_found;

void create_object(void)
{
  set_short("A dark, smelly cave (se)");
  set_long("You are in a dark, cold cave that is so smelly you "+
           "almost pass out. The walls of the cave are jagged and "+
           "the floor is covered with the filth that probably is the "+
           "cause of the horrible smell. There is a pile of bones in "+
           "one of the corners, and a pile of rags and other junk in "+
           "another. The way out of the cave is to the southeast. "+
           "Perhaps it would be a good idea to go that way?\n");
  set_new_light(1);
  add_property("indoors");
  set_room_hint("Hmm, searching piles of <insert practically anything "+
                "here> is often rewarded. Don't give up if you don't find "+
                "anything the first time. Sometimes you have to search more "+
                "than once before you find things.;)\n");

  add_item("cave","This cave looks just like you would have imagined a "+
           "troll cave to look like");
  add_item("%","Bleurgh, this has got to be the worst smell you have ever "+
           "felt in your life!");
  add_item("wall|walls","The cold stone walls of the cave are rough "+
           "and uneven");
  add_item("floor","The stone floor is covered with filth");
  add_item("filth","Filth left by the trolls, no doubt. It smells "+
           "horribly!!");
  add_item("trolls","If there are any here at the moment, you are in big "+
           "trouble!");
  add_item("smell","You can't see it but you sure can smell it!");
  add_item("corner|corners","There's a pile of bones in one of them and "+
           "a pile of rags in the other");
  add_item("pile","Perhaps look at the bones or the rags and junk?");
  add_item("bone|bones","A pile of bones, probably from all the newbies "+
           "who have been eaten by the trolls! You wonder if you might "+
           "find some useful stuff in it if you looked more closely");
  add_item("rag|rags|junk","A pile of things that probably belonged "+
           "to some of the newbies that the trolls have eaten. Perhaps "+
           "one of them had something nice? Might be worth it to search "+
           "it");
  add_item("way","It is the way out. I suggest you use it before it is "+
           "too late");

  add_exit(NROOM+"troll_cave_in","southeast");

  reset(0);
}

// Trolls use this function to know which room they 
// are in and which way to go when they return home
int query_room_id(void)
{
  return 13;
}

void reset(int arg)
{
  sack_found = 0;
  stick_found = 0;

  if(!troll1 || !living(troll1))
  {
    troll1 = make(NMONSTER+"troll");
  }
 
  if(!troll2 || !living(troll2))
  {
    troll2 = make(NMONSTER+"troll");
  }

  if(!troll3 || !living(troll3))
  {
    troll3 = make(NMONSTER+"troll_child");
  }
 
  if(!troll4 || !living(troll4))
  {
    troll4 = make(NMONSTER+"troll_child");
  }

  if(!troll5 || !living(troll5))
  {
    troll5 = make(NMONSTER+"troll_child");
  }
 
  if(!troll6 || !living(troll6))
  {
    troll6 = make(NMONSTER+"troll_child");
  }

  if(!troll7 || !living(troll7))
  {
    troll7 = make(NMONSTER+"troll_child");
  }
}

void init(void)
{
  add_action("do_search","search");
}

int do_search(string str)
{
  if(str == "pile")
  {
    W("Search which pile? The pile of bones or the pile of rags.\n");
    return 1;
  }

  if(str == "bones" || str == "pile of bones" || str == "the pile of bones")
  {  
    if(TP->query_skill("perception") > random(15))
    {
      if(!stick_found)
      {
        W("You search through the bones of your fallen peers but all "+
          "you find is a wooden stick. Boring. ");
        stick = make(NWEAPON+"twisted_stick");
        stick_found = 1;
        if(!transfer(stick,TP))
	{
          W("You pick the stick up anyway.\n");
	}
        else
	{
          W("You carry too much to pick it up so you just leave it.\n");
	}
        S(TP->QN+" searches through the bones but doesn't seem to find "+
          "anything of any value.\n");
        return 1;
      }
      else
      {
        W("You find nothing and you're quite sure it is because somebody "+
          "else have been looking through the pile not too long ago.\n");
        S(TP->QN+" searches through the bones but doesn't seem to find "+
          "anything of value.\n");
        return 1;
      }
    }
    else
    {
      W("You search for a while but don't find anything this time.\n");
      S(TP->QN+" searches through the bones but doesn't find anything of "+
        "any value.\n");
      return 1;
    }
  }

  if(str == "junk" || str == "rags" || str == "pile of junk" ||
     str == "pile of rags")
  {
    if(TP->query_skill("perception") > random(15))
    {
      if(!sack_found)
      {
        W("You search through the rags for a while but the only thing "+
          "you find that is not rusty or rotten is an old sack. ");
        sack = make(NARMOUR+"mithril_sack");
        sack_found = 1;
        if(!transfer(sack,TP))
	{
          W("It looks pretty useless but you pick it up anyway.\n");
	}
        else
        {
          W("You're even carrying too much to pick it up so you leave it "+
            "on the floor.\n");
	}
        S(TP->QN+" searches the rags but finds only an old sack.\n");
        return 1;
      }
      else
      {
        W("You search the rags but don't find anything. Could be because "+
          "somebody else has been here not too long ago...\n");
        S(TP->QN+" searches the rags but finds nothing.\n");
        return 1;
      }
    }
    else
    {
      W("You search the rags but don't find anything this time.\n");
      S(TP->QN+" searches the rags but finds nothing.\n");
      return 1;
    }
  }
}
