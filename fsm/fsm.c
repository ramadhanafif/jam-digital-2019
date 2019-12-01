	/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../fsm/fsm.h"

void fsm_debounce(int input, int *state, int *variable) {
	// increment variable
	// increment terjadi setiap 1 ms
	// input dianggap berhenti bouncing setelah variable bernilai 10

	if (*variable < 10)
	{
		*variable++;
	}
	else //variable>10
	{
		if (input == 1)
			*state = 1;
	}
}

void fsm_jam(int mode_clean, int set_clean, int *state, int *variable) {
	int curr_state = *state;
	int next_state;
	switch (curr_state)
	{
	case S_TIME:
		if (mode_clean)
			next_state = S_DATE;
		
		if (set_clean)
			next_state = S_TIME_HOUR;
		break;
	
	case S_DATE:
		if (mode_clean)
			next_state = S_TIME;
		
		if (set_clean)
			next_state = S_DATE_HOUR;
		break; 
/*-----------------------------------------------*/
	case S_TIME_HOUR:
		if (mode_clean)
			next_state = S_TIME_HOUR;
		
		if (set_clean)
			next_state = S_TIME_MINUTE;
		break; 

	case S_TIME_MINUTE:
		if (mode_clean)
			next_state = S_TIME_MINUTE;
		
		if (set_clean)
			next_state = S_TIME_DAY;
		break; 

	case S_TIME_DAY:
		if (mode_clean)
			next_state = S_TIME_DAY;
		
		if (set_clean)
			next_state = S_TIME_MONTH;
		break; 

	case S_TIME_YEAR:
		if (mode_clean)
			next_state = S_TIME_YEAR;
		
		if (set_clean)
			next_state = S_TIME;
		break; 
/*--------------------------------------------------------*/
	case S_DATE_HOUR:
		if (mode_clean)
			next_state = S_DATE_HOUR;
		
		if (set_clean)
			next_state = S_DATE_MINUTE;
		break; 

	case S_DATE_MINUTE:
		if (mode_clean)
			next_state = S_DATE_MINUTE;
		
		if (set_clean)
			next_state = S_DATE_DAY;
		break; 

	case S_DATE_DAY:
		if (mode_clean)
			next_state = S_DATE_DAY;
		
		if (set_clean)
			next_state = S_DATE_MONTH;
		break; 

	case S_DATE_YEAR:
		if (mode_clean)
			next_state = S_DATE_YEAR;
		
		if (set_clean)
			next_state = S_DATE;
		break; 
	}

	//next state assignment
	*state = next_state

}

void fsm_lengkap(int mode_in, int set_in, int *state, int *variable) {

}

/**
 * initialize all states
 */
void fsm_debounce_init(int *state, int *variable) {

}

void fsm_jam_init(int *state, int *variable) {
    *state = S_TIME_HOUR;
}