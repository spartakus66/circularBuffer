// bufferProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include "CircularBuffer.h"

int main()
{
	IBuffer *buffer = new CircularBuffer(10);

	for (int i = 0; i < 12; i++)
		buffer->push('a' + i);

	if(!buffer->isEmpty())
	for (int i = 0; i < 12; i++)
		printf("%.2X\n", buffer->pop());

	for (int i = 0; i < 8; i++)
		buffer->push('f' + i);

	for (int i = 0; i < 8; i++)
		printf("%d: %c\n", i, buffer->pop());

	for (int i = 0; i < 5; i++)
		buffer->push('n' + i);

	for (int i = 0; i < 5; i++)
		printf("%c\n", buffer->pop());

	getchar();
	return 0;
}