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

int TestDebounce(char *filename) {
    char buffer[1000];
    int output_benar = 0;
    int output_salah = 0;
    int time;
    int in, out, state, counter;
    char *status;
    FILE *handle;
    // simulasi FSM dengan data dari file
    // buka file data
    printf("pengujian debounce: %s\n", filename);
    ;
    handle = fopen(filename, "r");
    if (handle != NULL) {
        status = fgets(buffer, 1000, handle); // buang baris pertama
        while ((status = fgets(buffer, 1000, handle)) != NULL) {
            //            printf("isinya %s\n", buffer);
            sscanf(buffer, "%d,%d,%d,%d", &in, &out, &state, &counter);
            printf("time %d: %d %d %d\n", in, out, state, counter);
        }
        fclose(handle);
    } else {
        printf("error open file %s\n", filename);
    }
    printf("jumlah output benar: %d\n", output_benar);
    printf("jumlah output salah: %d\n", output_salah);
}

int TestJam(char *filename) {
    char buffer[1000];
    int output_benar = 0;
    int output_salah = 0;
    int time;
    int mode_evt, set_evt, state, year, month, date, hour, minute;
    char *status;
    FILE *handle;
    // simulasi FSM dengan data dari file
    // buka file data
    printf("pengujian jam:%s\n", filename);
    handle = fopen(filename, "r");
    if (handle != NULL) {
        printf("sukses\n");
        status = fgets(buffer, 1000, handle); // buang baris pertama
        while ((status = fgets(buffer, 1000, handle)) != NULL) {
            //            printf("isinya %s\n", buffer);
            sscanf(buffer, "%d,%d,%d,%d,%d,%d,%d,%d,%d", &time, &mode_evt, &set_evt, &state, &year, &month, &date, &hour, &minute);

            printf("time %d: %d %d %d %d %d %d %d %d\n", time, mode_evt, set_evt, state, year, month, date, hour, minute);
        }
        fclose(handle);
    } else {
        printf("error open file %s\n", filename);
    }
    printf("jumlah output benar: %d\n", output_benar);
    printf("jumlah output salah: %d\n", output_salah);
}

int TestTotal(char *filename) {
    char buffer[1000];
    int output_benar = 0;
    int output_salah = 0;
    int time;
    int mode_in, set_in, mode_evt, set_evt, state, year, month, date, hour, minute;
    char *status;
    FILE *handle;
    // simulasi FSM dengan data dari file
    // buka file data
    printf("pengujian total:%s\n", filename);
    handle = fopen(filename, "r");
    if (handle != NULL) {
        status = fgets(buffer, 1000, handle); // buang baris pertama
        while ((status = fgets(buffer, 1000, handle)) != NULL) {
            int status_scan;
            status_scan = sscanf(buffer, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &time, &mode_in, &set_in, &mode_evt, &set_evt, &state, &year, &month, &date, &hour, &minute);
            if (status_scan == 11) { // cek apakah jumlah kolom sesuai
                printf("time %d %d %d %d %d %d %d %d %d %d %d\n", time, mode_in, set_in, mode_evt, set_evt, state, year, month, date, hour, minute);
            }
        }
        fclose(handle);
    } else {
        printf("error open file %s\n", filename);
    }
    printf("jumlah output benar: %d\n", output_benar);
    printf("jumlah output salah: %d\n", output_salah);
}

/*
 * 
 */
int main(int argc, char** argv) {

    //    TestDebounce("../data/debounce-00.csv");
    //    TestDebounce("../data/debounce-01.csv");
    TestJam("../data/jam-00-time.csv");
    TestJam("../data/jam-01-date.csv");
    TestJam("../data/jam-02-year.csv");
    TestTotal("../data/total-00.csv");
    return (EXIT_SUCCESS);
}
