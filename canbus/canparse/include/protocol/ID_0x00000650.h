#pragma once
#include "protocol.h" 
class ID_0x00000650:public protocol{
  public:
    ID_0x00000650();
    virtual ~ID_0x00000650()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double uwbDis();
    void UpdateuwbDis();
    double uwbFW();
    void UpdateuwbFW();
    double uwbSta();
    void UpdateuwbSta();
    double uwbZT();
    void UpdateuwbZT();
  private:
    double uwbDis_;
    double uwbFW_;
    double uwbSta_;
    double uwbZT_;
};
