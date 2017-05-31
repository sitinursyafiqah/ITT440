#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>

int main()
{
	
	int connectionFd, in;
	struct sockaddr_in servaddr;
	char timebuffer[MAX_BUFFER+1];
	int socket;
	struct sockaddr_in localaddr, sockaddr_in peeraddr, in_addr in;
	int la_len, ret;
	int sock, ret, size, len;
	char hostbuffer[MAX_HOSTNAME+1]
	int ret;
	struct hostent *hp;


	connectionFd= socket(AF_INET, SOCK_STREAM, 0);

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family= AF_INET;
	servaddr.sin_port= htons(DAYTIME_SERVER_PORT);
	
	servaddr.sin_addr.s_addr= inet_addr("127.0.0.1");

	connect(connectionFd,
		(struct sockaddr_in *) &servaddr,
		sizeof(servaddr));
	
	while((in= read(connectionFd, timebuffer,
		MAX_BUFFER))>0){

	timebuffer[in]=0;
	printf("\n%s",timebuffer);

	}

	la_len= sizeof(localaddr);
	ret= getsockname(socket, struct sockaddr_in *)&localaddr, &la_len);
	if(ret==0){
	printf("Local Address is: %s\n", inet_ntoa(localaddr.sin_addr));
	printf("Local Port is: %d\n", localaddr.sin_port);
	}

	la_len= sizeof(peeraddr);
	ret= getpeername(socket, struct sockaddr_in *)&peeraddr, &la_len);
	if(ret==0){
	printf("Peer Address is: %s\n", inet_ntoa(peeraddr.sin_addr));
	printf("Peer Port is: %d\n", peeraddr.sin_port);
	}

	sock= socket (AF_INET, SOCK_STREAM, 0);
	len=sizeof(size);
	ret= getsockopt (sock, SOL_SOCKET, SO_SNDBUF, (void *)&size, (socklen_t *)&len);
	size= size *2;
	ret= setsockopt (sock, SOL_SOCKET, SO_SNDBUF, (void *)&size, sizeof(size));

	ret= gethostname (hostbuffer, MAX_HOSTNAME);
	if(ret==0){
		printf("Host name is %s\n", hostbuffer);
	}
	
	strcpy(hostbuffer, "Elise");
	ret= sethostname (hostbuffer, strlen(hostbuffer));
	if(ret ==0){
		printf("Host name is now %s\n", hostbuffer);
	}

	inet_aton ("192.168.1.1", &in);
	if( hp= gethostbyaddr ((char *)&in.s_addr, sizeof(in.s_addr), AF_INET)){
		printf("Host name is %s\n", hp->h_name);
	}
	close(connectionFd);

	return (0);
}
