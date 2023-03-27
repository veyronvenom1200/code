import sys
import nltk
import turtle
from nltk.corpus import treebank
from collections import namedtuple
import colorcode as cc
import string

punctuation_marks = list(string.punctuation)


def words_to_color(input_text):
	tokens = nltk.word_tokenize(input_text)
	tagged = nltk.pos_tag(tokens)
	assigned_dict = {}

	for word in tagged:
		if word[0] not in punctuation_marks:
			assigned_dict[word[0]] = cc.pos_tag_colors[word[1]]

	return assigned_dict
	# return [tup[1] for tup in tagged]


# def assigned_color(tagged):
# 	assigned_dict = {}
# 	for word in tagged:
# 		if word[0] not in punctuation_marks:
# 			assigned_dict[word[0]] = cc.pos_tag_colors[word[1]]

# 	return assigned_dict
