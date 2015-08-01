// ==================================================================
// Random armour worn by random goblins.
// ==================================================================
#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

int i;

string *name = ({ "helmet", "shield", "boots", "gloves" });
string *short_desc = ({ "A leather helmet", "A wooden shield",
                        "A pair of leather boots",
                        "A pair of leather gloves" });
string *long_desc = ({ "A worn leather helmet. It doesn't seem like it " +
                       "will provide much protection.\n",
                       "A wooden shield with an iron handle.\n",
                       "Some worn leather boots.\n",
                       "Some worn leather gloves.\n" });
string *type = ({ "helmet","shield","boot","glove" });
int *value = ({ 20, 25, 20, 20 });
string *material = ({ "leather", "wood", "leather", "leather" });
int *ac = ({ 2, 3, 2, 1 });
string *alias = ({ "leather helmet", "wooden shield", "leather boots",
                   "leather gloves" });

void create_object(void);
void set_stat_index(int index);

void create_object(void)
{
    set_weight(1);
    set_property("poor");
    set_stat_index(random(4));
}

void set_stat_index(int index)
{
    i = index;
    set_short(short_desc[i]);
    set_long(long_desc[i]);
    set_name(name[i]);
    add_id(alias[i]);
    set_value(value[i]);
    set_material(material[i]);
    set_new_ac(ac[i]);
    set_type(type[i]);
}

int query_stat_index(void)
{
    return i;
}

string query_allow_login(void)
{
    return name_file(TO) + ":query_stat_index|set_stat_index";
}
