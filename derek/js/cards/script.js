const SPADE = "&#x2660;"; // use .innerText with another element to produce that given character
const CLUB = "&#x2663;";
const HEART = "&#x2665;";
const DIAMOND = "&#x2666;";

// example: someCardElement.innerText = "A" + SPADE
// this will produce: A♠

var fullDeckvalue = ["A",2,3,4,5,6,7,8,9,10,"J","Q","K"]; // fullDeckvalues.indexOf("J") will return 10
var fullDecksuit = ["S","C","H","D"];
const A=1
const J=11
const Q=12
const K=13

//var newInput = document.getElementById ("card-input");
//var gotValue = newInput.addEventListener("click", makecard);


class Card {
 constructor(inputValue, inputSuit){
     // this.suit will be "S", "D", "H", or "C"
     this.suit = inputSuit; //instance variables = different for every instantiation of the object.
     this.value = inputValue; 
     
     
 }
 visualRep(){                       //1. set innerhtml to be set to this.value /tempSuit, 2. class to include card class, 3.class to include B/R depending on suit
     var tempSuit = ""
     newSpan = document.createElement("span");  // create new span for every card
     addClassToSpan = newSpan.classList.add("card");
     
     
     switch (this.suit) {
        case "S":
        tempSuit = SPADE;
          break;
        case "C":
            tempSuit = CLUB;
          break;
        case "H":
            tempSuit = HEART;
          break;
        case "D":
            tempSuit = DIAMOND;
          break;
        }
       // 
        combined = this.value + tempSuit;
        newSpan.innerHTML = combined;
        return newSpan;
  }
};

//
     

c1 = new Card("A", "S");//instantiate

c1.visualRep();


//addNewCard(c1.visualRep());   //need to return visual representation of the card.

c2 = new Card("J", "S");
c3 = new Card("9", "H");
// make a class which can accept these as their input.



// Note: Use the span element to output new card.
//       use the class "card", and a class coresponding to the correct color: red or black



function separateoutValue(gotValue){ // extract value from input
   return separateoutValue;
};

function separateoutSuit(gotValue){ // extract suit from input
    return separateoutSuit;
 };

function parseArrayForValue(){}
function parseArrayForSuit(){}


function makecard (){   //make card logic

}
 