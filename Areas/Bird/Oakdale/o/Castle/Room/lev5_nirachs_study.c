#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void remote_long(int arg);
void reset(int arg);
void init(void);
int do_read(string str);
int do_look(string str);
int do_walk(string str);
void summon_spirit(int step);
void orb_destroyed(void);

void create_object(void)
{
    set_short("The study of Nirach the Sorcerer");
    set_long("A large room at the top of the tower. The room is dimly lit " +
             "by a black wax candle standing on a shelf. The walls are " +
             "lined with shelves containing hundreds of books, scrolls and " +
             "parchments. By the north wall is a wooden desk with scrolls " +
             "and writing material on it, and by the west wall is a table " +
             "filled with bottles, jars and other containers. A white " +
             "crystal ball can also be seen on the table. There is a wooden " +
             "chest here, and a full lenght mirror is standing by the desk. " +
             "The floor is covered by a soft, black rug and in the centre " +
             "of the room is a wooden lectern carved into the shape of a " +
             "dragon. Outside the window in the east wall you only see the " +
             "dark, thick clouds. Occult symbols of warding and conjuring " +
             "are carved, painted and etched everywhere in the room, and " +
             "the air is filled with a strong, evil power. Half-imaginary " +
             "shapes appear momentarily in the pulsating air. Some crying " +
             "out in agony, others leering hungrily at you. You have to " +
             "summon up every ounce of self-discipline in your being to " +
             "keep yourself from fleeing from this unholy place.\n");
    set_new_light(5);
    add_property("indoors");
    set_skip_obvious(1);

    add_item("room","A large room that looks like you'd expect the study " +
             "of a powerful sorcerer to look like");
    add_item("candle","A black wax candle on one of the wooden shelves");
    add_item("shelf|shelves","Wooden shelves line the walls. Most of them " +
             "are filled with books, scrolls and parchments");
    add_item("scroll|scrolls","Scrolls containing powerful spells, no doubt");
    add_item("parchment|parchments","Yellow, cracked parchments with " +
             "strange writing on them");
    add_item("writing","Nothing you can make anything out of");
    add_item("book|books","Hundreds of books. Some with wooden covers, " +
             "others inlaid with jewels and yet others with covers of skin " +
             "of an origin you'd rather not know. All have strange runes " +
             "on them, and they all seem to be flinching and moving, " +
             "rubbing up against each other as if they're drawing power " +
             "from each other");
    add_item("wall|walls","The smooth, black walls are covered with shelves");
    add_item("desk","A wonderfully crafted oak desk covered with scrolls " +
             "and writing material");
    add_item("material","Quills, ink and the like");
    add_item("quill|quills|ink","Writing material");
    add_item("table","A black oak table filled with bottles, jars and other " +
             "containers");
    add_item("bottle|bottles","Glas bottles of different colours, " +
             "containing strange substances");
    add_item("substance|substances","You can't tell what it is, but for " +
             "some reason you're actually glad that you can't");
    add_item("jar|jars","Jars of different sizes and shapes, no doubt " +
             "containing nasty things needed to cast spells");
    add_item("thing|things|components|components","Different spell " +
             "components");
    add_item("container|containers","Containers of varying size, probably " +
             "containing disgusting things");
    add_item("ball|crystal","A translucent crystal ball containing a milky " +
             "white mist");
    add_item("mist","A swirling white mist");
    add_item("chest","A chest made of black wood. There's no lock on it but " +
             "you suspect you wouldn't be able to open it anyway");
    add_item("mirror","A full length mirror with a silver frame. There's " +
             "something strange about it. Maybe you could look into it?");
    add_item("frame","The silver frame is engraved with spidery runes");
    add_item("rune|runes","Try reading the runes");
    add_item("pedestal","A black stone pedestal");
    add_item("orb","A shining white orb");
    add_item("floor","The floor is covered by a black rug");
    add_item("rug","A soft. black rug that feels good to walk upon");
    add_item("lectern","A dark wood lectern that is carved into the shape " +
             "of a dragon. A chain is hanging from the lectern, but there " +
             "is no book attached to it");
    add_item("chain","A silver chain");
    add_item("dragon","A black dragon with it's wings spread");
    add_item("wing|wings","The dragon's wings are spread");
    add_item("window","A large window in the east wall");
    add_item("cloud|clouds","Nothing can be seen outside the window except " +
             "for the dark, threatening clouds");
    add_item("symbol|symbols","Strange scary symbols of enchantment");
    add_item("air","The air is so charged with magic power that it almost " +
             "blurs your vision");
    add_item("shape|shapes|figure|figures","Dark, twisted figures appearing " +
             "for a moment and then vanishing again. You're not even sure " +
             "if they are really there, or if they are just figments of " +
             "your own imagination");

    (ROOM + "lev5_stairroom")->load_doors();
    reset(0);
}

void remote_long(int arg)
{
    W("You can't see anything. It's like a dark veil of shadow covers the " +
      "doorway...\n");
}

void reset(int arg)
{
    present("_oakdale_dragon_spirit_",TO)->destroy();
    add_monster(MONSTER + "nirach",1);
    ::reset(arg);
}

void init(void)
{
    add_action("do_read","read");
    add_multi_action("do_look","l|look");
    add_action("do_walk","walk");
    SYS_ADMIN->visit(394);
    ::init();
}

int do_read(string str)
{
    if(str == "runes")
    {
        if(TP->query_skill("runes") + TP->query_int() > 45)
        {
            W("They are runes of seeing and movement.\n");
            S(TP->QN + " studies the runes on the frame of the mirror.\n");
            return 1;
        }
        else
        {
            W("You can't understand these runes.\n");
            S(TP->QN + " studies the runes on the frame of the mirror and " +
              "looks confused.\n");
            return 1;
        }
    }
    return 0;
}

int do_look(string str)
{
    if(str == "into mirror" || str == "in mirror")
    {
        W("Instead of seeing your reflection and the room behind you in " +
          "the mirror, you see a dark room with a pedestal on it. On the " +
          "pedestal lies an orb. It looks almost like you could walk " +
          "trough the mirror into that room.\n");
        S(TP->QN + " looks deep into the mirror.\n");
        return 1;
    }
}

int do_walk(string str)
{
    if(str == "through mirror")
    {
        W("As you approach the mirror the image fades. The proper spells " +
          "of movement have apparently not been said yet.\n");
        S(TP->QN + " walks over to the mirror.\n");
        return 1;
    }
    return notify_fail("Walk where?\n");
}

void summon_spirit(int step)
{
    // If there's been a reset and Nirach has come back, we stop this thing
    // have to allow the first step because Nirach is still in the room
    // when the call is sent
    if(!step || !present("_oakdale_nirach_the_sorcerer_",TO))
    {
        switch(step)
        {
            case 0: set_alarm(5.0,0.0,"summon_spirit",1);
              break;
            case 1: tell_room(TO,"You notice that Nirach's shadow still " +
                              "lingers on the wall...\n");
                    set_alarm(15.0,0.0,"summon_spirit",2);
              break;
            case 2: tell_room(TO,"The air in the room begins to vibrate " +
                              "in an eerie way...\n");
                    set_alarm(15.0,0.0,"summon_spirit",3);
              break;
            case 3: tell_room(TO,"You hear a rumbling sound from somewhere. " +
                              "The wind is howling outside the window.\n");
                    set_alarm(15.0,0.0,"summon_spirit",4);
              break;
            case 4: tell_room(TO,"Something is approaching... Something " +
                              "powerful...\n");
                    set_alarm(8.0,0.0,"summon_spirit",5);
              break;
            case 5: tell_room(TO,"The floor begins to tremble softly.\n");
                    set_alarm(4.0,0.0,"summon_spirit",6);
              break;
            case 6: tell_room(TO,"It is coming... It is drawing nearer...\n");
                    set_alarm(6.0,0.0,"summon_spirit",7);
              break;
            case 7: tell_room(TO,"The whole tower is trembling now. Maybe " +
                              "it would be best to leave.\n");
                    set_alarm(5.0,0.0,"summon_spirit",8);
              break;
            case 8: tell_room(TO,"Something is beginning to take shape in " +
                              "the air before you...\n");
                    set_alarm(5.0,0.0,"summon_spirit",9);
              break;
            case 9: tell_room(TO,"Something horrible is coming!! The tower " +
                              "is shaking violently now!!\n");
                    set_alarm(4.0,0.0,"summon_spirit",10);
              break;
            case 10: tell_room(TO,"It's almost here!! Run, fool!! " +
                               "Run!!!!!!\n");
                     set_alarm(3.0,0.0,"summon_spirit",11);
              break;
            case 11: tell_room(TO,"By the gods...\n");
                     set_alarm(4.0,0.0,"summon_spirit",12);
              break;
            case 12: tell_room(TO,"A huge shape materializes in the room!!\n" +
                               "The dragon spirit roars as it bears down " +
                               "upon you.\n");
                     set_alarm(1.0,0.0,"summon_spirit",13);
              break;
            case 13: tell_room(TO,"Run for your life!!!!!!!!!!!!\n");
                     // This shouldn't happen, but just in case. We don't
                     // want both of them around at the same time
                     if(!present("_oakdale_nirach_the_sorcerer_"))
                     {
                         make(MONSTER + "dragonspirit");
                     }
              break;
        }
    }
}

// This is called from FOREST + "Room/shrine_altar" when the orb is
// destroyed. Since that's supposed to defeat Nirach, any present
// Nirach or spirit here should be dested
void orb_destroyed(void)
{
    object nirach = present("_oakdale_nirach_the_sorcerer_");
    if(nirach)
    {
        // The odds of anyone being here when it happens probably aren't
        // great but let's add some special effects anyway just in case
        tell_room(TO,"Nirach suddenly shrieks in terror and collapses onto " +
                  "the floor.\nNirachs body dissolves and turns into a " +
                  "black misty figure that floats away through the wall, " +
                  "leaving only the echo of a chilling scream of terror!\n");
        move_object(nirach,SYS_VOID);
        nirach->destroy();
    }
    nirach = present("_oakdale_dragon_spirit_");
    if(nirach)
    {
        tell_room(TO,"The spirit suddenly lets out an ear piercing shriek!" +
                  "\nThe spirit dissolves and turns into a black misty " +
                  "figure that floats away through the wall, leaving only " +
                  "the echo of a chilling scream of terror!\n");
        nirach->destroy();
    }
}
