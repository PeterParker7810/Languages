import seaborn as sns

print(sns.get_dataset_names())
DS = sns.load_dataset("exercise")
print(DS.head())
sns.displot(DS['pulse'])