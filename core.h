/* 
 * File:   core.h
 * Author: bohome
 *
 * Created on 2016年2月12日, 下午 8:21
 */

#ifndef CORE_H
#define	CORE_H
#define _XTAL_FREQ 4000000
#include "htc.h"
typedef struct _task
{
  void (*func)(void);
  //unsigned int (Program_Count);
  unsigned int count;
  //Save Stack Value(Program Counter)
  unsigned char S_TOSL;
  unsigned char S_TOSH;
  unsigned char S_TOSU;
  //Save Regeister
  unsigned char reg[12];
}task;

unsigned char index=0;
task tt[2];
task Task_Create(void (*)(void));
void Task_Save(task* task1);
void TASK_Restore(task* task1);
void Task_Empty(void);
void TASK_Init(task* task1);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* CORE_H */

