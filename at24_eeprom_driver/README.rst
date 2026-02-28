

AT24C256 EEPROM 
********
Zephyr RTOS library for AT24C256 EEPROM


Write function
==============
Both read and write functions has 3 parameters - address, buffer and buffer size. 
Address could be number from range 0-32768 - it addresses every single char. 
As we decided to divide memory into blocks of 16, to read the first block, 
we will use address 0. The following 16 chars will be readed (0-15). 
To read second block, use address 16, and block 16-31 will be readed.

Write function
==============

.. code-block:: c
   :caption: main.c
   :name: main
    print("Explicit is better than implicit.")



