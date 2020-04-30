#!/usr/bin/env python3
# we need this package to get command line arguments
import sys

def main():
  # Variables do not have a type
  ages = []
  known_fors = []
  num_of_friends = 6
  names_of_friends = []
  stupendously_large_number = 2085151919191923259151095239520912355321576
  country_codes = {
    "Canada": "CA",
    "Iceland": "IS",
    "Russia": "RU",
    "Switzerland": "CH",
    "United States of America": "US"
  }

  '''
  Here are some basic conditional statements in python

  This is also a block comment in python. Three single quotes in a row.
  '''
  if num_of_friends > 5:
    print("I have many friends!") # The indentation is *REQUIRED*.
  # Seni-colons are not

  if num_of_friends > 9:
    print("Too many friends. Not enough time for school...")
  else:
    print("Just right!")

  # else if is shortened to elif

  # This is how to check if an item is in an array.
  if "Micheal" in names_of_friends:
    print("Micheal is my friend!")
  elif "Carly" in names_of_friends:
    print("Carly is my friend! Micheal is not!")
  else:
    pass

  '''
  Because indentation is required for any python code blocks to work,
    the 'pass' statement is sometimes neseccary if you don't want your code to do anything
  'pass' can also be a placeholder for later, much like // TODO: comments are in other languages
  '''

  # Files

  # Let's open a file with some information about some of my friends!
  file_path = "friends.txt" # relative path
  file_mode = "r"
  '''
  The file mode can be any of these (and more, see docs):

  r: read-only
  rw: read-write
  a: append
  '''

  file_object = open(file_path, file_mode)
  # How to go through lines in a file
  for line in file_object:
    # The 'line' string *CONTAINS* the \n at the end of a file.
    # The end= "keyword argument" in a print function will tell it what to add onto
    #   the end of the line after it is done printing.
    print(line, end="")

  file_object.close()

  # Let's split up the data
  f = open(file_path, file_mode)

  for line in f:
    name, friend_type, age, known_for = line.split(";")
    ages.append(int(age))
    known_fors.append(int(known_for))
    names_of_friends.append(name)
    # Example for python formatting
    print("Name: '{0}'".format(name))
    print("Type: '{0}'".format(friend_type))
    print("Age: '{0}'".format(age))
    # You'll notice that the known_for variable contains a newline
    print("Known for: '{0}' months".format(known_for))
    # We can use a strip function to take it out.
    print("Known for: '{0}' months".format(known_for.strip("\n")))


  # Now let's try some list comprehention
  print("Upper case list of friends")
  upper_case_friends = [x.upper() for x in names_of_friends]
  print(upper_case_friends)

  print("List of friends that do not start with s")
  no_s_names = [x for x in names_of_friends if x.lower()[0] != 's']
  print(no_s_names)

  print("'s' names replaced with empty strings")
  replace_s_names_with_empty = [x if x.lower()[0] != 's' else "" for x in names_of_friends]
  print(replace_s_names_with_empty)

  def centered(s):
    return "{0:*^15}".format(s)

  print("Running centered on each name")
  cen = [centered(x) for x in names_of_friends]
  print(cen)

  # Because it is so common to run a function on a list, you can just map the list.
  # A map will run a function on each element of a list and return a new list with the elements having run through a function
  print("Using map to center the names")
  cen2 = list(map(centered, names_of_friends))
  print(cen2)

  # Python also support lambda (inline/anonymous) functions like so
  # Anywhere you can pass a function in python, you may also pass a lambda.
  print("Using lambda functions to left align the names")
  l_al = list(map(lambda x: "{0:<<15}".format(x), names_of_friends))
  print(l_al)

  # You can pass multiple arrays into a map function, as long as the function is is calling accepts two arguments.
  print("Using two lists, adding them together.")
  known_since = list(map(lambda yo, kn: yo-round(kn/12), ages, known_fors))
  print("I have known each of my friends since they were")
  print(known_since)

  # We can use a zip function to put some data together like so
  print()
  print("Zipping the names, age, and known since lists")
  friends_time_info = list(zip(names_of_friends, ages, known_since))
  print(friends_time_info)

  # looping through is easy
  for friend in friends_time_info:
    print("Name: {0[0]}\nAge: {0[1]}\nKnown since: {0[2]}\n".format(friend))

def add_friend():
  name = input("What is the name of your friend? ")
  age = input("How old are they? ")
  known_for = input("How long have your known them (in months)? ")
  f_type = input("What kind of friend are they (roommate, mentor, peer, etc)? ")
  write_to_file_string = "{};{};{};{}\n".format(name, f_type, age, known_for)
  # writing to a file
  friend_file = open("friends.txt", "a")
  friend_file.write(write_to_file_string)
  friend_file.close()

# Using __name__
if __name__ == "__main__":
  main()
  print("You ran this from the command line.")
  if len(sys.argv) > 1:
    print("We only want to work on command line arguments if we know it is being run from the command line")
    for ar in range(len(sys.argv)):
      print("[{}]: {}".format(ar, sys.argv[ar]))
      if sys.argv[ar] == "--add" or sys.argv[ar] == "-a":
        add_friend()
else:
  print("You imported this")
print("__name__ = \"{}\"".format(__name__))
