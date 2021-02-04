# comments are written like so same as //
'''
multiline comments are like this
this is like the Java /* */
'''

# String x = "Test";
x = "test"
x = 11

l = [1, 2, 3]
for y in l:
    print(y)

'''
for (int i = 0; i < somevalue; i++) {

}
'''
# 0 - 9
for n in range(10):
    print(n)

# runs forever
while True:
    print("Something")

'''
public void test(String x) {
    System.out.println(x);
}
'''
def test(x):
    print(x)

def test2():
    return 10

def test3():
    return "Hello world!"

'''
class Animal {
    int health = 10;
    String name = "";

    public Aminal(int health, String name) {
        this.health = health;
        this.name = name;
    }
}
'''
class Animal:
    def __init__(self, health, name):
        self.health = health
        self.name = name
    def getName(self):
        return self.name

animal1 = Animal(10, "Test")
print(animal1.getName())

'''
String[] countries = {"Canada", "USA", "Taiwan", "Norway"};
for (int i = 0; i < countries.length; i++) {
    countries[i] = countries[i].toUpperCase();
}
'''
countries = ["Canada", "USA", "Taiwan", "Norway"]
upper_countries = [upper(country) for country in contries]
print(upper_countries)

