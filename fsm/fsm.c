/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../fsm/fsm.h"

void fsm_debounce(int input, int *state, int *variable) {

}

void fsm_jam(int mode_clean, int set_clean, int *state, int *variable) {

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