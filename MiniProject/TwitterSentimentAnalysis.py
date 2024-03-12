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

# Get user input for a new tweet
Msg = input("Type your tweet here: ")
NewMsg = stemming(Msg)

# Transform the new tweet using the pre-trained vectorizer
X_new = vect.transform([NewMsg])

# Make predictions with the pre-trained model
prediction = newModel.predict(X_new)

# Display the result
if prediction[0]:
    print('Positive Tweet')
else:
    print('Negative Tweet')
