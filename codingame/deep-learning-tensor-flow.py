
# MNIST For ML Beginners!

# This tutorial is intended for readers who are new to both machine learning and TensorFlow.
# Just like programming has Hello World, machine learning has MNIST.
# MNIST is a simple computer vision dataset. It consists of images of handwritten digits.
# Source: https://goo.gl/rLXVsR

# Please help us to improve this section by sending us your
# feedbacks and comments on: https://docs.google.com/forms/d/16fH20Qf8gJ2o31Vnlss2uLJ7wL9vq76TeUGqghTY0uI/viewform

# Importing input data
import random
import input_data
mnist = input_data.read_data_sets(raw_input(), raw_input(), raw_input())


import tensorflow as tf
################################
# Enter your code between here #
################################


print ' '.join(map(str, [random.randint(0,9) for _ in range(len(mnist.validation.images))]))


########################
#        And here      #
########################


# Uncomment to get a prediction number for each image

#result = sess.run(tf.argmax(y,1), feed_dict={x: mnist.validation.images})
#print ' '.join(map(str, result))
