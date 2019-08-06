/**
  ******************************************************************************
  * @file	qinnew.h
  * @author	Thor Zhou	
  * @email	dongxvzhou@gmail.com
  * @date	2019-07-18
  ******************************************************************************
  */
#ifndef qinnew_h
#define qinnew_h


// Version of the EEPROM data. Will be used to migrate existing data from older versions of Grbl
// when firmware is upgraded. Always stored in byte 0 of eeprom
//eeprom 数据的版本。在升级固件时, 将用于将现有数据从旧版本的 grbl 中迁移。始终存储在 eeprom 的字节0中
#define SETTINGS_VERSION 1  // NOTE: Check settings_reset() when moving to next version.

#define minirobot

#define Purple

typedef struct {

  float D1;
  float A1;
  float A2;
  float A3;
  float D4;
  float L;

  uint8_t use_interpolation;//是否使用插补，0或1
  uint8_t interpolation_num;//插补的精细程度

  uint8_t use_compensation;//是否使用X轴补偿，0或1  暂时没实现等下
  uint8_t compensation_num;//补偿的脉冲个数

  uint8_t use_reset_pos;//是否再运动复位后再运动到初始位置的距离
} robot_t;


#define QINNEW_VERSION "20190806"


#define _use_reset_pos_  //是否在复位以后运动复位的距离！！！
//#define _use_compensation_  //是否启用X轴的补偿，暂时先用它没实现等下


//表示初始位置的笛卡尔坐标值
#define Cartesian_x (settings.robot_qinnew.A1 + settings.robot_qinnew.D4)//(208)
#define Cartesian_y (0)//(0)
#define Cartesian_z (settings.robot_qinnew.D1 + settings.robot_qinnew.A2 + settings.robot_qinnew.A3 + settings.robot_qinnew.L)//(143)
#define Cartesian_Rx (0)
#define Cartesian_Ry (0)
#define Cartesian_Rz (0)

#define serial2

#define mini6_board



//#define debug

void Inverse(double x_wrist,double y_wrist,double z_wrist,double alpha,double beta,double gama);
void InverseInit(void);
void go_reset_pos();
void Forward(double *angle);
void angle_to_coordinate();
void coordinate_to_angle();







#endif

