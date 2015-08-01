// This is the prayer the darkling cleric casts. It's supposed to
// work like a cleric lightning, but with aligns reversed
#pragma strict_types
#include "../def.h"
inherit CLERIC_LIGHTNING;

int check_target(object who,object cross,int boolean = 1);
int test_spell(string casting_spell,int bonus);
float query_alignment_multiplier(object caster,object target);

// The cleric can cast lightning at whoever he wants to
int check_target(object who,object cross,int boolean = 1)
{
    return 1;
}

// And no matter how evil or whatever he is
int test_spell(string casting_spell,int bonus)
{
    return 0;
}

// Lets reverse the align multiplier too so he does more than
// burn eyebrows
float query_alignment_multiplier(object caster,object target)
{
  float aldiff;
  int undead_al;

  aldiff = itof((caster->query_alignment() * -1) -
                (target->query_alignment() * -1))/240.0;
  if(target->query_property("undead"))
  {
    undead_al = -1100 + ftoi(itof((target->query_alignment() * -1))/12.0);
    aldiff = itof((caster->query_alignment() * -1) - undead_al)/240.0;
  }
  return aldiff;
}
