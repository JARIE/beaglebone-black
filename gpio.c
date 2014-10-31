#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "gpio.h"

int gpio_export(const char *pin)
{
	int fd = open("/sys/class/gpio/export", O_WRONLY);
	if(fd == -1)
		return -1;

	unsigned int digit_length = 0;
	const char *pin_mod = pin;

	while(*(pin_mod++) != '\0') 
		++digit_length;

	int ret = write(fd, pin, digit_length);
	if(ret == -1) {
		close(fd);
		return -1;
	}
	else {
		close(fd);
		return 0;
	}
}

int gpio_unexport(const char *pin)
{
	int fd = open("/sys/class/gpio/unexport", O_WRONLY);
	if(fd == -1)
		return -1;

	unsigned int digit_length = 0;
	const char *pin_mod = pin;

	while(*(pin_mod++) != '\0') 
		++digit_length;

	int ret = write(fd, pin, digit_length);
	if(ret == -1) {
		close(fd);
		return -1;
	}
	else {
		close(fd);
		return 0;
	}
}

int gpio_direction(const char *pin, const char *direction)
{
	char base_path[] = "/sys/class/gpio/gpio";
	unsigned int pin_length = 0, dir_length = 0;
	const char *pin_mod = pin, *dir_mod = direction;

	while(*(pin_mod++) != '\0')
		++pin_length;

	while(*(dir_mod++) != '\0')
		++dir_length;

	char *path = malloc((sizeof(base_path)/sizeof(char)) + pin_length + 1 + 10);
	if(path == NULL) 
		return -1;

	strcpy(path, base_path);

	strcat(path, pin);
	strcat(path, "/direction");

	int fd = open(path, O_WRONLY);
	if(fd == -1) {
		free(path);
		printf("error opening file\n");
		return -1;
	}
	
	int ret = write(fd, direction, dir_length);
	if(ret == -1) {
		printf("error writing\n");
		free(path);
		close(fd);
		return -1;
	}
	else if(ret == 0) {
		printf("error none written\n");
		free(path);
		close(fd);
		return -1;
	}
	else {
		free(path);
		close(fd);
		return 0;
	}
}

int gpio_value(const char *pin, const char *value) 
{
	char base_path[] = "/sys/class/gpio/gpio";
	unsigned int pin_length = 0, val_length = 0;
	const char *pin_mod = pin, *val_mod = value;

	while(*(pin_mod++) != '\0') 
		++pin_length;

	while(*(val_mod++) != '\0')
		++val_length;

	char *path = malloc((sizeof(base_path)/sizeof(char)) + 1 + 6);
	if(path == NULL)
		return -1;

	strcpy(path, base_path);

	strcat(path, pin);
	strcat(path, "/value");

	int fd = open(path, O_WRONLY);
	if(fd == -1) {
		free(path);
		printf("error opening file\n");
		return -1;
	}

	int retval = write(fd, value, val_length);
	if(retval == -1) {
		printf("error writing\n");
		free(path);
		close(fd);
		return -1;
	}
	else if(retval == 0) {
		printf("error none written\n");
		free(path);
		close(fd);
		return -1;
	}
	else {
		free(path);
		close(fd);
		return 0;
	}
}








