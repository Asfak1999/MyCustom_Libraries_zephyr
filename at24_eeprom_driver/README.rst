

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

Sample Output
=============

.. code-block:: console

    Hello! I\'m your echo bot.
    Tell me something and press enter:
    # Type e.g. "Hi there!" and hit enter!
    Echo: Hi there!

