

AT24C256 EEPROM 
********
Zephyr RTOS library for AT24C256 EEPROM


Building and Running
********************

Build and flash the sample as follows, changing ``nrf52840dk/nrf52840`` for
your board:

.. zephyr-app-commands::
   :zephyr-app: samples/drivers/uart/echo_bot
   :board: nrf52840dk/nrf52840
   :goals: build flash
   :compact:


Write Function
==============

.. code-block:: c

	printf("Hello from readme fiile");


Read Function
==============

.. code-block:: c

	printf("Hello from readme fiile");

Sample Output
=============

.. code-block:: console

    Hello! I\'m your echo bot.
    Tell me something and press enter:
    # Type e.g. "Hi there!" and hit enter!
    Echo: Hi there!



<<<<<<< HEAD
.. code-block:: c
	printf("Hello from readme fiile")

=======
>>>>>>> a757fa54852de67805fe82a689f2eb18cf18d604
