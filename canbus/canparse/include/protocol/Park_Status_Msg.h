#pragma once
#include "protocol.h" 
class Park_Status_Msg:public protocol{
  public:
    Park_Status_Msg();
    virtual ~Park_Status_Msg()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double act_fault_level();
    void Updateact_fault_level();
    double act_work_mode();
    void Updateact_work_mode();
    double checksum();
    void Updatechecksum();
    double park_status();
    void Updatepark_status();
    double rolling_counter();
    void Updaterolling_counter();
  private:
    double act_fault_level_;
    double act_work_mode_;
    double checksum_;
    double park_status_;
    double rolling_counter_;
};
