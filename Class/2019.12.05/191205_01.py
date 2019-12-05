import tensorflow as tf
import numpy as np
tf.random.set_seed(0)

# training data
x_data = [[1, 2], [2, 3], [3, 1], [4, 3], [5, 3], [6, 2]]
y_data = [[0], [0], [0], [1], [1], [1]]

# keras Sequential model
model = tf.keras.Sequential()
model.add(tf.keras.layers.Dense(units = 1, input_dim = 2))
model.add(tf.keras.layers.Activation("sigmoid"))

# set optimizer and learning method
sgd = tf.keras.optimizers.SGD(lr = 0.01)
model.compile(loss = "binary_crossentropy", optimizer = sgd, metrics = ["accuracy"])

# print summary
model.summary()

# train the model
history = model.fit(x_data, y_data, epochs = 100)

# Accuracy report
print("Accuracy : ", history.history["accuracy"][-1])

# trainning result
y_predict = model.predict(x_data)
result = tf.cast(y_predict > 0.5, dtype = tf.float32)
print(y_predict)
print(result.numpy())
