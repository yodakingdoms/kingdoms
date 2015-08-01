#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
void init(void);
int do_rude(string str);
int do_sit(string str);
int do_open(string str);
int do_light(string str);
int load_doors(void);

void create_object(void)
{
    set_short("In a small cottage in the forest");
    set_long("You are in a small cottage in the forest. The ceiling is low, " +
             "and there is only a small window in one of the stone walls, " +
             "so it is quite dark in here. In the west wall is a fireplace " +
             "where a small fire is burning. A small lamp is hanging from " +
             "one of the wooden roofbeams, but it is not lit at the moment. " +
             "A small bed stands by the north wall, and by the east wall is " +
             "a wardrobe. A few cupboards hang one the walls, and the " +
             "wooden floor is covered by a bearskin rug. A few animal " +
             "hides are stashed in a pile in a corner, and in the middle " +
             "of the room is a table and a stool. There is a strange smell " +
             "in the air.\n");
    set_new_light(10);
    set_skip_obvious(1);
    add_property("indoors");

    add_item("cottage","Just type 'look'");
    add_item("room","A neat little room");
    add_item("ceiling","A low wooden ceiling. A small lamp is hanging from " +
             "one of the roombeams");
    add_item("window","A small window letting in little light. The forest " +
             "outside the window is dark and silent");
    add_item("forest","It is dark and silent");
    add_item("wall|walls","Made of stone");
    add_item("fireplace","A stone fireplace. A fire is burning there, " +
             "filling the room with light and warmth");
    add_item("fire","A nice little fire, warming the room");
    add_item("lamp","A small oil lamp hanging from the ceiling. It is not " +
             "lit at the moment");
    add_item("bed","A small, uncomfortable looking bed");
    add_item("wardrobe","A small wardrobe made of oak");
    add_item("cupboard|cupboards","The strange smell in the room is coming " +
             "from one of the wooden cupboards");
    add_item("floor","A wooden floor. A bearskin rug and a wooden table " +
             "take up most of the space on it");
    add_item("table","A heavy oak table");
    add_item("stool","A small wooden stool. It looks extremely " +
             "uncomfortable, so sit on it at your own risk");
    add_item("hide|hides|pile","A pile of different types of animal hides " +
             "stashed in the corner");
    add_item("corner","A pile of animal hides is stashed there");
    add_item("rug","A soft bearskin rug");
    add_item("%|%smell|%cupboards","The strange herbal smell in the room " +
             "seem to be coming from one of the cupboards");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "alliria",1);
    ::reset(arg);
}

void init(void)
{
    add_action("do_rude","search");
    add_action("do_rude","move");
    add_action("do_sit","sit");
    add_action("do_open","open");
    add_action("do_light","light");
    ::init();
}

int do_rude(string str)
{
    if(str == "skin" || str == "skins" || str == "rug")
    {
        W("Hmm, would that not be a bit rude when the woman is standing " +
          "right in front of you??\n");
        return 1;
    }
}

int do_sit(string str)
{
    if(str == "on stool" || str == "stool")
    {
        W("Ouch! You hurt your bum! Don't say I didn't warn you!\n");
        S(TP->QN + " seems to hurt " + TP->QPO + " behind as " + TP->QPR +
          " sits down on the stool.\n");
        TP->add_temporary_penalty(random(5));
        return 1;
    }
    return notify_fail("Sit on what?\n");
}

int do_open(string str)
{
    if(str == "cupboard")
    {
        W("Judging by how the cupboard smells, you decide it might not be " +
          "a good idea to open it after all, so you change your mind.\n");
        S(TP->QN + " steps up to a cupboard to open it, but appears to " +
          "change " + TP->QPO + " mind.\n");
        return 1;
    }
    if(str == "wardrobe")
    {
        W("Would it not be a bit rude to do that when the old woman who " +
          "lives here is standing right in front of you?\n");
        return 1;
    }
    return 0;
}

int do_light(string str)
{
    if(str == "lamp")
    {
        W("The old woman looks at you as you walk over to light the lamp " +
          "and says: Oh, please leave it unlit. Too much light hurt my " +
          "old eyes, child. She smiles wearily at you and you decide not " +
          "to light it anyway.\n");
        S(TP->QN + " walks up to the lamp to light it, but the old woman " +
          "asks " + TP->QO + " not to.\n");
        return 1;
    }
}

int load_doors(void)
{
    string dir1 = "south";
    string dir2 = "north";
    string next_room = ROOM + "cottage_clearing";
    string desc = "wooden door";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A nice oak door.\n";
    string entercmd1 = "south";
    string entercmd2 = "north";
    int solidity = 10;
    int complex = 0;
    int hidden1 = 0;
    int hidden2 = 0;

    add_door(dir1, dir2, next_room, desc,  closed, locked, key_id,
             long_desc, entercmd1, entercmd2, solidity, complex,
             hidden1, hidden2 );
    return 1;
}
