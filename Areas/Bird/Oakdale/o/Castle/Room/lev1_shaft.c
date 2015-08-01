#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

object falling_player;

void create_object(void);
void reset(int arg);
void init(void);
void falling(int step);

void create_object(void)
{
    set_short("A dark, steep shaft");
    set_long("You are falling down a shaft that is steeper than it looked " +
             "at first!! You realize this must be a garbage shute!\n");
    set_new_light(0);
    set_skip_obvious(1);
    add_property("indoors");

    add_item("shute|shaft","A shaft where the cooks dispose of their " +
             "garbage, and now it's disposing of you!");

    reset(0);
}

void reset(int arg)
{
    // This will probably not be needed, but just in case so it doesn't
    // lock up forever if something gets messed up
    falling_player = 0;
}

void init(void)
{
    if(falling_player)
    {
        // This shouldn't happen either but let's check just in case so noone
        // gets trapped here
        W("You hear screams from down below and feel it's best to climb " +
          "out back to the kitchen.\n");
        TP->move_player("climbs back up from the shaft",
                        ROOM + "lev1_kitchen","",1);
    }
    else
    {
        falling_player = TP;
        set_alarm(1.0,0.0,"falling",0);
    }
}

void falling(int step)
{
    if(present(falling_player,TO))
    {
        switch(step)
        {
            case 0: tell_room(TO,"Gasp! It's steep and slippery! You lose " +
                              "your grip and you're falling!!!!\n\n");
                    tell_room(ROOM + "lev1_kitchen","You hear screaming " +
                              "from the hole in the floor.\n\n");
                    set_alarm(3.0,0.0,"falling",1);
              break;
            case 1: tell_room(TO,"You're falling down through the shaft!!" +
                              "\n\n");
                    tell_room(ROOM + "lev1_kitchen","You hear someone " +
                              "screaming from the hole in the floor.\n\n");
                    set_alarm(3.0,0.0,"falling",2);
              break;
            case 2: tell_room(TO,"You're falling down through the shaft! " +
                              "You see light at the end of it, an opening!" +
                              "\n\n");
                    tell_room(ROOM + "lev1_kitchen","Someone is " +
                              "screaming. It sounds like somebody is " +
                              "falling down through the hole.\n\n");
                    set_alarm(3.0,0.0,"falling",3);
              break;
            case 3: tell_room(TO,"Oh, no!! It looks like you'll be thrown " +
                              "out down the side of the cliff! You'll die " +
                              "for sure!!\n\n");
                    tell_room(ROOM + "lev1_kitchen","Someone is falling " +
                              "down the shaft under the hole, screaming " +
                              "loudly.\n\n");
                    set_alarm(2.0,0.0,"falling",4);
              break;
            case 4: tell_room(TO,"The shaft ends in an opening in the side " +
                              "of the cliff below the castle. You are " +
                              "thrown out into empty space, and for a " +
                              "moment you hang suspended in mid air, " +
                              "several hundred feet above the river below. " +
                              "You'll plunge to your death here!!!!\n\n");
                    tell_room(ROOM + "lev1_kitchen","The screams coming " +
                              "from the hole reach an almost deafening " +
                              "crescendo.\n\n");
                    set_alarm(4.0,0.0,"falling",5);
              break;
            default: tell_room(TO,"Just as you start to fall, you reach out " +
                               "and manage to grab hold of a rock!! You " +
                               "manage to hang on and pull yourself up on " +
                               "a ledge by the opening of the shaft. " +
                               "PHEW!!\n");
                     tell_room(ROOM + "lev1_kitchen","The screaming heard " +
                               "from the hole stops abruptly.\n");
                     falling_player->move_player("falls out of the hole at " +
                                                 "the end of the shaft",
                                                 ROOM + "lev1_ledge",
                                                 "comes flying out through " +
                                                 "the opening and manages " +
                                                 "to grab hold of a rock",1);
                     falling_player = 0;
              break;
        }
    }
    else
    {
        falling_player = 0;
    }
}
