#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<errno.h>
#include<netdb.h>
#include<arpa/inet.h>
 
struct hostent *h_ent;
struct in_addr **addr_list;
int i;

int main(int argc, char *argv[]) {

if(argc < 2) {
    printf("Please enter hostname"); 
    exit(1);
}
            
if((h_ent = gethostbyname(argv[1])) == NULL) {
    herror("gethostbyname");
    return 1;
}
 
addr_list = (struct in_addr **)h_ent->h_addr_list; 

    for(i = 0; addr_list[i] != NULL; i++) {
        printf("%s\n", inet_ntoa(*addr_list[i]));
    }

return 0;

}

