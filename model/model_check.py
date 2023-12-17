import onnxruntime as ort

# Load the model
sess = ort.InferenceSession("mnist.onnx")

# Get input and output names
input_names = [input.name for input in sess.get_inputs()]
output_names = [output.name for output in sess.get_outputs()]

print("Input Names:", input_names)
print("Output Names:", output_names)
