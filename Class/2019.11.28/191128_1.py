import tensorflow as tf

# 주석 :

'''
블럭 주석...?
'''

# test set
x_train = [1, 2, 3]
y_train = [1, 2, 3]

# W.b
W = tf.Variable(tf.random.normal([1]), name = "weight")
b = tf.Variable(tf.random.normal([1]), name = "bias")

print(W.numpy(), b.numpy())


# hypothesis
hypothesis = lambda: X * W + b

# error cost
cost = lambda: tf.reduce_mean(tf.square(hypothesis() - y_train))

# optimizer
optimizer = tf.keras.optimizers.SGD(lr = 0.01)

# train function
def train():
    optimizer.minimize(cost, var_list = [W, b])

X = x_train

# training
for step in range(6001):
    train()
    if step % 20 == 0:
        print("{0}\t{1}\t{2}\t{3}".format(step, cost(), W.numpy(), b.numpy()))

# testing
X = [4, 7, 10]
print(hypothesis().numpy())
