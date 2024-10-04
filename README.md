# Wokwi-Chip-L298N
## Description

L298N Dual H-bridge motor driver

-  

To use this chip in your project, include it as a dependency in your `diagram.json` file:

```json
"dependencies": { "chip-l298n": "github:drf5n/Wokwi-Chip-L298N@1.0.2" }
```

Then, add the chip to your circuit by adding a `chip-l298n` item to the `parts` section of `diagram.json`:

```json
  "parts": {
    ...,
    {
      "type": "chip-l298n",
      "id": "driver1",
      "attrs": { }
    },
```

The actual source code for the chip lives in [src/main.c](https://github.com/drf5n/Wokwi-Chip-L298N/blob/main/src/main.c), and the pins are described in [chip.json](https://github.com/drf5n/Wokwi-Chip-L298N/blob/main/chip.json).

## Examples

* [Wokwi Uno with L298N driver  using tabbed files](https://wokwi.com/projects/410302035690579969) -- with LED-motors and scopes

### Wokwi files for monitor in a PWM pin:
```
void setup() {
  pinMode(3, OUTPUT);
  analogWrite(3, 128);
}

void loop() {
}

```

```
{
  "version": 1,
  "author": "drf5n",
  "editor": "wokwi",
  "parts": [
    { "type": "wokwi-arduino-uno", "id": "uno", "top": 0, "left": 0, "attrs": {} },
    { "type": "chip-freq", "id": "freq1", "top": -75.78, "left": 273.6, "attrs": {} }
  ],
  "connections": [ [ "freq1:IN", "uno:3", "green", [ "h0" ] ] ],
  "dependencies": { "chip-freq": "github:drf5n/Wokwi-Chip-FrequencyCounter@1.0.8" }
}
```

## Versions
* github:drf5n/Wokwi-Chip-L298N@1.0.1 -- Working release

## License

This project is licensed under the MIT license. See the [LICENSE](https://github.com/drf5na/Wokwi-Chip-L298N/blob/main/LICENSE) file for more details.
