import streamlit as st
import seaborn as sns

st.title("Practice Streamlit App")
st.write("This is a simple Streamlit application to practice displaying data visualizations.")

# Load a sample dataset
df = sns.load_dataset("iris")
st.write("Here is the Iris dataset:")
st.dataframe(df)