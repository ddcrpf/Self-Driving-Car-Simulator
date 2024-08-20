



from tensorflow import keras
import numpy as np
from tensorflow.keras import layers

 


def make_model(inshape):

   inputs = keras.Input(shape=inshape+(3,))
   x = layers.Rescaling(1.0 / 255.0)(inputs)
   x = layers.Conv2D(24, 5, strides=2, padding="same")(x)
   x = layers.Activation("relu")(x)
   x = layers.Conv2D(36, 5, strides=2, padding="same")(x)
   x = layers.Activation("relu")(x)
   x = layers.Conv2D(48, 5, strides=2, padding="same")(x)
   x = layers.Activation("relu")(x)
   x = layers.Conv2D(64, 3, strides=1, padding="same")(x)
   x = layers.Activation("relu")(x)
   x = layers.Conv2D(78, 3, strides=1, padding="same")(x)
   x = layers.Activation("relu")(x)  
   x = layers.Flatten()(x)
   x= layers.Dense(100,activation="relu")(x)
   x= layers.Dense(50,activation="relu")(x)  
   x= layers.Dense(10,activation="relu")(x) 
   outputs= layers.Dense(1,activation="tanh")(x)     # tanh activation used since output range from -1 to 1
   
   return keras.Model(inputs,outputs)

        

      
