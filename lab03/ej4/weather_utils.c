/*
  @file weather_utils.c
  @brief Weather functions implementation
*/
#include "limits.h"
#include "weather_utils.h"

int minimum_temperature(WeatherTable a){
    int min_temp = INT_MAX; 
    for (int y = 0; y < YEARS; y++){   //Recorremos todo el arreglo
        for (month_t m = january; m <= december; m++){
            for (int d = 0; d < DAYS; d++){
                if (a[y][m][d]._min_temp < min_temp) { 
                    min_temp = a[y][m][d]._min_temp;
                }
            }
        }
    }
    return min_temp; 
}

void array_max_temperature(WeatherTable a, int output[YEARS]){
    for (unsigned int y = 0; y < YEARS; y++) {
        int max_temp_year = INT_MIN;   //Se resetea con cada año

        for (month_t m = january; m <= december; m++){
            for (int d = 0; d < DAYS; d++){
                if (a[y][m][d]._max_temp > max_temp_year) {
                    max_temp_year = a[y][m][d]._max_temp;
                }
            }
        }
        output[y] = max_temp_year;
    }
}

void array_months_rainfall(WeatherTable a, month_t output[YEARS]){
    month_t max_month;
    unsigned int max_rain, monthly_rain;

    for (unsigned int y = 0; y < YEARS; y++) {
        max_month = january;
        max_rain = 0;        //Se resetean con cada año

        for (month_t m = january; m <= december; m++){
            monthly_rain = 0;        //Se resetea con cada año
            for (int d = 0; d < DAYS; d++){    //Calcula la lluvia mensual
                monthly_rain = monthly_rain + a[y][m][d]._rainfall; 
            }
            if (monthly_rain > max_rain) {
                max_month = m;
                max_rain = monthly_rain;
            }
        }
        output[y] = max_month;
    }


}
