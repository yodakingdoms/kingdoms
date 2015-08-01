#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void);
void init(void);
int do_strum(string str);

void create_object(void)
{
    set_short("A strangely shaped mandolin");
    set_long("A black mandolin with a strange shape and a pointy head. It " +
             "seems to be solid, not hollow like mandolins usually are, " +
             "and when you strum it it makes a strange, distorted sound.\n");
    set_name("mandolin");
    add_id("strangely shaped mandolin");
    add_id("black mandolin");
    set_class(8);
    set_weight(2);
    set_value(30);
    set_material("wood");
    set_type("blunt");
    set_property("poor");
}

void init(void)
{
    add_action("do_strum","strum");
    ::init();
}

int do_strum(string str)
{
    if(str == "mandolin")
    {
        W("You strum the mandolin. It makes a strange distorted sound.\n");
        S(TP->QN + " strums a strangely shaped mandolin. It makes a strange " +
          "distorted sound.\n");
        return 1;
    }
    return notify_fail("Strum what?\n");
}
