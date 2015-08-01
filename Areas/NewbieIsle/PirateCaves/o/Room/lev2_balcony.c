#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

int railing_broken;

void create_object(void);
void reset(int arg);
string long_fun(void);
void init(void);
int do_lean(string str);
int query_ship_at_sea(void);
int query_railing_broken(void);

void create_object(void)
{
    ::create_object();
    set_short("A balcony (e)");
    set_long("#long_fun");

    add_item("sight|magnificent sight","It is magnificent");
    add_func_item("balcony|natural balcony","#query_railing_broken",({
                 "It's basically an outcropping of rock with a wooden " +
                 "railing built around it",
                 "It's basically an outcropping of rock with a wooden " +
                 "railing built around it. The railing is broken"
                }));
    add_func_item("railing|wooden railing","#query_railing_broken",({
                 "A wooden railing built around the balcony. It doesn't " +
                 "look very sturdy and it looks like it's a long way down, " +
                 "so don't lean against it if you value your life",
                 "The railing is broken, maybe someone leaned against it. " +
                 "It looks like it's a long way down so someone probably " +
                 "had a pretty scary ride down there"
                }));
    add_item("outcropping","It forms a sort of natural balcony in the wall");
    add_item("cave|underground cave|huge cave|huge underground cave",
             "The lagoon in the cave forms a natural hidden harbour");
    add_item("ceiling|domed ceiling","It curves up above you. The shining " +
             "stones in it make it look like a starlit night sky");
    add_item("lagoon|underground lagoon","It forms a natural harbour " +
             "hidden from the outside");
    add_item("sea","You can see it as you look out the crack. The sea is " +
             "raging but the water below you in the cave is calm");
    add_item("water","The water in the lagoon is calm, there must be a " +
             "breakwater somewhere near. It sparkles in the light from " +
             "stones in the ceiling above");
    add_item("breakwater","You can't see one, but there probably is one " +
             "somewhere near");
    add_item("west wall","There's a huge crack in it");
    add_item("crack","It's high and wide enough to sail a ship through " +
             "but narrow enough to be difficult to see from the outside");
    add_item("ledge|wide ledge","It goes around the lagoon, forming a " +
             "natural dock");
    add_item("dock|natural dock","There's not much happening down there");
    add_item("box|boxes|sack|sacks|supplies","They're stacked against the " +
             "walls. You have no idea what might be in them");
    add_func_item("ship|big ship","#query_ship_at_sea", ({
                 "A ship with two masts. The sails are furled and there is " +
                 "nobody on deck. It looks as if it was quite a while " +
                 "the ship was last out at sea" }));
    add_func_item("mast|masts","#query_ship_at_sea", ({
                  "The ship has two masts. There's a crows nest in one of " +
                  "them" }));
    add_func_item("nest|crows nest","#query_ship_at_sea", ({
                  "The place where the lookout sits when the ship is at " +
                  "sea. It is empty now" }));
    add_func_item("sail|sails","#query_ship_at_sea", ({
                  "The sails are furled now and don't look as if they've " +
                  "been used in quite a long time" }));
    add_func_item("deck","#query_ship_at_sea", ({
                  "The deck is deserted at the moment" }));
    add_func_item("ring|rings|iron ring|iron rings","#query_ship_at_sea", ({
                  "Iron rings. The ship is moored to the with thick lines",
                  "Iron rings that you can probably use when mooring a " +
                  "ship here"
                  }));
    add_func_item("line|lines|thick line|thick lines","#query_ship_at_sea",({
                  "Thick lines used to moor the ship in the harbour" }));
    add_item("stone|stones|small stone|small stones|shining stone|" +
             "shining stones|small shining stone|small shining stones",
             "There are hundreds of them in the ceiling of the cave");
    add_item("light","Light from the stones");
    add_item("harbour|natural harbour|proper harbour|hidden harbour",
             "A hidden harbour formed by mother nature");

    add_exit(PCROOM + "lev2_corridor2","east");

    reset(0);
}

void reset(int arg)
{
    railing_broken = 0;
}

string long_fun(void)
{
    string desc = "A magnificent sight meets you. You are standing on a " +
                  "balcony with a ";
    if(railing_broken)
    {
        desc += "broken ";
    }
    desc += "wooden railing high up in a wall of a huge underground cave. " +
            "A domed ceiling curves above you and below you is an " +
            "underground lagoon, opening up into the sea through a huge " +
            "crack in the west wall. A wide ledge goes around the cave " +
            "and boxes, sacks and other supplies are stacked against " +
            "the walls. ";
    if(!query_ship_at_sea())
    {
        desc += "Moored in the hidden harbour lies a big ship! It is tied " +
                "to rings in the wall by thick lines and the sails are " +
                "furled. The two masts rise about as high up as the " +
                "balcony you're standing on is but the cave is so high and " +
                "crack to the west is so big it easily fits in here. ";
    }
    desc += "The cave is lit by many small shining stones in the walls and " +
            "ceiling, and the water below sparkles magically in the light. " +
            "It looks like a proper harbour but there doesn't seem to be a " +
            "lot of activity down there.\n";
    return desc;
}

void init(void)
{
    add_action("do_lean","lean");
    "/sys/admin/room/admin_room"->visit(1101);
}

int do_lean(string str)
{
    if(str == "against railing" || str == "against wooden railing")
    {
        if(!railing_broken)
        {
            W("You lean against the railing. There's a loud *CRACK* as " +
              "the railing breaks!\nYou fall from the balcony head first!\n" +
              "You land in the water below with a huge *SPLASH*!\n");
            S(TP->QN + " leans against the railing. There's a loud *CRACK* " +
              "as the railing breaks!\n" + TP->QN + " falls from the " +
              "balcony, screaming: AAAAaaaaaaaahhhh...\nYou hear a loud " +
              "*SPLASH* from below!\n");
            railing_broken = 1;
            tell_room(PCROOM + "lev3_harbour","You hear a loud scream as " +
                      TP->QN + " comes flying from above and lands in the " +
                      "water with a huge *SPLASH*!\n");
            TP->move_player("falls down from the balcony!",
                            PCROOM + "lev3_harbour_water",
                            "falls into the water from above and lands " +
                            "with a *SPLASH*!",1);
            return 1;
        }
        else
        {
            W("There's not really enough of a railing left to lean " +
              "against.\n");
            S(TP->QN + " looks at the broken railing.\n");
            return 1;
        }
    }
    return notify_fail("Lean against what?\n");
}

int query_ship_at_sea(void)
{
    return SHIP_OBJ->query_is_at_sea();
}

int query_railing_broken(void)
{
    return railing_broken;
}
