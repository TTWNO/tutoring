#include <iostream>

// Most basic function
void simple_function(){
  std::cout << "This is a simple function!" << std::endl;
}

// function which takes a single argument
void print_number(int pn){
  std::cout << "Number: " << pn << std::endl;
}

// function which takes an array argument
// you must pass the length of the array with the array
// note that in a function argument:
// int arr[], and
// int* arr
// are equivilant
void print_array(int arr[], int length){
  for (int i = 0; i < length; i++){
    std::cout << arr[i] << "," << std::endl;
  }
}

// Here in an improved array printer which
//  1. keeps all the data on one line
//  2. doesn't put a comma after the last item
void print_array2(int* arr, int length){
  std::cout << "[";
  for (int i = 0; i < length; i++){
    if (i < length-1){
      std::cout << arr[i] << ", ";
    } else {
      std::cout << arr[i] << "]" << std::endl;
    }
  }
}

// basic returning function
int get_me_a_four(){
  return 4;
}

// this could also be a float
// but that would require putting an f at the end of the number
// like the next function
double get_me_an_a_plus(){
  return 87.5;
}

float get_me_an_a_plus_float(){
  return 87.5f;
}

// To make a function that returns something like the biggest number in a list
// you can loop through the list and keep a copy of the highest number.
int get_biggest(int* arr, int length){
  int biggest = 0;

  // for each int in list
  for (int i = 0; i < length; i++){
    // if a is bigger than the already biggest number (starts at zero)
    if (arr[i] > biggest){
      // set biggest to a new value
      biggest = arr[i];
    }
  }
  return biggest;
} // a similar thing could be done with a very simple change to get the lowest in an array

// you can also permenantly change the values of an array
// when you loop through a list
void add_one_to_all(int* arr, int length){
  for (int i = 0; i < length; i++){
    arr[i]++;
  }
}

// you can take another argument and change all the numbers in an array by a paramater number
// this will add *by* to every value in the array
void add_n_to_all(int* arr, int length, int by){
  for (int i = 0; i < length; i++){
    arr[i] += by;
  }
}

// you can also make functions that call other functions
// this one get the biggest number, and then sets the biggest number zero
void make_biggest_zero(int* arr, int length){
  int g = get_biggest(arr, length);
  for (int i = 0; i < length; i++){
    if (arr[i] == g){
      arr[i] = 0;
    }
  }
}

// Turns out main has to be an int function, haha!
int main(){
  std::cout << "Hello world! The program has started!" << std::endl;

  // calling a simple function
  simple_function();

  // making a little array
  int arr[] = {15, 25, 18, 67, 233, 12, 5, 3};
  print_array2(arr, 8);

  // what is the biggest number in this array?
  // set it to a variable called biggest_in_array
  int biggest_in_array = get_biggest(arr, 8);
  std::cout << "This is the biggest number in the array: " << biggest_in_array << std::endl;

  // add one to every item in the array
  std::cout << "Adding 1 to all numbers in the array" << std::endl;
  add_one_to_all(arr, 8);
  std::cout << "Compare values to previous printing of values" << std::endl;
  // print array values again
  print_array2(arr, 8);

  // add 15 to all items in the array
  std::cout << "Adding 15 to all items in the array" << std::endl;
  add_n_to_all(arr, 8, 15);
  std::cout << "Values after adding an arbitrary number" << std::endl;
  print_array2(arr, 8);

  // here we call a function that calls another function inside it
  std::cout << "Making biggest number equal to zero" << std::endl;
  make_biggest_zero(arr, 8);
  print_array2(arr, 8);

  // now you may think that it's bullshit you have to type this every time you loop through an array
//  for (int i = 0; i < length; i++)
  // You would be right.
  // Later on, you'll learn about an std::list
  // this has all the speed of an array with all the benefits of a C++ class
  // you can send it BY ITSELF to other functions, and then use
  // list_var.length() to just get the length of it in the function
  //
  // an std::vector is similar, but lets you also add an arbitrary amount of items
  // I'm happy to show you that code as well some time!

  return 0;
}
