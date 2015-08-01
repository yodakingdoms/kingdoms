#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
void init(void);
int do_enter(string str);
int load_doors(void);

void create_object(void)
{
    set_short("A small yard");
    set_long("A small yard surrounded by a high net fence. There is no " +
             "grass on the ground, it is packed dirt and covered by " +
             "seeds. There is a small wooden building here that is " +
             "obviously a henhouse. It's only a few feet high and it has " +
             "no windows. It's standing on four wooden legs and a plank " +
             "leads from the ground up to a small entrance hole in the " +
             "wall. You see the barn through the fence to the northeast " +
             "and south of here is a larger field. In the distance, beyond " +
             "the rolling hills to the west, you think you can make out " +
             "the ocean.\n");

    set_new_light(5);
    set_skip_obvious(1);

    add_item("yard|small yard|poultry yard","This yard is obviously a " +
             "poultry yard");
    add_item("fence|net fence|high net fence","Well, the fence would be " +
             "high if you were the size of a hobbit, but since you are not " +
             "it really isn't that high. It would be very high to a hen, " +
             "and you suspect keeping some of those inside is the primary " +
             "task of the fence");
    add_item("grass","You can't see any grass inside the fence");
    add_item("ground","The dirt on the ground is covered with seeds, thrown " +
             "there so the hens will have something to eat probably");
    add_item("dirt","It's packed. You doubt the hens are big enough to " +
             "make the dirt look like that so you assume someone or " +
             "something else has been stomping around here to pack it " +
             "that way");
    add_item("seed|seeds","Different kind of seeds presumably spread " +
             "around here so the hens will have something to eat");
    add_item("building|wooden building|small building|small wooden building|" +
             "house|small house|henhouse","It looks like a small version " +
             "of a house but since hens probably don't care much about what " +
             "their house looks like, you assume it looks that way so the " +
             "yard will look nicer to the twolegged inhabitants of the farm");
    add_item("farm","The rest of the farm is north and east of here");
    add_item("window|windows","Presumably, hens don't care much about " +
             "windows");
    add_item("leg|legs|wooden leg|wooden legs","The legs lift the house " +
             "a foot above the ground");
    add_item("plank","A plank that lets the hens walk from the ground " +
             "straight into the hole in the henhouse");
    add_item("wall|walls","The walls of the henhouse have no windows in " +
             "them");
    add_item("hole|entrance hole|entrance","It's where the hens go in and " +
             "out of the henhouse");
    add_item("barn","You can see it through the fence but you'd have to " +
             "go there to get a better look");
    add_item("field|large field|larger field|cornfield","It seems to be " +
             "a cornfield but you'd have to go there to get a better look");
    add_item("hill|hills|rolling hills","The rolling hills stretch towards " +
             "the ocean to the west");
    add_item("ocean","You can just about make it out beyond the hills to " +
             "the west. You wonder what lies on the other side of it");
    add_item("%|%smell|%chicken","The poultry yard smells like chicken, it " +
             "makes you rather hungry");
    add_item("$|$house|$sound|$hen|$hens","You hear the sound of hens " +
             "moving around in the small hen house");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "hen",8);
    add_monster(MONSTER + "rooster",1);
    ::reset();
}

void init(void)
{
    add_action("do_enter","enter");
    ::init();
}

int do_enter(string str)
{
    if(str == "house" || str == "hole" || str == "entrance" ||
       str == "entrance hole")
    {
        W("It seems to be a nice house to live in but you are much " +
          "bigger than a hen and will unfortunately not fit inside.\n");
        S(TP->QN + " looks longingly at the small house.\n");
        return 1;
    }
    // So 'enter door' works
    return 0;
}

int load_doors(void)
{
    string dir1 = "in the fence to the east";
    string dir2 = "in the fence to the west";
    string next_room = ROOM + "farm_path2";
    string desc = "net door";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A net door in the net fence.\n";
    string entercmd1 = "east";
    string entercmd2 = "west";
    int solidity = 30;
    int complex = 20;
    int hidden1 = 0;
    int hidden2 = 0;

    add_door(dir1, dir2, next_room, desc,  closed, locked, key_id,
             long_desc, entercmd1, entercmd2, solidity, complex,
             hidden1, hidden2 );
    return 1;
}
