/* Automatically generated by refactor.pl.
 *
 *
 * CMDNAME: newpass
 * CMDLEVEL: QCMD_SECURE | QCMD_AUTHED
 * CMDARGS: 3
 * CMDDESC: Change your password.
 * CMDFUNC: csa_donewpw
 * CMDPROTO: int csa_donewpw(void *source, int cargc, char **cargv);
 * CMDHELP: Usage: NEWPASS <oldpassword> <newpassword> <newpassword>
 * CMDHELP: Changes your account password.  Your new password must be at least 6 characters
 * CMDHELP: long, contain at least one number and one letter, and may not contain sequences
 * CMDHELP: of letters or numbers.  Your new password will be sent to your registered email
 * CMDHELP: address.  Where:
 * CMDHELP: oldpassword - your existing account password
 * CMDHELP: newpassword - your desired new password.  Must be entered the same both times.
 * CMDHELP: Note: due to the sensitive nature of this command, you must send the message to
 * CMDHELP: Q@CServe.quakenet.org when using it.
 */

#include "../chanserv.h"
#include "../authlib.h"
#include "../../lib/irc_string.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int csa_donewpw(void *source, int cargc, char **cargv) {
  reguser *rup;
  nick *sender=source;
  int i, cntweak = 0, cntdigits = 0, cntletters = 0;

  if (cargc<3) {
    chanservstdmessage(sender, QM_NOTENOUGHPARAMS, "newpass");
    return CMD_ERROR;
  }

  if (!(rup=getreguserfromnick(sender)))
    return CMD_ERROR;

  if (!checkpassword(rup, cargv[0])) {
    chanservstdmessage(sender, QM_AUTHFAIL);
    cs_log(sender,"NEWPASS FAIL username %s bad password %s",rup->username,cargv[0]);
    return CMD_ERROR;
  }

  if (strcmp(cargv[1],cargv[2])) {
    chanservstdmessage(sender, QM_PWDONTMATCH); /* Sorry, passwords do not match */
    cs_log(sender,"NEWPASS FAIL username %s new passwords don't match (%s vs %s)",rup->username,cargv[1],cargv[2]);
    return CMD_ERROR;
  }

  if (strlen(cargv[1]) < 6) {
    chanservstdmessage(sender, QM_PWTOSHORT); /* new password to short */
    cs_log(sender,"NEWPASS FAIL username %s password to short %s (%d characters)",rup->username,cargv[1],strlen(cargv[1]));
    return CMD_ERROR;
  }

  for ( i = 0; cargv[1][i] && i < PASSLEN; i++ ) {
    if ( cargv[1][i] == cargv[1][i+1] || cargv[1][i] + 1 == cargv[1][i+1] || cargv[1][i] - 1 == cargv[1][i+1] )
      cntweak++;
    if(isdigit(cargv[1][i]))
      cntdigits++;
    if(islower(cargv[1][i]) || isupper(cargv[1][i]))
      cntletters++;
  }

  if( cntweak > 3 || !cntdigits || !cntletters) {
    chanservstdmessage(sender, QM_PWTOWEAK); /* new password is weak */
    cs_log(sender,"NEWPASS FAIL username %s password to weak %s",rup->username,cargv[1]);
    return CMD_ERROR;
  }

  setpassword(rup, cargv[1]);
  rup->lastauth=time(NULL);
  chanservstdmessage(sender, QM_PWCHANGED);
  cs_log(sender,"NEWPASS OK username %s", rup->username);
  csdb_updateuser(rup);
  csdb_createmail(rup, QMAIL_NEWPW);

  return CMD_OK;
}
