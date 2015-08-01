//=====================================================================
// animal - Generic monster for cloning of different kinds of animal
//          type monsters, like foxes, birds, squirrels etc. These
//          monsters go away when it gets dark, and return when it
//          gets light and the trolls go back into their cave
//=====================================================================
// Added the desc of the badger a bit due to bug report. Badgers are,
// of course, nocturnal.
// Yoda 2003-09-21
//=====================================================================
#pragma strict_types
#include "../def.h"
inherit STD_MOV_MONSTER;
//inherit STD_EVENT;

void create_object(void);
void check_time(void);
void go_to_sleep(void);
void wake_up(void);

string *names = ({"fox","bird","bird","badger","squirrel","rabbit"});
string *short_descs = ({"A fox","A red bird","A blue bird","A badger",
                        "A squirrel","A rabbit"});
string *long_descs = ({"A little red fox that peers suspiciously at you.\n",
                       "A pretty little red bird.\n",
                       "A strange looking blue bird.\n",
                       "A slow moving badger that looks a bit tired. " +
                       "Badgers are nocturnal so it should probably " +
                       "be asleep now.\n",
                       "A squirrel merrily looking for food on the ground.\n",
                       "A rabbit that looks frightened when it sees you.\n"});
string *races = ({"newbie island fox","newbie island bird",
                  "newbie island bird","newbie island badger",
                  "newbie island squirrel","newbie island rabbit"});

string *animal_chats = ({({"The fox peers suspiciously at you.\n",
                           "The fox waves its tail in a curious manner.\n"}),
                         ({"The bird twitters.\n",
                           "The bird preens its feathers.\n"}),
                         ({"The bird caws in a strange way.\n",
                           "The bird peers strangely at you.\n"}),
                         ({"The badger plods around clumsily.\n",
                           "The badger looks at you and yawns.\n"}),
                         ({"The squirrel chews on something it found on the "+
                           "ground.\n",
                           "The squirrel's nose twitches happily.\n"}),
                         ({"The rabbit scurries around on the ground.\n",
                           "The rabbit's nose twitches nervously.\n"})});

string *animal_a_chats = ({({"The fox bares its teeth at you.\n",
                             "The fox snarls viciously at you.\n"}),
                           ({"The bird tries to fly away.\n",
                             "The bird twiddles desperately.\n"}),
                           ({"The bird caws loudly at you.\n",
                             "The bird hacks at you with its beak.\n"}),
                           ({"The badger tries to run away but it is slow.\n",
                             "The badger jabs at you with its paw.\n"}),
                           ({"The squirrel throws a nut at you.\n",
                             "The squirrel tries to bite you.\n"}),
                           ({"The rabbit yelps desperately.\n",
                             "The rabbit sobs heartbreakingly.\n"})});

string *dusk_message = ({"The fox sniffs the air for a moment and then "+
                         "runs off as the night approaches.\n",
                         "The bird flies away as dusk falls.\n",
                         "The bird slowly glides away between the trees "+
                         "as night approaches.\n",
                         "The badger slowly plods away as dusk falls.\n",
                         "The squirrel swiftly climbs up a tree as "+
                         "night approaches.\n",
                         "The rabbit scurries away into some bushes as "+
                         "darkness falls.\n"});

string *dawn_message = ({"A fox appears from behind some bushes as dawn "+
                         "arrives.\n",
                         "A bird comes flying through the forest to greet "+
                         "the morning.\n",
                         "A bird lands suddenly on a stone near you.\n",
                         "A badger appears from behind some trees, yawning "+
                         "in the morning light.\n",
                         "A squirrel comes climbing down a tree, its nose "+
                         "twiching happily in the morning light.\n",
                         "A rabbit carefully sneaks out from behind a bush "+
                         "as dawn arrives.\n"});

int id;
object my_last_room;  // The animal remembers the room it was in when
                      //dusk fell and returns to this room at dawn

void create_object(void)
{
  id = random(6);
  set_name(names[id]);
  set_short(short_descs[id]);
  set_long(long_descs[id]);
  set_race(races[id]);
  set_level(2);
  set_hp(40+random(50));
  set_new_ac(10+random(10));
  set_wc(7+random(3));
  set_time_slice(5);
  set_walking();

  load_chat(20,animal_chats[id]);
  load_a_chat(30,animal_a_chats[id]);

  set_alarm(2.0,300.0,"check_time");
}

void check_time(void)
{
  if(query_hour() > 20 || query_hour() < 5)
  {
    go_to_sleep();
  }
  else
  {
    wake_up();
  }
}

void go_to_sleep(void)
{
  if(ENV(TO) != find_object(DEN_ROOM))
  {
    tell_room(ENV(TO),dusk_message[id]);
    my_last_room = ENV(TO);
    move_object(TO,DEN_ROOM);
  }
}

void wake_up(void)
{
  if(ENV(TO) == find_object(DEN_ROOM))
  {
    move_object(TO,my_last_room);
    tell_room(ENV(TO),dawn_message[id]);
    my_last_room = 0;
  }
}

