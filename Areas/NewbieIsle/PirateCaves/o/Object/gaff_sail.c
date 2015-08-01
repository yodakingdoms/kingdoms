//======================================================================
// This is the sail needed for the piracy quest
//======================================================================
#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;
inherit STD_LORE;

void create_object(void);

void create_object(void)
{
    set_name("sail");
    add_id("gaff sail");
    add_id("_pirate_quest_gaff_sail_");
    set_short("A gaff sail");
    set_long("A sail with four corners and four edges.\n");
    set_weight(4);
    set_value(75);

    add_lore("Schooners are usually rigged with gaff sails, and most " +
             "square rigged vessels have a gaff sail on their aft mast " +
             "called the spanker. Above the gaff is often rigged a " +
             "triangular sail called a gaff topsail.\n",5);
    add_lore("A gaff sail is a fore-and-aft sail with four corners and " +
             "four edges. The lowest edge is called the foot and is " +
             "attached to a horizontal spar called a boom. The vertical " +
             "edge that is attached to the mast is called the luff. The " +
             "upper edge is called the head and is attached to a spar " +
             "called a gaff. The remaining edge is the leech. The corner " +
             "between the luff and the head is called the throat, between " +
             "the head and the leech is the peak, between the leech and " +
             "the foot is the clew, and the remaining corner is called " +
             "the tack.\n",10);
    set_material("canvas"); //Angelwings
}
