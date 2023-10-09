#pragma once

#include "include/interfaces.h"
#include "interfaces.h"
#include <memory>

class SetStateHandler : public mw_tools::servers::IPostHandler {
public:
    SetStateHandler(std::shared_ptr<IState> state);

    virtual bool ProcessRequest(const std::string& body);
private:
    std::shared_ptr<IState> m_state;
    uint8_t m_controlPin;
};