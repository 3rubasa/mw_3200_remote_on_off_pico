#pragma once
#include <cstdint>

class IState {
    public:
    virtual bool GetState() const = 0;
    virtual void SetState(bool state) = 0;
};

class II2CNode {
    public:
    virtual void Init() = 0;
    virtual uint8_t ReadByte(uint8_t regAddr) = 0;
    virtual uint16_t ReadWord(uint8_t regAddr) = 0;
    virtual void WriteByte(uint8_t regAddr, uint8_t val) = 0;
};

class ICPF8591Device {
    public:
    virtual float readVoltage() = 0;
    virtual void writeVoltage(float voltage) = 0;
    virtual float getLastReadVoltage() = 0;
    virtual float getLastWrittenVoltage() = 0;
};