#include "monty.h"
/**
 * _error - handelling error
 * @er: error
 */
void _error(int er, ...)
{
	va_list arg;
	char *op;
	int line;

	va_start(arg, err);
	switch (er)
	{
		case 1:
			fprint(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(arg, char*));
			break;
		case 3:
			line = va_arg(arg, int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	_free();
	exit(EXIT_FAILURE);
}
/**
 * error1 - handel errors
 * @er: errors
 */
void error1(int er, ...)
{
	int line;
	va_list arg;

	va_start(arg, er);
	line = va_arg(arg, int);
	switch (er)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",  va_arg(arg, int));
			break;
		case 8:
			line =  va_arg(arg, unsigned int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line, op);
			break;
		default:
			break;
	}
	_free();
	exit(EXIT_FAILURE);
}


