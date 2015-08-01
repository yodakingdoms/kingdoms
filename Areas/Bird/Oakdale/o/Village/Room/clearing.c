#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

object *listeners = ({});

void create_object(void);
void init(void);
int do_listen(string str);
void listen_song(object player,int step);

void create_object(void)
{
    set_short("A small clearing where the road ends");
    set_long("A clearing in the forest south of the village. The road ends " +
             "here. Short grass grows in the clearing and the forest " +
             "around it seems impenetrable. To the west the village church " +
             "stands. A beautiful white building with decorated windows. " +
             "The doors are open and the decorated archway looks inviting. " +
             "The slender white tower rises high in the air and you see " +
             "the bird is still circling it, twiddling a sad melody. To the " +
             "northeast the castle looms over the treetops.\n");
    set_new_light(5);

    add_item("clearing","The clearing is almost completely circular and " +
             "the ground is covered by short grass");
    add_item("sign","Try reading it");
    add_item("grass","The grass is short and neatly trimmed");
    add_item("forest","A forest of oaks. The forest is dense, and should " +
             "you enter, you'd surely get lost");
    add_item("church","A beautiful building. It is built out of white stone " +
             "and it shines in the sun. The windows and the doors are " +
             "beautifully decorated and the slender tower rises high up in " +
             "the air");
    add_item("window|windows","The windows are beautifully decorated with " +
             "pictures of saints");
    add_item("doors|archway","Decorated with beautiful symbols and patterns");
    add_item("symbols|patterns","They seem to be religious in nature");
    add_item("symbol|pattern","You can't tell what this one is supposed " +
             "to stand for, but it looks religious in nature");
    add_item("tower","It's the tower where the church bell hangs. A small " +
             "bird is circling the tower");
    add_item("castle","From here the castle doesn't look quite so " +
             "threathening. You still don't see any sign of life up there, " +
             "though");
    add_item("bird","A little swallow. The swallow is twiddling a sad " +
             "melody in an almost human voice");

    add_exit(ROOM + "road17","north");
    add_exit(ROOM + "church","west");
}

void init(void)
{
    add_action("do_listen","listen");
    SYS_ADMIN->visit(279);
}

int do_listen(string str)
{
    S(TP->QN + " listens carefully.\n");
    if(str == "song")
    {
        W("The swallow is twiddling a sad tune. It's voice sounds almost " +
          "human and you almost think you can hear words in the song.\n");
        return 1;
    }
    if(str == "words")
    {
        if(!is_in(TP,listeners))
        {
            W("Suddenly as you concentrate you hear what the bird is " +
              "singing!\n");
            S(TP->QN + " listens carefully to the little bird.\n");
            set_alarmv(3.0,0.0,"listen_song",({ TP,0 }));
            listeners += ({ TP });
            return 1;
        }
        else
        {
            W("You are already listening to the words.\n");
            return 1;
        }
    }
    W("The only thing that can be heard is the sad song of the little " +
      "swallow.\n");
    return 1;
}

void listen_song(object player,int step)
{
    if(present(player))
    {
        set_this_player(player);
        if(step < 12)
        {
            set_alarmv(4.0,0.0,"listen_song",({ player, step + 1 }));
            W("\nThe bird sings: ");
        }
        switch(step)
        {
            case 0: W("The night slipped into morning,\n" +
                      "                and the match it was a-made.\n\n");
              break;
            case 1: W("And silent lay the misty glen,\n" +
                      "                as the veil began to fade.\n\n");
              break;
            case 2: W("She lay there still in his embrace,\n" +
                      "                and slumbered but a while.\n\n");
              break;
            case 3: W("When she woke alone she lay,\n" +
                      "                There at the break of day.\n\n");
              break;
            case 4: W("She danced across the meadows,\n" +
                      "                Her laughter filled the air.\n\n");
              break;
            case 5: W("And troll and faerie turned to view,\n" +
                      "                this joyous lass so fair.\n\n");
              break;
            case 6: W("Now what, they mulled, could she have found,\n" +
                      "                to make her heart so light.\n\n");
              break;
            case 7: W("A promise made that they would wed,\n" +
                      "                the last words he had said.\n\n");
              break;
            case 8: W("She waits down by the willow tree,\n" +
                      "                there's a blackbird mongst the " +
                      "leafs.\n\n");
              break;
            case 9: W("'Say have you seen my love' she asks,\n" +
                      "                the bird is struck with grief.\n\n");
              break;
            case 10: W("Oh woe to thee sweet Mary'O,\n" +
                       "                the blackbird wept and told.\n\n");
              break;
            case 11: W("For yon the gray and stormy sea\n" +
                       "                your true love left last eve.\n\n");
              break;
            case 12: W("How sad... You sniff sadly for a little while.\n");
                     S(TP->QN + " sniffs sadly for a little while.\n");
                     listeners -= ({ player });
              break;
        }
    }
    else
    {
        listeners -= ({ player });
    }
}
