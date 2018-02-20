#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include "IBuffer.h"

class CircularBuffer : public IBuffer
{
public:

	CircularBuffer(int size)
	{
		buffer = new char[size];
		bufferSize = size - 1;
		wrIndex = 0;
		rdIndex = 0;
	}
	~CircularBuffer()
	{
		delete[] buffer;
		bufferSize = 0;
	}

	bool isEmpty()
	{
		return (wrIndex == rdIndex);
	}

	bool isFull()
	{
		int increasedWrIndex = wrIndex + 1;
		if (increasedWrIndex > bufferSize)
			increasedWrIndex = 0;

		return (increasedWrIndex == rdIndex);
	}

	bool isAlmostFullYetNotEmpty()
	{
		return (!isFull() && !isEmpty());
	}

	void push(char c)
	{
		if (isFull())
			return;

		wrIndex++;		
		if (wrIndex > bufferSize)
			wrIndex = 0;

		buffer[wrIndex] = c;
	}

	char pop()
	{
		if (isEmpty())
			return 0x00;

		rdIndex++;
		if (rdIndex > bufferSize)
			rdIndex = 0;

		return buffer[rdIndex];
	}

private:
	int wrIndex, rdIndex, bufferSize;
	char *buffer;
};
#endif // !CIRCULAR_BUFFER_H_