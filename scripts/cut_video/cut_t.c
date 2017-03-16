#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char aux[100];
	char sub1[20];
	char sub2[20];
	int count = 1;
	
	FILE *fp;
	FILE *saida;
	FILE *commands;
	char dirsrt[100] = "../../romeo_and_juliet/r_a_j_sync.srt";
	char dirvid[100] = "../../romeo_and_juliet/r_a_j_sync.avi";
	char dirout[100] = "times.txt";
	char dircmd[100] = "commands.txt";
	
	fp = fopen(dirsrt, "r");
	saida = fopen(dirout, "w");
	
	if (fp == NULL){
		printf ("the directory fp is not found");
		return 0;
	}
	
	if (saida == NULL){
		printf ("the directory saida is not found");
		return 0;
	}
	
	rewind(fp);	
	
	while((fgets(aux, sizeof(aux), fp)) != NULL){

		if (strstr(aux, "-->") != NULL){
			fprintf(saida, "%s" ,aux);
		}
		
	}
	
	fclose(fp);
	fclose(saida);
	
	saida = fopen(dirout, "r");
	commands = fopen(dircmd, "w");
	
	while((fscanf(saida, "%s --> %s" ,sub1 ,sub2)) != EOF){
		fprintf(commands, "ffmpeg -i %s -ss %s -to %s out/%d.avi\n" ,dirvid, sub1 ,sub2 ,count);
		count++;
	}

	fclose(commands);

	return 0;
}
