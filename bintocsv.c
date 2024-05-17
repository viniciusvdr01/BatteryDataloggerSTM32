#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structs.h"



int main(int argc, char **argv)
{
	samples_t sample[60];

	if(argc == 3) 
	{
		FILE *arq_bin = fopen(argv[1],"rb");

		if( arq_bin  == NULL )
			printf("Error reading %s file.\n",argv[1]);

		FILE *arq_csv = fopen(argv[2],"w");


		fputs("Number,ibat,vbat,hour,minute,second\r\n",arq_csv);

		for(int i = 0; i < 60 ; i++)
		{
			fread(&sample[i],sizeof(samples_t),1,arq_bin);
			fprintf(arq_csv,"%d,%d,%d,%d,%d,%d\r\n",sample[i].number,
					sample[i].ibat,
					sample[i].vbat,
					sample[i].time_ticks.hour,
					sample[i].time_ticks.minute,
					sample[i].time_ticks.second);

		}

		fclose(arq_bin);
		fclose(arq_csv);


	}
	else
		printf("Error : Wrong arguments number\n");

	return 0;
}
