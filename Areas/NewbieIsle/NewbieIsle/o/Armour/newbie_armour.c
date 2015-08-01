//=====================================================================
// A random piece of newbie armour players below level 5 can get if
// they toss a coin into the pond in the troll forest. They are a little
// bit better than they should be considering they are 'poor' but they
// are only for newbie use, so...
// Yoda 970420
//=====================================================================
#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void  create_object(void);
void  set_me_to_armour(void); // Want to make one piece an 'armour' piece
mixed query_prevent_login(void);

string *names = ({ "helmet","gloves","cloak","leggings","shield","boots" });
string *types = ({ "helmet","glove","cloak","legging","shield","boot" });
string *shorts = ({ "An iron helmet","Iron gloves","A fur cloak",
                    "Iron leggings","A wooden shield","Leather boots" });
string *longs = ({ "A dented iron helmet that looks as if it has seen "+
                   "better days.\n",
                   "A pair of iron gloves that don't look very good, but "+
                   "better than nothing.\n",
                   "A fur cloak with quite a few patched holes in it.\n",
                   "A pair of dented iron leggings.\n",
                   "A worn wooden shield with plenty of pieces chopped "+
                   "away.\n",
                   "A pair of worn leather boots.\n" });
string *materials = ({ "iron","iron","fur","iron","wood","leather" });

void create_object(void)
{
  int i = random(6);
  set_name(names[i]);
  add_id(types[i]);
  set_short(shorts[i]);
  set_long(longs[i]);
  set_type(types[i]);
  set_property("poor");
  set_material(materials[i]);
  set_weight(1);
  set_value(0);
  set_new_ac(3+random(3));
  set_db(0);
  set_newbie();
}

void set_me_to_armour(void)
{
  int i;
  string *junk = query_ids();
  for(i = 0; i < sizeof(junk); ++i)
  {
    remove_id(junk[i]);
  }
  set_name("chainmail");
  add_id("chain mail");
  set_short("A rusty chainmail");
  set_long("A rusty chainmail that seems to have been lying at the bottom "+
           "of a forest pond or something similar for quite a long time.\n");
  set_type("armour");
  set_property("poor");
  set_material("iron");
  set_weight(3);
  set_value(0);
  set_new_ac(7+random(7));
  set_db(0);
}

mixed query_prevent_login(void)
{
  return 1;
}
