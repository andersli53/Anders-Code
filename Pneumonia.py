# Pneumonia
# Dataset from: https://www.kaggle.com/paultimothymooney/chest-xray-pneumonia

# Importing the libraries
from keras.models import Sequential
from keras.layers import Dense
from keras.layers import Convolution2D
from keras.layers import MaxPooling2D
from keras.layers import Flatten

# Initializing the CNN
classifier = Sequential()

# Step 1 - Convolution
classifier.add(Convolution2D(filters = 32, kernel_size = (3, 3),
                             input_shape = (64, 64, 3), activation = 'relu'))

# Step 2 - Pooling
classifier.add(MaxPooling2D(pool_size = (2, 2)))

# Adding additional convolutional layer and appply max pooling to it
classifier.add(Convolution2D(filters = 32, kernel_size = (3, 3), activation = 'relu'))
classifier.add(MaxPooling2D(pool_size = (2, 2)))

# Step 3 - Flattening
classifier.add(Flatten())

# Step 4 - Full Connection
# Creating ANN
# Adding hidden layer with rectifier as activation function
classifier.add(Dense(units = 128, activation = 'relu'))

# Adding output layer with sigmoid as activation function
classifier.add(Dense(units = 1, activation = 'sigmoid'))

# Compiling the CNN
classifier.compile(optimizer = 'adam', loss = 'binary_crossentropy', metrics = ['accuracy'])

# Fitting the CNN to the images
from keras.preprocessing.image import ImageDataGenerator
train_datagen = ImageDataGenerator(
        rescale = 1./255,
        shear_range = 0.2,
        zoom_range = 0.2,
        horizontal_flip = True)

test_datagen = ImageDataGenerator(rescale = 1./255)

# Extract training set, resize each image, create each batch with 32 images
training_set = train_datagen.flow_from_directory('train',
                                                 target_size = (64, 64),
                                                 batch_size = 32,
                                                 class_mode = 'binary')

# Extract test set, resize each image, create each batch with 32 images
test_set = test_datagen.flow_from_directory('test',
                                             target_size = (64, 64),
                                             batch_size = 32,
                                             class_mode = 'binary')



classifier.fit_generator(training_set,
                        steps_per_epoch = 5218,
                        epochs = 25,
                        validation_data = test_set,
                        validation_steps = 626)
