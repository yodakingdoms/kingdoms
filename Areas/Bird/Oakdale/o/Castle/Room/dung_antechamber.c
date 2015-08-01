#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void my_reset(void);
void remote_long(int arg);

void create_object(void)
{
    set_short("A dark chamber");
    set_long("A dark dungeon chamber with rough stone walls. The chamber " +
             "is circular and the ceiling is domed. The floor is covered " +
             "by a layer of dry, fine sand. The air is chilly, but not as " +
             "cold as in the rest of the dungeon, and there's a strange, " +
             "hazy mist floating around in the chamber. For some reason " +
             "you suddenly feel like you are being watched, and the air " +
             "seems to smother the light you bring. It only reaches a few " +
             "feet into the darkness of the chamber. You do see, however " +
             "that there is an archway in the east wall, as well as in the " +
             "west wall.\n");
    set_new_light(0);
    add_property("indoors");

    add_item("room|chamber","A circular dungeon chamber with rough stone " +
             "walls and a floor covered by a layer of fine sand");
    add_item("wall|walls","Rough, black stone");
    add_item("ceiling","A low, domed ceiling");
    add_item("floor","The floor is covered by a layer of fine sand");
    add_item("layer|sand","Fine, dry sand. You sink down a bit with every " +
             "step you take");
    add_item("air","A strange, black mist is floating around in the air");
    add_item("mist","A black, hazy mist, moving in an eerie way. It looks " +
             "as its movements have purpose..");
    add_item("darkness","The darkness is thick and does not yield to the " +
             "light you bring");
    add_item("archway","There is one in the east and one in the west wall");

    add_exit(ROOM + "dung_bottom2","west");
    add_exit(ROOM + "dung_orbchamber","east");

    reset(0);
}

void reset(int arg)
{
    my_reset();
}

void my_reset(void)
{
    // This is called from dung_orbchamber too so the guardian
    // will be here when the orb is reset
    add_monster(MONSTER + "guardian",1);
}

void remote_long(int arg)
{
    W("A strange room. You can't look into it as your vision is " +
      "obscured by a strange, black mist floating around in the air.\n");
}
