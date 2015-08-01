#pragma strict_types
#include "../def.h"
inherit STD_ENHANCER;
inherit STD_LORE;
inherit STD_ARRAYS;

object *rune_readers = ({});
object book_opener;

void create_object(void);
void init(void);
int do_open(string str);
int do_runes(string str);
int attune(string arg);
int query_spellbook_multiplier(void);

void create_object(void)
{
    set_name("book");
    add_id("spellbook");
    set_short("The Spellbook of Aldarak");
    set_long("A thick, black leatherbound book. Strange runes are written " +
             "on it's cover and a strange, evil power is emanating from " +
             "the book. The book is cold to the touch, and it almost seems " +
             "to draw the warmth from the air around it.\n");
    set_value(300);
    set_weight(2);
    set_adder(5);
    set_multiplier(5);
    set_multiplier_fun("query_spellbook_multiplier");
    set_difficulty(30);
    set_material("paper");

    add_lore("The spellbook of Aldarak... You remember your mother used to " +
             "scare you with that name when you didn't want to eat all your " +
             "porridge when you were a child.\n",1,19);
    add_lore("Aldarak the Soulstealer was the most powerful wizard who ever " +
             "lived, and this is his spellbook... It must hold untold " +
             "powers.\n",20);
    add_lore("It is told that the mighty wyrmkin wizard documented every " +
             "single known spell in this tome. Indeed, this book is the " +
             "single most sought after artifact in the Kingdoms among the " +
             "Brotherhood of dark mages.\n",30);
    add_lore("Untold powers would be granted those who master the spells in " +
             "this book, but the elder also tell of unholy protective " +
             "spells laid upon it. The one who tries, but fails to master " +
             "the book would suffer a terrible fate.\n",40);
    set_property("godlike");
}

void init(void)
{
    add_action("do_open","open");
    add_multi_action("do_runes","l|look|read|examine");
    spell_enhancer_init();
}

int do_open(string str)
{
    if(str == "book" || str == "book now")
    {
        if(ENV(TO) != TP)
        {
            W("You need to hold the book to open it.\n");
            return 1;
        }
        if(book_opener != TP)
        {
            if(!is_in(TP,rune_readers) && str != "book now")
            {
                W("As you try to open the book, the runes on the cover " +
                  "begin to glow softly. You could <open book now> if you " +
                  "do not wish to pay any attention to the runes...\n");
                return 1;
            }
            if(TP->query_alignment() > 299)
            {
                W("There is a bright flash as you touch the book and you " +
                  "are struck with a bolt of lightning!\nAs you throw the " +
                  "book onto the floor, a dark shape rises from it... " +
                  "The shape grins at you for a moment and then fades " +
                  "away.\n");
                S("There is a bright flash and " + TP->QN + " doubles over " +
                  "in pain as " + TP->QPR + " is struck by a bolt of " +
                  "lightning and throws a black spellbook onto the floor.\n");
                TP->do_spell_damage(random(50) + 30,"electric");
                TP->command("drop book");
                return 1;
            }
            else if(TP->query_alignment() > -300)
            {
                W("There is a bright flash as you touch the book and you " +
                  "are struck with a bolt of lightning!\nYou throw the book " +
                  "to the floor and double over in pain.\n");
                S("There is a bright flash and " + TP->QN + " doubles over " +
                  "in pain as " + TP->QPR + " is struck with a bolt of " +
                  "lightning!\n");
                TP->do_spell_damage(random(20) + 20,"electric");
                TP->command("drop book");
                return 1;
            }
            else
            {
                W("You open the book. Runes of magic appear on the page " +
                  "before you, glowing softly, beckoning you to " +
                  "<choose book>.\n");
                S(TP->QN + " opens the black spellbook.\n");
                book_opener = TP;
                return 1;
            }
        }
        W("You have already opened the spellbook!\n");
        return 1;
    }
    return 0;
}

int do_runes(string str)
{
    if(str == "runes" || str == "at runes")
    {
        rune_readers += ({ TP });
        if(TP->query_skill("runes") < 1)
        {
            W("You can make nothing out of these runes.\n");
            S(TP->QN+" is baffled by the runes on the cover of the " +
              "spellbook.\n");
            return 1;
        }
        else if(TP->query_skill("runes") < 10)
        {
            W("These runes are evil. For kind souls to open this book " +
              "would be foolish.\n");
            S(TP->QN + " studies the runes on the cover of the spellbook.\n");
            return 1;
        }
        else if(TP->query_skill("runes") < 20)
        {
            W("These runes are evil. For kind souls to open this book would " +
              "be foolish. The runes are magic runes of warding and " +
              "conjuring.\n");
            S(TP->QN + " studies the runes on the cover of the spellbook.\n");
            return 1;
        }
        else if(TP->query_skill("runes") < 30)
        {
            W("These runes are evil. For kind souls to open this book would " +
              "be foolish. The runes are magic runes of warding and " +
              "conjuring and you notice several magic seals that would be " +
              "broken by anyone trying to open the book.\n");
            S(TP->QN + " studies the runes on the cover of the spellbook.\n");
            return 1;
        }
        else if(TP->query_skill("runes") < 40)
        {
            W("These evil runes are magic seals that will release " +
              "conjurning spells upon any kind souled person trying to open " +
              "the spellbook. The spells would summon dark spirits against " +
              "good, but would invite evil, as evil is the purpose of this " +
              "spellbook.\n");
            S(TP->QN+" studies the runes on the cover of the spellbook.\n");
            return 1;
        }
        else if(TP->query_skill("runes") > 39)
        {
            W("According to the runes, this book will bring doom for the " +
              "one with a kind soul why tries to wield it's powers. The " +
              "evil will prosper as the purpose of the book is evil, but " +
              "only the highest ranking and most black souled ones will be " +
              "able to fully utilise its powers.\n");
            S(TP->QN + " studies the runes on the cover of the " +
              "spellbook.\n");
            return 1;
        }
    }
}

int attune(string arg)
{
    if(book_opener != TP)
    {
        W("You have to open the book to be able to read the spells and draw " +
          "power from it.\n");
        return 1;
    }
    W("Your blood starts to burn with magic as you begin to study the " +
      "spells.\n");
    S(TP->QN + " opens the black spellbook and begins to study the spells.\n");
    return ::attune(arg);
}

int query_spellbook_multiplier(void)
{
    if(TP->query_alignment() <-1000 && TP->query_level() > 18)
        return 5;
    else if(TP->query_alignment() <-1000 && TP->query_level() > 15)
        return 4;
    else if(TP->query_alignment() <-1000 && TP->query_level() > 11)
        return 3;
    else if(TP->query_alignment() <-1000 && TP->query_level() < 12)
        return 2;
    else if(TP->query_alignment() <-800 && TP->query_level() > 18)
        return 4;
    else if(TP->query_alignment() <-800 && TP->query_level() > 15)
        return 4;
    else if(TP->query_alignment() <-800 && TP->query_level() > 11)
        return 3;
    else if(TP->query_alignment() <-800 && TP->query_level() < 12)
        return 2;
    else if(TP->query_alignment() <-550 && TP->query_level() > 18)
        return 4;
    else if(TP->query_alignment() <-550 && TP->query_level() > 15)
        return 3;
    else if(TP->query_alignment() <-550 && TP->query_level() > 11)
        return 2;
    else if(TP->query_alignment() <-550 && TP->query_level() < 12)
        return 2;
    else if(TP->query_level() > 18)
        return 3;
    else
        return 2;
}
