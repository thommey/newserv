/* Automatically generated by mkcommandlist.pl, do not edit. */

#include "../chanserv.h"

/* Prototypes */
int csc_doaddchan(void *source, int cargc, char **cargv);
int csc_doadduser(void *source, int cargc, char **cargv);
int csc_doautolimit(void *source, int cargc, char **cargv);
int csc_dopermban(void *source, int cargc, char **cargv);
int csc_dobanclear(void *source, int cargc, char **cargv);
int csc_dobandel(void *source, int cargc, char **cargv);
int csc_dobanlist(void *source, int cargc, char **cargv);
int csc_dobantimer(void *source, int cargc, char **cargv);
int csc_dochanflags(void *source, int cargc, char **cargv);
int csc_dochanlev(void *source, int cargc, char **cargv);
int csc_dochanlevhistory(void *source, int cargc, char **cargv);
int csc_dochanmode(void *source, int cargc, char **cargv);
int csc_dochannelcomment(void *source, int cargc, char **cargv);
int csc_dochanophistory(void *source, int cargc, char **cargv);
int csc_dochanstat(void *source, int cargc, char **cargv);
int csc_dochantype(void *source, int cargc, char **cargv);
int csc_doclearchan(void *source, int cargc, char **cargv);
int csc_dodelchan(void *source, int cargc, char **cargv);
int csc_dodeopall(void *source, int cargc, char **cargv);
int csc_dodevoiceall(void *source, int cargc, char **cargv);
int csc_dogiveowner(void *source, int cargc, char **cargv);
int csc_doinvite(void *source, int cargc, char **cargv);
int csc_doop(void *source, int cargc, char **cargv);
int csc_dopermban(void *source, int cargc, char **cargv);
int csc_dorecover(void *source, int cargc, char **cargv);
int csc_dorejoin(void *source, int cargc, char **cargv);
int csc_doremoveuser(void *source, int cargc, char **cargv);
int csc_dorenchan(void *source, int cargc, char **cargv);
int csc_dorequestowner(void *source, int cargc, char **cargv);
int csc_dorollbackchan(void *source, int cargc, char **cargv);
int csc_dosettopic(void *source, int cargc, char **cargv);
int csc_dosuspendchan(void *source, int cargc, char **cargv);
int csc_dosuspendchanlist(void *source, int cargc, char **cargv);
int csc_dotempban(void *source, int cargc, char **cargv);
int csc_dobandel(void *source, int cargc, char **cargv);
int csc_dounbanall(void *source, int cargc, char **cargv);
int csc_dounbanmask(void *source, int cargc, char **cargv);
int csc_dounbanme(void *source, int cargc, char **cargv);
int csc_dounsuspendchan(void *source, int cargc, char **cargv);
int csc_dovoice(void *source, int cargc, char **cargv);
int csc_dowelcome(void *source, int cargc, char **cargv);

void _init() {
  chanservaddcommand("addchan", QCMD_OPER, 4, csc_doaddchan, "Adds a new channel to the bot.", "Usage: addchan <channel> [<owner> [<flags> [<type>]]]\nAdds the given channel to the bot, where:\nowner - can be either nickname on the network or #authname.  If not supplied,\n        the channel will belong to the user issuing the ADDCHAN command.\nflags - can be any valid chanflags (see CHANFLAGS).  If not specified this \n        defaults to +j.\ntype  - is a channel type as per old Q and is now obsolete.\n");
  chanservaddcommand("adduser", QCMD_AUTHED, 20, csc_doadduser, "Adds one or more users to a channel as +aot.", "Usage: ADDUSER <channel> [<flags>] <user1> [<user2> [<user3> [...]]]\nAdds the named user(s) to the channel, where:\nchannel - the channel to use\nflags   - the list of flags to add for each user, introduced by + (for example\n          +gv).  See CHANLEV for valid flags.  If no flags are specified, \n          +aot is used.  This command cannot be used to add masters (+m) or\n          owners (+n).\nuser<n> - either a user's current nickname on the network or #accountname. Up to\n          18 users can be specified.\nADDUSER requires master (+m) access on the named channel.\n");
  chanservaddcommand("autolimit", QCMD_AUTHED, 2, csc_doautolimit, "Shows or changes the autolimit threshold on a channel.", "Usage: AUTOLIMIT <channel> [<threshold>]\nThis command shows or changes the number of free slots to keep on the channel\nwhen autolimit (see CHANFLAGS) is enabled.  Where:\nchannel   - the channel to use.\nthreshold - specifies the new threshold.  If not specified, the current threshold \n            is displayed.\nViewing the current threshold requires operator (+o) access on the named channel.\nUpdating the threshold requires master (+m) access on the named channel.\n");
  chanservaddcommand("ban", QCMD_AUTHED | QCMD_ALIAS, 3, csc_dopermban, "Permanently bans a hostmask on a channel.", "Usage: BAN <channel> <hostmask> [<reason>]\nPermanently bans the provided hostmask on the channel.  If the ban is\nremoved from the channel e.g. by a channel op or the BANTIMER feature, the\nban will be reapplied if a matching user joins the channel.  Bans\nset with the PERMBAN command can be removed via BANCLEAR or BANDEL.  Any users\nmatching the hostmask will be kicked from the channel.\nWhere:\nchannel  - channel to set a ban on\nhostmask - hostmask (nick!user@host) to ban.\nreason   - reason for the ban.  This will be used in kick messages when kicking\n           users matching the ban.  If this is not provided the generic message\n           \"Banned.\" will be used.\nBAN requires master (+m) access on the named channel.\nBAN is an alias for PERMBAN.\n");
  chanservaddcommand("banclear", QCMD_AUTHED, 1, csc_dobanclear, "Removes all bans from a channel including persistent bans.", "Usage: BANCLEAR <channel>\nRemoves all temporary and persistent bans from a channel, where:\nchannel - the channel to use\nBANCLEAR requires master (+m) access on the named channel.\n");
  chanservaddcommand("bandel", QCMD_AUTHED, 2, csc_dobandel, "Removes a single ban from a channel.", "Usage: BANDEL <channel> <ban>\nRemoves the specified persistent or channel ban, where:\nchannel - the channel to use\nban     - either a ban mask (nick!user@host), or #number (see BANLIST)\nRemoving channel bans requires operator (+o) access on the named channel.\nRemoving persistent bans requires master (+m) access on the named channel.\n");
  chanservaddcommand("banlist", QCMD_AUTHED, 1, csc_dobanlist, "Displays all persistent bans on a channel.", "Usage: BANLIST <channel>\nDisplays a list of persistent and channel bans on the named channel.  Each ban\nis identified by a number which can be passed to a subsequent BANDEL command.\nNote that the numbers can change if bans are added to or removed from the \nchennel. Where:\nchannel - the channel to use\nBANLIST requires operator (+o) access on the named channel.\n");
  chanservaddcommand("bantimer", QCMD_AUTHED, 2, csc_dobantimer, "Shows or changes the time after which bans are removed.", "Usage: BANTIMER <channel> [<duration>]\nTo help keep channels clear of the clutter of too many bans, Q can automatically\nremove channel bans after a specified time.  This command is used to alter that\ntime period, disable the feature, or show the current setting, where:\nchannel  - the channel to use\nduration - how long to remove channel bans after.  If duration is 0 then channel\n           bans will not be automatically removed.  If duration is not specified,\n           the current setting will be displayed.  Suffixes can m (minutes), \n           h (hours), d (days), w (weeks), M (months) and y (years) can be used \n           to specify the duration, for example 3d, 1w, 1h30m.\nViewing the current setting requires operator (+o) access on the named channel.\nChanging the setting requires master (+m) access on the named channel.\n");
  chanservaddcommand("chanflags", QCMD_AUTHED, 2, csc_dochanflags, "Shows or changes the flags on a channel.", "Usage: CHANFLAGS <channel> [<changes>]\nShows or changes the status of channel flags, where:\nchannel - channel to use\nchanges - changes to apply to the channel flags in the usual +/- format, e.g. +c\n          to set +c and -c to remove it.\nViewing the current flags requires operator (+o) access on the named channel.\nChanging the flags requires master (+m) access on the named channel.\nValid channel flags are:\n +a AUTOOP     Automatically ops any user who has op access when they join the\n               channel.  Same effect as giving all ops the +a chanlev flag.\n +b BITCH      Prevents users who don't have operator access on the channel\n               from being opped (automatically deops them)\n +c AUTOLIMIT  Enables automatic limit feature - updates the channel limit at\n               regular intervals to keep a certain number of free spaces.  This\n               can mitigate the effect of join floods.  See AUTOLIMIT.\n +e ENFORCE    Enforces bans on the channel.  Any user who is banned will be\n               kicked automatically.\n +f FORCETOPIC Prevents channel ops from changing the topic.  The SETTOPIC\n               command must be used instead.\n +g AUTOVOICE  Automatically voices any user who has voice access when they join\n               the channel.  Same effect as giving all voices the +g chanlev flag.\n +j JOINED     Causes Q to remain on the channel.  Cannot be removed.\n +k KNOWNONLY  Any user who joins the channel who is not known (+k) will be kicked.  \n               Unless channel mode +i is set they will be banned as well.\n +p PROTECT    Any user with voice (+v) or operator (+o) access will have that \n               status enforced on the channel at all times.  Same effect as giving\n               all ops and voices the +p chanlev flag.\n +t TOPICSAVE  Saves the topic when it changes.  Such saved topics can be restored\n               via settopic, or when the bot rejoins when a channel has been left\n               empty.\n +v VOICEALL   Automatically grants voice (+v) on the channel to any user who enters,\n               unless they have quiet (+q) chanlev flag.\n +w WELCOME    Sends the welcome message to users joining the channel.  See WELCOME.\nNote: Previous versions of Q included the facility to enforce limits and keys using\n+k and +l chanflags.  This functionality is now available via the CHANMODE command.\n");
  chanservaddcommand("chanlev", QCMD_AUTHED, 3, csc_dochanlev, "Shows or modifies user access on a channel.", "Usage: CHANLEV <channel> [<user> [<change>]]\nDisplays or alters the access of known users on a channel, where:\nchannel - the channel to use\nuser    - the user to list or modify.  user can be specified as either an active\n          nickname on the network or #accountname.  If user is not specified then\n          all known users are listed.\nchange  - lists the flags to add or remove, with + to add or - to remove.  For\n          example, +ao to add a and o flags, or -gv to remove g and v flags.  This \n          can be used to add or remove users from the channel.  If change is not\n          specified then the current access of the named user is displayed.\nDisplaying known user information requires you to be known (+k) on the named channel.\nAdjusting flags for other users requires master (+m) access on the named channel.\nAdding or removing the +m flag for other users requires owner (+n) access on the \n named channel.\nYou may always remove your own flags, except +qdb flags (which are not visible to you).\nAdding or removing personal flags requires you to be known (+k) on the named channel.\nNote that channel owners (+n) can grant +n to channel masters but they must use \nthe GIVEOWNER command for this.\nThe access level flags determine which commands a user is allowed to use on a channel.\nHolding an access flag also grants access to any action requiring a lesser flag (e.g.\n+m users can perform actions requiring operator (+o) status even if they do not\nactually have +o set).  The access flags are listed in descending order.\nValid flags are:\nAccess level flags - these control the user's overall privilege level on the channel:\n +n OWNER     Can add or remove masters and all other flags (except personal flags)\n +m MASTER    Can add or remove all access except master or owner\n +o OP        Can get ops on the channel\n +v VOICE     Can get voice on the channel\n +k KNOWN     Known on the channel - can get invites to the channel via INVITE\nPunishment flags - these restrict the user on the channel in some way:\n +q DEVOICE   Not allowed to be voiced on the channel\n +d DEOP      Not allowed to be opped on the channel\n +b BANNED    Banned from the channel\nExtra flags - these control specific behaviour on the channel:\n +a AUTOOP    Ops the user automatically when they join the channel (the user \n              must also hold +o in order to have this flag)\n +g AUTOVOICE Voices the user automatically when they join the channel (the \n              user must also hold +v in order to have this flag)\n +p PROTECT   If the user has +o or +v, this makes sure they will always have\n              that status, they will be reopped/voiced if deopped/voiced\n +t TOPIC     Can use SETTOPIC to alter the topic on the channel\nPersonal flags - these control user personal preferences and can only be changed\n                 by the user concerned.  They are not visible to other users.\n +w NOWELCOME Prevents the welcome message being sent when you join the channel.\n +j AUTOINV   Invites you to the channel automatically when you authenticate.\nNote that non-sensible combinations of flags are not allowed.  After making a \nchange the current status of the named user on the channel will be confirmed.\n");
  chanservaddcommand("chanlevhistory", QCMD_HELPER, 2, csc_dochanlevhistory, "View user access changes on a channel.", "");
  chanservaddcommand("chanmode", QCMD_AUTHED, 4, csc_dochanmode, "Shows which modes are forced or denied on a channel.", "Usage: CHANMODE <channel> [<modes>]\nShows or changes the list of channel modes being enforced on the channel, where:\nchannel  - the channel to use\nmodes    - the list of modes to allow or deny.  Modes specified with + will be\n           enforced on the channel at all times, those specified with - will not\n           be allowed on the channel.  If modes are not specified the current\n           setting will be displayed.  If +k or +l modes are included, the actual\n           key or limit to be enforced must also be specified, for example \n           \"-il+ntk mykey\", or \"+nstl-Cc 20\".  If you do not want any modes\n           enforced, \"CHANMODE <channel> +\" will clear the list.\nViewing the enforced modes requires operator (+o) access on the named channel.\nUpdating the enforced modes requires master (+m) access on the named channel.\nNote: unlike similar commands that work on flags, specifying modes REPLACES\nthe list of modes to be enforced rather than changing the existing list.  This \nis because - modes are valid as well as + modes.  Thus whenever you specify \nthe modes argument you must provide the complete list of desired modes each\ntime.\nNote: if autolimit is enabled (see CHANFLAGS) it will cause a +l limit mode\nto be enforced, with the value updating periodically as users join and leave.\nThis +l forcing cannot be changed or overridden without disabling the autolimit\nfunction using the CHANFLAGS command.\n");
  chanservaddcommand("channelcomment", QCMD_OPER, 2, csc_dochannelcomment, "Shows or changes the staff comment for a channel.", "");
  chanservaddcommand("chanophistory", QCMD_AUTHED, 1, csc_dochanophistory, "Displays a list of who has been opped on a channel recently with account names.", "Usage: CHANOPHISTORY <channel>\nDisplays a list of users who have recently been opped on a channel by the\nservice, along with the account name responsible for the opping.  Usually\nthis is the account the user being opped was using, but in the case of the \nOP command being used to op other users, the account used by the user issuing\nthe OP command will be shown.  Where:\nchannel  - the channel to use\nCHANOPHISTORY requires operator (+o) access on the named channel.\n");
  chanservaddcommand("chanstat", QCMD_AUTHED, 1, csc_dochanstat, "Displays channel activity statistics.", "Usage: CHANSTAT <channel>\nShows some statistics about a channel, including total number of joins and \nmaximum channel size.  Two sets of statistics are displayed, a lifetime\ncounter, and a trip meter counter which can be reset.  Where:\nchannel - channel to display statistics for.\nCHANSTAT requires master (+m) access on the named channel.\n");
  chanservaddcommand("chantype", QCMD_OPER, 2, csc_dochantype, "Shows or changes a channel's type.", "");
  chanservaddcommand("clearchan", QCMD_AUTHED, 1, csc_doclearchan, "Removes all modes from a channel.", "Usage: CLEARCHAN <channel>\nRemoves all channel modes (such as keys, limits, invite only, etc.) from\nthe named channel.  Modes being enfored (see CHANMODE) will not be removed.\nWhere:\nchannel - channel to remove modes from\nCLEARCHAN requires master (+m) access on the named channel.\n");
  chanservaddcommand("delchan", QCMD_OPER, 2, csc_dodelchan, "Removes a channel from the bot.", "");
  chanservaddcommand("deopall", QCMD_AUTHED, 1, csc_dodeopall, "Deops all users on channel.", "Usage: DEOPALL <channel>\nDeops every user in the channel.  Registered channel operators (+o on CHANLEV) \nwho are protected (via the +p flag in CHANLEV or CHANFLAGS) will not be deopped.\nWhere:\nchannel - channel to use\nDEOPALL requires master (+m) access on the named channel.\n");
  chanservaddcommand("devoiceall", QCMD_AUTHED, 1, csc_dodevoiceall, "Devoices all users on a channel.", "Usage: DEVOICEALL <channel>\nDevoices all users in the channel.  Registered voices (+v on CHANLEV) who are \nprotected (+p flag set in CHANLEV or CHANFLAGS) will not be devoiced.\nDEVOICEALL requires master (+m) access on the named channel.\n");
  chanservaddcommand("giveowner", QCMD_AUTHED, 3, csc_dogiveowner, "Gives total control over a channel to another user.", "Usage: GIVEOWNER <channel> <user> [<code>]\nGives complete control (+n flag) to the named user on the channel.  The new owner\nwill have full control over the channel, including the ability to remove the\nexisting owner(s).  As a precaution the named user must already have master (+m) \naccess on the channel.  Use this command with extreme caution.  Where:\nchannel - channel to use\nuser    - user to give owner to, either a nickname on the network or #accountname.\ncode    - a unique code used to authorize the operation.  If the code is not \n          supplied, the appropriate code will be provided together with a \n          warning about the dangers of this command.  If the wrong code is\n          entered owner access will not be granted.\nGIVEOWNER requires owner (+n) access on the named channel.\n");
  chanservaddcommand("invite", QCMD_AUTHED, 1, csc_doinvite, "Invites you to a channel.", "Usage: INVITE <channel>\nInvites you to the named channel, where:\nchannel - channel to be invited to.\nINVITE requires you to be known (+k) on the named channel.\n");
  chanservaddcommand("op", QCMD_AUTHED, 20, csc_doop, "Ops you or other users on channel(s).", "Usage: OP [<channel> [<user1> [<user2> [...]]]\nOps you on one or more channels, or ops other named users on a given channel.\nThis command cannot be used to op users who are otherwise prevented from getting\nops, e.g. via the +d chanlev flag (see CHANLEV) or bitch mode (see CHANFLAGS).\nWhere:\nchannel - channel to use.  If no channel is specified, you will be given ops on\n          every channel where you have appropriate access and are not already\n          opped.\nuser<n> - user(s) to op instead of yourself.  Each user must be specified as the\n          current nickname of a user on the named channel.\nOP requires operator access (+o) on the named channel.  If this command is used\nto op other users, a notice will be sent to other channel operators on the \nchannel identifying you, unless you have master (+m) access.\n");
  chanservaddcommand("permban", QCMD_AUTHED, 3, csc_dopermban, "Permanently bans a hostmask on a channel.", "Usage: PERMBAN <channel> <hostmask> [<reason>]\nPermanently bans the provided hostmask on the channel.  If the ban is\nremoved from the channel e.g. by a channel op or the BANTIMER feature, the\nban will be reapplied if a matching user joins the channel.  Bans\nset with the PERMBAN command can be removed via BANCLEAR or BANDEL.  Any users\nmatching the hostmask will be kicked from the channel.\nWhere:\nchannel  - channel to set a ban on\nhostmask - hostmask (nick!user@host) to ban.\nreason   - reason for the ban.  This will be used in kick messages when kicking\n           users matching the ban.  If this is not provided the generic message\n           \"Banned.\" will be used.\nPERMBAN requires master (+m) access on the named channel.\n");
  chanservaddcommand("recover", QCMD_AUTHED, 1, csc_dorecover, "Recovers a channel (same as deopall, unbanall, clearchan).", "Usage: RECOVER <channel>\nThis command resets the named channel if undesired modes, bans or ops have been\nset.  This has the same effect as DEOPALL followed by UNBANALL followed by\nCLEARCHAN on the channel, where:\nchannel - channel to recover\nRECOVER requires master (+m) access on the named channel.\n");
  chanservaddcommand("rejoin", QCMD_OPER, 1, csc_dorejoin, "Makes the bot rejoin a channel.", "");
  chanservaddcommand("removeuser", QCMD_AUTHED, 20, csc_doremoveuser, "Removes one or more users from a channel.", "Usage: REMOVEUSER <channel> <user1> [<user2> [<user3> [...]]]\nRemoves any flags the named user(s) have on the channel.  This command\ncannot be used to remove owners (+n) from the channel, and cannot be used\nto remove masters (+m) unless the user issuing the command is an owner.\nWhere:\nchannel - channel to use\nuser<n> - a user to remove.  Can either be a nickname on the network\n          or #authname.  Up to 18 users can be specified.\nREMOVEUSER requires master (+m) access on the named channel.\n");
  chanservaddcommand("renchan", QCMD_OPER, 2, csc_dorenchan, "Renames a channel on the bot.", "");
  chanservaddcommand("requestowner", QCMD_AUTHED, 1, csc_dorequestowner, "Requests ownership of a channel on which there are no owners.", "Usage: requestowner <channel>\nRequests owner (+n) access to the named channel.  In order to use this command,\nthere must be no owners left on the channel, and you must have the highest\naccess level of the remaining users.  Where:\nchannel - the channel to request ownership of\n");
  chanservaddcommand("rollbackchan", QCMD_OPER, 3, csc_dorollbackchan, "Roll back access changes on a channel.", "");
  chanservaddcommand("settopic", QCMD_AUTHED, 2, csc_dosettopic, "Changes the topic on a channel.", "Usage: SETTOPIC <channel> [<topic>]\nChanges the topic on the channel, where:\nchannel - channel to use\ntopic   - new topic.  If no topic is set, the stored topic will be reset (this\n          feature is useful if some users can no longer see the topic due to a \n          netsplit).\nSETTOPIC requires topic (+t) or master (+m) access on the named channel.\n");
  chanservaddcommand("suspendchan", QCMD_OPER, 2, csc_dosuspendchan, "Suspends a channel from the bot.", "");
  chanservaddcommand("suspendchanlist", QCMD_HELPER, 1, csc_dosuspendchanlist, "Lists suspended channels.", "");
  chanservaddcommand("tempban", QCMD_AUTHED, 4, csc_dotempban, "Bans a hostmask on a channel for a specified time period.", "Usage: TEMPBAN <channel> <hostmask> <duration> [<reason>]\nTemporarily bans the provided hostmask on the channel.  If the ban is\nremoved from the channel e.g. by a channel op or the BANTIMER feature, the\nban will be reapplied if a matching user joins the channel.  When the time \nexpires the ban will be removed automatically.  Bans set with the TEMPBAN \ncommand can be removed via BANCLEAR or BANDEL.  Any users matching the hostmask \nwill be kicked from the channel.\nWhere:\nchannel  - channel to set a ban on\nhostmask - hostmask (nick!user@host) to ban.\nduration - length of time to apply the ban for.  Suffixes m (minutes), h (hours),\n           d (days), w (weeks), M (months) and y (years) can be used to specify \n           the duration, for example 3d, 5h, 1h30m, 1M.\nreason   - reason for the ban.  This will be used in kick messages when kicking\n           users matching the ban.  If this is not provided the generic message\n           \"Banned.\" will be used.\nTEMPBAN requires master (+m) access on the named channel.\n");
  chanservaddcommand("unban", QCMD_AUTHED | QCMD_ALIAS, 2, csc_dobandel, "Removes a single ban from a channel.", "Usage: UNBAN <channel> <ban>\nRemoves the specified persistent or channel ban, where:\nchannel - the channel to use\nban     - either a ban mask (nick!user@host), or #number (see BANLIST)\nRemoving channel bans requires operator (+o) access on the named channel.\nRemoving persistent bans requires master (+m) access on the named channel.\nUNBAN is an alias for BANDEL.\n");
  chanservaddcommand("unbanall", QCMD_AUTHED, 1, csc_dounbanall, "Removes all bans from a channel.", "Usage: UNBANALL <channel>\nRemoves all the channel bans set on the named channel.  This does not affect\npersistent bans set via the TEMPBAN and PERMBAN commands, see BANCLEAR or\nBANDEL for more information on removing those bans.  Where:\nchannel - channel to use\nUNBANALL requires master (+m) access on the named channel.\n");
  chanservaddcommand("unbanmask", QCMD_AUTHED, 2, csc_dounbanmask, "Removes bans matching a particular mask from a channel.", "Usage: UNBANMASK <channel> <mask>\nRemoves any bans on the channel which are overlapped by the named mask.  Can\nremove both channel bans and registered bans.  Where:\nchannel - channel to use\nmask    - mask to remove.  Any ban subsumed by this mask will be removed.  For\n          example, UNBANMASK *!*@*.isp.net would remove *!*@host1.isp.net and \n          *!*@host2.isp.net and *!user@*.isp.net.\nUNBANMASK requires operator (+o) access on the named channel.\nRemoving registered bans requires master (+m) access on the named channel.\n");
  chanservaddcommand("unbanme", QCMD_AUTHED, 1, csc_dounbanme, "Removes any bans affecting you from a channel.", "Usage: UNBANME <channel>\nThis command removes any channel bans which affect you from a channel.  It does\nnot affect persistent bans set by PERMBAN and TEMPBAN.  Where:\nchannel - channel to use\nUNBANME requires operator (+o) access on the named channel.\n");
  chanservaddcommand("unsuspendchan", QCMD_OPER, 1, csc_dounsuspendchan, "Unsuspends a channel from the bot.", "");
  chanservaddcommand("voice", QCMD_AUTHED, 20, csc_dovoice, "Voices you or other users on channel(s).", "Usage: VOICE [<channel> [<user1> [<user2> [...]]]\nGrants voice to you on one or more channels, or grants voice to one or more\nother users on a particular channel.  This command cannot be used to grant\nvoice to users who would otherwise be prevented from obtaining voice, e.g.\nthe quiet (+q) chanlev flag.  Where:\nchannel - channel to use.  If no channel is specified, you will be granted voice\n          on every channel where you have appropriate access and are not already \n          voiced.\nuser<n> - other users to grant voice to.  Must be specified as the nickname\n          of users who are on the named channel.\nVoicing yourself requires voice (+v) access on the relevant channels.\nVoicing other users requires operator (+o) access on the named channel.  If this \ncommand is used to voice other users, a notice will be sent to channel operators\non the channel identifying you, unless you have master (+m) access.\n");
  chanservaddcommand("welcome", QCMD_AUTHED, 2, csc_dowelcome, "Shows or changes the welcome message on a channel.", "Usage: WELCOME <channel> [<message>]\nThis shows the current welcome message set on a channel and allows it to be\nchanged.  In order to be displayed to users, the feature must be enabled\nby the +w chanflag (see CHANFLAGS).  Where:\nchannel - channel to use\nmessage - welcome message to set.  If this is not provided the existing welcome\n          message is displayed.\nDisplaying the message requires operator (+o) access on the named channel.\nChanging the message requires master (+m) access on the named channel.\n");
}

void _fini() {
  chanservremovecommand("addchan", csc_doaddchan);
  chanservremovecommand("adduser", csc_doadduser);
  chanservremovecommand("autolimit", csc_doautolimit);
  chanservremovecommand("ban", csc_dopermban);
  chanservremovecommand("banclear", csc_dobanclear);
  chanservremovecommand("bandel", csc_dobandel);
  chanservremovecommand("banlist", csc_dobanlist);
  chanservremovecommand("bantimer", csc_dobantimer);
  chanservremovecommand("chanflags", csc_dochanflags);
  chanservremovecommand("chanlev", csc_dochanlev);
  chanservremovecommand("chanlevhistory", csc_dochanlevhistory);
  chanservremovecommand("chanmode", csc_dochanmode);
  chanservremovecommand("channelcomment", csc_dochannelcomment);
  chanservremovecommand("chanophistory", csc_dochanophistory);
  chanservremovecommand("chanstat", csc_dochanstat);
  chanservremovecommand("chantype", csc_dochantype);
  chanservremovecommand("clearchan", csc_doclearchan);
  chanservremovecommand("delchan", csc_dodelchan);
  chanservremovecommand("deopall", csc_dodeopall);
  chanservremovecommand("devoiceall", csc_dodevoiceall);
  chanservremovecommand("giveowner", csc_dogiveowner);
  chanservremovecommand("invite", csc_doinvite);
  chanservremovecommand("op", csc_doop);
  chanservremovecommand("permban", csc_dopermban);
  chanservremovecommand("recover", csc_dorecover);
  chanservremovecommand("rejoin", csc_dorejoin);
  chanservremovecommand("removeuser", csc_doremoveuser);
  chanservremovecommand("renchan", csc_dorenchan);
  chanservremovecommand("requestowner", csc_dorequestowner);
  chanservremovecommand("rollbackchan", csc_dorollbackchan);
  chanservremovecommand("settopic", csc_dosettopic);
  chanservremovecommand("suspendchan", csc_dosuspendchan);
  chanservremovecommand("suspendchanlist", csc_dosuspendchanlist);
  chanservremovecommand("tempban", csc_dotempban);
  chanservremovecommand("unban", csc_dobandel);
  chanservremovecommand("unbanall", csc_dounbanall);
  chanservremovecommand("unbanmask", csc_dounbanmask);
  chanservremovecommand("unbanme", csc_dounbanme);
  chanservremovecommand("unsuspendchan", csc_dounsuspendchan);
  chanservremovecommand("voice", csc_dovoice);
  chanservremovecommand("welcome", csc_dowelcome);
}
