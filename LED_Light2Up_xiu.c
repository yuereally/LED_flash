#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gpio=144;


int main(int argc, char const *argv[])
{
	
	FILE *fp;
	char buffer[10];
	int value;
        char s[50]="";
	char s1[50]="";
	if ((fp = fopen("/sys/class/gpio/export", "w")) == NULL) 
	{
		printf("Cannot open export file.\n");
		return -1;
	}
	fprintf(fp, "%d", gpio);
	fclose(fp);

	sprintf(s,"/sys/class/gpio/gpio%d/direction",gpio);
	if ((fp = fopen(s, "rb+")) == NULL) 
	{
		printf("Cannot open %s.\n",s);
		return -1;
	}
	fprintf(fp, "out");
    fclose(fp);
		
	sprintf(s1,"/sys/class/gpio/gpio%d/value",gpio);

	if ((fp = fopen(s1, "rb+")) == NULL) 
	{
	    printf("Cannot open %s.\n",s1);
		return -1;
	}
	strcpy(buffer,"1");
	fwrite(buffer, sizeof(char), sizeof(buffer) - 1, fp);		
	fclose(fp);
    return 1;
}


