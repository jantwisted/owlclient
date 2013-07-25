#include "common.h"

void xterm(int sockfd)
{
  char s[400];
  int c;
  while(1){
    fputs("owl> ",stdout);
    fgets(s,400,stdin);
    if(strcasecmp(s,"quit\n")==0)
      break;
    if(strcmp(s,"\n")!=0)
      xcommand(s);   
      
  }
}
