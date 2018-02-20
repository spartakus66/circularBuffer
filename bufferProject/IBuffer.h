struct IBuffer 
{
	virtual ~IBuffer() {}
	virtual void push(char c) = 0;
	virtual char pop() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual bool isAlmostFullYetNotEmpty() = 0; // ani pełny ani pusty
};