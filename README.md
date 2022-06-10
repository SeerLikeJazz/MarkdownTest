## 外观
 <div alihn="center"> ![](/Image/Top.jpg)</div>

## 使用说明
- <font style="background: #F09B59">安卓手机安装nRF connect </font>   
![](/Image/app.jpg#pic_center)
- <font style="background: #F09B59">搜索到“Pacemaker-V1”设备，并点击“CONNECT” </font>   
![](/Image/search.jpg#pic_center)  
- <font style="background: #F09B59">1.点击三点符号；2.使能CCCDs</font>   
![](/Image/CCCD.jpg#pic_center) 
- <font style="background: #F09B59">发送指令</font>   
![](/Image/RX.jpg#pic_center) 
- <font style="background: #F09B59">参数设置格式：IWFT</font>   
<font style="background: #F0D7C1">I(电流)-></font>      
输入参数：1，2，3，4，5  
对应关系：1=100uA，2=200uA, 3=300uA, 4=400uA, 5=500uA  
<font style="background: #F0D7C1">W(脉宽)-></font>     
输入参数：1，2，3，4  
对应关系：1=1ms，2=2ms，3=3ms，4=4ms  
<font style="background: #F0D7C1">F(频率)-></font>     
输入参数：1，2，3，4  
对应关系：1=2000ms，2=1000ms，3=500ms，4=333ms  
默认输出为：300uA，2ms，1000ms
- <font style="background: #F09B59">示例</font>  
<font style="background: #F0D7C1">1.手机发送:123T</font>         
![](/Image/123T.jpg#pic_center)     
<font style="background: #F0D7C1">1.对应示波器显示</font>       
![](/Image/tek123T.bmp#pic_center)
<font style="background: #F0D7C1">2.手机发送:242T</font>         
![](/Image/242T.jpg#pic_center)  
<font style="background: #F0D7C1">2.对应示波器显示</font>       
![](/Image/tek242T.bmp#pic_center)  




> 更新说明
### 22.06.09
- 编写使用说明

### 22.06.04
- 抽象出I、W、F 3三个参数（电流，脉宽，频率）
- 'xxxT'指令格式，nRF connect带设置成功回显
- 到公司需使用示波器，校准I、W参数

### 22.06.03
BLE的RXTX和开发板的连接方式需要交换
- 频率F：0.5-3Hz. 2000ms，1000ms，500ms，333ms
- 电流I：100-500uA. 100uA, 200uA, 300uA, 400uA, 500uA
- 脉宽W：1-4ms. 1ms, 2ms, 3ms, 4ms

- DAC输出，电流最大Io=Vin/R10=400uA，模拟负载500欧姆
- CPC4051 LDO1输出3.3V，给刺激器供电
