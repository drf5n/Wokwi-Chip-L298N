# Wokwi Frequency Counter Chip Example

This is a basic custom chip for [Wokwi](https://wokwi.com/). It implements a simple inverter: the output is always opposite to the input.

## Pin names

| Name | Description               |
| ---- | ------------------------  |
| IN   | Input signal              |
| OUT  | Output (inverted) signal  |
| ENA  | Enable (ground to disable) |
| GND  | Ground                    |
| VCC  | Supply voltage            |

## Usage

To use this chip in your project, include it as a dependency in your `diagram.json` file:

```json
  "dependencies": {
    "chip-FrequencyCounter": "github:drf5n/Wokwi-FrequencyCounter-chip@v1.0.1"
  }
```

Then, add the chip to your circuit by adding a `chip-FrequencyCounter` item to the `parts` section of diagram.json:

```json
  "parts": {
    ...,
    { "type": "chip-FrequencyCounter", "id": "FrequencyCounter1" }
  },
```

For a complete example, see [the FrequencyCounter chip test project](https://wokwi.com/projects/406335146945275905).
