//========================================================
// Definitions for Oakdale domain.
//========================================================
// Standard mudlib includes
//--------------------------------------------------------
#include <macros.h>
#include <mudlib.h>
#include <sysdefs.h>
#include <levels.h>
#include <guild.h>
#include <items.h>
#include <align.h>
#define STD_LORE "/std/toolbox/lore"
#define STD_ARRAYS "/std/toolbox/arrays"

//--------------------------------------------------------
// Domain path definitions
//--------------------------------------------------------
#define OAKDALE "/areas/Bird/Oakdale/o/"
#define VILLAGE OAKDALE + "Village/"
#define FOREST OAKDALE + "Forest/"
#define CASTLE OAKDALE + "Castle/"

#define MOD_ITEMS OAKDALE + "Master/items_module"
#define MASTER_ROOM OAKDALE + "Master/master_room"

//--------------------------------------------------------
// Paths to places outside of domain
//--------------------------------------------------------
#define OLD_FOREST "/areas/Bird/OldForest/o/Room/road13"
#define MAGE_SPELL_PARSER "/areas/Guilds/Mage/o/spells/spell_parser"
#define CLERIC_LIGHTNING "/areas/Guilds/Cleric/o/Main/Prayers/lightning"
#define MOD_SHOP "/std/modules/room/shop_mod"
#define MOD_APO "/std/modules/room/apothek_mod"
#define MOD_BANK "/std/modules/room/bank_mod"
#define MOD_POST "/std/modules/room/post_mod"
#define TRASHCAN "/std/clone/trashcan"

//--------------------------------------------------------
// Flags
//--------------------------------------------------------
#define QUEST_FLAG 168
#define QUEST_SUB_FLAG_1 169
#define QUEST_SUB_FLAG_2 170
#define QUEST_SUB_FLAG_3 171
#define QUEST_SUB_FLAG_4 172
#define QUEST_SUB_FLAG_5 173
#define QUEST_SUB_FLAG_6 174
#define QUEST_SUB_FLAG_7 175

//--------------------------------------------------------
// Logs
//--------------------------------------------------------
#define QUEST_LOG "/areas/Bird/Oakdale/log/quest_solvers"
#define NIRACH_KILLER_LOG "/areas/Bird/Oakdale/log/nirach_killer"
#define KILLED_BY_NIRACH_LOG "/areas/Bird/Oakdale/log/killed_by_nirach"
#define DRAGON_SPIRIT_LOG "/areas/Bird/Oakdale/log/dragon_spirit"
