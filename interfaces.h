#pragma once

class IState {
    public:
    virtual bool GetState() const = 0;
    virtual void SetState(bool state) = 0;
};