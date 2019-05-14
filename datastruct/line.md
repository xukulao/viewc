### 线性表  
- 定义  
  线性表LIST：是0个或多个的数据元素的有限序列    
  
  图
  ![list](datastruct/list1.png)  
  
  线性表元素n(n>=0)的个数线性表的长度，没有元素的为空表  
  非空表中的每个元素都有自己的位置，a1为第一个数据元素，an为最后一个数据元素  
  ai为第i个数据元素，称i为ai在线性表中的位序  
  
  
- 线性表的抽象数据类型   

    ![line](datastruct/listdefine1.png)
    ![line](datastruct/listdefine2.png)  
    
- 线性表的数据存储顺序    
    线性表的顺序存储结构，指的是用一连续内存存储单元依次存储线性表的数据元素   
    ![](datastruct/line_storage.png)   
    
    [顺序存储方式](list.c)

    ![](datastruct/line_storage_loc.png)  
    
- 线性表的数据元素插入和删除  
    [数据元素插入和删除](list.c)