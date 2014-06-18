#include <string>
#include <stdio>
#include <stdlib>
#include <sys/tyeps>
#include <sys/socket>
#include <netinet/in>

#define BACKLOG 10
#define MYPORT 4000

int main() {
	char* addr;
	int sockfd;
	struct sockaddr_in local_addr, client_addrs;

	int res;
	int sin_size;

	char* buf;

	// Create a socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		perror("socket() error.");
		exit(1);
	}

	// Set connection information
	local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons(MYPORT);
	local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	bzero(&(local_addr.sin_zero), 8);

	// Binding
	res = bind(sockfd, (struct sockaddr*)&local_addr, sizeof(struct sockaddr));
}
