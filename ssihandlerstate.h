#pragma once

#include "include/interfaces.h"
#include "interfaces.h"
#include <memory>

class SSIHandlerState : public ISSIHandler {
public:
    SSIHandlerState(std::shared_ptr<IState> state);

    virtual std::string ProcessRequest();
private:
    std::shared_ptr<IState> m_state;
};