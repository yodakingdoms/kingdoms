#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

void create_object(void);
void reset(int arg);
int query_is_quest_shed(void);

void create_object(void)
{
    ::create_object();
    set_short("A small shed (se)");
    set_long("A small wooden shed filled with different tools and other " +
             "strange things. There are shovels leaned against the wall, " +
             "scythes hanging on the walls, pitchforks and a plough in one " +
             "corner, and a big wooden box filled with hammers, saws, " +
             "carving knives and other tools. Ropes and leather straps hang " +
             "from hooks on the walls. A few rakes lie on the floor next to " +
             "one of the walls. The shed has no windows and the ceiling is " +
             "low.\n");

    add_item("shed|wooden shed|small shed|small wooden shed","It's small " +
             "from your point of view but it would be pretty roomy for " +
             "someone the size of a hobbit");
    add_item("tool|tools|hammer|hammers|saw|saws|knife|knives|carving " +
             "knife|carving knives","The normal kind of tools used on a " +
             "farm. You notice that the shed contains all the tools " +
             "needed to, for example, make a scarecrow provided you " +
             "already have all the necessary parts for it");
    add_item("thing|things","Tools, shovels, scythes, forks and many " +
             "other things");
    add_item("other thing|other things","You're not quite sure what those " +
             "are supposed to be");
    add_item("shovel|shovels","Shovels are used to move earth around and " +
             "dig holes");
    add_item("scythe|scythes","They are hanging on the walls");
    add_item("wall|walls","All sorts of things are hanging on them");
    add_item("fork|forks|pitchfork|pitchforks","Pitchforks are used to move " +
             "hay around");
    add_item("plough","A plough stands in a corner, it's probably not " +
             "ploughing season right now");
    add_item("corner|corners","There are things in all of them");
    add_item("box|wooden box|big wooden box","Filled with tools");
    add_item("rope|ropes|strap|straps|leather strap|leather straps","Used " +
             "to tie things up, no doubt");
    add_item("hook|hooks","All sorts of things hang from them");
    add_item("rake|rakes","A normal tool used on a farm");
    add_item("ceiling","The ceiling is low and you have to watch your head");
    add_item("floor","You can hardly see the floor all the tools and other " +
             "things in the shed");
    add_item("$|$rodent|$rodents|$rodent|$rodents","You hear the sound of " +
             "rodents scurrying about in the shed");

    add_exit(ROOM + "farm_west","southeast");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "rat",3);
}

int query_is_quest_shed(void)
{
    return 1;
}
