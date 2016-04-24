#include "main.h"

unsigned char Stack_Sav;
void func2()
{
   TRISB=0x00;
   NOP();
   NOP();
   for(int i=0;i<10000;i++)
   {
       NOP();
   }
   while(1)
   {
        PORTB=0x01;
        NOP();
        NOP();
        NOP();
   }
}
void func1()
{
    TRISB=0x00;
    NOP();
    NOP();
    while(1)
    {
        unsigned char bytess=0x02;
        NOP();
        NOP();
        PORTB=bytess;
        NOP();
        NOP();
        NOP();
    }
}
int main()
{
    int bbytess=0x00;
    task t1;
    task t2;
    t1=Task_Create(func1);
    t2=Task_Create(func2);
    tt[0]=t1;
    tt[1]=t2;
    //Empty
    Task_Empty();
    TASK_Init(&tt[0]);
    TASK_Init(&tt[1]);
    //
    index=0;
    //timer imtrrupt init
    T1CON=0B11111101;
    TMR1H=(65536-2)/256;
    TMR1L=(65536-2)%256;
    TMR1IF=0;
    TMR1IP=1;
    TMR1IE=1;
    IPEN=1;
    GIEH=1;
    //t1.func();;*/
    while(1)
    {
        tt[index].func();
        bbytess+=index;
        NOP();
    }
    return 0;
}

void interrupt  HighInt()
{
    if(TMR1IE && TMR1IF)
    {
       TMR1IE=0;
       TMR1IF=0;
       Task_Save(&tt[index]);
       //Empty
       Task_Empty();
       //Save Address from Stack
       tt[index].S_TOSL=TOSL;
       tt[index].S_TOSH=TOSH;
       tt[index].S_TOSU=TOSU;
       index++;
       index=index%2;
       TASK_Restore(&tt[index]);
       TOSH=tt[index].S_TOSH;
       TOSL=tt[index].S_TOSL;
       TOSU=tt[index].S_TOSU;
       tt[index].count++;
       // TMR1IE=0;
       TMR1H=(65536-5)/256;
       TMR1L=(65536-5)%256;
       TMR1IE=1;
    }

}
