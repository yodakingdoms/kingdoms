#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void);
void init(void);
int do_eat(string str);

void create_object(void)
{
    set_name("carrots");
    add_id("bundle");
    add_id("bundle of carrots");
    set_short("a bundle of carrots");
    set_long("A bundle of fresh, tasty looking carrots. You feel yourself " +
             "beginning to drool when you look at them.\n");
    set_value(3);
    set_weight(1);
    set_type("blunt");
    set_class(4);
    set_material("carrot");
    set_property("poor");
}

void init(void)
{
    add_multi_action("do_eat","eat|taste");
    ::init();
}

int do_eat(string str)
{
    if(str == "carrots" || str == "carrot" || str == "bundle" ||
       str == "bundle of carrots")
    {
        W("Unfortunately the carrots are not as tasty as they look. They " +
          "are hard as stone so you decide against it.\n");
        return 1;
    }
}
