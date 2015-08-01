#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A dining room (s/e)");
    set_long("This room looks like it was once the dining room of the " +
             "mansion. There are no chairs here but there's still a big " +
             "table in the centre of the room. Large windows take up most " +
             "of the north wall and you see the forest outside through " +
             "them. The floor is covered with small stones and other debris " +
             "and there are large cracks in the ceiling. A large chandelier " +
             "is still hanging from the ceiling over the table.\n");

    set_new_light(5);
    add_property("indoors");

    add_item("room","It's in a state of disrepair but it looks like it " +
             "once was a dining room");
    add_item("dining room","That's what this room looks like it was used " +
             "for before the mansion was abandoned. It was here people " +
             "came to feast when it was time to celebrate");
    add_item("mansion","It seems like it's been abandoned a long time");
    add_item("chair|chairs","There are no chairs here. Maybe they've been " +
             "made part of the debris on the floor");
    add_item("table|big table","A big table. It looks like there's " +
             "room for many people to sit down and eat around it");
    add_item("window|windows|large window|large windows","They take up " +
             "most of the north wall. It must have been relaxing to sit " +
             "here, having a meal and looking out at the forest outside");
    add_item("wall|walls|stone wall|stone walls","The walls are made of " +
             "stone. There are cracks in the walls and they seem to be " +
             "crumbling");
    add_item("stone|crumbling stone","The stone walls seem to be crumbling " +
             "and you're beginning to think it might be best to leave " +
             "the mansion before it collapses");
    add_item("north wall","Large windows take up most of the north wall");
    add_item("forest|dark forest|dense forest","There's a dark forest " +
             "outside the windows. It's so dense you can't see very far " +
             "into it");
    add_item("floor","There's lots of debris on the floor");
    add_item("stones|small stone|small stones","There are plenty of them " +
             "all over the floor. They probably come from the walls or " +
             "the ceiling");
    add_item("remains|debris","There's plenty of it all over the floor. " +
             "Probably remains of chairs or other furniture that once was " +
             "in this room");
    add_item("furniture|other furniture","You can't tell what it once " +
             "might have been just by looking at the debris");
    add_item("crack|cracks|large crack|large cracks","There are plenty of " +
             "them in the ceiling. You feel a bit uneasy standing under " +
             "a ceiling looking like that");
    add_item("ceiling","The ceiling has many large cracks in it");
    add_item("chandelier|large chandelier","It's still hanging down from " +
             "the ceiling over the table, but only barely");

    add_exit(ROOM + "house_floor1_entrance","south");

    (ROOM + "house_floor1_kitchen")->load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "goblin",1);
    ::reset(arg);
}
