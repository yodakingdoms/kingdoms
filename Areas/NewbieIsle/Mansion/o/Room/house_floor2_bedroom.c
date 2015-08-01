#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_sleep(string str);

void create_object(void)
{
    set_short("A bedroom (w)");
    set_long("This used to be a bedroom but now this room is in the same " +
             "state of disrepair as the rest of the mansion. There is a " +
             "large bed by one of the walls, and a few wooden cabinets and " +
             "chests have also survived. The windows in the east wall are " +
             "broken and the floor is covered with small stones and other " +
             "debris. There are large cracks in the ceiling. In one of the " +
             "corners is a large pile of old sheets and pillows and there's " +
             "a chandelier hanging from the ceiling.\n");

    set_new_light(5);
    add_property("indoors");

    add_item("bedroom|room","It used to be a bedroom but you would not " +
             "want to sleep in it now. It's is very untidy and filthy");
    add_item("mansion|rest of the mansion","It seems to have been abandoned " +
             "for a very long time");
    add_item("bed|large bed","A large bed that probably was pretty nice to " +
             "sleep in at one time but now it doesn't look very nice. There " +
             "are no sheets or pillows there anymore");
    add_item("wall|walls","They look like they could crumble any second");
    add_item("cabinet|cabinets|wooden cabinet|wooden cabinets","They are " +
             "all empty and look as if they've been searched time and time " +
             "again");
    add_item("chest|chests|wooden chest|wooden chests","They are all " +
             "open but whatever riches they once contained are long gone now");
    add_item("riches","Not much of that here these days");
    add_item("east wall","There are some windows there");
    add_item("window|windows|broken window|broken windows","The windows " +
             "are all broken. You can see the forest outside");
    add_item("forest|dark forest","A dark forest surrounding the mansion");
    add_item("floor","It is covered with debris and small stones. It is " +
             "obvious that noone has been cleaning up in this room in a " +
             "very long time");
    add_item("stone|stones|small stone|small stones","Plenty of them cover " +
             "the floor. They probably come from the ceiling");
    add_item("debris","Plenty of it covers the floor. It seems to be what's " +
             "left of the windows mixed with bits and pieces of broken " +
             "furniture");
    add_item("bit|bits|piece|pieces|bits and pieces|furniture|" +
             "broken furniture","Looks like someone who was here searching " +
             "the room in the past wasn't very careful with the furniture");
    add_item("crack|cracks|large crack|large cracks","There are many of " +
             "them in the ceiling");
    add_item("ceiling","There are many large cracks there, you don't really " +
             "feel safe standing here. A chandelier still hangs from it");
    add_item("corner|corners","There's a pile of sheets and pillows in one " +
             "of them");
    add_item("pile|sheet|sheets|pillow|pillows|old sheet|old sheets|" +
             "old pillow|old pillows","A pile of old sheets and pillows " +
             "that look as if they've seen better days. You wouldn't want " +
             "to be tucked in in those sheets");
    add_item("chandelier","It doesn't look to be in a very good shape " +
             "anymore. It looks as if it could fall from the ceiling at " +
             "any moment");
    add_item("mattress","The mattress looks rotten, you would not like " +
             "to sleep in that bed");

    add_exit(ROOM + "house_floor2_landing","west");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "goblin_chief");
    add_monster(MONSTER + "bodyguard_goblin",2);
}

void init(void)
{
    add_multi_action("do_sleep","sleep|lie");
    SYS_ADMIN->visit(1107);
}

int do_sleep(string str)
{
    if(str == "bed" || str == "in bed")
    {
        W("There are no sheets or pillows in the bed and the mattress " +
          "looks rotten so you decide against it.\n");
        S(TP->QN + " walks up to the bed and looks at it while pondering " +
          "deeply.\n");
        return 1;
    }
    return notify_fail(C(query_verb()) + " where?\n");
}
