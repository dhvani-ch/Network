#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>

int main()
{

int sockfd, n, retval;
pid_t childpid;
socklen_t clilen;
char buf[10000];
struct sockaddr_in cliaddr, servaddr;

sockfd = socket(AF_INET, SOCK_DGRAM, 0);
if(sockfd < 0)
{
	perror("sock");
	exit(1);
}

bzero(&servaddr, sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(8000);



//retval = bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
if(retval < 0)
{
	perror("bind:");
	exit(2);
}

//listen(listfd, 5);
printf("Socket bound to port 8000\n");
clilen = sizeof(struct sockaddr_in);

while(1)
{
	printf("before recvfrom\n");
	n = recvfrom(sockfd, buf, 10000, 0, (struct sockaddr *)&cliaddr, &clilen);
	printf("recv''d %d bytes\n ",n);
	printf("msg from client= %s\n", buf);
}

close(sockfd);

}
