//========================================================
// Definitions for Mansion domain.
//========================================================
// Standard mudlib includes
//--------------------------------------------------------
#include <macros.h>
#include <mudlib.h>
#include <sysdefs.h>
#include <levels.h>
#include <guild.h>
#include <items.h>
#define STD_LORE "/std/toolbox/lore"
// Subrace for the goblins so later xp isn't affected by killing
// the wimpy monsters here
#define MANSION_GOBLIN_SUBRACE_FLAG 18

//--------------------------------------------------------
// Domain path definitions
//--------------------------------------------------------
#define MANSION "/areas/NewbieIsle/Mansion/o/"
#define ROOM MANSION + "Room/"
#define MONSTER MANSION + "Monster/"
#define OBJECT MANSION + "Object/"
#define WEAPON MANSION + "Weapon/"
#define ARMOUR MANSION + "Armour/"

//--------------------------------------------------------
// Master stuff
//--------------------------------------------------------
#define MASTER_ROOM MANSION + "Master/master_room"
#define MASTER_INDOORS_ROOM MANSION + "Master/master_indoors_room"
#define ITEMS_MODULE MANSION + "Master/items_module"
#define SYS_DESTRUCT "/sys/room/destruct_room"
//--------------------------------------------------------
// Exits to Playground area
//--------------------------------------------------------
#define PLAYGROUND "/areas/NewbieIsle/Playground/o/Rooms/entrance"

//--------------------------------------------------------
// Log
//--------------------------------------------------------
#define QUEST_LOG "/areas/NewbieIsle/Mansion/log/quest_solvers"
