#include "protocol.h"
constexpr int32_t BYTE_LENGTH = static_cast<int32_t>(sizeof(int8_t) * 8);
const uint8_t RANG_MASK_1_L[] = {0x01, 0x03, 0x07, 0x0F,
                                 0x1F, 0x3F, 0x7F, 0xFF};
const uint8_t RANG_MASK_0_L[] = {0xFE, 0XFC, 0xF8, 0xF0,
                                 0xE0, 0xC0, 0x80, 0x00};
uint8_t GetByte(const uint8_t *byte,const int32_t start_pos, const int32_t length){
  if (start_pos > BYTE_LENGTH - 1 || start_pos < 0 || length < 1) {
    return 0x00;
  }
  int32_t end_pos = std::min(start_pos + length - 1, BYTE_LENGTH - 1);
  int32_t real_len = end_pos + 1 - start_pos;
  uint8_t result = static_cast<uint8_t>( (*byte) >> start_pos);
  result &= RANG_MASK_1_L[real_len - 1];
  return result;
}
void SetByte(uint8_t *byte,const int32_t start_pos, const int32_t length,const uint8_t value){
  if (start_pos > BYTE_LENGTH - 1 || start_pos < 0 || length < 1) {
    return;
  }
  int32_t end_pos = std::min(start_pos + length - 1, BYTE_LENGTH - 1);
  int32_t real_len = end_pos + 1 - start_pos;
  uint8_t current_value_low = 0x00;
  if (start_pos > 0) {
    current_value_low = *byte & RANG_MASK_1_L[start_pos - 1];
  }
  uint8_t current_value_high = *byte & RANG_MASK_0_L[end_pos];
  uint8_t middle_value = value & RANG_MASK_1_L[real_len - 1];
  middle_value = static_cast<uint8_t>(middle_value << start_pos);
  *byte = static_cast<uint8_t>(current_value_high + middle_value +
                                 current_value_low);

}
double BoundedValue(const double lowerbound,const double upperbound, const double value){
  double ret=0;
  if(value > upperbound) ret = upperbound;
  else if(value < lowerbound) ret = lowerbound;
  else ret = value;
  return ret;
}
void protocol::Reset(){
  id_=is_error_=is_rtr_=is_extended_=dlc_=0;
  for(int i=0;i<8;i++) data_[i]=0;
}
unsigned int protocol::id(){return id_;};
unsigned int protocol::is_error(){return is_error_;};
unsigned int protocol::is_rtr(){return is_rtr_;};
unsigned int protocol::is_extended(){return is_extended_;};
unsigned char protocol::dlc(){return dlc_;};