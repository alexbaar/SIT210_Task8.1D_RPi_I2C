# RPi master for Arduino slave
#connects to Arduino via I2C 

from smbus import SMBus   # we need this library when working with I2C

address = 0x8  # bus address same as arduino
bus = SMBus(1) #we have I2C-1 or I2C-0 connections on RPi, input the corresponding one here; here:  /dev/i2c-1

number = 1

print("1 = led in on       // 0 = led is off")
while number ==1:
    led_on_off = input(">>>>    ")  # user input, assign to a variable
    
    if led_on_off == "1":
        bus.write_byte(address, 0x1)  # led on
    elif led_on_off == "0":
        bus.write_byte(address, 0x0)  # led off
    else:
        number = 0  # any other number will end the program  