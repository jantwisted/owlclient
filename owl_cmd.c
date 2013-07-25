#include "common.h"

void xcommand(char** str){
  char spacer[2]=" ";
  char* cmd;
  char* option;
  char* other;
  
  /* prepare parameters for xrun() */
  cmd = strtok(str, spacer);
  option = strtok(NULL, spacer);
  option = (option==NULL)?"default":option;
  other = strtok(NULL, spacer);
  other = (other==NULL)?"default":other;
  /*call xrun()*/
  xrun(cmd, option, other);
}
