#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include"structs.h"
#include"types.h"

void adc_read();

void file_min();

samples_t sample[60];

DLtime time;

uint16_t adc_val1,adc_val2;

void timer_interrupt();

void tcon();

int sample_number = 0;

int main()
{

	time.second = 0; 
	while(1)
	{
		sleep(1);
		timer_interrupt();
		printf("second tick = %d\r\n",time.second);
		printf("minute_tick = \%d\r\n",time.minute);

	}

return 0;
}

void adc_read()
{
        adc_val1 =(int) 1000 + (rand() % 100) -50;
	adc_val2 = (int) 1450 + (rand() % 100) -50;
}

void timer_interrupt()
{
	adc_read();

	sample[time.second].time_ticks.second = time.second;
	sample[time.second].time_ticks.minute = time.minute;
	sample[time.second].time_ticks.hour = time.hour;
	sample[time.second].ibat = adc_val2;
	sample[time.second].vbat = adc_val1;
	sample[time.second].number = sample_number;


	if(time.second == 59) file_min();

	sample_number++;

	tcon();

}

void tcon()
{

	if(time.second < 59)	
	{
		time.second++;
	}
	else
	{
		time.second = 0;
		if(time.minute <59)
		{
			time.minute ++;
		}
		else
		{
			time.minute = 0;
			time.hour ++;
		}
	}

// calcular minuto, hora e segundo.
}

void file_min()
{
	char file_name[30];
	
	sprintf(file_name,"logs/bin_log_%d-%d-%d.bin",time.hour,
			time.minute,
			time.second);

	printf("%s\n",file_name);

	FILE *arq_bin= fopen(file_name, "wb");

	for( int i = 0; i< 60; i++)
	{
		fwrite(&sample[i],sizeof(sample[i]),1,arq_bin);
	}
	fclose(arq_bin);

}

