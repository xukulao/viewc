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
    
- 线性表的优缺点   
    ![](list2.png)    
    插入和删除元素要移动大量的数据元素，效率低下！O(n)太高   
    
- 线性表的链式存储结构     

  - 定义：  
  用任意的存储单元去存储线性表的数据元素，存储单元可以是连续的，也可以不是连续的   
  ![链式存储](datastruct/list3.png)     
  
  为了表示数据元素ai和数据元素ai+1的逻辑关系，存储单元不但要存储数据元素本身  
  还要存储后继元素的位置，存储数据元素的域称为数据域，存储后继元素位置的域称为  
  指针域，两者互相结合构成数据元素ai的映像，称为结点Node  
  
  n个结点（ai的存储映像）链结成一个链表，就称为线性表(a1,a2,ai,an)的链式存储结构   
  
  
  链表中每个结点都有指针域，称为单链表，单链表通过每个结点的指针域将线性表中的  
  数据元素按其逻辑次序链接在一起     
  
  链表中的第一个存储位置叫头指针   
  ![list_chain](datastruct/list_chain2.png)  
  
  单链表的头结点【存储位置为头指针】  
  ![chainline](datastruct/line_chain3.png)
  
  
  单链表  
  ![](datastruct/list_chain3.png)  
  
- 单链表读取     
    不断的循环读取指定位置i的结点  
    
- 单链表的插入与删除   
 ![insert](datastruct/listchain_insert.png)  
 [单链表的展示与插入](listchain.c)  
 
- 单链表的整表创建    
 [单链表的展示与插入](listchain.c)  
- 单链表的清空  
 [单链表的展示与插入](listchain.c)    
 
- 静态链表   
 用数组描述的链表叫静态链表       
 
- 循环链表  
 让单链表的终端结点的指针域指向头结点弄成一个环  
 简称为循环链表circular linkedlist


