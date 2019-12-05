/*
  To change this license header, choose License Headers in Project Properties.
  To change this template file, choose Tools | Templates
  and open the template in the editor.
*/

#include "fsm.h"

int mode_counter = 0;
int set_counter = 0;
#define DEB_COUNT 100


void fsm_debounce(int input, int *state, int *variable) {
  // increment variable
  // increment terjadi setiap 1 ms
  // input dianggap berhenti bouncing setelah variable bernilai DEB_COUNT

  if (*variable < DEB_COUNT)
  {
    (*variable)++;
  }
  else //variable>DEB_COUNT
  {
    if (input == 1)
      *state = 1;
    *variable = 0;
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
      else if (set_clean)
        next_state = S_TIME_HOUR;
      else
        next_state = curr_state;
      break;

    case S_DATE:
      if (mode_clean)
        next_state = S_TIME;
      else if (set_clean)
        next_state = S_DATE_HOUR;
      else
        next_state = curr_state;
      break;
    /*--------------------------------------------------------*/
    case S_TIME_HOUR:
      if (mode_clean) {
        next_state = S_TIME_HOUR;
        (*variable)++;
        if (*variable == 24)
          *variable = 0;
      }
      else if (set_clean)
        next_state = S_TIME_MINUTE;
      else
        next_state = curr_state;
      break;

    case S_TIME_MINUTE:
      if (mode_clean) {
        next_state = S_TIME_MINUTE;
        (*variable)++;
        if (*variable == 60)
          *variable = 0;
      }
      else if (set_clean)
        next_state = S_TIME_DAY;
      else
        next_state = curr_state;
      break;

    case S_TIME_DAY:
      if (mode_clean) {
        next_state = S_TIME_DAY;
        (*variable)++;
        if (*variable == 31)
          *variable = 0;
      }
      else if (set_clean)
        next_state = S_TIME_MONTH;
      else
        next_state = curr_state;
      break;

    case S_TIME_YEAR:
      if (mode_clean) {
        next_state = S_TIME_YEAR;
        (*variable)++;
      }
      else if (set_clean)
        next_state = S_TIME;
      else
        next_state = curr_state;
      break;
    /*--------------------------------------------------------*/
    case S_DATE_HOUR:
      if (mode_clean) {
        next_state = S_DATE_HOUR;
        (*variable)++;
        if (*variable == 24)
          *variable = 0;
      }
      else if (set_clean)
        next_state = S_DATE_MINUTE;
      else
        next_state = curr_state;
      break;

    case S_DATE_MINUTE:
      if (mode_clean) {
        next_state = S_DATE_MINUTE;
        (*variable)++;
        if (*variable == 60)
          *variable = 0;
      }
      else if (set_clean)
        next_state = S_DATE_DAY;
      else
        next_state = curr_state;
      break;

    case S_DATE_DAY:
      if (mode_clean) {
        next_state = S_DATE_DAY;
        (*variable)++;
        if (*variable == 32)
          *variable = 0;
      }
      else if (set_clean)
        next_state = S_DATE_MONTH;
      else
        next_state = curr_state;
      break;

    case S_DATE_YEAR:
      if (mode_clean) {
        next_state = S_DATE_YEAR;
        (*variable)++;
      }
      else if (set_clean)
        next_state = S_DATE;
      else
        next_state = curr_state;
      break;
    default:
      next_state = curr_state;
  }
  //next state assignment
  (*state) = next_state;
}

void fsm_lengkap(int mode_in, int set_in, int *state, int *variable) {
  int mode_clean = 0;
  int set_clean = 0;

  if (mode_in)
    fsm_debounce(mode_in, &mode_clean, &mode_counter);

  else if (set_in)
    fsm_debounce(set_in, &set_clean, &set_counter);

  fsm_jam(mode_clean, set_clean, state, variable);
}

/* Debouce counter reset */
void fsm_debounce_init(int *state, int *counter) {

  mode_counter = 0;
  set_counter = 0;
}


/* Initial state set */
void fsm_jam_init(int *state, int *variable) {
  *state = S_TIME;
}
