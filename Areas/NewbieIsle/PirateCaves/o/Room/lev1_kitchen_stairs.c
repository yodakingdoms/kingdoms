#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("Stairs (d/e)");
    set_long("Some stairs going down to what judging by the smell and " +
             "sounds coming from down there seems to be a kitchen. A " +
             "corridor continues to the east from here. There are fumes " +
             "and smoke in the air, coming up from the room below. The " +
             "steps of the stairs are damp and wet, and the walls are " +
             "dirty. A shining stone in a niche in a wall provides light " +
             "for the room.\n");

    add_item("stair|stairs","They go down into what seems to be a kitchen");
    add_item("%|%kitchen|%smell","It smells like someone is cooking " +
             "something");
    add_item("$|$sound|$sounds","It sounds like someone's preparing dinner");
    add_item("kitchen","You'd have to go down there to get a better look");
    add_item("fume|fumes|smoke","The kind you get when you make food");
    add_item("corridor","It continues to the east");
    add_item("air","There are lots of fumes and smoke in it");
    add_item("step|steps","Covered with something wet");
    add_item("something wet","Looks like someone spilled his or her or its " +
             "drink. Abuse of alcohol!");
    add_item("stone|shining stone|softly shining stone","A softly shining " +
             "stone, providing the room with light");
    add_item("niche","There's a softly shining stone in it");
    add_item("light|soft light","A soft light coming from the stone in the " +
             "wall");

    add_exit(PCROOM + "lev1_ew_corridor1","east");
    add_exit(PCROOM + "lev2_kitchen","down");
}
