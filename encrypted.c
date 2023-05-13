#include <stdio.h>
#include <stdlib.h>

int main(){
	
	FILE *fileRead, *fileWrite;
	int c;
	char fileName[50];

	printf("Enter file path: ");
	scanf("%s", fileName);

	if((fileRead = fopen(fileName, "r")) == NULL) {
		perror("ERROR");
		return -1;
	}

	fileWrite = fopen("fileEncrypted.txt", "w");

	while(1) {
		c = fgetc(fileRead);

		if(c == EOF){
			printf("\n\n");
			break;
		}

      	if(c != 10) {
			fputc(c + 3, fileWrite);
        	} else {
      		fputc(c, fileWrite);
		}
	}

	fclose(fileRead);
	fclose(fileWrite);
	printf("Successfully encrypted file\n");

	return 0;
}