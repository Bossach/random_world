#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define HE_ 25928
#define LL_ 27756
#define O_CM_ 11375
#define SP_W_ 30496
#define OR_ 29295
#define LD_ 25708
#define EX_END_ 33



int discover();



int main(){
	
	short str[7]; // = {HE_, LL_, O_CM_, SP_W_, OR_, LD_, EX_END_};
	
	
	srand(7928);
	str[0] = rand();
	
	srand(8488);
	str[1] = rand();
	
	srand(13506);
	str[2] = rand();
	
	srand(9327);
	str[3] = rand();
	
	srand(29028);
	str[4] = rand();
	
	srand(17895);
	str[5] = rand();
	
	srand(40136);
	str[6] = rand();

	
	printf("%s\n", str);
	
	//printf("\nRANDMAX = %d\n\n", 0x7FFF);
	
	
	//discover();
	
	return 0;
}



int discover(){
	
	#define SEED_MIN 0
	#define SEED_MAX 65536
	#define PASSES 1
	int seed, seed_is_printed, value, pass;
	FILE * outfile;
	
	
	for(seed = SEED_MIN; seed < SEED_MAX; seed++){
		
		srand(seed);
		seed_is_printed = 0;
		for(pass = 0; pass < PASSES; pass++){
			value = rand();
			switch(value){
				case HE_:
				case LL_:
				case O_CM_:
				case SP_W_:
				case OR_:
				case LD_:
				case EX_END_:
				
					outfile = fopen("matches.txt", "a");
					if(outfile == NULL){
						printf("Failed to open file. seed=%d, pass = %d, value =%d\n", seed, pass, value);
						exit(1);
					}
					
					if(!seed_is_printed){
						seed_is_printed = 1;
						printf("Seed %d:\n", seed);
						fprintf(outfile, "Seed %d:\n", seed);
					}
					printf("\tValue %d on pass %d\n", value, pass);
					fprintf(outfile, "\tValue %d on pass %d\n", value, pass);
					
					fclose(outfile);
			}
			
			
		}
		
	}
	
	return 0;
}
