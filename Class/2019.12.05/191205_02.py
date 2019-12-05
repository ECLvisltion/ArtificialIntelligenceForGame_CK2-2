import tensorflow as tf
import numpy as np

# training data
xy = np.loadtxt("diabetes.csv", delimiter = ",", dtype = np.float32)
x_data = xy[: , 0 : -1]
y_data = xy[:, [-1]]

# data shape
x_dim = tf.shape(x_data)[1].numpy() # 8
y_dim = tf.shape(y_data)[1].numpy() # 1

# keras Sequential model
model = tf.keras.Sequential()
model.add(tf.keras.layers.Dense(units = y_dim, input_dim = x_dim))
model.add(tf.keras.layers.Activation("sigmoid"))

# optimizer setting
sgd = tf.keras.optimizers.SGD(lr = 0.01)
model.compile(loss = "binary_crossentropy", optimizer = sgd, metrics = ["accuracy"])

# print summary
model.summary()

# train the model
history = model.fit(x_data, y_data, epochs = 500, verbose = 2)

# print accuracy
print("Accuracy : {0}".format(history.history["accuracy"][-1]))

# predict a single data point
y_predict = model.predict([[-0.294118, 0.487437, 0.180328, -0.292929, 0, 0.00149028, -0.53117, -0.0333333]])
print("Predict : {0}".format(y_predict))

# evaluate model
_eval = model.evaluate(x_data, y_data)
print("loss : {0}, accuracy : {1}".format(_eval[0], _eval[1]))
