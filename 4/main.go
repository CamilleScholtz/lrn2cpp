package main

import (
	"time"

	"gobot.io/x/gobot"
	"gobot.io/x/gobot/drivers/gpio"
	"gobot.io/x/gobot/platforms/firmata"
)

var (
	tty = firmata.NewAdaptor("/dev/ttyACM0")

	r = gpio.NewLedDriver(tty, "13")
	y = gpio.NewLedDriver(tty, "12")
	g = gpio.NewLedDriver(tty, "11")
)

func leftToRight() {
	var i int
	gobot.Every(1*time.Second, func() {
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

		if i > 1 {
			i = 0
		} else {
			i++
		}
	})
}

func fillUp() {
	var i int
	gobot.Every(1*time.Second, func() {
		switch i {
		case 0:
			r.On()
		case 1:
			y.On()
		case 2:
			g.On()
		}

		if i > 2 {
			i = 0

			r.Off()
			y.Off()
			g.Off()
		} else {
			i++
		}
	})
}

func main() {
	robot := gobot.NewRobot("bot",
		[]gobot.Connection{tty},

		[]gobot.Device{r},
		[]gobot.Device{y},
		[]gobot.Device{g},

		fillUp,
	)

	robot.Start()
}
