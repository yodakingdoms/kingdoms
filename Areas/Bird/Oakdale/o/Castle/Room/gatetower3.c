#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A tunnel through the third gate tower");
    set_long("You are in a tunnel through the third gate tower. The tunnel " +
             "turns to the west midway through, and opens up into the " +
             "inner courtyard to the west. The ground is paved with " +
             "cobblestones and the ceiling is arched and full of small " +
             "holes. You see the spikes of the two portcullises protrude " +
             "from the ceiling, and there are massive wooden gates at both " +
             "ends of the tunnel.\n");
    set_new_light(5);
    add_property("indoors");
    add_property("allow_horse");

    add_item("tunnel","An arched tunnel that turns ninety degrees here. " +
             "Probably to make it more difficult for a team with a " +
             "battering ram to break down the last gate");
    add_item("courtyard","The inner courtyard is to the west and the outer " +
             "courtyard is to the south");
    add_item("ground","The ground is paved with cobblestones");
    add_item("cobblestones|cobblestone|stones|stone","Round, smooth stones");
    add_item("ceiling","The ceiling is arched and littered with holes");
    add_item("hole|holes","Holes through which defenders could shoot and " +
             "pour nasty things down at attackers that have gotten this far");
    add_item("spike|spikes","The bottom part of a portcullis");
    add_item("portcullis|portcullises","There are two of them here, and " +
             "would they be lowered, they would slow down any attacking " +
             "force");
    add_item("gate|gates","Massive wooden gates. You see them at both ends " +
             "of the tunnel");
    add_item("end|ends","In both ends of the tunnel are massive wooden " +
             "gates, ready to be shut and bolted");

    add_exit(ROOM + "ocourtyardn","south");
    add_exit(ROOM + "icourtyarde","west");
}
