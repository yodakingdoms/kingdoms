//=======================================================================
// boat_object.c - An object that is put into the destination rooms so
//                 players see there's a boat there
//=======================================================================
#pragma strict_types
#include "../def.h"
inherit STD_STDOBJ;
inherit "/std/modules/general/description";
inherit "/std/modules/general/identity";

int location;                      // 1 = Larstown, 2 = Island

void create_object(void);
int  get(string str);
int  can_put_and_get(void);
void init(void);
int  do_board(string str);
void set_location(int location);

void create_object(void)
{
  set_name("boat");
  add_id("sailing boat");
  add_id("small sailing boat");
  set_material("wood"); //Angelwings
}

int get(string str)
{ 
  return 0;
}

int can_put_and_get(void)
{
  return 0;
}

// Fix for the spamming of the ILLEGAL_CLONING log (23 meg was quite enough)
// Yoda 13 Feb 1901
int is_public(void)
{
  return 1;
}
 
void init(void) 
{
  add_multi_action("do_board","board|enter|embark");
}

int do_board(string str)
{
  if(str == "boat" || str == "sailing boat")
  {
    switch(location) 
    {
      case 1: if(TP->query_level() <= 4)
              {
                W("The boatman nods to you in a friendly way as you "+
                  "climb on board the small boat.\n");
                TP->move_player("climbs on board the sailing boat",
                                NROOM+"ferry",
                                "climbs on board to join you",1);
                return 1;
              }
              else
              {
                W("You have to talk to the boatman and pay him for the "+
                  "passage if you want to travel to Newbie Island.\n");
                S(TP->QN + " studies the sailing boat with an interested "+
                  "look on " + TP->QPO + " face.\n");
                return 1;
              }
        break;
      case 2: W("You climb onboard and make yourself ready for the passage "+
                "to Lars Town.\n");
              TP->move_player("climbs on board the sailing boat.",
                              NROOM+"ferry",
                              "climbs on board to join you",1);
              return 1;
        break;
    }
  }
}
 
void set_location(int current_location)
{
  switch(current_location)
  {
    // Larstown
    case 1: set_short("A small sailing boat tied to the pier");
            set_long("A small, but sturdy sailing boat tied to " +
                     "the Lars Town pier. You think this might "+
                     "be the vessel that takes people to and from " +
                     "Newbie Island. If the boatman is around, he "+
                     "can probably let you know about that.\n");
      break;
    // Island
    case 2: set_short("A small sailing boat pulled up onto the shore");
            set_long("A small, but sturdy sailing boat pulled onto "+
                     "the sandy shore of the island. If you want to "+
                     "go back to Lars Town, you only have to board "+
                     "the boat and wait for the boatman to take her "+
                     "to sea.\n");
          
      break;
  }
  location = current_location;
}
