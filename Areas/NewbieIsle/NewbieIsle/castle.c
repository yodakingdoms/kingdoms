// Added bug tracking.
// Yoda 2003-09-21
// ------------------------------------------------------------------
// Added optional church
// Yoda 2003-11-13
// ------------------------------------------------------------------
#pragma strict_types
#define NAME "NewbieIsle"
#include <church.h>

inherit "/sys/room/std_castle";

void create_object()
{
  set_name("castle");
  set_short("Castle of " + capitalize(NAME));
  set_long("This is the " + short() + ".\n");
  set_area_name("Newbie Island");
  set_kingdom("Newbie");
  set_reputation("good");
  set_optional_church(CHURCH_NEWBIEISLE,2);
  set_bug_tracking(1);
  move_object(this_object(),"/castle_dest");

  "/areas/NewbieIsle/NewbieIsle/o/Master/troll_master"->load_me();
  "/areas/NewbieIsle/NewbieIsle/o/Room/troll_cave"->load_me();
  "/areas/NewbieIsle/NewbieIsle/o/Room/ferry"->load_me();
}

int do_enter(string str)
{
  if(!id(str))
    return 0;
  tell_object(this_player(),"It is not an open castle.\n");
  return 1;
}

void init()
{
  add_action("do_enter","enter");
}

string * query_creators()
{
  // put in here your list of now defunct coders.
  // return ({ "wizname1", "wizname2", });
}