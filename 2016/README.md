SirSoccer-Robot 2016
====================

Define Wi-Fi Connection
-----------------------
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

Sources
-------
https://www.raspberrypi.org/documentation/configuration/wireless/wireless-cli.md
