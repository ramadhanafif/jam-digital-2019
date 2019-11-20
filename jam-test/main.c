/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: waskita
 *
 * Created on November 20, 2019, 7:05 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "../fsm/fsm.h"

/*
 * 
 */
int main(int argc, char** argv) {
    char buffer[1000];
    int output_benar = 0;
    int output_salah = 0;
    int time;
    int mode_in, set_in, mode_evt, set_evt, state, year, month, date, hour, minute;
    char *status;
    FILE *handle;
    // simulasi FSM dengan data dari file
    char filename[] = "../data/test-data-time.csv";
    // buka file data
    handle = fopen(filename, "r");
    if (handle != NULL) {
        status = fgets(buffer, 1000, handle); // buang baris pertama
        while ((status = fgets(buffer, 1000, handle)) != NULL) {
            //            printf("isinya %s\n", buffer);
            sscanf(buffer, "%d,%d,%d,%d", &time, &mode_in, &set_in, &mode_evt, &set_evt, state, year, month, date, hour, minute);
            printf("time %d mode_in %d set_in %d\n", time, mode_in, set_in);
        }
        fclose(handle);
    }
    printf("jumlah output benar: %d\n", output_benar);
    printf("jumlah output salah: %d\n", output_salah);
    return (EXIT_SUCCESS);
}
