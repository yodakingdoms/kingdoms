#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit DOOR_MOD;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A gate to a farm (n/w/s)");
    set_long("Inside the gate of a small farm in the middle of the rolling " +
             "landscape of Newbie Island. To the east is a wooden arch over " +
             "the gate and a finely crafted fence. North of here is a small " +
             "field and south of there there seems to be a well. To the " +
             "west are the buildings that make up the farm. You can see a " +
             "barn, a stable, a big hill that seems to be a normal hobbit " +
             "house and a smaller shed. A huge oak tree grows on top " +
             "of the hill. The grass all around you is trampled and flat " +
             "and you see tracks from many different kinds of creatures.\n");

    set_new_light(5);

    add_item("farm|small farm","It lies tucked away in a small, flatter " +
             "area in the rolling landscape around you");
    add_item("area|flatter area|small area|small, flatter area","The area " +
             "that makes up the farm is flatter than the landscape around " +
             "it. It was probably the reason why this area was chosen to " +
             "build the farm on");
    add_item("landscape|rolling landscape","Grassy, green hills as far as " +
             "the eye can see");
    add_item("hill|hills|green hill|green hills|grassy hill|grassy hills|" +
             "green, grassy hill|green, grassy hills","Grassy hills, most " +
             "of them crowned with trees");
    add_item("trees","They grow on most of the hills but you can't tell " +
             "more about them from this distance");
    add_item("island|newbie island|Island|Newbie Island","It's the island " +
             "this area is on");
    add_item("arch|wooden arch","The arch rises over the gate. There's a " +
             "wooden sign nailed to it");
    add_item("@sign|@wooden sign|sign|wooden sign","You can't see what is " +
             "says from here, you would have to go outside the gate to " +
             "read it");
    add_item("fence|crafted fence|finely crafted fence","The fence " +
             "stretches a long distance both to the south and to the north");
    add_item("field|small field","A small field where something is growing");
    add_item("something","You can't tell what's growing there from here");
    add_item("well","There's a well a short distance to the south. You'd " +
             "have to go there to get a better look");
    add_item("building|buildings","The buildings look like your normal farm " +
             "buildings, but there's something about their scale that's not " +
             "quite right");
    add_item("scale","The buildings all seem a little smaller than they " +
             "should be");
    add_item("barn","The barn is some distance to the west of here");
    add_item("stable","The stable is northwest from here");
    add_item("hill|big hill|grassy hill|big, grassy hill|house|hobbit house|" +
             "normal hobbit house","A big, grassy hill with a round door " +
             "and some windows");
    add_item("door|round door","You'd have to go east to get a better " +
             "look at it");
    add_item("window|windows","There are windows facing all directions in " +
             "the hill");
    add_item("shed|smaller shed","It's squeezed in between the barn and " +
             "the stable");
    add_item("top|top of the hill","A huge tree grows on top of the hill, " +
             "looming over the farm");
    add_item("oak|tree|oak tree|huge oak|huge tree|huge oak tree","It " +
             "grows on top of the hill and looks very impressive");
    add_item("ground","The ground is covered with short grass");
    add_item("grass|short grass","It's pretty short to begin with and it's " +
             "also trampled flat all around you");
    add_item("track|tracks","Many different kinds of creatures seem to " +
             "have been walking around here");
    add_item("$|$sound|$sounds|$animal|$animals","You hear the sounds of " +
             "farm animals coming from all around you");
    add_item("%|%smell|%animal|%animals","You feel the smell of farm " +
             "animals. It is rather faint here though");

    add_exit(ROOM + "farm_pumpkin_field","north");
    add_exit(ROOM + "farm_well","south");
    add_exit(ROOM + "farm_center","west");

    set_door_control("door_control");
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "bird",3);
    ::reset(arg);
}
