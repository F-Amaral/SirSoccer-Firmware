SirSoccer-Robot 2016
====================

1 - Expand SD Card
------------------
Open *raspi-config*.

```
$ sudo raspi-config
```
Select Expand and Reboot.

2 - Define Wi-Fi Connection
---------------------------
Open the *wpa-supplicant* configuration file:
```
$ sudo nano /etc/wpa_supplicant/wpa_supplicant.conf
```

Go to the bottom of the file and add the following:
```
network={
    ssid="The_ESSID_from_earlier"
    psk="Your_wifi_password"
}
```
Reboot

3 - Define a Static IP
----------------------
Open the */etc/network/interfaces* file and add the following changes:

Change *iface wlan0 inet dhcp* into *iface wlan0 inet static*. This changes the wlan0 interface from DHCP to static.

Add the following lines before the wpa-conf line:
```
address 192.168.0.50    # Static IP you want 
netmask 255.255.255.0 
gateway 192.168.0.1     # IP of your router
```

4 - Access via SSH
------------------
```
$ ssh pi@<IP> ex: ssh pi@192.168.0.50
```
*User:* pi, *Password:* raspberry

5 - Disable the Graphics User Interface
---------------------------------------
Open *raspi-config*.

```
$ sudo raspi-config
```
Select *Boot->Console*   Auto-Login and Reboot

Sources
-------
https://www.raspberrypi.org/documentation/configuration/wireless/wireless-cli.md
http://weworkweplay.com/play/automatically-connect-a-raspberry-pi-to-a-wifi-network/