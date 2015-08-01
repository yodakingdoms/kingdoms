// ===================================================================
// Module to check if a player has something that can be used to light
// the magic powder. This is done in two places (at least) so it's in
// this module instead of duplicated wherever it's needed
// ===================================================================
#pragma strict_types
#include "../def.h"

int query_can_light_powder(object player);

/**
* Returns 1 if player carries something that can be used to light
* the powder, false otherwise.
*/
int query_can_light_powder(object player)
{
    int i;
    object *inventory = all_inventory(player);

    // Check to see the player has something that can be used to
    // ignite the powder. Things will probably have to be added
    // to this bit since there doesn't seem to be a standard and
    // everything has not been thought of here yet
    for(i = 0; i < sizeof(inventory); ++i)
    {
        // Property afire = lit torch, maybe other burning lights also
        // id "demon_fire" is a demon using the fire ability
        // "f_i_r_e" present in "d_e_a_t_h_b_l_a_d_e" is Dreadlord sword
        // on fire
        if(inventory[i]->query_property("afire") ||
           inventory[i]->id("demon_fire") ||
           (inventory[i]->id("d_e_a_t_h_b_l_a_d_e") &&
            present("f_i_r_e",inventory[i])))
        {
            return 1;
        }
    }
    return 0;
}