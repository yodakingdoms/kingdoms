#pragma strict_types
#include <church.h>

inherit "/sys/room/std_castle";

void create_object()
{
    set_name("castle");
    set_short("Castle of Mansion");
    set_long("This is the " + short() + ".\n");
    set_area_name("Abandoned Mansion");
    set_kingdom("Newbie");
    set_reputation("good");
    set_optional_church(CHURCH_NEWBIEISLE,2);
    set_bug_tracking(1);
    move_object(this_object(),"/castle_dest");
}

string * query_creators()
{
  // put in here your list of now defunct coders.
  // return ({ "wizname1", "wizname2", });
}