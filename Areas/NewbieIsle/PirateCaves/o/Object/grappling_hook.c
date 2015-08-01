//======================================================================
// This is the grappling hook you tie to a rope to use in the piracy
// quest
//======================================================================
#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void create_object(void);
void init(void);
int do_tie(string str);

void create_object(void)
{
  set_name("hook");
  add_id("grappling hook");
  set_short("A grappling hook");
  set_long("A steel grappling hook. If you had a rope, you could tie " +
           "the hook to the rope and make a nice tool to be used when " +
           "attacking ships on the high seas.\n");
  set_weight(1);
  set_value(25);
 set_material("iron"); //Angelwings
}

void init(void)
{
    add_action("do_tie","tie");
}

int do_tie(string str)
{
    string obj, obj2;
    object rope;

    if(!str)  //Added by Angelwings 20040919
    {
      return notify_fail("Tie what to what?\n");
    }

    if(str == "hook")
    {
        return notify_fail("Tie hook to what?\n");
    }
    else if(sscanf(str, "hook to %s", obj) == 1 ||
	    sscanf(str, "%s to hook", obj2) == 1) //Added by Angelwings
    {
        if(obj == "rope" || obj2 =="rope")
        {
            if(rope = present("rope",TP))
            {
                W("You tie the rope and hook together to make a nice " +
                  "rope with a hook.\n");
                S(TP->QN + " ties a rope and a hook together to make a " +
                  "nice rope with a hook.\n");
                // If players can carry the hook and a rope, they can carry
                // the grappling rope
                make(PCOBJECT + "grappling_rope",TP);
                rope->destroy();
                TO->destroy();
                return 1;
            }
            else
            {
                W("You have to carry a rope to be able to do that.\n");
                return 1;
            }
        }
        else
        {
            W("You can't tie the hook to " + obj + ".\n");
            return 1;
        }
    }
}
