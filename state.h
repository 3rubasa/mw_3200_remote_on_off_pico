#pragma once

#include "interfaces.h"

#include <cstdint>

class State : public IState {
public:
    State(bool initState, uint8_t controlPin);

    virtual bool GetState() const;
    virtual void SetState(bool state);

private:
    bool m_state;
    uint8_t m_controlPin;
};