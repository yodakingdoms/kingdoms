#pragma strict_types
#include "../def.h"
inherit TRASHCAN;

void create_object(void);
void long(void);
int is_unkillable(void);
string unkillable_string(object attacker);

void create_object(void)
{
    ::create_object();
    set_short("A small drunken trash dragon");
    load_chat(1,({
              "The drunken trash dragon begs you to feed him.\n",
              "The drunken trash dragon looks real THIRSTY.\n",
              }));
}

void long(void)
{
    W("This is undoubtedly one of the famous trash dragons that " +
      "once ruled the world. They are ferociously hungry all the " +
      "time and will devour anything people care to feed them " +
      "with. This particular dragon is in a sorry state. It has a " +
      "big red nose and wobbles around the floor. It looks as if " +
      "has had (a lot) more ale than trash lately.\n");
    if(chewing)
    {
        W("It is currently chewing on something.\n");
    }
}

int is_unkillable(void)
{
    return 1;
}

string unkillable_string(object attacker)
{
    return "As you approach the dragon to kill it, it breathes in your " +
           "general direction. The stench almost makes you throw up and " +
           "definitely makes you change your mind about attacking it.";
}
