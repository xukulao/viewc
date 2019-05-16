### TCP/IP协议测试   
- 使用tcpdump抓取http通信过程  
```php
tcpdump -s 2000 -i eth0 -ntX '(src 目标服务器ip) or (dst 目标服务器ip) or (arp)'

wget --header "Conection:close" https://www.xxx.com/api/xxx/testdb
```