#include "common.h"
int xconnect(char** ip, char** port)
{
  char temp[100]="connecting to ";
  // socket descriptor begins here
  int sockfd;
  struct sockaddr_in servaddr;
  sockfd = Socket(AF_INET, SOCK_STREAM, 0);
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(port));
  
  Inet_pton(AF_INET, ip, &servaddr.sin_addr);
  // socket descriptor ends here
  strcat(temp,ip);
  Fputs(temp, stdout);
  Fputs("\n",stdout);
  Connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
  //connect to the server
  return sockfd;
}
