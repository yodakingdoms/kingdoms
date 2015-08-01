// ==================================================================
// Random cannon fodder goblin.
// ==================================================================
#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

string *short_desc = ({ "A small goblin","A tiny goblin","A puny goblin",
                        "An ugly goblin" });
string *long_desc = ({ "A small goblin who is bruised and battered. You " +
                       "guess that he's been picked on quite a lot due " +
                       "to his size.\n",
                       "The smallest goblin you've ever seen. He almost " +
                       "doesn't fill up his armour enough to wear it.\n",
                       "A puny little goblin who looks like the weakest " +
                       "goblin you've ever seen. You're amazed he even " +
                       "manages to carry his weapon.\n",
                       "This is the ugliest goblin you've ever seen, and " +
                       "considering how pretty goblins normally are, that's " +
                       "saying something!\n"
                     });
string *name = ({ "small goblin","tiny goblin","puny goblin",
                   "ugly goblin" });

void create_object(void)
{
    int i = random(4);
    object weapon;

    set_short(short_desc[i]);
    set_long(long_desc[i]);
    set_name(name[i]);
    add_id("goblin");

    set_level(1);
    set_race("goblin");
    set_sub_race(MANSION_GOBLIN_SUBRACE_FLAG);
    set_al(-100);
    // They are supposed to be easy to kill by newbies ...
    set_hp(15);
    add_money(20 + random(20));
    set_gender(1);

    weapon = make(WEAPON + "goblin_weapon");
    init_command("wield " + weapon->QN);
    make(ARMOUR + "leather_armour");
    make(ARMOUR + "goblin_armour");
    init_command("wear all");

    load_chat(5,({
        C(name[i]) + " peers suspiciously at you.\n",
        C(name[i]) + " snarls at you!!\n",
        C(name[i]) + " pushes you back a few steps.\n",
        C(name[i]) + " snarls: Ye had better not be here to find our " +
        "treasure.\n",
        C(name[i]) + " jabs at you with his fist.\n",
        C(name[i]) + " snarls: I'm sick of this here house, I want to " +
        "go home.\n",
        C(name[i]) + " snarls: I wonder if Skrowks even knows what that " +
        "treasure he has us looking for looks like.\n",
        C(name[i]) + " moans: 45 days in this here place, and no treasure.\n",
        C(name[i]) + " states: Forests are dire places, they should all " +
        "be fed into our forges.\n",
    }));

    load_a_chat(30,({
        C(name[i]) + " shouts: If you give up, I won't hurt you\n",
        C(name[i]) + " shouts: I have a goblin family of four back home, " +
        "you know!\n",
        C(name[i]) + " shouts: Take the treasure, just leave me alone!\n",
        C(name[i]) + " tries to poke you in the eye!\n",
        C(name[i]) + " tries to knee you, without much effect.\n",
        C(name[i]) + " snarls.\n",
    }));
}

// Don't want goblins ganging up on poor little players
int query_no_combat_help(void)
{
    return 1;
}
