#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A tunnel through the inner gate tower");
    set_long("A tunnel through the inner gate tower. The road is paved " +
             "with cobblestones and the ceiling above you is arched and " +
             "full of small holes. The huge wooden gates at the west end " +
             "of the tunnel are wide open, and you see the spikes of the " +
             "raised portcullis protrude from the ceiling. Through the " +
             "opening to the west you see the outer courtyard.\n");
    set_new_light(5);
    add_property("indoors");
    add_property("allow_horse");

    add_item("tunnel","An arched tunnel through the inner gate tower");
    add_item("tower","The inner gate tower is the seconed line of defence " +
             "for the castle");
    add_item("defence|line","The castle's defence is very strong");
    add_item("road","A road paved with cobblestones");
    add_item("stone|stones|cobblestones|cobblestone","Small, smooth stones");
    add_item("ceiling","The ceiling is arched and littered with holes");
    add_item("hole|holes","You suppose they are used to pour and shoot " +
             "nasty things down upon attackers who have managed to come " +
             "this far through");
    add_item("gate|gates","Huge, wooden gates. It would be very difficult " +
             "to force them open if they were locked and barred");
    add_item("spikes","The bottom end of the portcullis");
    add_item("portcullis|portcullises","There are two portcullises here, " +
             "that would slow any attacking force down considerably");
    add_item("courtyard","That's where you will end up if you would go " +
             "west");

    add_exit(ROOM + "drawbridge","east");
    add_exit(ROOM + "ocourtyards","west");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_guard",2);
}
