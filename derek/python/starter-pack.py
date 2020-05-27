
# functions
def test1(s):
    print(s)

def test2(s, end_l="\n"):
    print(s, end=end_l)

def test3(s, end_l="\n", trunca=-1):
    print(s[:trunca], end=end_l)

test1("Hello World!")
test2("I am Tait!")
test2("I am running...", ",")
test3("I am done running...", trunca=1) # prints "I" 

hw = "Hello World!"
ex = hw[-1] # exclaimation point
hello = hw[:5] # "Hello"
world = hw[6:11] # "World"
world2 = hw[6:-2] # "World"


rs = JSON.stringify({"random_string": hw})
json_back = JSON.parse(rs)
print(json_back['random_string']) # would print "Hello World!"

def double_num(x):
    return x*2

def is_even(x):
    return x % 2 == 0

arr = [1, 2, 3, 4, 5]
doubled = [x*2 for x in arr]
doubled_v2 = map(arr, double_num) # exactly equal to doubled

even_nums = filter(arr, is_even)

class Student:
    def __init__(self, n_name="John Doe", n_gpa=0.0):
        self.gpa = n_gpa
        self.name = n_name

s = Student("", 3.0)
print(s.gpa)
print(s.name)

s2 = Student(n_gpa=3.9)
print(s.gpa)
print(s.name)
