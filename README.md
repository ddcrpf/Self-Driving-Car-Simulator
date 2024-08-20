# Self-Driving Car Simulator

This project employs behavioral cloning to develop a neural network-based car control model for the Udacity simulator. By training the model on a dataset of recorded driving actions, it learns to replicate human driving behavior. The model is optimized to handle diverse driving scenarios, including challenges like shadowing, enhancing its robustness and efficiency. This approach contributes to advancements in autonomous driving technologies.

## Model Architecture

The model uses a Convolutional Neural Network (CNN) with the following architecture:

| Layer (type)   | Output Shape       | Param # |
| -------------- | ------------------ | ------- |
| Lambda         | (None, 66, 200, 3) | 0       |
| Conv2D (1)     | (None, 31, 98, 24) | 1,824   |
| Conv2D (2)     | (None, 14, 47, 36) | 21,636  |
| Conv2D (3)     | (None, 5, 22, 48)  | 43,248  |
| Conv2D (4)     | (None, 3, 20, 64)  | 27,712  |
| Conv2D (5)     | (None, 1, 18, 64)  | 36,928  |
| Dropout        | (None, 1, 18, 64)  | 0       |
| Flatten        | (None, 1152)       | 0       |
| Dense (1)      | (None, 100)        | 115,300 |
| Dense (2)      | (None, 50)         | 5,050   |
| Dense (3)      | (None, 10)         | 510     |
| Dense (4)      | (None, 1)          | 11      |

**Total Parameters:** 252,219 (All trainable)

## Features

- **Behavioral Cloning:** Mimics human driving by learning from recorded driving data.
- **Robust Performance:** Handles diverse driving conditions, including challenging scenarios like shadowing.
- **Autonomous Driving Simulation:** Demonstrates potential real-world applications in self-driving car technology.

## Tech Stack

- Python
- Numpy
- Pandas
- TensorFlow Keras
- OpenCV
- Flask
- Socket.io
- Udacity Simulator

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/ddcrpf/Self-Driving-Car-Simulator.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Self-Driving-Car-Simulator
   ```
3. Install the required dependencies:
   ```bash
   pip install -r requirements.txt
   ```

## Usage

1. Launch the Udacity Simulator.
2. Run the Flask server to connect the model to the simulator:
   ```bash
   python drive_final.py
   ```
3. Start driving and observe how the model controls the car based on its learned behavior.

## Contributing

Contributions are welcome! Fork this repository and submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.



