#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4455

void load_menu(void);
void tcpn(void);
void tcpvv(void);
void tcpem0(void);
void tcpd(void);
void forks(void);
void rest(void); 
int main()
{
int sockfd;
struct sockaddr_in serverAddr;

int newSocket;
struct sockaddr_in newAddr;

socklen_t addr_size;
char buffer[1024];

sockfd=socket(PF_INET, SOCK_STREAM, 0);
memset(&serverAddr, '\0', sizeof(serverAddr));

serverAddr.sin_family=AF_INET;
serverAddr.sin_port=htons(PORT);
serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");

bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

listen(sockfd, 5);
addr_size = sizeof(newAddr);

newSocket=accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);

strcpy(buffer, "Hello");
send(newSocket, buffer, strlen(buffer), 0);

   int n, c = 2;
   int choice;
      
      do
    {
    	printf("\n");
        printf("Menu\n\n");
        printf("\n");
        printf("1. Quote\n");
        printf("\n");
        printf("2. Fork\n");
        printf("\n");
        printf("3. Tcpdump -vv\n");
        printf("\n");
        printf("4. Tcpdump -nn\n");
        printf("\n");
        printf("5. Tcpdump -D\n");
        printf("\n");
        printf("6. Tcpdump em0\n");
        printf("\n");

        printf("7. Exit\n");
        scanf("%d",&choice);
 
        switch(choice)
        {

            case 1: rest();
                break;

            case 2: forks();
                break;
         
            case 3: tcpvv();
                break;

            case 4: tcpn ();
                break;

            case 5: tcpd ();
                break;

            case 6: tcpem0 ();
                break;

                    
            case 7: 
			printf("\n");
			printf("Quitting program!\n");
                exit(0);
                break;
            default: 
			printf("\n");
			printf("Invalid choice!\n");
                break;
        }
    } while (choice != 7);   
}

void tcpn(void)
{
int ch;
int n;
int ret;

    while ((ch = getchar()) != '\n' && ch != EOF) ;
 
    printf("\n");
    printf("\n\nPress ENTER to continue.");
    while ((ch = getchar()) != '\n' && ch != EOF);

    ret = execl("/usr/sbin/tcpdump","tcpdump","-nn", NULL);

    return;
}

void tcpvv(void)
{
int ch;
int ret;

    while ((ch = getchar()) != '\n' && ch != EOF) ;
 
    printf("\n");
    printf("\n\nFor stopping the program 'ctrl + c'. Press ENTER to continue.");
    
    while ((ch = getchar()) != '\n' && ch != EOF);

    ret = execl("/usr/sbin/tcpdump","tcpdump","-vv", NULL);

return;
}
void tcpem0(void)
{
int ch;
int n;
int ret;

    while ((ch = getchar()) != '\n' && ch != EOF) ;

    printf("\n");
    printf("\n\nFor stopping the program 'ctrl + c'. Press ENTER to continue.");
    while ((ch = getchar()) != '\n' && ch != EOF);

    ret = execl("/usr/sbin/tcpdump","tcpdump","-n", "-i", "em0", NULL);

    return;
}
void tcpd(void)
{
int ch;
int n;
int ret;

    while ((ch = getchar()) != '\n' && ch != EOF) ;

    printf("\n");
    printf("\n\nFor stopping the program 'ctrl + c'. Press ENTER to continue.");
    while ((ch = getchar()) != '\n' && ch != EOF);

    ret = execl("/usr/sbin/tcpdump","tcpdump","-D", NULL);

    return;
}

void forks(void)
{

 int ch;
 int pid;

  pid = fork();

  if (pid < 0) { // error occurred
          fprintf(stderr, "Fork failed!\n");
          exit(-1);
  }else if (pid == 0) { // child process
          printf("I am the child, return from fork=%d\n", pid);
          execlp("/bin/ps", "ps", NULL);
  }else { // parent process
          printf("I am the parent, return from fork, child pid=%d\n", pid);
          printf("Parent exiting!\n");
          
    while ((ch = getchar()) != '\n' && ch != EOF) ;
 
    printf("\n");
    printf("\n\nPress ENTER to continue.");
    printf("\n");
    while ((ch = getchar()) != '\n' && ch != EOF);
  }

return;
}

void rest(void)
{
    int ch;
    printf("\n");
    printf("There are no secrets to success. It is the result of preparation, hard work and learning from failure \n");
 
    /* Flushes input buffer */
    while ((ch = getchar()) != '\n' && ch != EOF) ;
 
    printf("\n");
    printf("\n\nPress ENTER to continue.");
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
 
    return;
}
