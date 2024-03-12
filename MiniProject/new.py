import numpy as np
import pandas as pd
import re
from nltk.corpus import stopwords
from nltk.stem.porter import PorterStemmer
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression 
from sklearn.metrics import accuracy_score

# Download NLTK resources
import nltk
nltk.download('stopwords')

# Load Sentiment 140 dataset
columns = ['target', 'id', 'date', 'flag', 'user', 'text']
df = pd.read_csv('/home/Utkarsh/Documents/twitter.csv', encoding='ISO-8859-1', names=columns)

# Preprocess the data
df = df[['target', 'text']]
df['target'] = df['target'].replace(4, 1)  # Convert positive class to 1
df['text'] = df['text'].str.lower()  # Convert text to lowercase

# Remove stop words and perform stemming
stop_words = set(stopwords.words('english'))
ps = PorterStemmer()

def preprocess_text(text):
    tokens = re.sub('[^a-zA-Z]', ' ', text).split()
    tokens = [ps.stem(word) for word in tokens if word not in stop_words]
    return ' '.join(tokens)

df['text'] = df['text'].apply(preprocess_text)

# Split the dataset into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(df['text'], df['target'], test_size=0.2, random_state=42)

# TF-IDF Vectorization
vectorizer = TfidfVectorizer(max_features=5000, ngram_range=(1, 3))
X_train_tfidf = vectorizer.fit_transform(X_train)
X_test_tfidf = vectorizer.transform(X_test)

# Build and train the model
model = LogisticRegression()
model.fit(X_train_tfidf, y_train)

# Make predictions
predictions = model.predict(X_test_tfidf)

# Evaluate the model
accuracy = accuracy_score(y_test, predictions)
print(f"Accuracy: {accuracy:.2%}")
