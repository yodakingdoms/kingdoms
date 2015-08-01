//=====================================================================
// A random piece of newbie weapon players below level 5 can get if
// they toss a coin into the pond in the troll forest. They are a little
// bit better than they should be considering they are 'poor' but they
// are only for newbie use, so...
// Yoda 970420
//=====================================================================
#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void  create_object(void);
mixed query_prevent_login(void);

string *names = ({ "sword","shortsword","hammer","hand axe","knife" });
string *alt_names = ({ "iron sword","sword","iron hammer","axe",
                       "short knife" });
string *types = ({ "longblade","shortblade","blunt","axe","dagger" });
string *shorts = ({ "An iron sword","A shortsword","An iron hammer",
                    "A hand axe","A short knife" });
string *longs = ({ "An old sword with a pretty dull blade. Still, it's "+
                   "better than nothing.\n",
                   "An iron shortsword that looks a bit rusty.\n",
                   "An old iron warhammer. Looks as if it hasn't fought "+
                   "any wars in quite a long time.\n",
                   "A hand axe that seems to be made more for chopping "+
                   "down trees than chopping heads of enemies.\n",
                   "A short iron knife that looks more suited for putting "+
                   "butter on bread than slitting throats of others.\n" });

void create_object(void)
{
  int i = random(5);
  set_name(names[i]);
  add_id(alt_names[i]);
  add_id(types[i]);
  set_short(shorts[i]);
  set_long(longs[i]);
  set_type(types[i]);
  set_property("poor");
  set_material("iron");
  switch(i)
  {
    case 4: set_weight(1); 
     break;
    default:set_weight(2); 
     break; 
  }
  set_value(10);

  set_class(5+random(5));
  set_newbie();
}

mixed query_prevent_login(void)
{
  return 1;
}
