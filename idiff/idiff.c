#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio2.h>

#define HUGE	10000	// Huge number of lines
#define BUFSIZE	2048	// Buffer size


char *progname;

int main(int argc, char *argv[]) {
	
	FILE *fin, *fout, *f1, *f2, *efopen();
	
	char buf[BUFSIZE], *mktemp();
	char *diffout = "idiff.XXXXXX";
	
	progname = argv[0];
	
	if (argc != 3) {
		fprintf(stderr, "Usage: idiff file1 file2\n");
		exit(1);
	}
	
	f1 = efopen(argv[1], "r");
	f2 = efopen(argv[2], "r");
	fout = efopen("idiff.out", "w");
	
	mktemp(diffout);
	
	sprintf(buf, "diff %s %s > %s", argv[1], argv[2], diffout);
	system(buf);
	
	fin = efopen(diffout, "r");
	idiff(f1, f2, fin, fout);
	unlink(diffout);
	
	printf("output went to %s to idiff.out\n", progname);
	
	system("PAUSE");	
  
  	return(-1);
}



FILE *efopen(char *file, char *mode) {		// fopen file, die if can't

	FILE *fp, *fopen();
	extern char *progname;

	if ((fp = fopen(file, mode)) != NULL)
		return fp;
	fprintf(stderr, "%s: can't open file %s in mode %s\n",
		progname, file, mode);
	exit(1);
}

idiff(FILE *f1, FILE *f2, FILE *fin, FILE *fout) {
     
     char *tempfile = "idiff.XXXXXX";
     char buf[BUFSIZ], buf2[BUFSIZ], *mktmp();
     FILE *ft, *efopen();
     int cmd, n, from1, to1, form2, to2, nf1, nf2;
     
     mktemp(tempfile);
     nf1 = nf2 = 0;
     
     while (fgets(buf, sizeof buf, fin) != NULL) {
           parse(buf, &from1, &to1, &cmd, &from2, &to2);
     
     }







}
     
