// =======================================================================
// This can be used as a panic button. When you drink it, you're magically
// moved to Newbie Island. It can be used to escape from really nasty
// monsters and/or playerkillers (as long as you are outdoors). It will
// take a fair ammount of time to fly to the island though, so a player
// chasing you will have a chance to get there and wait for you. It won't
// be an instant escape to safety from pkers, more a chance to regroup.
// =======================================================================
#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;
inherit STD_LORE;

void create_object(void);
void init(void);
int do_my_attune(string str);
int do_drink(string str);
void do_soar(object player);
string query_break_msg(void);
mixed query_prevent_login(void);
void log_drinker(void);

void create_object(void)
{
    set_name("vial");
    add_id("crystal vial");
    add_id("potion");
    set_short("A crystal vial");
    set_long("A small crystal vial containing a translucent potion. The " +
             "vial is engraved with tiny images of birds in flight. It is " +
             "certainly an exquisite piece of glasswork.\n");
    add_property("fragile");
    add_property("nostore");
    set_weight(1);
    set_value(320);
    set_material("crystal"); //Angelwings
}

void init(void)
{
    add_action("do_drink","drink");
    add_action("do_my_attune","attune");
    if(ENV(TO) == TP && TP->query_skill("attune") > 20)
    {
        W("The small crystal vial gives you a tingling feeling as you "+
          "pick it up.\n");
    }
}

int do_my_attune(string str)
{
    if(str == "vial" || str == "to vial")
    {
        if(TP->query_skill("attune") > 20)
        {
            W("The potion in the vial definitely has magical properties.\n");
            return 1;
        }
        if(TP->query_skill("attune") > 50)
        {
            W("The aura the vial emits seems to suggest some sort of "+
              "change of form.\n");
            return 1;
        }
        W("You can't discern anything special about it.\n");
        return 1;
    }
}

int do_drink(string str)
{
    if(str == "vial" || str == "potion")
    {
        if(ENV(TP)->query_property("indoors"))
        {
            W("You get the feeling that drinking this potion indoors would " +
              "be a bad idea.\n");
            S(TP->QN + " looks up at the ceiling.\n");
            return 1;
        }
        W("You gulp down the contents of the vial.\nA tingling feeling "+
          "goes through your body, and then you double over in pain as "+
          "everything turns black.\n");
        say(TP->QN+" gulps down the contents of a small crystal vial and " +
            "doubles over in pain.\n");
        set_alarm(2.0,0.0,"do_soar",TP);
        return 1;
    }
}

void do_soar(object player)
{
    set_this_player(player);
    W("The pain recedes... You open your eyes, spread your wings, and " +
      "soar...\n");
    S(TP->QN + " disappears in a puff of smoke. In " + TP->QN + "'s place " +
      "is a huge falcon, spreading its wings, soaring majestically " +
      "towards the skies.\n");
    log_drinker();
    make(PCOBJECT + "flying_obj",TP);
    TP->move_player("x",PCROOM + "flying");
    destroy();
}

string query_break_msg(void)
{
    return "The vial shatters, a small puff of smoke rises from the potion " +
           "as it spills out on the floor. The smoke forms the shape of a " +
           "bird that quickly flies away.\n";
}

mixed query_prevent_login(void)
{
    return 1;
}

void log_drinker(void)
{
    int i;
    object *things = all_inventory(ENV(TP));

    write_file(BIRDVIAL_LOG,"\n" + ctime(time()) + ":\n  Room: " +
               name_file(ENV(TP)) + "\n  Drinker: " + C(TP->QRN) + "\n" +
               "  Also present:\n");
    for(i = 0; i < sizeof(things); ++i)
    {
        if(living(things[i]) && things[i] != TP)
        {
            write_file(BIRDVIAL_LOG,"   " + things[i]->short() + " (" +
                       things[i]->QRN + ")\n   " + name_file(things[i]) +
                       "\n");
        }
    }
}
