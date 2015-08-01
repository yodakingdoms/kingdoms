//========================================================
// Standard definitions.h file for the PirateCaves domain
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
#define MOD_SHOP "/std/modules/room/shop_mod"
#define MOD_APO "/std/modules/room/apothek_mod"
#define TRASHCAN "/std/clone/trashcan"
#define SYS_CORPSE "/sys/death/corpse"

//--------------------------------------------------------
// Domain path definitions
//--------------------------------------------------------
#define PIRATECAVES "/areas/NewbieIsle/PirateCaves/o/"
#define PCROOM PIRATECAVES + "Room/"
#define PCMONSTER PIRATECAVES + "Monster/"
#define PCOBJECT PIRATECAVES + "Object/"
#define PCWEAPON PIRATECAVES + "Weapon/"
#define PCARMOUR PIRATECAVES + "Armour/"
//--------------------------------------------------------
// Master stuff
//--------------------------------------------------------
#define MASTER_ROOM PIRATECAVES + "Master/master_room"
#define SHIP_ROOM PIRATECAVES + "Master/master_ship_room"
#define MASTER_INDOORS_ROOM PIRATECAVES + "Master/master_indoors_room"
#define ITEMS_MODULE PIRATECAVES + "Master/items_module"
#define CHECK_FIRE_MODULE PIRATECAVES + "Master/check_fire_module"

//--------------------------------------------------------
// Ship files
//--------------------------------------------------------
#define SHIP_OBJ "/areas/NewbieIsle/PirateCaves/o/Master/ship_obj"
//--------------------------------------------------------
// Exits to Newbie Island area
//--------------------------------------------------------
#define TROLL_HILL "/areas/NewbieIsle/NewbieIsle/o/Room/troll_hill"
#define SHORE "/areas/NewbieIsle/NewbieIsle/o/Room/shore1"

//--------------------------------------------------------
// Logs
//--------------------------------------------------------
#define QUEST_LOG "/areas/NewbieIsle/PirateCaves/log/quest_solvers"
#define BIRDVIAL_LOG "/areas/NewbieIsle/PirateCaves/log/birdvial_drinkers"
#define POWDER_LOG "/areas/NewbieIsle/PirateCaves/log/powder_log"
