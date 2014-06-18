#include <string>
#include <stdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>	// for struct socketaddr_in

#define DEST_IP "localhost"
#define DEST_PORT 4000


int main() {
	int res;
	int sockfd;
	struct sockaddr_in dest_addr;

	char* msg = "Hello World.";

	int len, bytes_sent;

	// Create a socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		perror("socket() error.");
		exit(1);
	}

	// Set connection information
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(DEST_PORT);
	dest_addr.sin_addr.s_addr = inet_addr(DEST_IP);
	bzero(&(dest_addr.sin_zero), 8);

	// Connect
	res = connect(sockfd, (struct sockaddr*)&dest_addr, sizeof(struct sockaddr_in));
	if (res == -1) {
		perror("connect() error.");
		exit(1);
	}

	// Send
	len = strlen(msg);
	bytes_sent = send(sockfd, msg, len, 0);

	// Close
	close(sockfd);
}