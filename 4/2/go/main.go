package main

import (
	"gobot.io/x/gobot"
	"gobot.io/x/gobot/drivers/gpio"
	"gobot.io/x/gobot/platforms/firmata"
)

var (
	tty = firmata.NewAdaptor("/dev/ttyACM0")

	r = gpio.NewLedDriver(tty, "13")
	y = gpio.NewLedDriver(tty, "12")
	g = gpio.NewLedDriver(tty, "11")

	bl = gpio.NewButtonDriver(tty, "10")
	br = gpio.NewButtonDriver(tty, "9")

	i int
)

func blink() {
	bl.On(gpio.ButtonPush, func(data interface{}) {
		if i < 0 {
			i = 2
		} else {
			i--
		}
	})
	br.On(gpio.ButtonPush, func(data interface{}) {
		if i > 2 {
			i = 0
		} else {
			i++
		}
	})

	r.Off()
	y.Off()
	g.Off()

	switch i {
	case 0:
		r.On()
	case 1:
		y.On()
	case 2:
		g.On()
	}
}

func main() {
	robot := gobot.NewRobot("bot",
		[]gobot.Connection{tty},

		[]gobot.Device{r},
		[]gobot.Device{y},
		[]gobot.Device{g},

		blink,
	)

	robot.Start()
}
