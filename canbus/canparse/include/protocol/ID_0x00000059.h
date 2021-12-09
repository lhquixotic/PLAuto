#pragma once
#include "protocol.h" 
class ID_0x00000059:public protocol{
  public:
    ID_0x00000059();
    virtual ~ID_0x00000059()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double flwLonAcc();
    void UpdateflwLonAcc();
    double flwRollRt();
    void UpdateflwRollRt();
    double flwTranAcc();
    void UpdateflwTranAcc();
    double flwVerAcc();
    void UpdateflwVerAcc();
  private:
    double flwLonAcc_;
    double flwRollRt_;
    double flwTranAcc_;
    double flwVerAcc_;
};
