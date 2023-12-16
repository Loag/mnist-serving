import os
import torch
import torch.nn as nn
import torch.optim as optim
import torchvision
import torchvision.transforms as transforms

# Load and preprocess the MNIST dataset
transform = transforms.Compose([
    transforms.ToTensor(),  # Convert PIL images to Tensors.
    transforms.Normalize((0.5,), (0.5,))  # Normalize the images with mean=0.5 and std=0.5.
])

trainset = torchvision.datasets.MNIST(
    root='./data',  # Directory where the datasets are stored.
    train=True,  # Specify training dataset.
    download=True,  # Download the data if it's not already present in the specified directory.
    transform=transform  # Apply the specified transformations to the dataset.
)

trainloader = torch.utils.data.DataLoader(
    trainset,  # The dataset to load.
    batch_size=64,  # Batch size for training.
    shuffle=True  # Shuffle the training data to ensure random distribution of data.
)

testset = torchvision.datasets.MNIST(
    root='./data',  # Directory for storing datasets.
    train=False,  # Specify test dataset.
    download=True,  # Download the data if it's not already present.
    transform=transform  # Apply transformations to the dataset.
)

testloader = torch.utils.data.DataLoader(
    testset,  # The dataset to load.
    batch_size=64,  # Batch size for testing.
    shuffle=False  # No need to shuffle the test data.
)


# Define a simple neural network
class SimpleNN(nn.Module):
    def __init__(self):
        super(SimpleNN, self).__init__()  # Initialize the parent class.
        self.fc1 = nn.Linear(28*28, 512)  # First fully connected layer (input layer).
        self.fc2 = nn.Linear(512, 50)  # Second fully connected layer (hidden layer).
        self.fc3 = nn.Linear(50, 10)  # third layer connected layer (output layer).


    def forward(self, x):
        x = x.view(-1, 28*28)  # Flatten the image input for the fully connected layer.
        x = torch.relu(self.fc1(x))  # Apply ReLU activation function after first layer.
        x = torch.relu(self.fc2(x))  # Apply ReLU activation function after second layer.
        x = self.fc3(x)  # Output layer.
        return x

net = SimpleNN()  # Create an instance of the network.


# Define the loss function and optimizer
criterion = nn.CrossEntropyLoss()  # Loss function for classification.
optimizer = optim.SGD(net.parameters(), lr=0.001, momentum=0.9)  # Optimizer (Stochastic Gradient Descent).

# Train the network
for epoch in range(10):  # Loop over the dataset for a total of 10 epochs.
    print(f"epoch: {epoch}")

    for data in trainloader:
        inputs, labels = data  # Get the inputs and labels from the data.
        optimizer.zero_grad()  # Zero the parameter gradients.
        outputs = net(inputs)  # Forward pass: compute the predicted outputs.
        loss = criterion(outputs, labels)  # Compute the loss.
        loss.backward()  # Backward pass: compute the gradient of the loss with respect to model parameters.
        optimizer.step()  # Update the parameters based on the gradients.

# Test the network
correct = 0
total = 0
with torch.no_grad():  # Gradient computation is not required in test phase.
    for data in testloader:
        images, labels = data
        outputs = net(images)  # Get predictions from the model.
        _, predicted = torch.max(outputs.data, 1)  # Get the predicted classes.
        total += labels.size(0)  # Update total count of labels.
        correct += (predicted == labels).sum().item()  # Update correct prediction count.

print('Accuracy of the network on the 10000 test images: %d %%' % (100 * correct / total))

input_size = torch.randn(1, 784) # onnx needs to know the shape of the model input

print("exporting onnx format model")
torch.onnx.export(net, input_size, "mnist.onnx")