//====================================================================
// master_monster - Master file containing some common functions used
//                  by monsters in the area. Only the special monsters
//                  use these things
//====================================================================
#pragma strict_types
#include "../def.h";
inherit STD_MONSTER;

//-Common variables---------------------------------------------------

string *friendly_players = ({});  // Array of names of players monster knows
string *nasty_players = ({});     // Array of names of players monster dislikes
string *met_players = ({});       // Array of names of players monster has
                                  // met but doesn't have an opinion about yet

//-Common functions---------------------------------------------------

// Is a player a friend
int query_friendly_player(object player)
{
  if(member_array(player->QRN,friendly_players) != -1)
  {
    return 1;
  }
  return 0;
}

// Is a player an enemy
int query_nasty_player(object player)
{
  if(member_array(player->QRN,nasty_players) != -1)
  {
    return 1;
  }
  return 0;
}

// Has the monster met the player without forming an opinion?
int query_met_player(object player)
{
  if(member_array(player->QRN,met_players) != -1)
  {
    return 1;
  }
  return 0;
}

int query_unknown_player(object player)
{
  if(member_array(player->QRN,friendly_players) != -1)
  {
    return 0;
  }

  if(member_array(player->QRN,nasty_players) != -1)
  {
    return 0;
  }

  if(member_array(player->QRN,met_players) != -1)
  {
    return 0;
  }
  return 1;
}

void add_friendly_player(object player)
{
  if(member_array(player->QRN,friendly_players) == -1)
  {
    friendly_players += ({player->QRN});
  }

  if(member_array(player->QRN,nasty_players) != -1)
  {
    nasty_players -= ({player->QRN});
  }

  if(member_array(player->QRN,met_players) != -1)
  {
    met_players -= ({player->QRN});
  }
}

void add_nasty_player(object player)
{
  if(member_array(player->QRN,nasty_players) == -1)
  {
    nasty_players += ({player->QRN});
  }

  if(member_array(player->QRN,friendly_players) != -1)
  {
    friendly_players -= ({player->QRN});
  }

  if(member_array(player->QRN,met_players) != -1)
  {
    met_players -= ({player->QRN});
  }
}

void add_met_player(object player)
{
  if(member_array(player->QRN,met_players) == -1)
  {
    met_players += ({player->QRN});
  }
}
