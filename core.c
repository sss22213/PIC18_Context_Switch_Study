#include "core.h"
task Task_Create(void (*func1)(void))
{
    task new_task;
    new_task.func=func1;
    new_task.S_TOSH=(unsigned char)(((unsigned int)func1 &  0xFF00) >> 8);
    new_task.S_TOSL=(unsigned char)((unsigned int)func1 & 0x00FF);
    new_task.S_TOSU=0x00;
    return new_task;
}
void Task_Empty()
{
    TRISA=0x00;
    TRISB=0x00;
    TRISC=0x00;
    TRISD=0x00;
    //GPIOX
    PORTA=0x00;
    PORTB=0x00;
    PORTC=0x00;
    PORTD=0x00;
    //LATX
    LATA=0x00;
    LATB=0x00;
    LATC=0x00;
    LATD=0x00;
}

void Task_Save(task* task1)
{
    //Save GPIO Register
    //TRISX
    task1->reg[0]=TRISA;
    task1->reg[1]=TRISB;
    task1->reg[2]=TRISC;
    task1->reg[3]=TRISD;
    //GPIOX
    task1->reg[4]=PORTA;
    task1->reg[5]=PORTB;
    task1->reg[6]=PORTC;
    task1->reg[7]=PORTD;
    //LATX
    task1->reg[8]=LATA;
    task1->reg[9]=LATB;
    task1->reg[10]=LATC;
    task1->reg[11]=LATD;
}
void TASK_Restore(task* task1)
{
    //Restore GPIO Register
    //TRISX
    TRISA=task1->reg[0];
    TRISB=task1->reg[1];
    TRISC=task1->reg[2];
    TRISD=task1->reg[3];
    //GPIOX
    PORTA=task1->reg[4];
    PORTB=task1->reg[5];
    PORTC=task1->reg[6];
    PORTD=task1->reg[7];
    //LATX
    LATA=task1->reg[8];
    LATB=task1->reg[9];
    LATC=task1->reg[10];
    LATD=task1->reg[11];


}
void TASK_Init(task* task1)
{
    //Save GPIO Register
    //TRISX
    task1->reg[0]=0x00;
    task1->reg[1]=0x00;
    task1->reg[2]=0x00;
    task1->reg[3]=0x00;
    //GPIOX
    task1->reg[4]=0x00;
    task1->reg[5]=0x00;
    task1->reg[6]=0x00;
    task1->reg[7]=0x00;
    //LATX
    task1->reg[8]=0x00;
    task1->reg[9]=0x00;
    task1->reg[10]=0x00;
    task1->reg[11]=0x00;
    Task_Empty();

}

