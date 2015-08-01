#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_pray(string str);

void create_object(void)
{
    set_short("The chapel of the castle");
    set_long("This is the chapel of the castle. It is a large hall with a " +
             "low ceiling supported by two rows of stone pillars. The " +
             "pillars and two rows of black stone benches form an isle " +
             "leading up to a black stone altar in the east part of the " +
             "chapel. In the black stone wall behind the altar is a large, " +
             "decorated window. A torch is attached to each of the pillars, " +
             "and their flickering flames makes eerie shadows dance upon " +
             "the walls. The chapel is, for some reason, so cold that mist " +
             "forms in front of your face when you breathe. There is an " +
             "archway in the west wall.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("room|chapel|hall","A dark, eerie chapel. You feel uneasy " +
             "here, realizing this must be a place of worship of a very " +
             "evil deity");
    add_item("ceiling","The black stone ceiling hangs low above your " +
             "head. It is supported by stone pillars");
    add_item("pillar|pillars","Two rows of rough, black, stone pillars"+
           " supporting the ceiling in the hall");
    add_item("row|rows","The pillars or the benches?");
    add_item("bench|benches","Uncomfortable looking black stone benches");
    add_item("isle","An isle between the pillars and benches. it is " +
             "leading up to an altar");
    add_item("altar","A rough block of black stone. It looks as if it is " +
             "the highest point of the castle rock that's coming up " +
             "through the floor and is used as an altar");
    add_item("point|rock|peak","Yes, the peak of the cliff the castle is " +
             "built upon comes through the floor here");
    add_item("wall|walls","Smooth, black stone");
    add_item("window","A decorated window painted with an image of a " +
             "black dragon");
    add_item("dragon","A gruesome beast indeed");
    add_item("beast","The huge black dragon");
    add_item("torch|torches","One is attached to each of the pillars. All " +
             "of them are lit");
    add_item("flame|flames","The torches flicker as if the air in here " +
             "itself is trying to smother them");
    add_item("shadow|shadows","Strange, eerie shadows dancing on the walls");
    add_item("mist","It appears in front of your face as you breathe. " +
             "This hall is unnaturally cold");

    add_exit(ROOM + "lev2_landing2","west");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_priest",1);
}

void init(void)
{
    add_action("do_pray","pray");
    SYS_ADMIN->visit(282);
}

int do_pray(string str)
{
    if(TP->query_alignment() < (MAX_EVIL_ALIGN))
    {
        W("You bow your head in prayer. As you close your eyes, you sense " +
          "a powerful evil presence approaching. Startled, you open your " +
          "eyes and find yourself surrounded by a strange, black mist. " +
          "Terrified you wave your arms and throw yourself on the floor. " +
          "The mist dissolves and you are left with a feeling of awe and " +
          "fear of whatever powerful being it is that is worshipped here.\n");
        S(TP->QN + " bows " + TP->QPO + " head in prayer. Suddenly " +
          TP->QPR + " starts waving " + TP->QPO + " arms around and then " +
          TP->QPR + " throws " + TP->QO + "self onto the floor. " +
          C(TP->QPR) + " looks up with a look of awe and fear on " +
          TP->QPO + " face.\n");
        return 1;
    }
    W("You bow your head and close your eyes, but open them again " +
      "immediately. Whatever evil being it is that is worshipped here, " +
      "you feel no desire to call upon it.\n");
    S(TP->QN + " looks as if " + TP->QPR + "'s going to pray, but changes " +
      TP->QPO + " mind.\n");
    return 1;
}
