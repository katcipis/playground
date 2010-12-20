#ifndef CONSTANTS_HPP_9UVATHU7
#define CONSTANTS_HPP_9UVATHU7

#include <iostream>

#define CHECKPOINT 
#define PRU_LOG0  std::cout<<"[CP] "<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<std::endl;
#define PRU_LOG1(x)  std::cout<<"[CP: "<<(x)<<"] "<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<std::endl;
#define PRU_LOG2(x,y)  std::cout<<"[CP: "<<(x)<<", "<<(y)<<"] "<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<std::endl;
#define PRU_LOG3(x,y,z)  std::cout<<"[CP: "<<(x)<<", "<<(y)<<", "<<(z)<<"] "<<__FILE__<<":"<< __LINE__ <<":"<<__FUNCTION__<<std::endl;

#define BOTH_SIDES wxLEFT | wxRIGHT
#define FORM_BORDERS wxLEFT | wxRIGHT | wxBOTTOM

#define WxToStd(x) ((x).utf8_str().data())
#define StdToWx(x) (wxString::FromUTF8((x).c_str()))

#endif /*CONSTANTS_HPP_9UVATHU7*/
