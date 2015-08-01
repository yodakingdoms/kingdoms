// The amulet is made to ward off disease, but unfortunately for whoever
// would need such an amulet, it is not a real warding amulet
#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;
inherit STD_LORE;

void create_object(void);

void create_object(void)
{
    set_name("amulet");
    add_id("amulet of warding");
    set_short("an amulet of warding");
    set_long("A small jewel hanging in a leather thong. Teeth from small " +
             "animals and strange leaves from plants are tied to the jewel, " +
             "in a way that will make them rest upon the bearers chest. "+
             "This is an amulet made to ward off disease.\n");
    set_type("amulet");
    set_weight(1);
    set_value(7);
    set_db(1);
    set_material("steel");
    set_property("poor");

    add_lore("You don't really remember hearing about warding amulets " +
             "of this kind.\n",10);
    add_lore("In fact, you're pretty sure it has no powers at all and " +
             "is useless. To bad for someone who is sick and trusts it.\n",20);
}
