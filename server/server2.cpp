/* A simple server in the internet domain using TCP
 *  *    The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  struct sockaddr_in * serv_addr_pt;
    
  if (argc < 2) {
    cout<<"ERROR, no port provided"<<endl;
    exit(1);
  }

  // Open a socket on a given port
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (argc < 2) {
    perror("ERROR opening socket");
    exit(1);
  }

  serv_addr_pt = (sockaddr_in*) memset((char *) &serv_addr, 0,sizeof(serv_addr));
  portno = atoi(argv[1]); 
  /*serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);*/
  
  serv_addr_pt->sin_family = AF_INET;
  serv_addr_pt->sin_addr.s_addr = INADDR_ANY;
  serv_addr_pt->sin_port = htons(portno);

  if(bind(sockfd, (struct sockaddr *)serv_addr_pt, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }
  
  listen(sockfd, 5);

  return 1;
}
