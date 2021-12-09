#pragma once 
#include "protocol.h" 
class ID_0x04EF8480:public protocol{
  public:
    ID_0x04EF8480();
    virtual ~ID_0x04EF8480()=default;
    virtual void Update(uint8_t *data) override;
    void Reset() override;
    double comControlCmd();
    void SetcomControlCmd(double comControlCmd);
    void Set_p_comControlCmd(double comControlCmd);
    double conDegCmd();
    void SetconDegCmd(double conDegCmd);
    void Set_p_conDegCmd(double conDegCmd);
    double conRtCmd();
    void SetconRtCmd(double conRtCmd);
    void Set_p_conRtCmd(double conRtCmd);
  private:
    double comControlCmd_;
    double conDegCmd_;
    double conRtCmd_;
};
