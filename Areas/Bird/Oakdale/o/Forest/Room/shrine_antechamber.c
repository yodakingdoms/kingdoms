#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_listen(string str);

void create_object(void)
{
    set_short("An antechanber");
    set_long("This seems to be some sort of antechamber. A mosaic is laid " +
             "in the floor and there are decorations on the walls. The " +
             "floor is covered with dust and moss grows in the corners. " +
             "There is a doorway to the north, and the way back out is to " +
             "the west. A black skeleton lies on the threshold to the room " +
             "to the north. There is something strange in the air here.\n");
    set_new_light(5);
    add_property("indoors");
        
    add_item("room|antechamber","This room looks very much like some sort " +
             "of antechamber");
    add_item("mosaic","A big mosaic of the symbol of The Church of True " +
             "Faith");
    add_item("floor","The smooth marble floor is covered with a thick layer " +
             "of dust");
    add_item("decoration|decorations","Symbols of religion and paintings of " +
             "struggling good and evil beings");
    add_item("symbol|symbols","Mostly symbols of The Church of True Faith");
    add_item("painting|paintings|being|beings","Elves with shining eyes " +
             "doing battle with cruel orcs and firebreathing dragons. Very " +
             "realistic. You can almost hear the sounds of battle as you " +
             "look at them");
    add_item("elf|elves","Elves are the embodiment of good");
    add_item("orc|orcs","Evil, disgusting creatures");
    add_item("dragon|dragons","Mighty, terrifying creatures");
    add_item("wall|walls","The marble walls are highly decorated");
    add_item("layer|dust","A thick layer of dust with no marks or tracks " +
             "in it");
    add_item("moss|corner|corners","A strange dark green moss grows in the " +
             "corners");
    add_item("doorway","Another room lies beyond it");
    add_item("skeleton","A black skeleton that does not look as if it is " +
             "the remains of a human. It looks as if it has been badly " +
             "burned and as if whoever it was died as he tried to enter " +
             "the room beyond");
    add_item("treshold","A skeleton lies on the threshold");
    add_item("air","Something about the air in this room feels strange");
    
    add_exit(ROOM + "shrine_entrance","west");
    add_exit(ROOM + "shrine_altar","north");
}

void init(void)
{
    add_action("do_listen","listen");
}

int do_listen(string str)
{
    W("Your ears are filled with the warcries of darkmen and elves, the " +
      "roar of ogres and the clang of swords. Over it all you hear the " +
      "screams of the wounded and the dying. Startled you take a step " +
      "back.\n");
    S(TP->QN + " takes a sudden step back.\n");
    return 1;
}
