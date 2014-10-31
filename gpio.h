#ifndef GPIO_H
#define GPIO_H

int gpio_export(const char *pin);
int gpio_unexport(const char *pin);
int gpio_direction(const char *pin, const char *direction);
int gpio_value(const char *pin, const char *value);

#endif
