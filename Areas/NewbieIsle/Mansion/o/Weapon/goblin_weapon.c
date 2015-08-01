// ==================================================================
// Random weapon wielded by random goblins.
// ==================================================================
#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

int i;

string *name = ({ "scimitar","sabre","dagger","axe" });
string *short_desc = ({ "A scimitar","A sabre","A curved dagger",
	                "A hand axe" });
string *long_desc = ({ "A scimitar that looks like it's seen a lot of use.\n",
                       "A curved sabre that looks like it has seen " +
                       "a lot of use.\n",
                       "A curved dagger that looks like it has seen a lot " +
                       "of use.\n",
                       "A hand axe that looks like it has seen a lot of " +
                       "use.\n"
                     });
int *wc = ({ 9,10,5,8 });
string *alias = ({ "scimitar","curved sabre","curved dagger","hand axe" });
int *weight = ({ 2,2,1,2 });
int *value = ({ 15,19,10,16 });
string *material = ({ "iron","steel","iron","iron" });
string *type = ({ "longblade","longblade","dagger","axe" });

void create_object(void);
void set_stat_index(int index);

void create_object(void)
{
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
    set_class(wc[i]);
    set_weight(weight[i]);
    set_value(value[i]);
    set_material(material[i]);
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
