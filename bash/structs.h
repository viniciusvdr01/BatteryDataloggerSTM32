#include "types.h"

typedef struct
{
	uint16_t second  __attribute__((packed));
	uint16_t minute  __attribute__((packed)); 
	uint16_t hour    __attribute__((packed));
}DLtime;

typedef struct 
{
	uint16_t vbat    __attribute__((packed));
	uint16_t ibat    __attribute__((packed));
	uint16_t number  __attribute__((packed));
	DLtime time_ticks;

}samples_t;




