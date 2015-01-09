// input filters
// these are useful for doing things like softening joystick input transitions
// before passing them along to motors to reduce the strain on them.

// AverageFilter
// this filter keeps a circular buffer of the last N values and returns the average of them.
typedef struct
{
	short m_bufsize;			// number of active entries in the buffer (filter window size)
	short m_next;					// index of the next value to be replaced
	short m_buffer[100];	// buffer (fixed size, of which m_bufsize are used)
} AverageFilter;

void AverageFilter_init(AverageFilter* this, short bufsize, short initialValue)
{
	this->m_bufsize = bufsize;
	for (int i=0; i<bufsize; i++)
		this->m_buffer[i] = initialValue;
	this->m_next = 0;
}

void AverageFilter_process(AverageFilter* this, short value)
{
	this->m_buffer[this->m_next++] = value;		// save the new input value in the next slot and incr index
	if (this->m_next >= this->m_bufsize)
		this->m_next = 0;												// loop around back to front of buffer
}

int AverageFilter_value(AverageFilter* this)
{
	int sum = 0;
	for (int i=0; i<this->m_bufsize; i++)
		sum += this->m_buffer[i];
	return sum / this->m_bufsize;
}

// RampFilter
// this filter limits the change applied to the filtered value at each iteration,
// so it ramps the output linearly from one input (target) value to the next.
typedef struct
{
	int m_limitSlope;
	int m_currentValue;
} RampFilter;

void RampFilter_init(RampFilter* this, int limitSlope, int initialValue)
{
	this->m_limitSlope = limitSlope;
	this->m_currentValue = initialValue;
}

int RampFilter_process(RampFilter* this, int target)
{
	if (this->m_currentValue < target)
	{
		this->m_currentValue += this->m_limitSlope;
		if (this->m_currentValue > target)
			this->m_currentValue = target;
	}
	else
	if (this->m_currentValue > target)
	{
		this->m_currentValue -= this->m_limitSlope;
		if (this->m_currentValue < target)
			this->m_currentValue = target;
	}
	// else we're already at the target value

	// return the current filtered value
	return this->m_currentValue;
}

int RampFilter_value(RampFilter* this)
{
	// return the current filtered value
	return this->m_currentValue;
}


// ThresholdFilter
// this is a stateless filter that just removes noise by returning zero for inputs
// whose absolute value falls below a given threshold
typedef struct
{
	int m_thresholdValue;
} ThresholdFilter;

void ThresholdFilter_init(ThresholdFilter* this, int thresholdValue)
{
	this->m_thresholdValue = thresholdValue;
}

int iabs(int x)
{
	return (x < 0) ? -x : x;
}

int ThresholdFilter_process(ThresholdFilter* this, int input)
{
	if (iabs(input) > this->m_thresholdValue)
		return input;
	else
		return 0;
}
