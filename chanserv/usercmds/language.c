/* Automatically generated by refactor.pl.
 *
 *
 * CMDNAME: language
 * CMDLEVEL: QCMD_AUTHED
 * CMDARGS: 1
 * CMDDESC: Shows or changes your current language.
 * CMDFUNC: csu_dolanguage
 * CMDPROTO: int csu_dolanguage(void *source, int cargc, char **cargv);
 */

#include "../chanserv.h"
#include "../../lib/irc_string.h"
#include <stdio.h>
#include <string.h>

int csu_dolanguage(void *source, int cargc, char **cargv) {
  nick *sender=source;
  reguser *rup=getreguserfromnick(sender);
  char buf[300];
  int bufpos=0;
  int i;
  int len;

  if (!rup)
    return CMD_ERROR;

  if (cargc==0) {
    /* Display language */
    i=rup->languageid;
    chanservstdmessage(sender, QM_YOURLANGUAGE, cslanguages[i] ? cslanguages[i]->name->content : "Unknown");
    
    /* Display available lanaguages */
    chanservstdmessage(sender, QM_LANGUAGELIST);
    
    for (i=0;i<MAXLANG;i++) {
      if (cslanguages[i]) {
	if (bufpos > 70) {
	  chanservsendmessage(sender, "%s", buf);
	  bufpos=0;
	}
	len=sprintf(buf+bufpos, "%.14s (%.2s)",cslanguages[i]->name->content,cslanguages[i]->code);
	memset(buf+bufpos+len,' ',20-len);
	bufpos+=20;
	buf[bufpos]='\0';
      }
    }

    if (bufpos) 
      chanservsendmessage(sender, "%s", buf);

    chanservstdmessage(sender, QM_ENDOFLIST);
  } else {
    /* Set language */
    for (i=0;i<MAXLANG;i++) {
      if (cslanguages[i] && !ircd_strcmp(cargv[0],cslanguages[i]->code)) {
	/* Match. */
	rup->languageid=i;
	csdb_updateuser(rup);
	
	chanservstdmessage(sender, QM_DONE);
	chanservstdmessage(sender, QM_YOURLANGUAGE, cslanguages[i]->name->content);
	break;
      }
    }

    if (i==MAXLANG)
      chanservstdmessage(sender, QM_UNKNOWNLANGUAGE, cargv[0]);
  }
  
  return CMD_OK;
}