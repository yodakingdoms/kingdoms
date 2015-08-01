//============================================================
// The tablecloth on the table in this room is the Jolly Roger
// flag needed for the piracy quest
//============================================================
#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

int flag_taken;

void   create_object(void);
void   reset(int arg);
void   my_reset(void);
void   init(void);
int    do_open_close(string str);
int    do_get(string str);
int    do_play(string str);
string long_fun(void);
int query_flag_taken(void);
void   command_all(string do_this,object except_me);

void create_object(void)
{
    ::create_object();
    set_short("A small room under the ground (n/u)");
    set_long("#long_fun");

    add_item("room","A room that looks as if it has once served as a "+
             "room guarding the stairs, but lately has been used for "+
             "playing cards");
    add_item("stair|stairs|stairway","The stairs go up");
    add_item("small stone|round stone|stone|strange stone","A strange "+
             "looking round stone that glows with a soft yellow light");
    add_item("light|yellow light","The light in the room comes from the "+
             "stone in a niche in one of the walls");
    add_item("niche","A small niche in one of the walls. There is a small "+
             "stone in the niche, glowing with a soft, yellow light");
    add_item("cards","You only see one card");
    add_item("tablecloth|table cloth","Upon closer inspection, you "+
             "notice the tablecloth looks an awful lot like a flag..");
    add_item("flag|jolly roger","A black flag with two white bones "+
             "crossed under a grinning white skull. It's the infamous "+
             "Jolly Roger! The pirates have sunk low indeed if they use "+
             "this legendary flag to play cards on");
    add_item("vase","A small clay vase with some flowers in it");
    add_item("flower|flowers","Small white flowers that don't look "+
             "as if they have long to live");
    add_item("stools|wooden stools","Four wooden stools placed around "+
             "the table");
    add_item("stool|wooden stool","Somebody has left a playing card on "+
             "one of the stools");
    add_item("card|playing card","It is the King of Kordar. Looks like "+
             "someone might have been cheating..");
    add_item("king|king of kordar","It is King Amrak of Kordar, the "+
             "highest card in the suite of Kordar");
    add_item("kordar","Kordar is really too far away from here for you "+
             "to be able to see it properly");
    add_item("doorway","There seems to be a corridor beyond it");
    add_item("corridor","You would have to go there to get a proper look");
    add_item("door|oak door","It is the door that once was in the doorway "+
             "to the north. It has dropped from its hinges and now it "+
             "just lies on the floor. What a sad fate for a door");
    add_item("hinge|hinges","There's no trace of the hinges that once "+
             "held the door. You wonder what could have happened to them. "+
             "(Well... not really. You couldn't care less actually)");

    add_func_item("table|wooden table","#query_flag_taken",
                 ({"A sturdy wooden table with some black tablecloth on it. "+
                   "The tablecloth looks like a nice cloth to play cards " +
                   "on, so maybe that is what this table has been used for. "+
                   "There is a vase with some flowers in it on the table",
                   "A sturdy wooden table. There is a vase with some " +
                   "flowers in it on the table"}));

    add_exit(PCROOM + "forest_entrance_stairs","up");
    add_exit(PCROOM + "lev1_ew_corridor1", "north");

    flag_taken = 0;

    reset(0);
}

void reset(int arg)
{
    add_monster(PCMONSTER + "pirate",2);
}

/**
* We want quicker resets for stuff needed for quests, especially newbie
* quests. This function called with a 5 minute delay when the flag is taken
*/
void my_reset(void)
{
    if(flag_taken)
    {
        tell_room(TO,"Drunk pirate arrives from the north.\n"+
                  "Drunk pirate lays some black tablecloth over the "+
                  "wooden table.\n"+
                  "Drunk pirate leaves north.\n");
        add_item("tablecloth|table cloth","Upon closer inspection, you "+
                 "notice the tablecloth looks an awful lot like a flag..");
        add_item("flag|jolly roger","A black flag with two white bones "+
                 "crossed under a grinning white skull. It's the infamous "+
                 "Jolly Roger! The pirates have sunk low indeed if they "+
                 "use this legendary flag to play cards on");
        flag_taken = 0;
    }
}

void init(void)
{
    add_multi_action("do_get","get|take");
    add_multi_action("do_open_close","open|close");
    add_action("do_play","play");
}

int do_open_close(string str)
{
    if(str == "door" || str == "broken door" || str == "oak door")
    {
        W("You can't really " + query_verb() + " the door in the "+
          "shape it is in at the moment.\n");
        return 1;
    }
    return 0;
}

int do_get(string str)
{
    object flag;

    if(str == "flag" || str == "flag from table" ||
       str == "tablecloth" || str == "tablecloth from table" ||
       str == "table cloth" || str == "table cloth from table" ||
       str == "jolly roger" || str == "jolly roger from table")
    {
        if(!flag_taken)
        {
            W("You take hold of the tablecloth and try to pull it "+
              "from the table without disturbing the things that "+
              "are on it.\n");
            S(TP->QN + " takes hold of the tablecloth and tries to "+
              "pull it from the table without disturbing the things that "+
              "are on it.\n");
            if(random(TP->query_dex()) >= 5)
            {
                W("In a magnificent display of showmanship you swiftly "+
                  "pull the tablecloth from the table!\n");
                S("In a magnificent display of showmanship, " + TP->QN +
                  " swiftly pulls the tablecloth from the table!\n");
                TP->command("say And the flowers are still standing!");
                tell_room(TO,"... and they actually are! *applaud*\n");
                command_all("applaud",TP);
            }
            else
            {
                W("In a pathetic display of clumsiness, you pull the "+
                  "tablecloth from the table, only to send the flowers "+
                  "on it flying across the room!\n"+
                  "You quickly gather them up, put them back in the vase "+
                  "and put them back on the table.\n"+
                  "You hope nobody noticed.\n");
                S("In a pathetic display of clumsiness, " + TP->QN +
                  " pulls the tablecloth from the table, only to send the " +
                  "flowers on it flying across the room!\n" + TP->QN +
                  " gathers them up quickly and puts them back in the vase " +
                  "and places the vase back on the table.\n"+
                  "How amusing! *cackle*\n");
                command_all("cackle",TP);
                TP->command("shame");
            }

            flag = make(PCOBJECT + "jolly_roger");
            flag_taken = 1;
            remove_item("tablecloth|table cloth");
            remove_item("flag|jolly roger");

            if(transfer(flag,TP))
            {
                W("You are unfortunately carrying too much to pick it "+
                  "up, so you drop it on the floor.\n");
                S(TP->QN + " drops the tablecloth on the floor.\n");
            }

            // Quicker reset for quest object
            set_alarm(300.0,0.0,"my_reset");
            return 1;
        }
    }
    else
    if(str == "card" || str == "playing card")
    {
        W("And what game do you think you can play with just one card?\n"+
          "Unless you plan to use it to improve your odds when playing "+
          "with another full deck, of course.\n"+
          "We don't allow cheating at cards here, so you leave the card "+
          "on the stool.\n");
        S(TP->QN + " seems to ponder taking up a career as a cheating "+
          "card shark.\n");
        return 1;
    }
    else
    if(str == "stone" || str == "stone from niche")
    {
        W("You try to pry the stone loose, but it seems to be "+
        "stuck.\nYou can't take the stone.\n");
        S(TP->QN + " tries to pry the glowing stone loose from "+
        "its place in the niche, but does not succeed.\n");
        return 1;
    }
    // No point in messing up other get commands (from sacks, bags,
    // or whatever), and give underserved hints with a notify_fail
    // here...
    return 0;
}

int do_play(string str)
{
    if(str == "cards" || str == "poker")
    {
        W("It might be fun to play some poker, but you have more "+
          "important things to do.\n");
        S(TP->QN + " looks interested in playing a game of poker.\n");
        return 1;
    }
    // No point in messing up bard songs (for example) with
    // a notify_fail here...
    return 0;
}

string long_fun(void)
{
    if(!flag_taken)
    {
        return "A small room under the ground. The room is lit by a "+
            "small stone that glows with a soft yellow light from "+
            "its place in a niche in one of the stone walls. There "+
            "is a wooden table with black tablecloth and a vase with "+
            "flowers on it in the middle of the room, and a few stools "+
            "are placed around it. There is a playing card on one "+
            "of the stools. A stone stairway goes up from here, and "+
            "there is a doorway to the north. The oak door that once "+
            "was in that doorway lies on the floor next to it.\n";
    }
    else
    {
        return "A small room under the ground. The room is lit by a "+
            "small stone that glows with a soft yellow light from "+
            "its place in a niche in one of the stone walls. There "+
            "is a wooden table with a vase with flowers on it in the "+
            "middle of the room, and a few stools are placed around it. "+
            "There is a playing card on one of the stools. A stone "+
            "stairway goes up from here, and there is a doorway to the "+
            "north. The oak door that once was in that doorway lies on "+
            "the floor next to it.\n";
    }
}

int query_flag_taken()
{
    return flag_taken;
}

/**
* Make all other players cackle if this_player() fails or applaud
* if this_player() succeeds in getting the flag from the table
*/
void command_all(string do_this,object except_me)
{
    int i;
    object *players = query_players_here();

    players -= ({ except_me });

    for(i = 0; i < sizeof(players); ++i)
    {
        players[i]->command(do_this);
    }
}
