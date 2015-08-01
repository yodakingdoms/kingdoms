//==========================================================================
// master_room.c -- The master room for this domain inherited by all rooms
//                  in it. The plan is that all the domains added to this
//                  island in the future should inherit it too, as it 
//                  contains some functions I want all rooms in it to have.
//                  Yoda - 970406
//==========================================================================
#pragma strict_types
#include "../def.h"
inherit STD_ROOM;

// Function declarations----------------------------------------------------

void   set_dragon_visibility(int visibility);
int    query_dragon_visibility(void);
void   set_room_hint(string hint);
string query_room_hint(void);

// Variables all rooms should have------------------------------------------

int dragon_visibility; // How well can the dragon be seen from this room as
                       // it flies over the island?
string room_hint = "I can't think of anything special to say about this "+
                   "place I'm afraid"; 
                   // Do we want the yet-to-be-named newbiehelper to give 
                   // players any hints in this room and if so, what do we
                   // want him to say? This is the default one

// Functions all rooms should have------------------------------------------

// Dragon functions-----------------------
void set_dragon_visibility(int visibility)
{
  dragon_visibility = visibility;  // Values: 10 - A high bare hill
                                   //          5 - A clear field or valley
                                   //          3 - A not too dense forest
                                   //          1 - A dense forest
                                   //          0 - Indoors with no windows
                                   //              or underground
}

int query_dragon_visibility(void)
{
  switch(query_daylight())
  {
    case 0: return dragon_visibility + 5; // The dragon can be seen easier
      break;                              // at night when it's fire lights
                                          // the dark sky
    case 1: case 3: return dragon_visibility + 3; // It's a bit easier to see
                                                  // the dragon when it's not
                                                  // too light
      break;
    default: return dragon_visibility; 
      break;
  }
}

//Hint functions---------------
void set_room_hint(string hint)
{
  room_hint = hint; // This string is what the newbiehelper will say if the
                    // helped player asks for a hint in this room. Hints
                    // might be about exploring, fighting or whatever we
                    // might want to share with the newbies
}

string query_room_hint(void)
{
  return room_hint;
}
//============================================================================
