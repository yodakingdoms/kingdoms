//===================================================================
// Object giving a wet extra look. Cloned on players thrown into the
// water by the tree in hazeldown_path3
//===================================================================
#pragma strict_types
#include "../def.h"
inherit STD_OBJ;

void create_object(void);
string extra_look(void);
void go_away(void);
int drop(void);
int get(void);

void create_object(void)
{
    // Player dries up after 5 minutes
    set_alarm(300.0,0.0,"go_away");
    set_material("none"); //Angelwings
}

string extra_look(void)
{
    return ENV(TO)->QN + " is soaking wet";
}

void go_away(void)
{
    tell_object(ENV(TO),"You feel dry again.\n");
    destroy();
}

int drop(void)
{
    return 1;
}

int get(void)
{
    return 1;
}
