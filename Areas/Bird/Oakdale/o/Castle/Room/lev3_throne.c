#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_sit(string str);
int do_pass(string str);

void create_object(void)
{
    set_short("A huge hall");
    set_long("A huge hall with a high hammerbeam ceiling. A big mosaic is " +
             "laid in the floor. Large murals and banners hang on the " +
             "walls. Four black pillars support the ceiling, and the walls " +
             "are lined with wooden chairs, tables and benches. Iron " +
             "braziers are placed around the hall and the smoke from their " +
             "fires fills the air, making it hard not to cough when you " +
             "breathe. By the north wall is a raised part of the floor " +
             "where two black stone thrones are. The wall behind them is " +
             "covered by black curtains and a majestic banner depicting " +
             "a huge, black dragon. This must be the throne room of the " +
             "castle.\n");
    set_new_light(5);
    add_property("indoors");
    add_property("allow_horse");

    add_item("room|hall","A huge, impressive looking hall. This must be " +
             "the old throne room");
    add_item("ceiling","A high, beautiful hammerbeam ceiling");
    add_item("mosaic","The mosaic is a black circle with a black dragon's " +
             "head inside it. It takes up most of the floor");
    add_item("floor","Most of the smooth floor is taken up by the mosaic " +
             "laid in it");
    add_item("mural|murals","All the large murals show the same image. The " +
             "silhouette of a castle against a night sky. An enourmous " +
             "shadow in the shape of a dragon is hanging over it");
    add_item("silhouette|castle","That silhouette looks strangely " +
             "familiar. You think you have seen that castle somewhere..");
    add_item("shadow|shape|dragon","The shadow hanging over the castle in " +
             "the mural has the shape of a dragon");
    add_item("banner|banners","All the black banners bear the mark of a " +
             "black dragon. It is the same mark that is on the armour of " +
             "the troops of the castle");
    add_item("pillar|pillars","The pillars look very strong. They are made " +
             "of smooth, black stone");
    add_item("chair|chairs","Wooden chairs made of oak");
    add_item("table|tables","Wooden tables made of oak");
    add_item("bench|benches","Wooden benches made of oak");
    add_item("brazier|braziers","Black iron braziers with fires burning in " +
             "them");
    add_item("smoke","Smoke from the braziers fill the air in the hall");
    add_item("wall|walls","The walls are covered by banners and murals");
    add_item("thrones","The smaller throne or the larger throne?");
    add_item("smaller throne","The smaller throne is made of black stone " +
             "and undecorated");
    add_item("larger throne","The armrests of the black stone throne are " +
             "shaped like the front legs of a dragon. At the top of the " +
             "throne is a large dragon's head, and curled round the bottom " +
             "of the chair is a dragon's tail. If anyone would sit in that " +
             "throne, it would look like he was sitting in the lap of a " +
             "dragon");
    add_item("curtains","Black, thick curtains. You notice something about " +
             "one of them");
    add_item("curtain","It looks like you could pass through the curtain " +
             "and enter another room");

    add_exit(ROOM + "lev3_landing2","south");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_commander",2);
    add_monster(MONSTER + "darkling_highguard",2);
    add_monster(MONSTER + "yzwul",1);
}

void init(void)
{
    add_action("do_sit","sit");
    add_action("do_pass","pass");
    SYS_ADMIN->visit(302);
}

int do_sit(string str)
{
    if(!present("yzwul"))
    {
        W("You approach the thrones, but you sense a powerful presence " +
          "there. The eyes on the head of the dragon glow for a moment. " +
          "Powerful magic must be laid upon the thrones, so you decide that " +
          "you should leave them alone.\n");
        S(TP->QN + " walks up towards the thrones, hesitates and turns " +
          "back.\n");
        return 1;
    }
    W("Yzwul snarls menancingly at you as you approach the thrones. You " +
      "quickly decide you don't want to sit there anyway...\n");
    S(TP->QN + " looks longingly at the thrones.\n");
    return 1;
}

int do_pass(string str)
{
    if(str == "through curtain" || str == "curtain")
    {
        if(present("darkling"))
        {
            W("A darkling steps out and prevents you from passing.\n");
            S("A darkling steps out in front of " + TP->QN + ".\n");
            return 1;
        }
        else if(present("yzwul"))
        {
            W("Yzwul leers at you as you approach and says: You are not " +
              "going that way, " + TP->QN + ".\n");
            S("Yzwul says something to " + TP->QN + ".\n");
            return 1;
        }
        else
        {
            W("You pass through the curtain and walk through an archway " +
              "into another room.\n");
            TP->move_player("passes through the curtain",
                            ROOM + "lev3_yzwulsroom",
                            "arrives from the archway to the south",1);
            return 1;
        }
    }
    return notify_fail("Pass through what?\n");
}
