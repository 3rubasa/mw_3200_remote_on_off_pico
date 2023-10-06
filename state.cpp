#include "state.h"

State::State(bool initState) : 
    m_state(initState) 
{}

bool State::GetState() const {
    return m_state;
};

void State::SetState(bool state) {
    m_state = state;
};