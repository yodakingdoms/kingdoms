// Items module hack for add_var_item
#pragma strict_types
#include "../def.h"
inherit "/std/modules/general/items";

// Mapping with item : array of descs pairs
private mapping item_descs = ([]);

string query_item(string str)
{
    string item = ::query_item(str);
    if(item)
    {
        string *descs = item_descs[str];
        if(descs)
        {
            int i = call_other(TO,item[1..-1]);
            // If you (for example) have ({ "Foo","","Bar" }) you will
            // get 'There is no <item> here.' if the function returns 1.
            // The same if the function returns an index out of bounds
            // for the array of descs for the item
            if(i < 0 || i >= sizeof(descs) ||
               (item = item_descs[str][i]) == "")
            {
                return (string)0;
            }
        }
    }
    return item;
}

// Add item with descs varying depening on a condition. *descs is an array
// of descriptions the item can have. Func is the name of a function that
// should return the index of descs for the desc that should be used, based
// on the current state of the room or object.
void add_func_item(string thing,string func,string *descs)
{
    int i;
    string *things = explode(thing,"|");

    for(i = 0; i < sizeof(things); i++)
    {
        item_descs += ([things[i]:descs]);
    }
    add_item(thing,func);
}

void remove_item(string thing)
{
    int i;
    string *things = explode(thing,"|");

    ::remove_item(thing);

    for(i = 0; i < sizeof(things); i++)
    {
        item_descs = m_delete(item_descs,things[i]);
    }
}

void remove_all_items()
{
    ::remove_all_items();
    item_descs = ([]);
}

// Don't need the below if query_item is nomask in the 'real' items module
/*
int write_item(string str)
{
  int i;
  string vrb = query_verb(),itm,*descs = item_descs[str];

  if(!str || str == "0") str = "";

  switch(vrb)
  {
    case "read": str = "@" +  str; break;
    case "listen": str = "$" + str; break;
    case "smell": str = "%" + str; break;
    case "touch": str = "&" + str; break;
    case "taste": str = "~" + str; break;

    default: if(vrb == "look" ||
                vrb == "examine" ||
                vrb == "l") break;

    else return 0;

  }

  itm = query_item(str);
  if (!itm)
  {
    return 0;
  }

  switch(vrb) // No message if argument is missing
  {
    case "read": if(str!="@") S(TP->QN+" reads the "+str[1..-1]+".\n");
	         break;
    case "listen": if(str!="$") S(TP->QN+" listens to the "+str[1..-1]+".\n");
	           break;
    case "smell": if(str!="%") S(TP->QN+" smells the "+str[1..-1]+".\n");
                  break;
    case "touch": if(str!="&") S(TP->QN+" touches the "+str[1..-1]+".\n");
		  break;
    case "taste": if(str!="~") S(TP->QN+" tastes the "+str[1..-1]+".\n");
                  break;
  }

  if (itm[0]=='#')
  {
    if(!descs)
    {
      call_other(TO, itm[1..-1], str);
      return 1;
    }
    else
    {
      itm = item_descs[str][call_other(TO,itm[1..-1])];
    }
  }
  W(itm + ((itm[-1..-1]=="!" || itm[-1..-1]=="?") ?"":".")+"\n");
  return 1;
}
*/