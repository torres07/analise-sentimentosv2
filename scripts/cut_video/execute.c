#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//example: ffmpeg -i TesteCorte.mp4 -ss 00:01:10 -to 00:01:20 teste.mp4

int main(){
	char command[100];

	FILE *saida;
	
	saida = fopen("commands.txt", "r");
	
	if (saida == NULL){
		printf ("the directory saida is not found");
		return 0;
	}
	
	rewind(saida);	
	
	while(fgets(command, sizeof(command), saida) != NULL){
		//printf("%s" ,command);
		system(command);
	}
	
	fclose(saida);

	return 0;
}

