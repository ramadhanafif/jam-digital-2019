#include "fsm.h"

int* state;
int mode_in, set_in, mode_evt, set_evt;
int *yea, *mont, *date, *hou, *minut;

// debounce counter
int *mode_deb, *set_deb;

//pin definition
#define MODE 16
#define SET 4

//null pointer
#define kosong 0

void setup() {
  //pin initialisation
  pinMode(MODE, INPUT_PULLUP);
  pinMode(SET, INPUT_PULLUP);

  //fsm initialisation
  fsm_jam_init(state, kosong);
  fsm_debounce_init(mode_deb, kosong);
  fsm_debounce_init(set_deb, kosong);

  //variable initialisation
  *yea = 2019;
  *mont = 12;
  *date = 1;
  *hou = 2;
  *minut = 3;

}

void loop() {

  mode_in = digitalRead(MODE);
  set_in = digitalRead(SET);

  switch (*state)
  {
    case S_TIME:
      fsm_lengkap(mode_in, set_in, state, kosong);
      break;
    case S_DATE:
      fsm_lengkap(mode_in, set_in, state, kosong);
      break;
    /*--------------------------------------------------------*/
    case S_TIME_HOUR:
      fsm_lengkap(mode_in, set_in, state, hou);
      break;

    case S_TIME_MINUTE:
      fsm_lengkap(mode_in, set_in, state, minut);
      break;

    case S_TIME_DAY:
      fsm_lengkap(mode_in, set_in, state, date);
      break;

    case S_TIME_YEAR:
      fsm_lengkap(mode_in, set_in, state, yea);
      break;
    /*--------------------------------------------------------*/
    case S_DATE_HOUR:
      fsm_lengkap(mode_in, set_in, state, hou);
      break;

    case S_DATE_MINUTE:
      fsm_lengkap(mode_in, set_in, state, minut);
      break;

    case S_DATE_DAY:
      fsm_lengkap(mode_in, set_in, state, date);
      break;

    case S_DATE_YEAR:
      fsm_lengkap(mode_in, set_in, state, yea);
      break;
  }

  Serial.println();
  delay(1);
}
