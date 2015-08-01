#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

string name;

void create_object(void);
void init(void);
int do_play(string str);

void create_object(void)
{
    string *names = ({ "Bithir","Narzug","Ceril","Dusk","Yoda" });
    name = names[random(5)];

    set_name("doll");
    add_id(lower_case(name) + " doll");
    add_id("wooden doll");
    set_short("a " + name + " doll");
    set_long("This small wooden doll is a perfect likeness of " +
             name + ".\n");
    set_value(90);
    set_weight(1);
    set_material("wood");
}

void init(void)
{
   add_action("do_play","play");
}

int do_play(string str)
{
    if(str == "with doll" || str == "doll" ||
       str == "with " + lower_case(name) + " doll")
    {
        W("You play for a while with the " + name + " doll, forgetting " +
          "everything and everyone around you.\n");
        S(TP->QN + " picks up the " + name + " doll and plays merrily " +
          "with it for a little while.\n");
        return 1;
    }
    // No point in messing up bard songs for example
    return 0;
}
