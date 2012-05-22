/*------------------------------------------------*/
/* --- 宏晶科技 STCMCU ---------------------------*/
/* --- Mobile: (86)13922805190 -------------------*/
/* --- Fax: 86-755-82944243 ----------------------*/
/* --- Tel: 86-755-82948412 ----------------------*/
/* --- Web: www.STCMCU.com -----------------------*/
/* 适用于: STC89C5xRC  STC89LE5xRC  --------------*/
/* ------- STC89C5xRD+ STC89LE5xRD+ --------------*/
/*------------------------------------------------*/

#ifndef __STC89_H__
#define __STC89_H__

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sfr  PSW        =   0xd0;       //程序状态字            Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //位描述                CY      AC      F0      RS1     RS0     OV      F1      P
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

sbit CY         =   PSW^7;      //进位标志
sbit AC         =   PSW^6;      //辅助进位标志
sbit F0         =   PSW^5;      //用户标志
sbit RS1        =   PSW^4;      //寄存器组选择位1
sbit RS0        =   PSW^3;      //寄存器组选择位0
sbit OV         =   PSW^2;      //溢出标志
sbit P          =   PSW^0;      //ACC的偶校验位

/////////////////////////////////

sfr  ACC        =   0xe0;       //累加器                Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

sbit ACC7       =   ACC^7;      //累加器第7位
sbit ACC6       =   ACC^6;      //累加器第6位
sbit ACC5       =   ACC^5;      //累加器第5位
sbit ACC4       =   ACC^4;      //累加器第4位
sbit ACC3       =   ACC^3;      //累加器第3位
sbit ACC2       =   ACC^2;      //累加器第2位
sbit ACC1       =   ACC^1;      //累加器第1位
sbit ACC0       =   ACC^0;      //累加器第0位

/////////////////////////////////

sfr  B          =   0xf0;       //B寄存器               Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  SP         =   0x81;       //堆栈指针              Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=0000,0111      0       0       0       0       0       1       1       1

/////////////////////////////////

sfr  DPL        =   0x82;       //数据指针低字节        Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

sfr  DPH        =   0x83;       //数据指针高字节        Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sfr  PCON       =   0x87;       //电源控制寄存器        Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //位描述                SMOD    SMOD0   -       POF     GF1     GF0     PD      IDL
                                //初始值=00x1,0000      0       0       x       1       0       0       0       0

#define SMOD        0x80        //串口波特率倍速位,置1可使波特率快1倍
#define SMOD0       0x40        //FE/SM0选择位,0:SCON.7为SM0 1:SCON.7为FE
#define POF         0x10        //上电复位标志位,上电时由硬件置1,需由软件清0
#define GF1         0x08        //通用标志位1
#define GF0         0x04        //通用标志位0
#define PD          0x02        //掉电控制位,写1可以使MCU进入PowerDown模式
#define IDL         0x01        //空闲控制位,写1可以使MCU进入Idle模式

/////////////////////////////////

sfr  WDT_CONTR  =   0xe1;       //看门狗定时器控制器    Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //位描述                -       -       EN_WDT  CLR_WDT IDL_WDT PS2     PS1     PS0
                                //初始值=xx00,0000      x       x       0       0       0       0       0       0

#define EN_WDT      0x20        //软件使能看门狗,打开后不能用软件的方式关闭
#define CLR_WDT     0x10        //清看门狗定时器
#define IDLE_WDT    0x08        //IDLE模式下,看门狗定时器是否继续计时

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sfr  AUXR       =   0x8e;       //辅助寄存器            Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //位描述                -       -       -       -       -       -       EXTRAM  S1BRS
                                //初始值=xxxx,xx00      x       x       x       x       x       x       0       0

#define EXTRAM      0x02        //内部扩展RAM禁能位,0:内部扩展RAM有效 1:禁用内部扩展RAM
#define ALEOFF      0x01        //禁止ALE信号输出,0:使能ALE信号输出 1:关闭ALE信号输出

/////////////////////////////////

sfr  AUXR1      =   0xa2;       //辅助寄存器1           Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //位描述                -       -       -       -       GF2     -       -       DPS
                                //初始值=xxxx,0xx0      x       x       x       x       0       x       x       0

#define GF2         0x08        //通用标志位2
#define DPS         0x01        //DPTR0/DPTR1选择位,0:DPTR0 1:DPTR1

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sfr  P0         =   0x80;       //I/O端口0              Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //位描述                P0.7    P0.6    P0.5    P0.4    P0.3    P0.2    P0.1    P0.0
                                //初始值=1111,1111      1       1       1       1       1       1       1       1

sbit P07        =   P0^7;       //I/O口P0.7
sbit P06        =   P0^6;       //I/O口P0.6
sbit P05        =   P0^5;       //I/O口P0.5
sbit P04        =   P0^4;       //I/O口P0.4
sbit P03        =   P0^3;       //I/O口P0.3
sbit P02        =   P0^2;       //I/O口P0.2
sbit P01        =   P0^1;       //I/O口P0.1
sbit P00        =   P0^0;       //I/O口P0.0

/////////////////////////////////

sfr  P1         =   0x90;       //I/O端口0              Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //位描述                P1.7    P1.6    P1.5    P1.4    P1.3    P1.2    P1.1    P1.0
                                //初始值=1111,1111      1       1       1       1       1       1       1       1

sbit P17        =   P1^7;       //I/O口P1.7
sbit P16        =   P1^6;       //I/O口P1.6
sbit P15        =   P1^5;       //I/O口P1.5
sbit P14        =   P1^4;       //I/O口P1.4
sbit P13        =   P1^3;       //I/O口P1.3
sbit P12        =   P1^2;       //I/O口P1.2
sbit P11        =   P1^1;       //I/O口P1.1
sbit P10        =   P1^0;       //I/O口P1.0

sbit T2         =   P1^0;       //定时器2的外部信号输入口
sbit T2CLKO     =   P1^0;       //定时器2定的时钟溢出脉冲输出脚
sbit T2EX       =   P1^1;       //定时器2的中断控制源

/////////////////////////////////

sfr  P2         =   0xa0;       //I/O端口2              Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //位描述                P2.7    P2.6    P2.5    P2.4    P2.3    P2.2    P2.1    P2.0
                                //初始值=1111,1111      1       1       1       1       1       1       1       1

sbit P27        =   P2^7;       //I/O口P2.7
sbit P26        =   P2^6;       //I/O口P2.6
sbit P25        =   P2^5;       //I/O口P2.5
sbit P24        =   P2^4;       //I/O口P2.4
sbit P23        =   P2^3;       //I/O口P2.3
sbit P22        =   P2^2;       //I/O口P2.2
sbit P21        =   P2^1;       //I/O口P2.1
sbit P20        =   P2^0;       //I/O口P2.0

/////////////////////////////////

sfr  P3         =   0xb0;       //I/O端口3              Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //位描述                P3.7    P3.6    P3.5    P3.4    P3.3    P3.2    P3.1    P3.0
                                //初始值=1111,1111      1       1       1       1       1       1       1       1

sbit P37        =   P3^7;       //I/O口P3.7
sbit P36        =   P3^6;       //I/O口P3.6
sbit P35        =   P3^5;       //I/O口P3.5
sbit P34        =   P3^4;       //I/O口P3.4
sbit P33        =   P3^3;       //I/O口P3.3
sbit P32        =   P3^2;       //I/O口P3.2
sbit P31        =   P3^1;       //I/O口P3.1
sbit P30        =   P3^0;       //I/O口P3.0

sbit RXD        =   P3^0;       //串口1的数据接收口
sbit TXD        =   P3^1;       //串口1的数据发送口
sbit INT0       =   P3^2;       //外部中断0的信号输入口
sbit INT1       =   P3^3;       //外部中断1的信号输出口
sbit T0         =   P3^4;       //定时器0的外部信号输入口
sbit T1         =   P3^5;       //定时器1的外部信号输入口
sbit WR         =   P3^6;       //外部数据存储器的写信号
sbit RD         =   P3^7;       //外部数据存储器的读信号

/////////////////////////////////

sfr  P4         =   0xc0;       //I/O端口4              Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //位描述                -       P4.6    P4.5    P4.4    P4.3    P4.2    P4.1    P4.0
                                //初始值=xxxx,1111      x       x       x       x       1       1       1       1

sbit P43        =   P4^3;       //I/O口P4.3
sbit P42        =   P4^2;       //I/O口P4.2
sbit P41        =   P4^1;       //I/O口P4.1
sbit P40        =   P4^0;       //I/O口P4.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sfr  IE         =   0xa8;       //中断使能寄存器        Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //位描述                EA      -       ET2     ES      ET1     EX1     ET0     EX0
                                //初始值=0x00,0000      0       x       0       0       0       0       0       0

sbit EA         =   IE^7;       //总中断开关
sbit ET2        =   IE^5;       //定时器2中断使能位
sbit ES         =   IE^4;       //串口中断使能位
sbit ET1        =   IE^3;       //定时器1中断使能位
sbit EX1        =   IE^2;       //外部中断1中断使能位
sbit ET0        =   IE^1;       //定时器0中断使能位
sbit EX0        =   IE^0;       //外部中断0中断使能位

/////////////////////////////////

sfr  IPH        =   0xb7;       //中断优先级寄存器高位  Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //位描述                PX3H    PX2H    PT2H    PSH     PT1H    PX1H    PT0H    PX0H
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

#define PX3H        0x80        //外部中断3中断优先级控制高位
#define PX2H        0x40        //外部中断2中断优先级控制高位
#define PT2H        0x20        //定时器2中断优先级控制高位
#define PSH         0x10        //串口中断优先级控制高位
#define PT1H        0x08        //定时器1中断优先级控制高位
#define PX1H        0x04        //外部中断1中断优先级控制高位
#define PT0H        0x02        //定时器0中断优先级控制高位
#define PX0H        0x01        //外部中断0中断优先级控制高位

/////////////////////////////////

sfr  IP         =   0xb8;       //中断优先级寄存器      Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //位描述                -       -       PT2     PS      PT1     PX1     PT0     PX0
                                //初始值=xx00,0000      x       x       0       0       0       0       0       0

sbit PT2        =   IP^5;       //定时器2中断优先级控制低位
sbit PS         =   IP^4;       //串口中断优先级控制低位
sbit PT1        =   IP^3;       //定时器1中断优先级控制低位
sbit PX1        =   IP^2;       //外部中断1中断优先级控制低位
sbit PT0        =   IP^1;       //定时器0中断优先级控制低位
sbit PX0        =   IP^0;       //外部中断0中断优先级控制低位

/////////////////////////////////

sfr  XICON      =   0xe8;       //辅助中断使能寄存器    Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //位描述                PX3     EX3     IE3     IT3     PX2     EX2     IE2     IT2
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

sbit PX3        =   XICON^7;    //外部中断3中断优先级控制低位
sbit EX3        =   XICON^6;    //使能外部中断3
sbit IE3        =   XICON^5;    //外部中断3的中断请求位,由硬件置1,可由软件清0或者在中断处理程序完成后由硬件自动清0
sbit IT3        =   XICON^4;    //外部中断3的触发类型,0:低电平触发外部中断 1:下降沿触发外部中断
sbit PX2        =   XICON^3;    //外部中断2中断优先级控制低位
sbit EX2        =   XICON^2;    //使能外部中断2
sbit IE2        =   XICON^1;    //外部中断2的中断请求位,由硬件置1,可由软件清0或者在中断处理程序完成后由硬件自动清0
sbit IT2        =   XICON^0;    //外部中断2的触发类型,0:低电平触发外部中断 1:下降沿触发外部中断

#define X0_INTNO    0           //外部中断0中断号,入口地址为0003H
#define T0_INTNO    1           //定时器0中断号,入口地址为000BH
#define X1_INTNO    2           //外部中断1中断号,入口地址为0013H
#define T1_INTNO    3           //定时器1中断号,入口地址为001BH
#define UART_INTNO  4           //串口中断号,入口地址为0023H
#define T2_INTNO    5           //定时器2中断号,入口地址为002BH
#define X2_INTNO    6           //外部中断2中断号,入口地址为0033H
#define X3_INTNO    7           //外部中断3中断号,入口地址为003BH

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sfr  TCON       =   0x88;       //定时器0/1控制寄存器   Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //位描述                TF1     TR1     TF0     TR0     IE1     IT1     IE0     IT0
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

sbit TF1        = TCON^7;       //定时器1溢出标志,由硬件置1,可由软件清0或者在中断处理程序完成后由硬件自动清0
sbit TR1        = TCON^6;       //定时器1的启动控制位,1:启动定时器 0:停止定时器
sbit TF0        = TCON^5;       //定时器0溢出标志,由硬件置1,可由软件清0或者在中断处理程序完成后由硬件自动清0
sbit TR0        = TCON^4;       //定时器0的启动控制位,1:启动定时器 0:停止定时器
sbit IE1        = TCON^3;       //外部中断1的中断请求位,由硬件置1,可由软件清0或者在中断处理程序完成后由硬件自动清0
sbit IT1        = TCON^2;       //外部中断1的触发类型,0:低电平触发外部中断 1:下降沿触发外部中断
sbit IE0        = TCON^1;       //外部中断0的中断请求位,由硬件置1,可由软件清0或者在中断处理程序完成后由硬件自动清0
sbit IT0        = TCON^0;       //外部中断0的触发类型,0:低电平触发外部中断 1:下降沿触发外部中断

/////////////////////////////////

sfr  TMOD       =   0x89;       //定时器0/1模式寄存器   Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //位描述                GATE    C/T#    M1      M0      GATE    C/T#    M1      M0
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

#define GATE1       0x80        //定时器1启动控制位,0:TR1为1时启动定时器1 1:TR1为1且INT1为高电平时才启动定时器1
#define C_T1        0x40        //定时器/计数器选择位,0:定时器(时钟源为内部时钟) 1:计数器(时钟源为T1引脚的外部时钟)
#define T1_M0       0x00        //定时器1操作模式0:13位定时器
#define T1_M1       0x10        //定时器1操作模式1:16位定时器
#define T1_M2       0x20        //定时器1操作模式2:8位自动重载定时器
#define T1_M3       0x30        //定时器1操作模式3:定时器1停止
#define GATE0       0x08        //定时器1启动控制位,0:TR0为1时启动定时器1 1:TR0为1且INT0为高电平时才启动定时器0
#define C_T0        0x04        //定时器/计数器选择位,0:定时器(时钟源为内部时钟) 1:计数器(时钟源为T0引脚的外部时钟)
#define T0_M0       0x00        //定时器0操作模式0:13位定时器
#define T0_M1       0x01        //定时器0操作模式1:16位定时器
#define T0_M2       0x02        //定时器0操作模式2:8位自动重载定时器
#define T0_M3       0x03        //定时器0操作模式3:TL0和TH0为两组独立8位定时器

/////////////////////////////////

sfr  TL0        = 0x8a;         //定时器0的低8位计数值  Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  TL1        = 0x8b;         //定时器1的低8位计数值  Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  TH0        = 0x8c;         //定时器0的高8位计数值  Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  TH1        = 0x8d;         //定时器1的高8位计数值  Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  T2CON      =   0xc8;       //定时器2控制寄存器     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //位描述                TF2     EXF2    RCLK    TCLK    EXEN2   TR2     C/T2#   CP/RL#
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

sbit TF2        = T2CON^7;      //定时器2溢出标志,由硬件置1,必须由软件清0
sbit EXF2       = T2CON^6;      //定时器2的外部标志,由硬件置1,必须由软件清0
sbit RCLK       = T2CON^5;      //接收时钟标志,0:使用定时器1作为串口接收发生器 1:使用定时器2作为串口接收发生器
sbit TCLK       = T2CON^4;      //发送时钟标志,0:使用定时器1作为串口发送发生器 1:使用定时器2作为串口发送发生器
sbit EXEN2      = T2CON^3;      //定时器2的外部使能标志
sbit TR2        = T2CON^2;      //启动定时期2
sbit C_T2       = T2CON^1;      //定时器/计数器选择位,0:定时器(时钟源为内部时钟) 1:计数器(时钟源为T2引脚的外部时钟)
sbit CP_RL2     = T2CON^0;      //捕获/重载标志

/////////////////////////////////

sfr  T2MOD      =   0xc9;       //定时器0/1模式寄存器   Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //位描述                -       -       -       -       -       -       T2OE    DCEN
                                //初始值=xxxx,xx00      x       x       x       x       x       x       0       0

#define T2OE        0x02        //定时器2输出使能,输出溢出率到T2脚
#define DCEN        0x01        //定时器2向下计数,0:向上计数 1:向下计数

/////////////////////////////////

sfr  RCAP2L     = 0xca;         //定时器2重载/捕获低8位 Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  RCAP2H     = 0xcb;         //定时器2重载/捕获高8位 Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  TL2        = 0xcc;         //定时器2的低8位计数值  Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  TH2        = 0xcd;         //定时器2的高8位计数值  Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  SCON       =   0x98;       //串口控制寄存器        Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //位描述                SM0/FE  SM1     SM2     REN     TB8     RB8     TI      Ri
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

sbit FE         =   SCON^7;     //帧错误检测位,当串口模块在接收数据时没有检测到正确的停止位时,FE被硬件置1,需要由软件来清0(当SMOD0为1时,FE有效)
sbit SM0        =   SCON^7;     //串口模式设置位
sbit SM1        =   SCON^6;     //SM0/SM1=0/0:移位寄存器 0/1:8位可变波特率 1/0:9位固定波特率 1/1:9位可变波特率
sbit SM2        =   SCON^5;     //自动地址识别使能位
sbit REN        =   SCON^4;     //使能串口接收模块
sbit TB8        =   SCON^3;     //发送的第9位数据
sbit RB8        =   SCON^2;     //接收的第9位数据
sbit TI         =   SCON^1;     //发送完成中断标志
sbit RI         =   SCON^0;     //接收完成中断标志

/////////////////////////////////

sfr  SBUF       =   0x99;       //串口接收/发送数据     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=xxxx,xxxx      x       x       x       x       x       x       x       x

/////////////////////////////////

sfr  SADDR      =   0xa9;       //串口设备从地址寄存器  Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  SADEN      =   0xb9;       //串口设备从地址屏蔽位  Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sfr  ISP_DATA   =   0xe2;       //ISP数据寄存器         Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=1111,1111      1       1       1       1       1       1       1       1

/////////////////////////////////

sfr  ISP_ADDRH  =   0xe3;       //ISP地址高位寄存器     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  ISP_ADDRL  =   0xe4;       //ISP地址低位寄存器     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  ISP_CMD    =   0xe5;       //ISP命令寄存器         Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=xxxx,xx00      x       x       x       x       x       0       0       0

#define ISP_IDLE    0x00        //ISP待机命令
#define ISP_READ    0x01        //ISP读字节数据命令
#define ISP_PROGRAM 0x02        //ISP字节编程命令
#define ISP_ERASE   0x03        //ISP扇区擦除命令(每扇区512字节))

/////////////////////////////////

sfr  ISP_TRIG   =   0xe6;       //ISP命令触发寄存器     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //初始值=xxxx,xxxx      x       x       x       x       x       x       x       x

#define ISP_TRIG0   0x46        //ISP功能触发命令1
#define ISP_TRIG1   0xb9        //ISP功能触发命令2

/////////////////////////////////

sfr  ISP_CONTR  =   0xe7;       //ISP控制寄存器         Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //位描述                ISPEN   SWBS    SWRST   -       -       WT2     WT1     WT0
                                //初始值=000x,x000      0       0       0       x       x       0       0       0

#define ISPEN       0x80        //ISP使能开关
#define SWBS        0x40        //软启动选择,0:从用户AP启动 1:从ISP启动
#define SWRST       0x20        //触发软件复位

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

void main()
{
 P0 = 0x55;
}
