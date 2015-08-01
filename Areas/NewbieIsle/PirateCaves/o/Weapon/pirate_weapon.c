// ==================================================================
// Random weapon wielded by random pirates.
// ==================================================================
#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

int i;

string *name = ({ "scimitar","sabre","dagger", "hook","leg","tankard" });
string *short_desc = ({ "A rusty scimitar","A curved sabre","A curved dagger",
	                "A hook","A wooden leg","A steel tankard" });
string *long_desc = ({ "A rusty scimitar that looks like it has seen better " +
                       "days.\n",
                       "A rusty, curved sabre that looks like it has seen " +
                       "better days.\n",
                       "A rusty, curved dagger that looks like it has been " +
                       "chewed on.\n",
                       "An iron hook of the type commonly seen at the end " +
                       "of an arm of a pirate that has lost his hand.\n",
                       "A wooden peg leg of the kind normally used by " +
                       "pirates who have lost their real leg. It can be " +
                       "used to bash skulls when it's not used for walking.\n",
                       "A tankard made of steel. When it's not being used " +
                       "to drink ale, it can be used to bash heads.\n",
                     });
int *wc = ({ 9,10,5,8,7,7 });
string *alias = ({ "rusty scimitar","curved sabre","curved dagger","iron hook",
                   "wooden leg", "steel tankard" });
int *weight = ({ 2,2,1,2,2,2 });
int *value = ({ 15,19,10,16,5,15 });
string *material = ({ "iron","steel","iron","iron","wood","steel" });
string *type = ({ "longblade","longblade","dagger","thrusting","blunt",
                  "blunt" });

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
