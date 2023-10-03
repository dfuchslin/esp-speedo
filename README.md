```
                                               _
  ___  ___ _ __        ___ _ __   ___  ___  __| | ___
 / _ \/ __| '_ \ _____/ __| '_ \ / _ \/ _ \/ _` |/ _ \
|  __/\__ \ |_) |_____\__ \ |_) |  __/  __/ (_| | (_) |
 \___||___/ .__/      |___/ .__/ \___|\___|\__,_|\___/
          |_|             |_|
```
# esp-speedo

compile:
	pio run

flash:
	pio run -t upload

upload:
	pio run -t upload -e ota

console:
	pio device monitor
