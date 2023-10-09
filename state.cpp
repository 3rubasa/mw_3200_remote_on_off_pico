#include "state.h"
#include "hardware/gpio.h"

State::State(bool initState, uint8_t controlPin) : 
    m_state(initState),
    m_controlPin(controlPin)
{
        gpio_init(m_controlPin);
        gpio_set_dir(m_controlPin, GPIO_OUT);
        if (initState)
            gpio_put(m_controlPin, 1);
        else
            gpio_put(m_controlPin, 0);
}

bool State::GetState() const {
    return m_state;
};

void State::SetState(bool state) {
    if (state) {
         gpio_put(m_controlPin, 1);
    } else {
         gpio_put(m_controlPin, 0);
    }

    m_state = state;
};