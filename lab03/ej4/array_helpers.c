/*
  @file array_helpers.c
  @brief Array Helpers method implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"


/**
 * @brief returns true when reach last line in weather file
 * @param[in] year Year array position (start in 0 ends with YEARS - 1)
 * @param[in] month Month of the year (december is last month 11u)
 * @param[in] day Day of the month. We assume all month have 28 days.
 * @return True when is the last line of the file, False otherwise
 */
static bool is_last_line(unsigned int year, unsigned int month, unsigned int day)
{
    return  year == YEARS - 1u && month == december && day == DAYS - 1u;
}


void array_dump(WeatherTable a) {
    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                fprintf(stdout, "%u %u %u ", year + FST_YEAR, month + 1, day + 1);
                weather_to_file(stdout, a[year][month][day]);
                if (!is_last_line(year, month, day))
                {
                    fprintf(stdout, "\n");
                }
            }
        }
    }
}

void array_dump_temperatures(int a[YEARS]) {
    for (unsigned int year = 0u; year < YEARS; year++) {
        fprintf(stdout, "Temperatura maxima en %u: %d ºC\n", year+1980, a[year]);
    }
}

const char* getMonthName(month_t month) {
    switch (month) {
        case january: return "January";
        case february: return "February";
        case march: return "March";
        case april: return "April";
        case may: return "May";
        case june: return "June";
        case july: return "July";
        case august: return "August";
        case september: return "September";
        case october: return "October";
        case november: return "November";
        case december: return "December";
   }
   return "0"; //Si no pongo este return al compilar tengo un warning. 
}

void array_dump_rainfall(month_t a[YEARS]) {
    for (unsigned int year = 0u; year < YEARS; year++) {
        fprintf(stdout, "Mes con mayores precipitaciones en %u: %s\n", year+1980, getMonthName(a[year]));
    }
}

void array_from_file(WeatherTable array, const char *filepath) {
    FILE *file = NULL;

    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }

    unsigned int k_year = 0u;
    unsigned int k_month = 0u;
    unsigned int k_day = 0u;
    while (!feof(file)) {
        int res = fscanf(file, " %u %u %u ", &k_year, &k_month, &k_day);
        if (res != 3) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
        Weather weather = weather_from_file(file);
        /* Completar acá: Guardar la medición de clima en el arreglo multidimensional */
        array[k_year-FST_YEAR][k_month-1][k_day-1] = weather;
    }
    fclose(file);
}
