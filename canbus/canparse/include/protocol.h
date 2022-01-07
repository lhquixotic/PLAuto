#ifndef _PROTOCOL_
#define _PROTOCOL_

#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
uint8_t GetByte(const uint8_t *byte,const int32_t start_pos, const int32_t length);
void SetByte(uint8_t *byte,const int32_t start_pos, const int32_t length,const uint8_t value);
double BoundedValue(const double lowerbound,const double upperbound, const double value);
class protocol{
  public:
    virtual void Update(uint8_t *data)=0;
    protocol()=default;
    virtual ~protocol()=default;
    virtual void Reset();
    unsigned int id();
    unsigned int is_error();
    unsigned int is_rtr();
    unsigned int is_extended();
    unsigned char dlc();
  protected:
    uint8_t data_[8];
    unsigned int id_:29; ///< CAN ID (11 or 29 bits valid, depending on is_extended member
    unsigned int is_error_:1; ///< marks an error frame (only used internally)
    unsigned int is_rtr_:1; ///< frame is a remote transfer request
    unsigned int is_extended_:1; ///< frame uses 29 bit CAN identifier
    unsigned char dlc_;
};
#endif