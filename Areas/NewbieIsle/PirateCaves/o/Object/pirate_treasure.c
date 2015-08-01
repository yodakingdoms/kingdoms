// ==================================================================
// Random treasure carried by random pirate. A pirate has a one in
// four chance of receiving a treasure when it is created.
// ==================================================================
#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

string *name = ({ "parrot","goblet","plate","frame","fork","glass" });
string *short_desc = ({ "A stuffed parrot","A golden goblet","A silver plate",
	                "An iron frame","A steel fork","A crystal glass" });
string *long_desc = ({ "A stuffed parrot that would not look out of place " +
                       "on the shoulder of a pirate.\n",
                       "A golden goblet that looks like it might be worth " +
                       "quite a bit.\n",
                       "A silver plate that looks like it might be worth " +
                       "quite a bit.\n",
                       "An iron frame to be used with a picture or " +
                       "you wonder why anyone would be carrying around an " +
                       "empty frame.\n",
                       "A dull steel fork that doesn't look as if it's of " +
                       "any use for anything.\n",
                       "A beautiful crystal glass, with figures of grinning " +
                       "skulls etched into its sides.\n",
                     });
string *alias = ({ "stuffed parrot","golden goblet","silver plate",
                   "iron frame","steel fork", "crystal glass" });
int *value = ({ 55,100,100,30,10,110 });
string *material = ({ "flesh","gold","silver","iron","steel","crystal" });

void create_object(void)
{
    int i = random(6);

    set_short(short_desc[i]);
    set_long(long_desc[i]);
    set_name(name[i]);
    add_id(alias[i]);
    set_weight(1);
    set_value(value[i]);
    set_material(material[i]);
}
