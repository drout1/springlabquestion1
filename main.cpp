
	#include "mbed.h"
	#include "string.h"
	#include <cstdio>
	

	InterruptIn buttn(PC_13);
	volatile int flag = 0;
	

	// start, sstop, read_us, reset
	Timer ti;
	

	void buttnRise(){
	    ti.stop();
	    flag = 1;
	}
	

	void buttnFall(){
	    ti.start();
	}
	

	int main(){
	    buttn.rise(&buttnRise);
	    buttn.fall(&buttnFall);
	

	    while (1) {
	        if(flag){
	            printf("You pressed the button for %llu us\n", ti.elapsed_time().count());
	            ti.reset();
	            flag = 0;
	        }
	

	

	

	

	    }
	}

