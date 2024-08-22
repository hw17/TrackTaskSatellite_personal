import json
import matplotlib.pyplot as plt

# Function to handle '--' and convert to None
def convert_value(value):
    return None if value == "--" else float(value)

# Read data from JSON file
with open('json_test.json', 'r') as file:
    data = json.load(file)

# Extract timestamps and output values
timestamps = [entry["timestamp"] for entry in data]
out1_values = [convert_value(entry["out1"]) for entry in data]
out2_values = [convert_value(entry["out2"]) for entry in data]
out3_values = [convert_value(entry["out3"]) for entry in data]

# Create the scatter plot
plt.figure(figsize=(8, 6))
plt.plot(timestamps, out1_values, label="Out1", color="red", marker='.')
plt.plot(timestamps, out2_values, label="Out2", color="green", marker='.')
plt.plot(timestamps, out3_values, label="Out3", color="blue", marker='.')

# Customize the plot
plt.xlabel("Timestamp")
plt.ylabel("Output Values")
plt.title("Output Values vs. Timestamp")
plt.legend()

# Show the plot
plt.grid(True)
plt.show()
