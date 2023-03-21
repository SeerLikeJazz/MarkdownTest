# iRecorder_WIFI8266_H7

## Attention
- WEB服务器密码：anylinkin
- 开机按键未释放，此时充电没反应(硬件遗留问题)
- NVIC:  

| 名称 | 优先级 | 备注|
| -------- | --- | ----------------------- |
| Systick  | 0   |           |
| EXTI 0   | 3   | 按键中断                    |
| EXTI 5-9 | 4   | SI4432，WIFI notify，手动打开 |
| USART1   | 4   | 串口1接收中断          |
| EXTI 4   | 5   | DRDY          |
| DMA1 S0  | 10  | ADC电量检测          |


## 待解决
- 有线也丢数据
- 刚开机，工作几分钟WIFI会断开连接
- 中间会有包不正确，2，3：wifi连接查询（不管用），AXI Sram溢出（不管用），Lwrb读写冲突（改写lwrb_read，不管用。！读了没发送成功的话就比较尴尬），SPI CRCPolynomial(不管用)，wifi发送长度（发送长度越长，9->27，不管用），__HAL_LOCK(hspi)（不管用），屏蔽ADS1299的spi读写（无关，不管用），屏蔽电池DMA（不管用）
- 意外断开，wifi模块超时120s
- WIFI spi时钟提高，信号完整性


## 更新
### 23.03.08
- WIFI加上连接时电量查询
- 有线的时候关闭WIFI电源

### 23.03.04
- 有线、无线运行逻辑，画状态图ProcessOn
- DEBUG_OUT是否使能printf
- 增加有线隔离传输模式，USART1，波特率 2000000，阻塞发送，可改DMA

### 23.02.24暂存二
- 加入SI4432
- EXTI9_5有多个中断时，EXTI9_5_IRQHandler里面需要都填写中断入口，不然初始化不通过

### 23.02.24--输出一版
- wifi模块更改设置，设置流程记录  
关闭Web服务器 5.2   
热点改名，最多13个字符，MAC地址后6位（序列号怎么编）  iRe_XXXXXX  
设置保存到模组的Flash  

### 23.02.24暂存
- 文件整理

### 23.02.23
- 开机速度优化：  
  延迟300ms改为50ms  
  延迟500ms改为200ms  
  M8266WIFI_SPI_OptSel_Local_Ap_Channel不使用，对AP频道根据环境进行AP频道的适配优化选择  
  TimeupFlag_2S提前闪烁  
- M8266模块会导致进入Standby模式失败，把M8266相关的IO 设置HAL_GPIO_DeInit

### 23.02.23暂存
- 充电检测、开关机，注意sPinParams.PinPolarity  = PWR_PIN_POLARITY_HIGH设置和package相反

### 23.02.22
- WIFI连接状态查询，软件定时器2S查询一次
- WIFI模块Notify接收中断，等模块初始化后打开(EXTI9_5_IRQn, 7, 0)
- ADC、DMA1、TIM8，电量采集，0.5s一次，AD_Value数组位于SRAM1
- Ringbuf使用512KB AXI SRAM，注意src_buff_data变量extern长度要一致
- ADS1299 ID读取：  
  MPU不加、Cache不加，正常  
  MPU加、Cache不加，正常  
  MPU加、Cache加，不正常  
  MPU不加、Cache加，不正常  
  ！Enable D-Cache，正常


### 23.02.21暂存
- M8266初始化绿灯闪烁导致频繁进入wifi接收中断
- Cache 会影响1299ID读取？？？，一开始不会
- USART1(printf)、Notify(WIFI)、UserLed
- cubeMX更新为6.7.0（6.5.0），H7 Package 更新为1.11.0（1.10.0）

### 23.02.20
- ADS1299、M8266驱动加入
- 建立工程，stm32H743VIT6




