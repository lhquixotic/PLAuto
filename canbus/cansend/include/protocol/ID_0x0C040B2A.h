#pragma once 
#include "protocol.h" 
class ID_0x0C040B2A:public protocol{
  public:
    ID_0x0C040B2A();
    virtual ~ID_0x0C040B2A()=default;
    virtual void Update(uint8_t *data) override;
    void Reset() override;
    double conAccReq();
    void SetconAccReq(double conAccReq);
    void Set_p_conAccReq(double conAccReq);
    double conSta();
    void SetconSta(double conSta);
    void Set_p_conSta(double conSta);
    double controlScheme();
    void SetcontrolScheme(double controlScheme);
    void Set_p_controlScheme(double controlScheme);
    double accPedOpenReq();
    void SetAccPedOpenReq(double accPedOpenReq);
    void Set_p_accPedOpenReq(double accPedOpenReq);
    double brkPedOpenReq();
    void SetBrkPedOpenReq(double brkPedOpenReq);
    void Set_p_brkPedOpenReq(double brkPedOpenReq);
  private:
    double conAccReq_;
    double conSta_;
    double controlScheme_;
    double accPedOpenReq_;
    double brkPedOpenReq_;
};
