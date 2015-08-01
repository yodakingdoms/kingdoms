#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_BANK;

void create_object(void);

void create_object(void)
{
    set_short("The Bank");
    set_long("This is the Oakdale Savings and Loans. The stone walls of " +
             "this house gives you a reassuring impression. The wooden " +
             "ceiling and floor looks really safe. You would not feel " +
             "insecure leaving your money in this place! A clerk stands " +
             "behind the counter, ready to serve you, and on the counter " +
             "is a sign.\n");
    set_new_light(10);
    add_property("indoors");

    add_item("clerk","You try to catch the clerk's eye, and he responds " +
             "immediately. 'What can I do for you?' he says in a " +
             "businesslike manner");
    add_item("sign","The sign reads:\nYou can deposit or withdraw money " +
             "from your account here");
    add_item("counter","You see nothing of interest, except from an " +
             "hourglass");
    add_item("hourglass","#fun_bank_hourglass");
    add_item("wall|walls","Strong, thick stone walls");
    add_item("house|building","The bank of Oakdale. Strong building where " +
             "your money will be safe");
    add_item("ceiling","A wooden ceiling that looks very safe");
    add_item("floor","A hard wooden floor that noone would be able to dig " +
             "in through");

    add_exit(ROOM + "road5","north");
}
