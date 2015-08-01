#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_scrutinize(string str);
int do_read(string str);

void create_object(void)
{
    set_short("The entrance to the shrine");
    set_long("You are in a shadowy corridor. Pillars line the once white " +
             "marble walls and your footsteps echo through the hallway. " +
             "The smooth marble floor is covered with a thick layer of " +
             "dust, under which you discern beautiful mosaics laid into " +
             "the floor. Murals hang on the north and south walls, " +
             "seemingly untouched by time. In the east wall is an archway, " +
             "the frame of which is engraved by strange runes. The way " +
             "back out is west.\n");
    set_new_light(10);
    add_property("indoors");
        
    add_item("hallway|corridor","A wide, shadowy corridor");
    add_item("pillar|pillars","Marble pillars that once were white. Now, " +
             "however they are grey and cracked");
    add_item("wall|walls","Marble walls that once were shining white. Their " +
             "luster is now long since faded");
    add_item("floor","The smooth floor is covered with a thick layer of dust");
    add_item("mosaic|mosaics","The mosaics have faded somewhat in time, but " +
             "they are still beautiful to behold. Perhaps you could find " +
             "something out by scrutinising them?");
    add_item("mural|murals","Murals with the symbol of the church of true " +
             "faith on them. It seems strange that they have not decayed " +
             "like most of the other things in this shrine");
    add_item("runes","Strange, ancient looking runes. Perhaps you could " +
             "read them?");
    add_item("dust","A thick layer with no marks or prints in it. It is " +
             "obvious that noone's been here in a very long time");
    add_item("archway","One leads west and another leads east");
    
    add_exit(ROOM + "shrine_outside","west");
    add_exit(ROOM + "shrine_antechamber","east");    
}

void init(void)
{
    add_multi_action("do_scrutinize","scrutinize|scrutinise");
    add_action("do_read","read");
}

int do_scrutinize(string str)
{
    if(str == "mosaic" || str == "mosaics")
    {
        W("The mosaics depict Clerics of Cay and Knights of Cor fighting " +
          "side by side against minions of darkness.\n");
        S(TP->QN+" examines the mosaics on the floor closely.\n");
    
        if(TP->query_skill("lore") > 40)
        {
            W("It was a long time ago that clerics and knights fought side " +
              "by side. These days the clerics have isolated themselves up " +
              "in the highlands, and allthough they serve the same " + 
              "alignment, the brother-, and sisterhoods of clerics and " +
              "knights are now estranged from each other. This shrine must " +
              "be very old indeed if it is from that time... Older than " +
              "the castle and the rest of the village. Fascinating.\n");
        }
        return 1;
    }
}

int do_read(string str)
{
    if(str == "runes")
    {
        if(TP->query_skill("runes") > 40)
        {
            W("These runes are very old. They say: 'Welcome child, in times " +
              "of darkness seek the light, lest the shadow will consume " +
              "you. May the fair Lady Cay bless your soul'.\n");
            S(TP->QN + " reads the runes on the archway.\n");
            return 1;
        }
        W("These runes are too old for you to make any sense of.\n");
        S(TP->QN + " peers at the runes on the archway, looking confused.\n");
        return 1;
    }
    return notify_fail("Read what?\n");
}
