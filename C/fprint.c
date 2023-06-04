#include <stdio.h>
#include <string.h>

int main(int argc, char *argv) {
	FILE *fp = fopen("a.txt", "r");
	char buf[30];
	memset(buf, 0, sizeof(buf));
	fseek(fp, 15L, SEEK_SET);
	fread(buf, sizeof(char), 4, fp);
	printf("%s\n", buf);
	fclose(fp);
	return 0;
}
