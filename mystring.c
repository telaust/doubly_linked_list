#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


typedef struct str
{
	uint8_t* data;
	uint8_t length;
	uint8_t buffer;
}str_t;


static str_t*
string_create(uint8_t length)
{
	str_t* string = malloc(sizeof (str_t));
	string->data = (uint8_t*) malloc(length);
	string->length = length;
	string->buffer = 0;
}

static void
string_free(str_t* string)
{
	free(string->data);
	free(string);
}

static uint8_t
string_length(str_t* string)
{
	return string->length;
}

static str_t*
string_dup(const char* str)
{
	str_t* string = string_create(sizeof(str));
	memcpy(string->data, str, string->length);
	string->buffer = string->length;

	return string;
}

static void
string_print(str_t* string, FILE* file)
{
	fwrite(string->data, sizeof(uint8_t), string->length, file);
}




static str_t*
string_concat(str_t* left, str_t* right)
{
	str_t* string = string_create(left->length + right->length);
	memcpy(string->data, left, left->length);
	memcpy(string->data + left->length, right, right->length);
	string->buffer = string->length;

	return string;
}

int main()
{

	str_t* string = string_dup("hello\n");


	string_print(string, stdout);

	return 0;
}