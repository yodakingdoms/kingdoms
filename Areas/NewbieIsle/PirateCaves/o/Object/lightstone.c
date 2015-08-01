//=================================================================
// This is a magic stone that provides light when you activate it.
// You need attune 20 to use it (and some lore to find out how),
// and it takes some sp from the person using it while it is lit.
// It can be found in /Room/lev1_wn_corridor.
//=================================================================
#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;
inherit STD_LORE;

object user;     // The player who is using the stone when it is lit.
                 // Always 0 when the stone is not lit
int shining;

void create_object(void);
void init(void);
int  do_attune(string str);
int  do_light(string str);
int  do_darken(string str);
int  drop(int silently);
void light(void);
void darken(void);
void drain(void);

void create_object(void)
{
    set_name("stone");
    add_id("lightstone");
    set_short("A small, grey stone");
    set_long("A small, grey stone that is a bit out of the ordinary "+
             "only because it is very smooth.\n");
    set_weight(1);
    set_value(300);
    add_property("magic");

    add_lore("You've heard about stones like these. Magic stones "+
             "that provides someone who knows how to use it with light.\n",1);
    add_lore("Not everyone can use them though, as you need a basic "+
             "knowledge of magic to light them.\n",10);
    add_lore("The stone will constantly need to draw power from the person "+
             "using it.\n",15);
    add_lore("To learn how to use the stone, you only need to be able to "+
             "attune to it.\n",20);

    shining = 0;
    user = 0;
    set_material("stone"); //Angelwings
}

void init(void)
{
    add_action("do_attune","attune");
    add_action("do_light","light");
    add_action("do_darken","darken");
    ::init();
}

int do_attune(string str)
{
    if(str == "stone")
    {
        if(TP->QS("attune") < 20)
        {
            W("You are not comfortable enough with the flows of magic "+
            "to use this stone.\n");
            S(TP->QN + " concentrates on a small stone, but looks "+
            "disappointed.\n");
            return 1;
        }
        W("You sense that you would be able to use this stone, and that "+
        "you would only have to <light> it to make it shine and <darken> "+
        "it to stop shining!\n");
        S(TP->QN + " concentrates on a small stone and goes: Aha!\n");
        return 1;
    }
}

int do_light(string str)
{
    int sp_cost = 10 + random(10);

    if(str == "stone" && TP->QS("attune") > 20 && ENV(TO) == TP)
    {
        if(shining)
        {
            W("The stone is already shining!\n");
            return 1;
        }

        if(TP->query_spell_points() >= sp_cost)
        {
            W("You channel some power into the stone and make it shine "+
              "with a warm light.\n");
            S(TP->QN + " concentrates on a small stone and suddenly it "+
              "starts shining with a warm light.\n");
            TP->reduce_spell_points(sp_cost);
            user = TP;
            light();
            set_alarm(300.0 + itof(random(120)),0.0,"drain");
        }
        else
        {
            W("You don't have enough power to light the stone at the "+
              "moment.\n");
            S(TP->QN + " concentrates on a small stone but looks "+
              "disappointed.\n");
            return 1;
        }
    }
    // No mistake here. Don't want hints to people with attune < 20,
    // and don't want to mess up other light commands
}

int do_darken(string str)
{
    if(str == "stone" && TP->QS("attune") > 20 && ENV(TO) == TP)
    {
        if(!shining)
        {
            W("The stone is already dark!\n");
            return 1;
        }

        W("You close off the flow of power into the stone and break the "+
          "bond.\n");
        darken();
        W("The stone stops shining.\nYou feel a strange longing...\n");
        S("The stone in " + TP->QN + "s hand stops shining.\n");
        return 1;
    }
}

int drop(int silently)
{
    if(shining)
    {
        W("The stone darkens as your bond to it is broken.\n");
        darken();
    }
    return 0;
}

void light(void)
{
    shining = 1;
    set_light(5);
    set_short("A small, shining stone");
    set_long("A small stone shining with a warm light. You feel "+
             "comforted when you look at it.\n");
}

void darken(void)
{
    shining = 0;
    set_light(-5);
    set_short("A small, grey stone");
    set_long("A small, grey stone that is a bit out of the ordinary "+
             "only because it is very smooth.\n");
    user = 0;
}

void drain(void)
{
    int sp_drain = random(5) + 1;

    if(shining)
    {
        if(ENV(TO) != user)
        {
            tell_object(ENV(TO),"The stone stops shining.\n");
            darken();
            return;
        }

        if(sp_drain > user->query_spell_points())
        {
            tell_object(user,"The stone grows dark as you have no more "+
                        "power to channel into it.\n");
            darken();
            return;
        }

        tell_object(user,"You channel some power into the stone to keep "+
                    "it shining.\n");
        user->reduce_spell_points(sp_drain);
        set_alarm(300.0 + itof(random(120)),0.0,"drain");
    }
}
