#pragma once

#include "interfaces.h"

class State : public IState {
public:
    State(bool initState);

    virtual bool GetState() const;
    virtual void SetState(bool state);

private:
    bool m_state;
};