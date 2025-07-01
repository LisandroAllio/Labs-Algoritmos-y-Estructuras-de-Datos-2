/*
  @file weather_utils.h
  @brief weather functions declarations.
*/
#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include "array_helpers.h"

/**
 * @brief Returns the historical minimum temperature recorded 
 * @param[in] a array with weather mesuarement to be read
 */
int minimum_temperature(WeatherTable a);

/**
 * @brief Returns an array with the maximum temperature recorded in each year 
 * @param[in] a array with weather mesuarement to be read
 * @param[in] a array wich will contain the weather temperatures
 */
void array_max_temperature(WeatherTable a, int output[YEARS]);

/**
 * @brief Returns an array with the months with biggest amount of rainfall recorded in each year 
 * @param[in] a array with weather mesuarement to be read
 * @param[in] a array wich will contain the months
 */
void array_months_rainfall(WeatherTable a, month_t output[YEARS]);


#endif


