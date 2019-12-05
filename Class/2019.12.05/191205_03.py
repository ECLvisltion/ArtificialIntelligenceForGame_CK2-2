import tensorflow as tf
import numpy as np

# data import
xy = np.loadtxt("data-04-zoo.csv", delimiter = ",", dtype = np.float32)
x_data = xy[:, 0 : -1]
y_data = xy[:, [-1]]

x_dim = tf.shape(x_data)[1].numpy()
nb_class = 7 # 0 ~ 6

# convert y_data to one-hot
y_one_hot = tf.keras.utils.to_categorical(y_data, nb_class)
print("one hot : ", y_one_hot)

model = tf.keras.Sequential()
model.add(tf.keras.layers.Dense(units = nb_class, input_dim = x_dim, activation = "softmax"))
sgd = tf.keras.optimizers.SGD(lr = 0.1)
model.compile(loss = "categorical_crossentropy", optimizer = sgd, metrics = ["accuracy"])

history = model.fit(x_data, y_one_hot, epochs = 500, batch_size = 101, verbose = 2)

model.summary()
test_data = np.array([[0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0,]]) # 3
print(model.predict(test_data), model.predict_classes(test_data))
