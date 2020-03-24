# Medical Cost
# Dataset from: https://github.com/stedy/Machine-Learning-with-R-datasets

# Importing the libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Importing the dataset
dataset = pd.read_csv('insurance.csv')
X_rf = dataset.iloc[:, 0:6].values
y_rf = dataset.iloc[:,6].values

# Data preprocessing
from sklearn.preprocessing import LabelEncoder, OneHotEncoder
labelencoder_X_1 = LabelEncoder()
X_rf[:, 1] = labelencoder_X_1.fit_transform(X_rf[:, 1])
labelencoder_X_2 = LabelEncoder()
X_rf[:, 4] = labelencoder_X_1.fit_transform(X_rf[:, 4])
labelencoder_X_3 = LabelEncoder()
X_rf[:, 5] = labelencoder_X_1.fit_transform(X_rf[:, 5])
# Create dummy variable to column 'region'
onehotencoder = OneHotEncoder(categorical_features = [5])
X_rf = onehotencoder.fit_transform(X_rf).toarray()
# Remove one of the dummy variables to avoid dummy variable trap
X_rf = X_rf[:, 1:]


# Splitting the data into Training and Test set
from sklearn.model_selection import train_test_split
X_rf_train, X_rf_test, y_rf_train, y_rf_test = train_test_split(X_rf, y_rf, test_size = 0.2)

# Fitting Random Forest Regression to the dataset
from sklearn.ensemble import RandomForestRegressor
random_forest_regressor = RandomForestRegressor(n_estimators = 10)
random_forest_regressor.fit(X_rf_train, y_rf_train)

# Predicting the Test set results using Random Forest Regression
y_pred_rfr = random_forest_regressor.predict(X_rf_test)
