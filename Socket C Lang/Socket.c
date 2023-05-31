#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include<string.h>	//strlen

int main(int argc , char *argv[])
{
	int socket_desc; //   IPv4         TCP     IP Protocol
	struct sockaddr_in server;
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	char *message;

	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}
	//                                 -IP de Conexão
	server.sin_addr.s_addr = inet_addr("23.200.83.26");
	server.sin_family = AF_INET; //IPv4
	server.sin_port = htons( 80 ); //Porta

	//Connect to remote server
	if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}

	puts("Connected");

	//Send some data
	message = "GET / HTTP/1.1\r\n\r\n";
	if( send(socket_desc , message , strlen(message) , 0) < 0)
	{
		puts("Send failed");
		return 1;
	}
	puts("Data Send\n");

	return 0;
}
