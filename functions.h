#include <stdio.h>
#include <errno.h>

/* cutchar function prints only nth byte from every line of given file.
   it treats space and tab characters as a single character.
   it prints upto end of file character. */
int remember, no, flag = 0;
typedef struct {
	char col1;
	char col2;
	char col3;
}arr;
arr C[1024];

/* ./a.out -b 3 file */
/* ./a.out -c 7 file */
int cutchar(int target, char *file) {
	FILE *fp;
	int c, count = 0;

	fp = fopen(file, "r");
	if(fp == NULL){
		perror("Can't open file:");
		return errno;	
	}
	do {
		/*count upto target, print target, go upto \n and make count = 0;
		  again start from new line and do the same procedure until you get the EOF*/		
		c = fgetc(fp);
		if(c == ' ')
			continue;
		/*else if(c == '\t')
		  count++;*/

		count = count + 1;
		if(count == target){
			if(flag == 0){
				if(c != EOF)
					printf("%c", c);
			}
		}

		if(c == '\n'){
			if(flag == 0)
				printf("\n");
			count = 0;
		}
	}while(c != EOF);
	if(flag == 1 || flag == 2){

	}
	fclose(fp);	
}

int cut_char(int target, char *file){
	FILE *fp;
	int c, count = 0, i = 0, j = 0, k = 0;

	fp = fopen(file, "r");
	if(fp == NULL){
		perror("Can't open file:");
		return errno;	
	}
	do {
		/*count upto target, print target, go upto \n and make count = 0;
		  again start from new line and do the same procedure until you get the EOF*/		
		c = fgetc(fp);
		if(c == ' ')
			continue;
		/*else if(c == '\t')
		  count++;*/

		count = count + 1;
		if(count == target){
			if(flag == 1){
				C[i].col1 = c;
				i++;
			}
			else if(flag == 2){
				C[j].col2 = c;
				j++;
			}

		}

		if(c == '\n'){
			count = 0;
		}
	}while(c != EOF);
	if(flag == 1 || flag == 2){
		while(k < j){
			if(C[k].col1 != EOF && C[k].col2 != EOF)
				printf("%c%c", C[k].col1, C[k].col2);

			printf("\n");
			k++;
		}

	}
	flag = 0;
	fclose(fp);	
}

int cut_chardash(int from, int to, char *file){
	FILE *fp;
	int c, count = 0;

	fp = fopen(file, "r");
	if(fp == NULL){
		perror("Can't open file: ");
		return errno;
	}

	while((c = fgetc(fp)) != EOF){
		count = count + 1;
		while(count >= from && count <= to){
			printf("%c", c);
		}
		if(c == '\n'){
			printf("\n");
			count = 0;
		}
	}
	fclose(fp);
}
//./a.out -b 3 --complement file
//./a.out -c 3 --complement file

int complement(int target, char *file) {
	FILE *fp;
	int c, count = 0;

	fp = fopen(file, "r");
	if(fp == NULL){
		perror("Can't open file:");
		return errno;
	}
	do {
		/*count upto target, print target, go upto \n and make count = 0;
		  again start from new line and do the same procedure until you get the EOF*/
		c = fgetc(fp);
		if(c == ' ')
			continue;
		/*else if(c == '\t')
		  count++;*/

		count = count + 1;
		if(count == target)
			continue;
		printf("%c", c);
		if(c == '\n'){
			//	printf("\n");
			count = 0;
		}
	}while(c != EOF);
}

// ./a.out -b -3 file

int cut_to(int to, char *file){
	FILE *fp;
	int c, count = 0;

	fp = fopen(file, "r");
	if(fp == NULL){
		perror("Can't open file:");
		return errno;
	}

	while((c = fgetc(fp)) != EOF){

		if(c != EOF){
			count++;
			if(count <= to)
				printf("%c", c);
		}
		if(c == '\n'){
			printf("\n");
			count = 0;
		}
	}
	fclose(fp);
}

// ./a.out -b 7- file
int cut_from(int from, char *file){
	FILE *fp;
	int c, count = 0;

	fp = fopen(file, "r");
	if(fp == NULL){
		perror("Can't open file:");
		return errno;
	}

	while((c = fgetc(fp)) != EOF){
		count++;
		if(count >= from && c != '\n'){
			printf("%c", c);
		}
		if(c == '\n'){
			printf("\n");
			count = 0;
		}

	}
	fclose(fp);
}

// ./a.out -b 3-7 file
// ./a.out -b 13-37 file
int cut_btw(int from, int to, char *file){
	FILE *fp;
	int c, count = 0;

	fp = fopen(file, "r");
	if(fp == NULL){
		perror("Can't open file:");
		return errno;
	}

	while((c = fgetc(fp)) != EOF){
		count++;
		if(count >= from && c != '\n'){
			if(count <= to)
				printf("%c", c);
		}
		if(c == '\n'){
			printf("\n");
			count = 0;	
		}
	}
	fclose(fp);
}

/* open cut_help file on cut --help command */
int help(){
	FILE *fp;
	int c;

	fp = fopen("cut_help", "r");
	if(fp == NULL){
		perror("can't open cut_help file: ");
		return errno;
	}

	while((c = fgetc(fp)) != EOF)
		printf("%c", c);

	fclose(fp);

}

/* reads standard input */
void stdinput(int target){
	char ip[128];
	char *str;
	int i;

	for(i = 0; i < 128; i++){
		scanf("%s", &ip[i]);
		str = (ip + i);
		i = i - 1;
		printf("%c\n", *(str + target - 1));
	}
}

void store(int x){
	flag = x;
}	
