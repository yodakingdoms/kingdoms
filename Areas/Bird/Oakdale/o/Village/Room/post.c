#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_POST;

void create_object(void);

void create_object(void)
{
    set_short("The post office");
    set_long("You are in the Oakdale post office. The house has stone walls " +
             "and wooden ceiling. There is a sign here with these " +
             "commands:\n" +
             "read         Read from the mailbox.\n" +
             "mail <name>  Mail to player 'name'.\n" +
             "from         List all headers.\n" +
             "Use the command: \"help post\" if you need more help.\n" +
             "(If <name> is \n" +
             "\"ARCH\"\tthen you'll mail all the arches.\n" +
             "\"QC\"\t\t -- \" --\t qc-arches.\n" +
             "\"LAW\"\t\t -- \" --\t law-arches.\n" +
             "\"WIZHELPER\"\t -- \" --\t wizhelpers.\n" +
             "\"GUILDBALANCE\"\t -- \" --\t guild-arches.\n" +
             "\"MAINTAINANCE\"\t -- \" --\t maintainance-arches.\n" +
             "If you do \"g\" while reading your mail, you will\n" +
             "get the groups listed.)\n\n");
    set_new_light(10);
    add_property("indoors");

    add_item("wall|walls","Thick stone");
    add_item("ceiling","It is made of wood");

    add_exit(ROOM + "road20","east");
}
