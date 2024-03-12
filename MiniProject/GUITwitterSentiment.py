import tkinter as tk
from tkinter import Label, Entry, Button, StringVar
import re
import nltk
import pickle
from nltk.corpus import stopwords
from nltk.stem.porter import PorterStemmer
from sklearn.feature_extraction.text import TfidfVectorizer

nltk.download('stopwords')

# Load the pre-trained model and vectorizer
newModel = pickle.load(open('/home/Utkarsh/Documents/MiniProject/TwitterModel.sav', 'rb'))
vect = pickle.load(open('/home/Utkarsh/Documents/MiniProject/vector.sav', 'rb'))

# Function for stemming
def stemming(content):
    stemmed = re.sub('[^a-zA-Z]', ' ', content)
    stemmed = stemmed.lower().split()
    stemmed = [PorterStemmer().stem(word) for word in stemmed if word not in stopwords.words('english')]
    return ' '.join(stemmed)

# Function to analyze sentiment on button click
def analyze_sentiment():
    tweet_text = entry.get()
    if tweet_text:
        stemmed_text = stemming(tweet_text)
        X_new = vect.transform([stemmed_text])
        prediction = newModel.predict(X_new)
        result_var.set('Positive Tweet' if prediction[0] else 'Negative Tweet')
    else:
        result_var.set('Please enter a tweet!')

# Function to clear the text field
def clear_text_field():
    entry.delete(0, 'end')
    result_var.set('')

# Create the main window
root = tk.Tk()
root.title("Twitter Sentiment Analysis")

# Create and configure the GUI components
label = Label(root, text="Enter your tweet:")
label.pack(pady=20)

entry = Entry(root, width=50)
entry.pack(pady=10)

analyze_button = Button(root, text="Analyze Sentiment", command=analyze_sentiment)
analyze_button.pack(pady=10)

clear_button = Button(root, text="Clear", command=clear_text_field)
clear_button.pack(pady=10)

result_var = StringVar()
result_label = Label(root, textvariable=result_var, font=('Helvetica', 15, 'bold'))
result_label.pack(pady=10)

# Run the main loop
root.mainloop()
