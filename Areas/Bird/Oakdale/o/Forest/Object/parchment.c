#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void create_object(void);

void create_object(void)
{
    set_name("parchment");
    add_id("piece");
    set_short("a piece of parchment");
    set_long("The parchment has been burnt, and only the lower right corner " +
             "remains. You can only make these words out.\n\n" +
             "                                      ...his life\n" +
             "                               " +
             "...two nights from\n             ...use the old sie" +
             "ge tunnel to enter\n          ...in the dark gnome " +
             "caves to the north\n       ...the other keystone will" +
             " be left here in\n the hideout. Should we fail, t" +
             "hat stone may give\n others the opportunity to fini" +
             "sh what we have   \n begun. Pray that it will not b" +
             "e needed, that our\n valley will be free three nigh" +
             "ts from now.      \n Hail Talinon                  " +
             "                  \n Hail Alywin\n");
    set_weight(1);
    set_value(30);
    set_material("parchment");
}
