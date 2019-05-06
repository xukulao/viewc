### DM9000EP网卡芯片工作原理说明
- [驱动原理](https://blog.csdn.net/b02330224/article/details/7895724)
- 芯片具体手册
具体手册可联系本人获取

- 工作大体说明
通过【读写时序图】AEN,CMD,IOR,IOW等引脚控制信号来完成数据的读写操作
接受和发送的数据全保存在SRAM【静态随机存储器，可以实现通电随机读写操作】
TX发送的数据是保存在TX SRAM里的，接受RX也是一样，发送和接受的数据都会经过
各种转换电路处理，在TX,RX端口都有一个变压器最终输出到RJ水晶头


数据存储电路SRAM和EEPROM【可存储芯片的MAC地址，6个字节】

网卡芯片进行通信的前提是知道双方【发送和接收方】的mac地址，mac地址可以存储在EEPROM可
电擦除寄存器里。

发送数据的前提：
1、知道mac地址
2、要发送的数据

根据tcp/ip协议，驱动程序会编写一个ARP程序负责将目的ip地址转换为mac地址
转换过程：是arp程序发起一个arp请求，网络中的网卡响应【arp响应】时会返回一个mac地址

tcp/ip协议至于封装的tcp,ip,以太网头[mac]只是一个规定，但低层通信只需要知道mac
和要发送的数据就可以了

- tcp/ip
数据通过应用层，传输层，网络，数据链路层封装
封装结果：
以太网目标物理地址|源物理地址|2个字节帧类型|数据|CRC

分用：
针对接收的时候

根据帧类型是ARP请求还是IP头，分别发给不同的协议【程序】来处理
TCP,UDP他们都是用IP协议的，会根据IP头的16位[端口】区分上层的应用程序
如http,dns,redis,mysql这些

根据以太网帧头来区分是ARP,IP协议
根据IP16位来区分是TCP,UDP
根据TCP/UDP的16位端口来区分上层应用程序

- 芯片写时序
```c
void dm9000_reg_write(unsigned char reg, unsigned char data)

{

PIO1 = reg;

AEN = 0;

CMD = 0;

IOR = 1;

IOW = 0;

udelay(1);

AEN = 1;

IOW = 1;

udelay(20);

PIO1 = data;

AEN = 0;

CMD = 0;

IOR = 1;

IOW = 0;

udelay(1);

AEN = 1;

IOW = 1;

}
```
- 读写数据驱动程序
```c
//发送数据包

//参数：datas为要发送的数据缓冲区（以字节为单位），length为要发送的数据长度（两个字节）。

void sendpacket(unsigned char *datas, unsigned int length)

{
    unsigned int len, i;
    dm9000_reg_write(IMR, 0x80);//先禁止网卡中断，防止在发送数据时被中断干扰
    len = length;

    dm9000_reg_write(TXPLH, (len>>8) & 0x0ff);

    dm9000_reg_write(TXPLL, len & 0x0ff);

/*这两句是将要发送数据的长度告诉DM9000的寄存器*/

    DM_ADD = MWCMD;//这里的写法是针对有总线接口的处理器，没有总线接口的处理器要注意加上时序。

    for(i=0; i<len; i+=2)//16 bit mode

    {

        udelay(20);

        DM_CMD = datas[i] | (datas[i+1]<<8);

    }

/*上面是将要发送的数据写到DM9000的内部SRAM中的写FIFO中，注意没有总线接口的处理器要加上适当的时序*/

/*只需要向这个寄存器中写数据即可，MWCMD是DM9000内部SRAM的DMA指针，根据处理器模式，写后自动增加*/

    dm9000_reg_write(TCR, 0x01);//发送数据到以太网上

    while((dm9000_reg_read(NSR) & 0x0c) == 0);//等待数据发送完成

    udelay(20);

    dm9000_reg_write(NSR, 0x2c);//清除状态寄存器，由于发送数据没有设置中断，因此不必处理中断标志位

    dm9000_reg_write(IMR, 0x81);//DM9000网卡的接收中断使能

}
```
![一些寄存器说明](TCR.png)
![一些寄存器说明](IMR.png)