//=====================================================================
// ferry.c - The ferry that takes players from Lars to the island and
//           back. Made it from scratch instead of using the inheritable
//           ferry... For no reason other than I felt like it! ;)
//=====================================================================
#pragma strict_types
#include "../def.h"
inherit STD_ROOM;

int location;    // 0 = sea, 1 = larstown, 2 = island

string *journey_messages = ({"A huge wave crashes over the side of the boat " +
                             "soaking everything in it!\n",
                             "The boat rolls violently on the stormy sea.\n",
                             "The mast of the boat creaks loudly in the "+
                             "stormy winds.\n",
                             "A huge wave lifts the boat high into the air "+
                             "and then drops it with an enormous *SPLASH* "+
                             "back into the water!\n",
                             "The boat rolls violently and suddenly and you "+
                             "barely manage to get hold of something to keep "+
                             "you from being thrown over board!\n"});

object larstown,island,boatman,boat_object,
       destination;

void create_object(void);
void init(void);
int  do_disembark(string str);
void set_at_sea(void);
void set_at_island(void);
void set_at_lars(void);
void depart(void);
void arrive(void);
void journey(void);

void create_object(void)
{
  set_short("A small sailing boat");
  set_new_light(5);
  set_skip_obvious(1);

  LARSTOWN->load_me();
  ISLAND->load_me();
  larstown = find_object(LARSTOWN);
  island = find_object(ISLAND);

  boatman = make(NMONSTER+"boatman");
  transfer(boatman,island);
  set_at_island();

  set_alarm(40.0,0.0,"depart");
}

void init(void)
{
  add_multi_action("do_disembark","disembark|leave|out");
  ::init();
}

int do_disembark(string str)
{
  switch(location)
  {
    case 0: W("No matter how bouncy the ride is, you don't really "+
              "think swimming the rest of the way would be more "+
              "enjoyable!\n");
            return 1;
      break;
    case 1: W("You climb out of the boat up onto the pier.\n");
            TP->move_player("leaves ashore",LARSTOWN,
                            "climbes onto the pier from the sailing boat",1);
            return 1;
      break;
    case 2: W("You climb out of the boat onto the sandy shore of the "+
              "island.\n");         
            TP->move_player("leaves ashore",ISLAND,"climbs out of the "+
                            "boat",1);
            return 1;
      break;
  }
}

void set_at_sea(void)
{
  location = 0;
  remove_all_items();
  boatman->set_at_sea();
  set_long("You are in a small sailing boat. It is not in a very good "+
           "condition, but it does not look as if it will break apart "+
           "any minute either. It is the vessel the boatman uses to "+
           "ship people to and from Newbie Island. The wind is filling "+
           "the white sail and the mast is creaking. Water splashes all "+
           "around you as the boat cuts through the grey waves of the "+
           "ocean.\n");

  add_item("boat|sailing boat|vessel","It is a worn, but still sturdy vessel "+
           "carrying people to and from Newbie Island");
  add_item("island|newbie island","You can just barely make it out there "+
           "far in the distance");
  add_item("sail","The sail is filled with the wind");
  add_item("mast","The thick wooden mast is creaking loudly, but it "+
           "still looks sturdy");
  add_item("water","The water splashes all over you as the boat cuts "+
           "through the waves. You figure the best thing you can do is "+
           "keep your head down. Looking at the raging sea just makes "+
           "you seasick!");
  add_item("wave|waves","The waves are high, and water splashes all over "+
           "you as the boat cuts through them");
  add_item("ocean|sea","The grey sea is raging around you. It seems as "+
           "if there might be a storm coming");

}

void set_at_island(void)
{
  location = 2;
  boat_object = make(NOBJECT+"boat_object",island);
  boat_object->set_location(location);
  boatman->set_at_island();
  remove_all_items();
  set_long("You are in a small sailing boat. The boat is pulled up on "+
           "the shore of a small island. The water here is calm, but as "+
           "you look to the east you see the raging grey ocean. It does "+
           "not look as if the journey to Larstown will be very pleasant. "+
           "You think it might be a good idea to <disembark>.\n");
  
  add_item("boat","A small, but sturdy sailing boat pulled ashore on "+
           "a small island. The leave the boat and get to the island, just "+
           "<disembark>.");
  add_item("shore|island","The boat is pulled up on the shore of the "+
           "small island. This must be Newbie Island!. To explore it, "+
           "just <disembark>. To go back to Larstown, just sit here and "+
           "wait for the boatman to take the boat to sea again");
  add_item("Newbie Island|newbie island","The lowest level island in "+
           "the Kingdoms");
  add_item("water","It is quite calm here by the shore");
  add_item("ocean","You don't look forward to crossing it to get back "+
           "to Larstown, that's for sure!");  

}

void set_at_lars(void)
{
  location = 1;
  boat_object = make(NOBJECT+"boat_object",larstown);
  boat_object->set_location(location);
  boatman->set_at_lars();
  remove_all_items();
  set_long("You are in a small sailing boat. The boat lies by the Larstown "+
           "pier. The sails are furled right now, but you suspect "+
           "they will be set and the boat will embark any moment now. "+
           "The grey ocean to the east is raging, and you hope the "+
           "journey to Newbie Island won't take too long.\n");

  add_item("boat","A small, but sturdy sailing boat lying by the "+
           "Larstown pier");  
  add_item("pier","The stone pier of Larstown");
  add_item("sail|sails","The sails are carfully furled in a way that "+
           "makes it seem as if they could quickly be set again");
  add_item("ocean|sea","The ocean is grey and there seems as if there might "+
           "be a storm coming");
 add_item("storm","It is not here quite yet, but you can sense it brewing "+
          "somewhere out at sea");
}

void depart(void)
{
  if(!boatman)
    {
      boatman = make(NMONSTER+"boatman");
    }

  switch(location)
    {
    case 1: tell_room(TO,"The boatman jumps on board and sets sail for "+
                      "Newbie Island.\n");
            tell_room(larstown,"The Boatman jumps into his sailing boat "+
                      "and sets sail for Newbie Island.\n");
      destination = island;
      break;
    case 2: tell_room(TO,"The boatman climbs on board and sets sail for "+
                      "Larstown.\n");
            tell_room(island,"The Boatman pushes the sailing boat out into "+
                      "the shallows, jumps on board, and sets sail for "+
                      "Larstown.\n");
      destination = larstown;
      break;
  }
  transfer(boatman,TO);
  boat_object->destroy();
  set_at_sea();
  set_alarm(5.0 + itof(random(5)),0.0,"journey");
  set_alarm(40.0,0.0,"arrive");
}

void arrive(void)
{
  if(destination == larstown)
  {
    tell_room(larstown,"A small sailing boat arrives at "+
              "the pier. The boatman climbs ashore after "+
              "furling the sails.\n");
    tell_room(TO,"The boat finally glides into the calmer waters inside "+
              "the Larstown harbour breakwater. The boatman steers it "+
              "to the pier, and jumps ashore to tie the lines to something "+
              "secure.\n");
    transfer(boatman,larstown);
    set_at_lars();
  }
  if(destination == island)
  {
    tell_room(island,"A small sailing boat arrives at the "+
              "shore. The boatman jumps ashore and pulls "+
              "the boat safely up onto the sand.\n");
    tell_room(TO,"The boat finally glides into calmer waters as it gets "+
              "close to the island. The Boatman jumps into the shallow water "+
              "and pulls the boat ashore.\n");
    transfer(boatman,island);
    set_at_island();
  }
  set_alarm(40.0,0.0,"depart");
}

void journey(void)
{
  if(!location)
  {
    tell_room(TO,journey_messages[random(sizeof(journey_messages))]);
    set_alarm(5.0 + itof(random(5)),0.0,"journey");
  }
}





