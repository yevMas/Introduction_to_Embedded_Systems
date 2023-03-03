#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <memory.h>
#include <stats.h>
#include <data.h>
#include <course1.h>
#include <platform.h>

int main(){
	#ifdef COURSE1
		printf("calling course1()\n");
		course1();
		return 0; 
	#endif

	return 0;
}
