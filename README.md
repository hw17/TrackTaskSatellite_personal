# TrackTaskSatellite_personal
This repo is to track my changes for the task

## TASK 1
to generate client1 exe in Terminal:
```
g++ -std=c++17 *.cpp -o client1
```

to execute it:
```
./client1
```

The output in terminal currently is:
```
...
{"timestamp": 1724343098159, "out1": "2.7", "out2": "4.0", "out3": "5.0"},
{"timestamp": 1724343098263, "out1": "4.0", "out2": "4.0", "out3": "5.0"},
{"timestamp": 1724343098369, "out1": "4.8", "out2": "3.0", "out3": "5.0"},
{"timestamp": 1724343098474, "out1": "5.0", "out2": "3.0", "out3": "5.0"},
...
```
## TASK 2
to generate client2 exe in Terminal:
```
g++ -std=c++17 -D C2_TIME *.cpp -o client2
```
> [!NOTE]
> **C2_TIME** will change from 100ms to 20ms
to execute it:
```
./client2
```
The output in terminal currently is (it should be a diffence of 20ms in each output):
```
...
{"timestamp": 1724427218107, "out1": "-2.5", "out2": "--", "out3": "--"},
{"timestamp": 1724427218127, "out1": "-2.9", "out2": "--", "out3": "--"},
{"timestamp": 1724427218152, "out1": "-3.3", "out2": "-1.0", "out3": "--"},
{"timestamp": 1724427218178, "out1": "-3.6", "out2": "-1.0", "out3": "--"},
{"timestamp": 1724427218200, "out1": "-3.6", "out2": "-1.0", "out3": "--"},
{"timestamp": 1724427218225, "out1": "-4.0", "out2": "-1.0", "out3": "--"},
...
```

## HOW TO SEE THE PLOT
The graph in python 
![Figure_1](https://github.com/user-attachments/assets/efb8e42e-6956-4d6f-a865-56454ac5e23d)

> [!NOTE]
> !!!
+ To be able to generate the plot make sure to install matplotlib library:
```
pip install matplotlib
```
+ to update/create the json_test.json file:
```
./client1 > json_test.json
```

+ edit json_test.json file by adding open square bracket [ at the top and close square bracket ] 
at the very bottom as the example below:
<img width="553" alt="Screenshot 2024-08-22 at 22 29 11" src="https://github.com/user-attachments/assets/a44c0f38-6a59-456e-a630-1cad4ea1728a">

to see the plot run:
```
python3 Docs/plotJsonFile.py
```


