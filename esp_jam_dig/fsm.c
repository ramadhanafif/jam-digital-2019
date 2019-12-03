/*
  To change this license header, choose License Headers in Project Properties.
  To change this template file, choose Tools | Templates
  and open the template in the editor.
*/

#include "fsm.h"

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
    /*--------------------------------------------------------*/
    case S_TIME_HOUR:
      if (mode_clean) {
        next_state = S_TIME_HOUR;
        *variable++;
        if (*variable == 24)
          *variable = 0;
      }
      if (set_clean)
        next_state = S_TIME_MINUTE;
      break;

    case S_TIME_MINUTE:
      if (mode_clean) {
        next_state = S_TIME_MINUTE;
        *variable++;
        if (*variable == 60)
          *variable = 0;
      }
      if (set_clean)
        next_state = S_TIME_DAY;
      break;

    case S_TIME_DAY:
      if (mode_clean) {
        next_state = S_TIME_DAY;
        *variable++;
        if (*variable == 31)
          *variable = 0;
      }
      if (set_clean)
        next_state = S_TIME_MONTH;
      break;

    case S_TIME_YEAR:
      if (mode_clean) {
        next_state = S_TIME_YEAR;
        *variable++;
      }
      if (set_clean)
        next_state = S_TIME;
      break;
    /*--------------------------------------------------------*/
    case S_DATE_HOUR:
      if (mode_clean) {
        next_state = S_DATE_HOUR;
        *variable++;
        if (*variable == 24)
          *variable = 0;
      }
      if (set_clean)
        next_state = S_DATE_MINUTE;
      break;

    case S_DATE_MINUTE:
      if (mode_clean) {
        next_state = S_DATE_MINUTE;
        *variable++;
        if (*variable == 60)
          *variable = 0;
      }
      if (set_clean)
        next_state = S_DATE_DAY;
      break;

    case S_DATE_DAY:
      if (mode_clean) {
        next_state = S_DATE_DAY;
        *variable++;
        if (*variable == 32)
          *variable = 0;
      }
      if (set_clean)
        next_state = S_DATE_MONTH;
      break;

    case S_DATE_YEAR:
      if (mode_clean) {
        next_state = S_DATE_YEAR;
        *variable++;
      }
      if (set_clean)
        next_state = S_DATE;
      break;

      //next state assignment
      *state = next_state;

  }
}

void fsm_lengkap(int mode_in, int set_in, int *state, int *variable) {
  int mode_counter;
  int set_counter;

  int mode_clean;
  int set_clean;

  fsm_debounce(mode_in, mode_clean, mode_counter);
  fsm_debounce(set_in, set_clean, mode_counter);

  fsm_jam(mode_clean, set_clean, state, variable);

}

/* Debouce counter reset */
void fsm_debounce_init(int *state, int *variable) {
  *variable = 0;
}


/* Initial state set */
void fsm_jam_init(int *state, int *variable) {
  *state = S_TIME;
}
