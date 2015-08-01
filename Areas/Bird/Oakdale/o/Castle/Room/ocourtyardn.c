#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("Northern end of the outer courtyard");
    set_long("You are at the northern end of the outer courtyard. In front " +
             "of you to the north is the impressive third gate tower. The " +
             "thick walls of the tower rise high above you, and only a few " +
             "thin arrowslits can be seen on the other walls facing the " +
             "courtyard. The courtyard continues to the south, and the road " +
             "passes through the massive wooden gates to the north. The " +
             "gates are open now, and you can see that the road turns west " +
             "after it has entered the tower. To the east you see the " +
             "battlements, and to the west are the high walls of the castle " +
             "proper.\n");
    set_new_light(5);
        
    add_item("courtyard|yard","The courtyard is paved with cobblestones");
    add_item("stones|stone|cobblestone|cobblestones","Small, smooth stones");
    add_item("tower","An impressive sight indeed. It's thick, black walls " +
             "loom over you, and it almost seems to be touching the dark " +
             "clouds above. It would be a disencouraging sight for any " +
             "attacking force that would get this far");
    add_item("wall|walls","Thick walls made of black stone");
    add_item("arrowslits|arrowslit","A defending force could do serious " +
             "damage to a force attacking the third gates by shooting " +
             "arrows through those arrowslits");
    add_item("road","A cobblestoned road going south and north through " +
             "the third gate");
    add_item("gate|gates","Two massive wooden gates. They are wide open " +
             "now, but when closed, it would be nigh to impossible for an " +
             "attacking force to force them open");
    add_item("battlements","The outer line of defence for the castle. The " +
             "defensive installations are turned inwards as well as " +
             "outwards. That way the battlements can be used against an " +
             "attacking force that has come through the first two gates as " +
             "well as attackers outside of the castle");
    add_item("installation|installations","The 'teeth' on the top of the " +
             "wall providing cover for soldiers");
    add_item("teeth|tooth","They are turned inwards as well as outwards");
    add_item("castle","A strong keep indeed. You get an eerie feeling when " +
             "you realize you might soon be standing within it's walls, You " +
             "are actually having second thoughts. maybe it would be best " +
             "to turn back..");
    
    add_exit(ROOM + "ocourtyards","south");
    add_exit(ROOM + "gatetower3","north");
    
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_guard",1)->set_walking();
}
