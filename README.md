ETHERNET-W5500
-----------------------------------------------------------------------------------------------------
Add " Driver/CMSIS/Ethernet_W5500 on Path
Download ncat on your system for communicate with stm32
Type: " echo 1 | ncat YOURIP YOURPORT " on Bash/Powershell for send data to stm32 '1' for example.
Example: echo 1 | ncat 192.165.1.1 1000
Change '1' data on "TCP_Server_Process()" function and send any data via powershell
