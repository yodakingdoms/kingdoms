// ==================================================================
// Random armour worn by random pirates.
// ==================================================================
#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

int i;

string *name = ({ "shirt", "eyepatch", "leg",
	          "shirt", "hat", "coat" });
string *short_desc = ({ "A striped shirt", "A black eyepatch", "A wooden leg",
	                "A dirty shirt", "A black pirate hat",
                        "A leather coat" });
string *long_desc = ({ "A black and white striped shirt.\n",
                       "A black eyepatch of the type commonly worn by " +
                       "pirates.\n",
                       "A wooden leg, but not a normal one. It's shaped " +
                       "like a foot and a leg and hollow. It looks more " +
                       "like a boot.\n",
                       "A dirty, stained shirt with a lace ruffled " +
                       "neckline.\n",
                       "A black hat with an emblem of a grinning skull " +
                       "and two crossed bones.\n",
                       "A bulky leather coat.\n" });
string *type = ({ "armour","helmet","boot","armour","helmet","armour" });
int *value = ({ 50, 20, 20, 40, 25, 55 });
int *weight = ({ 2, 1, 1, 2, 1, 2 });
string *material = ({ "cloth", "cloth", "wood", "cloth", "cloth",
                      "leather" });
int *ac = ({ 5, 1, 2, 5, 3,8 });
string *alias = ({ "striped shirt", "black eyepatch", "wooden leg",
                   "dirty shirt", "black hat", "leather coat" });

void create_object(void);
void set_stat_index(int index);

void create_object(void)
{
    set_property("poor");
    set_stat_index(random(6));
}

void set_stat_index(int index)
{
    i = index;
    set_short(short_desc[i]);
    set_long(long_desc[i]);
    set_name(name[i]);
    add_id(alias[i]);
    set_value(value[i]);
    set_weight(weight[i]);
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
