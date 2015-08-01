#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);

void create_object(void)
{
  set_short("Forest edge (w)");
  set_long("The path ends here at the edge of the forest. In front of you "+
           "to the east lie some green, rolling hills. Some are crowned "+
           "by copses of trees, others by what looks like remains of stone "+
           "defenses. Trails lead off in many directions from here. Beyond "+
           "the hills to the north and east, you see two almost identical "+
           "mountain ranges. To the south, a forest begins and to the "+
           "northeast you see another, dark forest, beyond which a lone "+
           "mountain peak rises high into the sky. There is a sign "+
           "nailed to one of the trees here.\n");
  set_new_light(5);
  set_dragon_visibility(5);
  set_room_hint("The rest of the island is not open yet, but many more "+
                "adventures await here. Beware the mountain to the northeast "+
                "though, for that is where the ancient dragon of the island "+
                "resides *shiver*. The ruins were once proud Kordic forts, "+
                "from the time when Kordar colonized the island. When the "+
                "Kordic troops awakened the dragon, however, those who did "+
                "not have time to flee were slaughtered. The road to the "+
                "shore to the west was built by them too, but now Kordar has "+
                "all but forgotten this isle and lays no claim to it anymore."+
                " The only ruler is the dragon, and the dwarves and goblins "+
                "in those mountains to the north and the east. The forest to "+
                "the south is inhabited by elves, but it has been a long time"+
                " since anyone has heard from then now.\n");

  add_item("path","The path you have been following through the forest. "+
           "It is well travelled, but some paving stones still remain, "+
           "indicating that this was once a road");
  add_item("stone|stones|paving stone|paving stones","There are still some "+
           "paving stones left here, remains of a road");
  add_item("road","It does seem the path was once a road. By the look of it "+
           "now, though, it seems that was quite a while ago");
  add_item("edge","The forest here on the west side of the island ends here");
  add_item("forest","You've seen most of this forest already. There is "+
           "another one to the south, and one that looks really dark to the "+
           "northeast, beyond the hills");
  add_item("south forest|forest to the south","Well, it looks sort of like "+
           "most forests do at a distance");
  add_item("dark forest","The forest to the northeast looks dark and "+
           "uninviting even at this distance. You can't tell if it is the "+
           "forest itself that does this or if it is the fact that it lies "+
           "in the shadow of the lone mountain to the northeast");
  add_item("hill|hills","The green, rolling hills spread out in front of you "+
           "in almost all directions. Copses of trees grow here and there and"+
           " on some of the hills you notice ruins of old stone forts and "+
           "walls. You wonder what has happened here, how old the ruins are "+
           "and who built them once upon a time");
  add_item("copse|copses|tree|trees","Here and there on some of the hills "+
           "you see trees");
  add_item("remains|defense|defenses","Old ruins of forts and walls");
  add_item("ruin|ruins|wall|walls|fort|forts","Old military defenses, that "+
           "surely looked proud cresting the hills once upon a time. Now, "+
           "however, only the ruins remain");
  add_item("trail|trails","They lead off in many directions from here, but "+
           "you can't follow any of them quite yet");
  add_item("mountain ranges|mountain range|mountains|ranges|range","There is "+
           "one to the north and one to the east. Their contours look "+
           "strangely similar, almost identical. They seem to come together "+
           "and join where the lone, high mountain peak to the northeast is");
  add_item("mountain peak|mountain|peak","The lone mountain rises towards "+
           "the sky like a black finger pointing at the sky. It is quite far "+
           "away, but you still feel uncomfortable looking at it");
  add_item("island","Looking at the scene in front of you, you begin to " +
           "think it's quite big even if it didn't look like that at first");
  add_item("scene","Try typing: look");
  add_item("sign","Try reading it");
  add_item("@sign","#sign");

  add_exit(NROOM+"path2","west");
  add_exit("/areas/NewbieIsle/Hazeldown/o/Rooms/mainr_w5","east");
}

void init(void)
{
  "/sys/admin/room/admin_room"->visit(986);
}

int sign(void)
{
 write("\n>>>===========> Hazeldown\n\n");
 return 1;
}

