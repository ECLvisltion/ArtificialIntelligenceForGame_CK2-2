import tensorflow as tf
tf.random.set_seed(0)

x_data = [[14.0, 80.0, 73.0],
          [18.0, 88.0, 95.0],
          [16.0, 91.0, 90.0],
          [20.0, 98.0, 100.0],
          [14.0, 66.0, 70.0]]
y_data = [[100.0], [131.0], [129.0], [143.0], [98.0]]

W = tf.Variable(tf.random.normal([3, 1]), name = "weight")
b = tf.Variable(tf.random.normal([1]), name = "bias")

# predict : hypothesis
hypothesis = lambda : tf.matmul(X, W) + b

# cost or lost or error function
cost = lambda : tf.reduce_mean(tf.square(hypothesis() - Y))

# train
optimizer = tf.keras.optimizers.SGD(lr = 1e-5)
train = lambda : optimizer.minimize(cost, var_list = [W, b])

X = x_data
Y = y_data
for step in range(4001):
    cost_val = cost().numpy()
    hy_val = hypothesis().numpy()
    train()
    if step % 10 == 0:
        print(step, "Cost : ", cost_val, "\nPrediction : ", hy_val)
