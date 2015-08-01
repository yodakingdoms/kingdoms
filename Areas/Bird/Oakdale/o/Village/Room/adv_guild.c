#pragma strict_types
#include "../def.h"
inherit STD_ADV_GUILD;

void reset(int arg);

void reset(int arg)
{
    // Set all the properties an limits according to standard guild
    // and then remove items and exits so we can set them for this
    // particular guild
    ::reset(arg);
    remove_all_items();
    remove_all_exits();

    set_short("The Oakdale adventurers guild");
    set_long("This is the Oakdale adventurer's guild. It is a suitable " +
             "meeting place for adventurers, a dimly lit room with dark " +
             "corners. There are a few tables with wooden benches for " +
             "travellers to sit by and rest their weary bones. A lamp is " +
             "hanging from one of the wooden roofbeams and the stone walls " +
             "will keep you safe from any storm. " +
         "You may come here when you want to advance your level. " +
         "You can also spend your experience here to raise your stats " +
         "and skills.  Commands: cost, advance [level, str, dex, int, " +
         "con, siz, dic], list (number), quests, hint (level) (number), " +
         "myscore, mywiz, explored, raise (skill), scost, scost " +
         "(skill), and limitations.\n");

    add_item("table|tables","Tables made of oak");
    add_item("bench|benches","Benches made of oak");
    add_item("lamp","A small oil lamp providing the room with a soothing " +
             "light");
    add_item("wall|walls","Strong stone walls");
    add_item("guild","The oakdale adventurer's guild. That's where you are");
    add_item("room","A dimly lit room with dark corners");
    add_item("corner|corners","The corners in the room are dark. Perfect " +
             "for people who want to discuss secret things in private, as " +
             "many people often want to do in a place like this");
    add_item("place","A meeting place for adventurers");
    add_item("roofbeam|roofbeams|beam|beams","Thick wooden beams guaranteed " +
             "to hold the roof up");

    add_exit(ROOM + "road14","east");
}
