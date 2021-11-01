#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

int main(int argc, char *argv[]) {

	//time variable
	clock_t begin = clock();

	//Create variables
	struct hostent *hstinfo;
	char *name;
	char **h_Alias;
	char **h_list;
	int i = 0;
	struct in_addr addr;
	struct in_addr **addr_list;

	//check input
	if (hstinfo == NULL) {
		herror("Invalid Entry!");
		exit(1);
	}

	//initialize variable
	hstinfo = gethostbyname(argv[1]);

	//Name of address
	if (hstinfo->h_name == NULL) {
		printf("Could not Obtain official name! \n");
	}
	else {
		printf("Official Name: %s\n", hstinfo->h_name);
	}

	//Alias Name
	if (hstinfo->h_aliases == NULL) {
		printf("Couldn't Obtain Aliases");
	}
	else {
		for (h_Alias = hstinfo->h_aliases; *h_Alias != 0; h_Alias++) {
			printf("Aliases: %s\n", *h_Alias);
		}
	}

	//adresses
	addr_list = (struct in_addr **)hstinfo->h_addr_list;
	for (i = 0; addr_list[i] != NULL; i++) {

		printf("%s ", inet_ntoa(*addr_list[i]));
	}

	//print time
	clock_t end = clock();
	printf("Execution Time: %f seconds\n", (double)(end - begin) / CLOCKS_PER_SEC);


	return 0;



}