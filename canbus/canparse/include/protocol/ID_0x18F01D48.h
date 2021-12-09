#pragma once 
#include "protocol.h" 
class ID_0x18F01D48:public protocol{
  public:
    ID_0x18F01D48();
    virtual ~ID_0x18F01D48()=default;
    virtual void Update(uint8_t *data) override;
    void Reset() override;
    double flwSteeringWheelAngel();
    void UpdateflwSteeringWheelAngel();
    double flwWheelSpd();
    void UpdateflwWheelSpd();
    double flwstdinfo();
    void Updateflwstdinfo();
    double stateinfo1();
    void Updatestateinfo1();
    double stateinfo23();
    void Updatestateinfo23();
    double stateinfo4();
    void Updatestateinfo4();
    double stateinfo5();
    void Updatestateinfo5();
    double stateinfo6();
    void Updatestateinfo6();
    double stateinfo7();
    void Updatestateinfo7();
  private:
    double flwSteeringWheelAngel_;
    double flwWheelSpd_;
    double flwstdinfo_;
    double stateinfo1_;
    double stateinfo23_;
    double stateinfo4_;
    double stateinfo5_;
    double stateinfo6_;
    double stateinfo7_;
};
