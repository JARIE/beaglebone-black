/*
 * File: gpio.h
 * Created: 23, October 2014
 *
 * Copyright(c) 2014 Jarielle Catbagan
 *
 * BSD-style license
 */

#ifndef GPIO_H
#define GPIO_H

int gpio_export(const char *pin);
int gpio_unexport(const char *pin);
int gpio_direction(const char *pin, const char *direction);
int gpio_value(const char *pin, const char *value);

#endif
