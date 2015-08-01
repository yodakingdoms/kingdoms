#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("The main kitchen of the castle");
    set_long("This is the main kitchen of the castle, where the food for " +
             "the lords and commanders is prepared. It is a big, dimly " +
             "lit room with three large ovens. The black stone walls are " +
             "covered with shelves and cupboards, and many sacks, crates " +
             "and barrels are on the floor. In the middle of the room are " +
             "a few benches and tables and a chest is by the south wall. " +
             "The room is lit only by the fires in the ovens, and strange, " +
             "long shadows dance on the walls.\n");
    set_new_light(5);
    set_skip_obvious(1);
    add_property("indoors");

    add_item("room|kitchen","This is the main kitchen of the castle");
    add_item("oven|ovens","There are three large ovens in the kitchen. A " +
             "lot of food could be prepared in them. The fires are lit");
    add_item("walls|wall","Black stone walls covered by shelves and " +
             "cupboards");
    add_item("shelf|shelves","Wooden shelves filled with cans and bottles");
    add_item("can|cans|bottle|bottles","Cans and bottles containing " +
             "spices and other things used when preparing food");
    add_item("cupboard|cupboards","Containing various kitchen utensils, no " +
             "doubt");
    add_item("utensil|utensils","Well, that's what kitchen cupboards " +
             "usually contain, right?");
    add_item("sack|sacks|barrel|barrels|crate|crates","Containing different " +
             "types of supplies");
    add_item("floor","Smooth, black stone");
    add_item("table|tables|bench|benches","Used for preparing food on");
    add_item("chest","The chest is open. It contains sheets of tablecloth " +
             "and shining silver tableware");
    add_item("sheet|sheets|tablecloth","White linen tablecloth. It would " +
             "look very nice on a big oak table");
    add_item("tableware","Shining silver tableware. Forks, spoons and " +
             "knives. Very classy stuff");
    add_item("fork|forks|spoon|spoons|knife|knives","Very classy silver " +
             "tableware");
    add_item("fire|fires","The fires are lit in the ovens, spreading warmth " +
             "in the room and making long shadows dance on the walls");
    add_item("shadow|shadows","Long shadows dancing around on the walls");

    (ROOM + "lev2_dininghall")->load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_chef",1);
    ::reset(arg);
}
