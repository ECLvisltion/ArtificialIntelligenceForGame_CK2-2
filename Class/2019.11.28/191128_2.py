import tensorflow as tf
import numpy as np

# training set
x_train = [1, 2, 3]
y_train = [1, 2, 3]

# tensorflow model
tf.model = tf.keras.Sequential()
tf.model.add(tf.keras.layers.Dense(units = 1, input_dim = 1))

# optimizer
sgd = tf.keras.optimizers.SGD(lr = 0.01)
tf.model.compile(loss = "mse", optimizer = sgd)

# print summary
tf.model.summary()

# train
tf.model.fit(x_train, y_train, epochs = 300)

# predict
y_predict = tf.model.predict(np.array([1.5, 4.5]))
print(y_predict)
