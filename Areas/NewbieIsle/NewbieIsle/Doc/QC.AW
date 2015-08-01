Files added post-qc: 

Room/ferry.c :
		A little curious to why you do not use the standard ferry.
		Kingdoms is full of things like this ;)
		However it seems to work ok, and give a more unique feeling
		than the ferry. Ok. (Spelling I can't vouche for ;P)
	
Monster/boatman.c :
		Looks ok... added a space between . and *grumble* on line 118
		
Object/boat_object.c :
		I would have had a ENV()->recalculate_object_string()
		after I change the short desc, but that is perhaps
		not nessesary. On whole it looks Ok :)

Files redone completely post-qc: Room/troll_cave_out.c and troll_cave_in.c
                                 the 2.c and bk.c versions of these two are
                                 not in use and can be disregarded.

		Both these files looks ok to me.
Armour
------
	
mithril sack:	OK (would be nice if you could use as a sack too though;)
                ## There are holes in it! ;) ##

		# DONE #set_long should end with a "?"
		# DONE #line 67 wondeful->wonderful

		I dont think newbies should be allowed such good equipment.
		Will check with Dusk
               
                # Will talk with whoever it is that decides things like #
                # that these days about that # 

newbie_armour	OK

		Is it necessary to make this so that is cant be inned?
		# See below #
                Is it possible to save the value of i so that when they log
		on again, they get the same item?
		# I would have to create a mapping with the players names #
                # and save that and restore it from there or something. All #
                # the objects are clones of the same file, so I can't just #
                # save the objects, and the inn code does not support saving #
                # of object variables (to my knowledge at least). All in all #
                # i figured it will be too complicated to do for something #
                # that's as easy to get anyway as this is. #
                # Woops, just saw how you can use query_allow_login... #
                # Anyway, I think set_newbie() makes it uninnable too? #
                # The newbie weapons given for free elsewhere are uninnable #
                # though, so I think these should be too. It's not that #
                # hard to get some new stuff anyway #

                Hmm..when does set_me_to_armour get called?
                # The room creates one piece of armour that is of one of #
                # the *types types, randomly. I have also set it to create #
                # one piece that is 'armour' type, so that the newbie gets #
                # one 'armour' armour and another of a random other type #
                # That function is called from the room when the armour #
                # is cloned #

		Is set_newbie needed in create_object and in set_me_armour?
                # Shouldn't be. Removed it from set_me_armour #

Monsters
--------
animal		OK

		#line 33 it's->its
		#line 34,48 croas -> caws? 
		#line 36,62 trods->plods sounds better here
		#line 41 squrries->scurries
		#line 54 yells->yelps?  Strange for a rabbit to shout...
                # Changed the above

		Nice messages - looking forwards to watching this lot.

boatman		#DONE#Have missed a space in tell_room when you poke him between
		. and *grumble* (L69)

		not shipping anyone who hurt him until next reboot could
		be nasty with such long uptimes. Does this include if they
		actually kill him? Ah, they cant, unkillable.
                # Only people above level 4 will be turned away if they #
                # want to go after having tried to kill him. And people #
                # above level 4 don't really have much business being #
                # there anyway. If they want to kill him it serves them #
                # right : #
		
		I assume the add_action for poke is in the ferry?
                # It is in the boatman now that he is finished #

fisherman	Should he have a limit on the amount of lore he can teach
		up to a newbie limit?
                # The limit_here for lore is set to 50 which is about #
                # newbie limit. I can take it down to 47 if you think #
                # but those non-dividable-by-5-skill-raisers annoy me #

		#Done#line 351 where->were

		A free 10 lore - nice touch!

		unkillable
                # I hate it when people kill quest monsters just to #
                # screw others. Especially in newbie quests         #

spirit 		unkillable
                # It will only ever appear for like 2 seconds in a room #
                # and it would be silly to have people start fights with it #


troll		#Done# line 18 gray-> grey (gray is American)
		

troll_child	#Done#line 16 gray->grey
		#Hope it does now:)#line 29 doesnt make sense
		#Done#line 33 meking->making, bad->badly

troll_mod	line 39 it's ->its
                #Done#		

		When will a troll be outside at sunrise?
                #Trolls will come out and wander randomly at night, and #
                #return an hour before sunrise. If a troll meets a player #
                #while it's returning, it will stick around until the player #
                #leaves. If the sun comes up while this is happening, shame #
                # :). Also, if a child is just delayed enough, it won't #
                # make it back in time before the parents close the 'door' #
                # to the cave, and the children can't open it by themselves #
                # -> stone. It shouldn't happen too often... I don't really #
                # know without actual testing how often it will happen, but #
                # it is logged and I will tweak it as necessary when I get #
                # a chance to study them after the area has been open a #
                # while #

objects
-------

fish		#Done#line 23 real->really (horrible americanism)	
		#Done#line 24 should be some punctuation after "you"
		
stone_troll	wow he's heavy...
                #It's supposed to be! :)#

troll_controller	trolls going to your workroom?

		void turn_to_stone(void) {}   ????
		#This object was scrapped. The troll stuff is in #
                # /Master/troll_master.c and this file can be deleted #
	
Room
----
clearing	#Done#line 112 allready->already
		line 123 *LAUGH* I like the bit about mocking
		#Done#line 134,142,174,183
			 firewood takes fire->firewood catches fire
		#Done#line 171 of->off
		dragon	yes #The Dragon thing can probaby be removed. It #
                            #will never happen #
		hint	no  #The hint thing, however, might happen yet, so #
                            #that stuff can stay :) #

cottage_clearing
		#Done#line 19,33 real->really
		#Done#line 34 quite many of them -> quite a lot of them
		#Done#line 62 I think you need reset(arg) for door rooms.
		dragon	yes - See above
		hint	yes

den		OK

fisherman_cottage
		#Done#line 15	real->really
		#Done#line 86 curtain ->curtains
		dragon	yes	
		hint	no
		

fishing_stone	#Done#line 38 fishingpoles->fishing poles
		#Done#line 50 gray->grey
		#Done#line 56-57 disappear->disappearing
		#Done#line 86	you->You
		
		dragon	yes
		hint	yes

forest_edge	#Done#line 28 lay->lays
		#Done#line 62 of->off
		dragon	yes
		hint

path1		#Done#line 47 gray->grey
		dragon	yes
		hint	yes
		Maybe mention about "take a closer look" often means search
                # Added in the room hint #

path2		#Done#L108,115 There forest is not as dense here... errr...
		#Done#add_item rack and remove_item remains at reset of rack?	
		#Done#L165 second it's ->its		
		Add firewood?		
                # I had some ideas for a quest that involved making a raft #
                # I think I'll save this place for that if I get around to #
                # Doing it #
		dragon	yes
		hint	yes
		I like the reset of the rack -automagically :-)


shore1		Should there be a se exit as the shore extends to the se.
		No mention in the long of the nw exit
		#The 'southeast' in the desc was meant to be 'northwest' :) #
                #Done#L55 cradeled->cradled
                
		#Done#L63 double "." should be one or three
		dragon	yes
		hint	yes

shore2		#Done#L35 litterally->literally
		#Done#L52 The sea the lies <-that lies
		#Done#L140 "stack rocks against cliff" too please, 
		#Done#L146,L153 allready->already
		#Done#L185	finish->finishes
		#Done#L229 shouldnt end with "."
		dragon 	yes
		hint	yes		

	
shore3		#Done#L36	no->now
		L102	This sounds a bit strange if I'm not wearing trousers
			or leggings of any type.	
                #I don't know... I don't think too many people will think #
                #about that, and I think it adds something... whatever... #
                #If you think I should remove the pants thing or if I start #
                #getting bugreports about it, I will remove it ;) #

		dragon	yes
		hint	no

slope		
		dragon	yes
		hint	no


troll_cave	add_item troll
                #Players will be able to look at a troll if there are #
                # trolls here, and if not, they shouldn't be able to look #
                # at one ;) #

		you find a stick and mithril_sack here
		dragon	indoors
		hint	yes

troll_cave_in	#Done#L109	allready->already
		#Done#L132	"There more people"  ????
		#Done#L214    was covering rather than has covered

		Seems to be hard to get out of here... out doesnt work
		Open area before explore goes in to check this.
                # Has been redone and simplified #

		dragon	indoors
		hint	yes

troll_cave_out	#Done#L47 	try ->are trying
		#Done#L143	allready->already
		#Done#L164	this was ->it is
		#Done#L164 	There more people you ????
		#Done#L288 	the behind the
		

		Check both players are present when the rock actually moves.
		If someone casts unmind, the person leaves the room but still
		pushes, similarly with shift. Maybe you could use deny_leave 
		instead?
		Now we cant even move it between us...something is going 
		horribly wrong here,...
                # Has been redone and simplified #


		dragon	yes
		hint 	yes

troll_clearing	#Done# L17 surrounding it....around it. remove the "around it"
		#Done# L18	look->looks
		#Done# L28	reccomend->recommend
		#Done# L75 	allready->already
		#Done# L120	feet->foot
		#Done# L123	the light and stars get lighter?

		dragon	yes
		hint	yes

troll_hill	#Done#L16 	like if -> as if
		#Done#L38	to steep -> too steep
		#Done#L44	of->at

		dragon 	yes
		hint 	no

.troll_woods1	#Done#no pine|pine trees, pine needles, here,troll footprint

		#Done#L38, L41, L48 two add_items for boulder and rock
		#Done#You can almost hear.... no listen??

		#Done#trail to viewpoint is southwest but in the set_long
		      it says southeast

		dragon	yes
		hint	yes

.troll_woods2	#Done#no pine tree,pine needle, pine needles, woods 

		#Done#L13 groing->growing

		dragon	yes
		hint	no


.troll_woods3	#Done#AI no pine, pines, pine tree,water (you hear it..maybe 
		it's here)
		#Done#L27 grow->grows

		#Done#no listen although you think you hear....
		#Done#L15 noticeably->noticeable

		dragon 	yes
		hint	no

.troll_woods4	#Done#L11 and->an
		dragon 	yes
		hint 	no

*.troll_woods5	OK
		dragon 	yes
		hint 	yes

.troll_woods6	#Done#L107 You have been drinking - You have drunk
		L100 comming ->coming
		dragon	yes
		hint	yes
	

.troll_woods7	#Done#L41 .. after pond and before Strange.
		dragon 	yes
		hint 	yes

.troll_woods8	#Done#AI troll footprint
		dragon	yes
		hint	no

.troll_woods9	#Done#AI water (same as brook?)


viewpoint	#Done#climb cliff

Weapons
-------
fishing_pole	This is a FUN weapon. I love it.

newbie_weapon	OK. Isnt there some function to say why it cant be inned?
                # Don't know, and noone else here now does either. Will #
                # look into it #

twisted_stick	I think it should have it's correct property, and that being
		for newbies only doesnt mean it should have property poor.
		Should be average.
                #Done#





Extra notes added by Lapsus

fishing_stone  	lack a ' ' when trying to fish w/o a pole 'pole hehas.'
		no add_item sand (might not be needed, 'sandy bottom')
		shouldn't there be some kind of punctuation mark (or whatever)
		in A fish jumps out of the water a yard from the stone disappears under the surface again with a *plask*
		#Done#
                you can drop your pole after you have started fishing, someone
		else can pick it up, and you still catch fish..
                ## The check for having a pole and wielding it added to all three ##
                ## steps in the fishing sequence ##

shore2		praise: real cool idea about stacking. When you climb up there
		is a . too much for the others that see you climb up from beach
		though
                #Done#

slope		additem bushes, the should be them. 'strange bush' isn't additem
                #Done#

clearing	uhm, just me being annoying. You can 'sit log' then 'rest log'
		and don't have to stand up in between.. 
                #I'll live with that ;)#
                ## I can sit on a log and then rest on it without standing up ##
                ## in real life too ;) ##

path2		second sentence in longdesc The, not There. Too bad no wood was
		here for fireplace.. ;o) real cool idea with rack though. :o)
                #Done# and #See above#

























