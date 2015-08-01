// Nirach has to have this thing in his inventory to be able to cast
// mage spells. Putting this stuff in his spellbook might have been
// possible but would probably mess things up for players who use that
// so we make this object instead
#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void create_object(void);
void init(void);
int drop(void);
int get(void);
string query_guild(void);
void owner_died(void);
int do_spell(string str);
int drain_component(mapping comp);

void create_object(void)
{
    add_id("magebook");
    add_id("m_a_g_e_b_o_o_k");
    set_material("magic");
    set_weight(0);
}

void init(void)
{
    if(!ENV()->id("_oakdale_nirach_the_sorcerer_"))
    {
        destroy();
    }
    else
    {
        add_action("do_spell","",1);
    }
}

int drop(void)  { return 1; }

int get(void) { return 1; }

string query_guild(void) { return MAGE; }

void owner_died(void)
{
    destroy();
}

int do_spell(string str)
{
    return MAGE_SPELL_PARSER->do_spell(TP,TO,str);
}

int drain_component(mapping comp)
{
    // Nirach has all the components he'll ever need
    return 1;
}
