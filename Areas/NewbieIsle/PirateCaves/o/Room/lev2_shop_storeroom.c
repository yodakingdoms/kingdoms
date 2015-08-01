#pragma strict_types
#include "../def.h"
inherit STD_STORE;

void create_object(void);
void generate_correction_values(void);

void create_object(void)
{
    set_short("Shop storeroom (w)");
    set_long("Storeroom for the shop. If you are a mortal you sure " +
             "are in a place you should not be.\n");
    set_new_light(1);
    add_property("indoors");

    add_exit(PCROOM + "lev2_shop","west");

    reset(0);
}

void generate_correction_values(void)
{
    // The shopkeeper is a drunken slob and easier to negotiate with
    corr_buy  = random(20) + 100;
    corr_sell = random(20) + 20;
    corr_max = random(20) + 100;
}