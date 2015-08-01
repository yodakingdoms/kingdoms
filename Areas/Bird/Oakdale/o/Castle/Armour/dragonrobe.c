#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("robe");
    add_id("velvet robe");
    add_id("black robe");
    add_id("black velvet robe");
    set_short("a black velvet robe");
    set_long("A soft, light robe made of the blackest velvet. Silver " +
             "threads are woven into it and strange runes are sown into " +
             "the hems of the robe. A dragon's head, sown into the robe " +
             "with gold threads, adorns it's back. This robe is both " +
             "protective and extremely elegant.\n");
    set_type("armour");
    add_property("magic");
    set_weight(1);
    set_value(94);
    set_new_ac(7);
    set_material("velvet");
    set_property("good");
}
