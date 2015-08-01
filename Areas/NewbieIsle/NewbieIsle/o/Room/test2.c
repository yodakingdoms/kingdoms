#pragma strict_types

#include <levels.h>
#include <sysdefs.h>
#include <macros.h>

inherit "/std/room/parse_room";
int    do_sit(string str);


void create_object(void);
void init(void);


void create_object()
{
  set_new_light(10);

 set_short("Cave kitchen");

  set_long("This is a cramped cave room, against one of the walls stands one single chair/n"+
           "next to it stands a table, the floor is filled with old food and bones."+     
           "All you can hear in this silent place is the sound of flies buzzing around the food"+
           "The air is filled with a stench of rotten food.\n");



  add_exit("/wiz/w/willer/test1","south");
  
  add_item("room","This is a room.\n");
  add_item("table","The table is small and judging from all the marks on it makes you realize its age");
  add_item("chair","The chair is of rotten quality and will probably break if you try sitting on it");
  add_item("darkness","Darkness pressing in from all sides, barely no light at all");
  add_item("$|$sound","You can hear the flies buzzing around the old food");
  add_item("wall|walls","Rough wet walls made of stone");
  add_item("%|%food|%air","It is an aweful stench of rotten food here");
  add_item("ceiling","Rough stone ceiling");
  add_item("floor|food|bones","Alot of rotten food lies on the floor together with old bones");

  add_property("indoors");
}

void init(void)
{
add_action("do_sit","sit");
::init()
}


int do_sit(string str)
{
    if(str == "chair")
{
    W(TP->QN + " sits down on a chair.");
    }
 return 1;
}
