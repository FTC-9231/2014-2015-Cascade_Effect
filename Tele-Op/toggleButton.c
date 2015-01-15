// Toggle button
// this class implements a stateful button whose value changes each time a given physical
// button is pushed and then released. The typical usage is a two-state toggle for something
// that, for example, goes fully up or down. However, it can have more than two states for
// something that, for example, cycles through a series of positions: up, middle, down, middle, ...

typedef struct {
	short m_buttonNumber;	// id of the button that drives this toggle
	bool m_buttonValue;		// last sampled physical button value
	short m_toggleValue;	// current value of the toggled output
	short m_numStates;		// number of states the toggle moves through
} ToggleButton;

void ToggleButton_init(ToggleButton* this, short buttonNumber, short numStates, short initvalue)
{
	this->m_buttonNumber = buttonNumber;
	this->m_toggleValue = initvalue;
	this->m_buttonValue = joy1Btn(this->m_buttonNumber) != 0;
	this->m_numStates = numStates;
}

// look at the current state of the controlling button and update the toggle if it has changed.
// return true iff the state has changed, since that's when the caller might want to do something.
bool ToggleButton_process(ToggleButton* this)
{
	// get the appropriate button value
	bool button = joy1Btn(this->m_buttonNumber) != 0;

	// if button was up and now it's down, cycle the state of the value to the next one
	bool changed = (this->m_buttonValue==false && button);
	if (changed)
		this->m_toggleValue = (this->m_toggleValue+1) % this->m_numStates;

	// remember the current state of the physical button
	this->m_buttonValue = button;

	return changed;
}

// return the current state of the toggle.
short ToggleButton_value(ToggleButton* this)
{
	return this->m_toggleValue;
}
