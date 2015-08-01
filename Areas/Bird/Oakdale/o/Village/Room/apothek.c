#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_APO;

void create_object(void);
void reset(int arg);
void init(void);
int do_smell(string str);

void create_object(void)
{
    set_short("Apothec");
    set_long("This is the Oakdale apothek. The stone walls of this room " +
             "are covered with different cupboards and shelves filled with " +
             "strange cans, bottles and potions. Strange herbs and plants " +
             "are hanging from the wooden ceiling filling the room with " +
             "strange smells. A small lamp is standing on the counter " +
             "providing the room with light. In the back of the room you " +
             "see some stairs going up and on the wall behind the counter " +
             "you see a menu.\n");
    add_property("indoors");
    set_new_light(10);

    add_item("shelf","There are several of them");
    add_item("shelves","They are filled with many strange cans and potions");
    add_item("cupboard|cupboards","Wooden cupboards");
    add_item("can|cans|bottle|bottles|potion|potions","Containing strange " +
             "mixtures");
    add_item("herb|herbs|plant|plants","Strange things you don't recognize " +
             "hanging from the ceiling");
    add_item("ceiling","It is wooden");
    add_item("lamp","A small oil lamp");
    add_item("counter","A wooden counter behind which the apothekary " +
             "usually stands");
    add_item("wood","Oak");
    add_item("oak","Well polished oak");
    add_item("stairs","Wooden stairs going up");
    add_item("smell|smells","You smell medicine");
    add_item("menu","#reading");
    add_item("wall|walls","The walls are made of stone");
    add_item("stone","Smooth, cold stone");

    add_exit(ROOM + "road4","south");
    add_exit(ROOM + "sl_hall","up");

    medicine = ({"oakhealer","leafjuice"});
    bloodclotters = ({"oakleaf","oakbinder"});
    criticals = ({"oakcrit","chlorofyl"});
    ware = medicine + bloodclotters + criticals;

    ware_path = OBJECT;

    max_strength_apothek = 3000;
    max_strength_player = 500;

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "apothekary",1);
    apothek_module_reset(arg);
    // I think it's a bit silly that this is in reset in the apo
    // module instead of create_object but that's how it is
    waitername = "Lallan";
}

void init(void)
{
    add_action("do_smell","smell");
    apothek_module_init();
}

int do_smell(string str)
{
    W("Wheee! You can't decide if you want to throw up or just fly away! " +
      "Your stomach feels wierd, but your head feels light. You are left " +
      "with a never before felt feeling of euphoria. What kind of herbs is " +
      "the apothekary selling here anyway?!?!\n");
    S(TP->QN + " smells the air and goes pale. " + C(TP->QPR) + " gets a " +
      "distant look in " + TP->QPO + " eyes and whispers: Grooovy....\n");
    return 1;
}
