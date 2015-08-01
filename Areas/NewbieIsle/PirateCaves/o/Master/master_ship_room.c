//==========================================================================
// master_ship_room - The master room for the rooms that belong to the
//                    ship. They will all have a reference to the master
//                    ship object, and different long descs depending on
//                    whether the ship is at sea or not, etc etc
// Yoda - 990413
//==========================================================================
#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

string sea_long;  // The rooms long desc when the ship is at sea
string attacking_long; // The rooms long desc when the ship is next to the
                       // target ship, attacking it
string cave_long; // The rooms long desc when the ship is in the lagoon
                  // in the cave

void create_object(void);
void set_sea_long(string str);
void set_cave_long(string str);
void set_attacking_long(string str);
int query_location(void);
string ship_room_long_fun(void);


void create_object(void)
{
    set_long("#ship_room_long_fun");
    SHIP_OBJ->load_me();

    set_new_light(10);
}


void set_sea_long(string str)
{
    sea_long = str;
}

void set_cave_long(string str)
{
    cave_long = str;
}

void set_attacking_long(string str)
{
    attacking_long = str;
}

/**
 * 0 = cave, 1 = sea, 2 = attacking
 */
int query_location()
{
    if(!SHIP_OBJ->query_is_at_sea())
    {
        return 0;
    }
    else if(!SHIP_OBJ->query_cannon_fired())
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

string ship_room_long_fun(void)
{
   if(SHIP_OBJ->query_is_at_sea())
   {
       // When the cannon is fired, the other ship is crippled
       // and the players are attacking it
       if(SHIP_OBJ->query_cannon_fired())
       {
           return attacking_long;
       }
       else
       {
          return sea_long;
       }
   }
   else
   {
      return cave_long;
   }
}

//============================================================================
