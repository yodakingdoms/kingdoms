#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;
inherit STD_LORE;

void create_object(void);
void init(void);
mixed weapon_hit(void);
int wielding_func(object ob);
int do_kill(string str);
int do_runes(string str);

void create_object(void)
{
    set_name("staff");
    add_id("staff of dragon bone");
    set_short("a staff of dragon bone");
    set_long("This staff is made of the blackened bone of a dragon. It is " +
             "extremely hard and slender, and a black jewel is fitted at " +
             "the tip of the staff. Strange, evil runes run up and down " +
             "the length of the staff. This staff radiates a powerful " +
             "evil.\n");
    set_value(175);
    set_weight(3);
    set_type("staff");
    set_class(30);
    set_material("bone");
    set_hit_func(TO);
    set_wield_func(TO);

    set_property("magic");

    add_lore("A staff made of dragon bone?? A weapon of this kind must " +
             "be very rare indeed...\n",1,30);
    add_lore("You have heard tales of a staff made of the bone of a dragon, " +
             "but never did you believe you would ever set eyes on it. To " +
             "wield a weapon of this kind, one would have to be dark souled " +
             "indeed.\n",31,50);
    add_lore("This must be the legendary staff made from the bone of the " +
             "great wyrmkin wizard Aldarak, who was slain in his dragon " +
             "form by Diedor Wyrmslayer, Knight of Kordar. The legend says " +
             "Aldarak's spirit is still present in the staff, and that only " +
             "the most black-souled can wield it.\n",51);
    set_property("exceptional");
}

void init(void)
{
    add_action("do_kill","kill");
    add_multi_action("do_runes","l|look|examine|read");
    ::init();
}

// This just provides special effects
mixed weapon_hit(void)
{
    switch(random(5))
    {
        case 0: W("You flap your huge wings in ecstasy as the power of the " +
                  "dragon flows through your soul!!\n");
                S("The huge shadow flaps its wings in ecstasy as " + TP->QN +
                  " crushes " + TP->query_attack()->QN + " with the black " +
                  "staff!!\n");
          break;
        case 1: W("The dragon spirit whispers powerful spells in your " +
                  "head...\n");
                S("Smoke spews out of " + TP->QN + "'s nostril as the huge " +
                  "shadow looms over you!!\n");
          break;
    }
    return 0;
}

int wielding_func(object ob)
{
    if(TP->query_alignment() > (-299))
    {
        W("You feel the spirit of the dragon trying to possess your " +
          "body, but dissatisfied with the purity of your soul it leaves, " +
          "howling with rage. The staff suddenly burns you, and you " +
          "can't hold on to it.\n");
        S("As " + TP->QN + " tries to wield the black staff, a dark spirit " +
          "appears and begins to circle " + TP->QO + ". Suddenly it " +
          "leaves, howling with rage.\n");
        TP->command("drop staff");
        return 0;
    }
    else
    {
        W("The spirit of the dragon enters your body howling with rage. " +
          "you can hear it whisper evil spells and feel its power flow " +
          "through your soul.\n");
        S("As " + TP->QN + " wields the staff, a dark spirit appears and " +
          "begins to circle " + TP->QO + " slowly. Howling with rage it " +
          "enters " + TP->QN + "'s body, and for a moment you thought you " +
          "saw a black dragon in "+TP->QN+"'s place.\n");
        set_wielding_extra(TP->QN +"'s shadow is that of a dragon.\n");
        return 1;
    }
}

int do_kill(string str)
{
    if(str && wielded_by && present(str,ENV(TP)))
    {
        W("The spirit of the black dragon seizes control! Spreading huge, " +
          "black wings and howling with rage you charge your enemy.\n");
        S("Suddenly " + TP->QN + "'s shadow grows into that of a huge " +
          "dragon!! The shadow spreads its wings as " + TP->QN +
          " approaches " + TP->QPO + " enemy!!\n");
    }
    return 0;
}

int do_runes(string str)
{
    if(str == "runes" || str == "at runes")
    {
        if(TP->query_skill("runes") + TP->query_int() > 60)
        {
            if(TP->query_skill("magic") + TP->query_int() > 60)
            {
                W("The runes of the staff are runes of powerful magic of " +
                  "the kind used to bind spirits to artifacts. You wonder " +
                  "what powerful spirit would need so many seals and " +
                  "pentagrams to be contained.\n");
                S(TP->QN + " studies the runes on the black staff and seems " +
                  "awed.\n");
                return 1;
            }
            W("The runes on the staff are runes of powerful magic.\n");
            S(TP->QN + " studies the runes on the black staff.\n");
            return 1;
        }
        W("You can't make anything out of these runes.\n");
        S(TP->QN + " seems baffled by the runes on the staff.\n");
        return 1;
    }
}
