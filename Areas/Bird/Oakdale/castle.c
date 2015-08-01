// Added bug tracking.
// Yoda 2003-09-21
// ------------------------------------------------------------------

#pragma strict_types
#define NAME "Oakdale"

inherit "/sys/room/std_castle";

void create_object()
{
  set_name("castle");
  set_short("Castle of " + capitalize(NAME));
  set_long("This is the " + short() + ".\n");
  set_area_name("Oakdale");
  set_kingdom("Bird Island");
  set_reputation("good");
  set_bug_tracking(1);
  move_object(this_object(),"/castle_dest");
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

string* query_creators()
{
  return ({"Yoda"});
}
