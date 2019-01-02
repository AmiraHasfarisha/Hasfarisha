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
void tcpi(void);
void forks(void);
void rest(void); 
int main()
{
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
        printf("3. Tcpdump -i eth0\n");
        printf("\n");
        printf("4. Tcpdump -nn\n");
        printf("\n");
        printf("5. Exit\n");
        scanf("%d",&choice);
 
        switch(choice)
        {

            case 1: rest();
                break;

            case 2: forks();
                break;
         
            case 3: tcpi();
                break;

            case 4: tcpn ();
                break;
                    
            case 5: 
			printf("\n");
			printf("Quitting program!\n");
                exit(0);
                break;
            default: 
			printf("\n");
			printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);   
}

void tcpn(void)
{
int ch;
int n;
int ret;

printf("tcpdump -nn:%d\n");
    while ((ch = getchar()) != '\n' && ch != EOF) ;
 
    printf("\n");
    printf("\n\nPress ENTER to continue.");
    while ((ch = getchar()) != '\n' && ch != EOF);

    ret = execl("/usr/sbin/tcpdump","tcpdump","-nn", NULL);

    return;
}

void tcpi(void)
{
int ch;
int ret;

printf("tcpdump -i udp:%d\n");
    while ((ch = getchar()) != '\n' && ch != EOF) ;
 
    printf("\n");
    printf("\n\nFor stopping the program 'ctrl + c'. Press ENTER to continue.");
    
    while ((ch = getchar()) != '\n' && ch != EOF);

    ret = execl("/usr/sbin/tcpdump","tcpdump","-vv", NULL);

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
