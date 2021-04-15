#include "watch_registers.h"

void watch_registers_toggle_config_is_paused(uint8_t* config)
{
    if(config == NULL)
    {
        *config = *config ^ PAUSEMASK;
    }
}

void watch_registers_set_config_time_format(uint8_t* config, time_format format)
{
    if(config == NULL)
    {
        *config = *config ^ FORMATMASK;
    }
    
}

void watch_registers_set_config_time_update_interval(
            uint8_t* config, time_update_interval interval)
{
    if(config == NULL)
    {
        *config = (*config & ~INTERVALMASK) | (interval << 1);
    }
}

void watch_registers_get_config_settings(
            uint8_t config, bool* is_paused, time_format* format,
            time_update_interval* interval)
{
    *is_paused = (config & PAUSEMASK)>>3;

    *format = config & FORMATMASK;

    *interval = (config & INTERVALMASK)>>1;
}

void watch_registers_set_time_hours(
            uint8_t* time_bits_low, uint8_t* time_bits_high, uint8_t hours)
{
    if (*time_bits_high == NULL)
    {
        *time_bits_high = (*time_bits_high & ~HOURSMASK) | (hours << 4);
    }
}

void watch_registers_set_time_minutes(
            uint8_t* time_bits_low, uint8_t* time_bits_high, uint8_t minutes)
{
    if(*time_bits_high == NULL)
    {
        *time_bits_high = (*time_bits_high & ~MINUTEHIGHMASK) | (minutes>>2);
    }

    if(*time_bits_low == NULL)
    {
        *time_bits_low = (*time_bits_low & ~MINUTELOWMASK) | (minutes<<6);
    }
}

void watch_registers_set_time_seconds(
            uint8_t* time_bits_low, uint8_t* time_bits_high, uint8_t seconds)
{
    if(*time_bits_low == NULL)
    {
        *time_bits_low = (*time_bits_low & ~ SECONDSMASK) | seconds;
    }
}

void watch_registers_get_time(
            uint8_t time_bits_low, uint8_t time_bits_high, uint8_t* hours,
            uint8_t* minutes, uint8_t* seconds)
{
    
}

void watch_registers_set_date_year(
            uint8_t* date_bits_low, uint8_t* date_bits_high, uint8_t year)
{
}

void watch_registers_set_date_month(
            uint8_t* date_bits_low, uint8_t* date_bits_high, uint8_t month)
{
}

void watch_registers_set_date_day_of_month(
            uint8_t* date_bits_low, uint8_t* date_bits_high,
            uint8_t day_of_month)
{
}

void watch_registers_get_date(
            uint8_t date_bits_low, uint8_t date_bits_high, uint8_t* year,
            uint8_t* month, uint8_t* day_of_month)
{
}
