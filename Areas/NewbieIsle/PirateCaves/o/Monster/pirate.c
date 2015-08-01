// ==================================================================
// Random cannon fodder pirate.
// ==================================================================
#pragma strict_types
#include "../def.h"
inherit STD_MOV_INT_MONSTER;

string *short_desc = ({ "A drunk pirate","A drunk pirate","A drunk pirate",
                        "An old pirate","A dirty pirate","A sick pirate" });
string *long_desc = ({ "A pirate drunk out of his skull. He looks as if he " +
                       "is about to pass out any moment.\n",
                       "A pirate who has had far too much to drink. He " +
                       "looks as if he is going to throw up any second, " +
                       "you should try to get out of the way.\n",
                       "A drunk pirate with a strange glazed look in his " +
                       "eyes. He's looking right at you but still seems to " +
                       "see something far away.\n",
                       "An old pirate with a huge, red, warty nose. He " +
                       "looks as if he's seen the bottom of many a tankard " +
                       "of ale in his days.\n",
                       "A dirty drunk pirate that looks as if he's never " +
                       "taken a bath in his life.\n",
                       "A drunk pirate that's green in the face and who has " +
                       "strange green things growing out of his ears an " +
                       "his nostrils.\n"});
string *alias = ({ "drunk pirate","drunk pirate","drunk pirate","old pirate",
                   "dirty pirate","sick pirate" });

void create_object(void)
{
    object weapon,armour;
    int i = random(6);

    set_short(short_desc[i]);
    set_long(long_desc[i]);
    set_name("pirate");
    add_id(alias[i]);

    set_time_slice(20 + random(10));
    set_walking();
    set_directions(({"north","south","east","west"}));

    set_level(2);
    set_race("newbie island pirate");
    set_hp(80 + random(25));
    set_al(-50);
    add_money(100 + random(20));
    set_gender(1);
    set_skill("combat",20 + random(10));

    weapon = make(PCWEAPON + "pirate_weapon");
    armour = make(PCARMOUR + "pirate_armour");
    init_command("wield " + weapon->QN);
    init_command("wear " + armour->QN);

    if(!random(4))
    {
        make(PCOBJECT + "pirate_treasure");
    }

    load_chat(10,({
        "Pirate mumbles: I don't feel very well, arr.\n",
        "Pirate throws up on your feet!!\n",
        "Pirate pushes you back a few steps.\n",
        "Pirate sings: Hey ho and a bottle of rum!\n",
        "Pirate jabs at you with his fist.\n",
        "Pirate wobbles around in a drunken state.\n",
        "Pirate gives you a huge drunken hug!\n",
        "Pirate moans: I'm sooo drunk, arr.\n",
        "Pirate states: Arr, ale is a harsh mistress. Harsh, but fair.\n",
    }));

    load_a_chat(30,({
        "Pirate shouts: You'll regret this in the morning, arr!!!\n",
        "Pirate shouts: Copyright infringement is not theft!\n",
        "Pirate shouts: I'll toast in ale by your grave, arr!\n",
        "Pirate screams: Arr, why is the room spinning?!\n",
        "Pirate screams: Shiver me timbers, arr!\n",
        "Pirate snarls.\n",
    }));
}
