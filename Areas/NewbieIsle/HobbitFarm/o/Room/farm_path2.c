#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);

void create_object(void)
{
    set_short("A path to a field (ne/sw)");
    set_long("A path going southwest from the main yard to a larger field " +
             "on the outskirts of the farm. On the west side of the path " +
             "is a small yard enclosed by a high net fence. There's a small " +
             "house on the inside of the fence. To the east is a small " +
             "field surrounded by a normal wooden fence. Beyond the field " +
             "is a large grassy hill with a huge oak growing on top of it. " +
             "North of here is a large wooden building with two floors that " +
             "looks like a barn and to the south is a larger field where " +
             "some crops seem to be growing.\n");

    set_new_light(5);

    add_item("path","It's going southwest and northeast. This path " +
             "is not as trampled as the ground is in the other parts " +
             "of the farm so you assume animals aren't walking around " +
             "here quite as much");
    add_item("ground|grass|short grass","The grass on the ground is short " +
             "but not trampled");
    add_item("yard|main yard","It is northeast of here");
    add_item("crop|crops","It looks like corn");
    add_item("corn","You think that's what is growing to the southwest " +
             "but you can't tell for sure from here");
    add_item("outskirts","There's a larger field where there seems to be " +
             "corn growing there");
    add_item("farm|small farm|cosy farm|small, cosy farm","A small, cosy " +
             "farm where you could see yourself settling down and live " +
             "if it weren't for your ambition to become a great " +
             "adventurer");
    add_item("adventurer|great adventurer","If you are great or not is up " +
             "to others to decide, not you");
    add_item("side","There is a west side and an east side of the path");
    add_item("west side","There is what seems to be a poultry yard on " +
             "that side of the path");
    add_item("east side","There's a small fenced in field on that side " +
             "of the path");
    add_item("yard|small yard|poultry yard","It looks like a poultry yard. " +
             "The fence going around it is high enough that hens probably " +
             "will not be able to fly over it");
    add_item("fence","There's a net fence and a wooden fence here");
    add_item("net fence","It's high enough that hens won't be flying over " +
             "it so you assume that there's a poultry yard inside");
    add_item("net|fine net","A fine net, designed to keep poultry on one " +
             "side of it");
    add_item("house|small house","It's small to you and it would also " +
             "be pretty small to a hobbit. However, it would be of a " +
             "good size for a hen to live in");
    add_item("hen|hens","You can't see any hens out here but maybe there " +
             "are some in the poultry yard");
    add_item("poultry","You can't see any from here, maybe in the poultry " +
             "yard");
    add_item("wooden fence|normal fence|normal wooden fence","It goes " +
             "around a small field on the east side of the path");
    add_item("field","You see a large field and a small field");
    add_item("large field|larger field","It's a larger field where the " +
             "farmers seem to be growing corn");
    add_item("small field","It seems to be used for keeping animals in");
    add_item("hill|large hill|grassy hill|large grassy hill","There seem " +
             "to be some windows in the side of the hill facing this way");
    add_item("window|windows","There are windows in the side of the hill. " +
             "Someone must be living there, you wonder who");
    add_item("tree|oak|huge oak","The oak grows on top of the hill and " +
             "can be seen towering above the farm from anywhere on the farm");
    add_item("barn|building|wooden building|large wooden building","It " +
             "is pretty large compared to the other buildings on the farm " +
             "but not that big compared to what you are used to");
    add_item("buildings","All the buildings seem to be built to hobbit " +
             "specifications");
    add_item("floor|floors","The barn has two floors");
    add_item("$|$sound|$sounds|$animal|$animals","You hear the sounds of " +
             "farm animals coming from around you");
    add_item("%|%smell|%animal|%animals","You feel the smell of farm " +
             "animals. It is rather faint here though");

    add_exit(ROOM + "farm_west","northeast");
    add_exit(ROOM + "farm_corn_field","southwest");

    (ROOM + "farm_sheep_field")->load_doors();
    (ROOM + "farm_poultry_yard")->load_doors();
    reset(0);
}
