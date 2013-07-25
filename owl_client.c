#include "common.h"
int main(int argc, char** argv)
{
  // socket descriptor begins here
  int sockfd;
  struct sockaddr_in servaddr;
  sockfd = Socket(AF_INET, SOCK_STREAM, 0);
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(SERV_PORT);
	
  if(argc<2){
    xterm(sockfd);
  }else{
    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    // socket descriptor ends here
    Connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    //connect to the server
    //main task begins here
    //echo_client(stdin, sockfd);	
    echo_client(sockfd);	
  }
  //main task ends here	
  close(sockfd);
  return 0;
}
 
