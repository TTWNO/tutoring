const SPADE = "&#x2660;"; // use .innerText with another element to produce that given character
const CLUB = "&#x2663;";
const HEART = "&#x2665;";
const DIAMOND = "&#x2666;";


class Card {
 constructor(inputValue, inputSuit){
     // this.suit will be "S", "D", "H", or "C"
     this.suit = inputSuit; //instance variables = different for every instantiation of the object.
     this.value = inputValue; 
     
     
 }
 visualRep(){                       //1. set innerhtml to be set to this.value /tempSuit, 2. class to include card class, 3.class to include B/R depending on suit
     let tempSuit = ""
     let newSpan = document.createElement("span");  // create new span for every card
     let addClassToSpan = newSpan.classList.add("card");
     
     
     
     switch (this.suit) {   
        case "S":
          tempSuit = SPADE;
          newSpan.classList.add("black");  //classList = attribute of any object that is an html element.
          break;
        case "C":
            tempSuit = CLUB;
            newSpan.classList.add("black");
          break;
        case "H":
            tempSuit = HEART;
            newSpan.classList.add("red");   //we are adding the RED class to the ELEMENT of "newSpan"
          break;
        case "D":
            tempSuit = DIAMOND;
            newSpan.classList.add("red");
          break;
        }
       // 
        let combined = this.value + tempSuit;
        newSpan.innerHTML = combined;
        return newSpan;
  }
};


window.onload = () => {   //once all html is done being rendered(dom loaded)  THEN DO THIS STUFF!

submitButton = document.getElementById("submit")
submitInfo = document.getElementById("card-input")
submitButton.addEventListener("click", () => {
        var theInput = "";
        theInput = submitInfo.value;
        submitInfo.value= "";
        theInputSuit = theInput[1];
        theInputValue = theInput[0];
        birthedCard = new Card (theInputValue,theInputSuit);
       birthedElement = birthedCard.visualRep()   // .visalrep()    method of the object (which is of the Card class)
        parentDiv = document.getElementById("cards");
        parentDiv.appendChild(birthedElement)
})

};

// user input will come in as "AS" of Ace of spades; "9H" for nine of hearts; "QS" for Queen of spades, etc.
// theInput[0] == first character in string
// theINput[1] == second character in string, etc.


// 1. add event listner to submitbutton, read input box,  clear input box,
 //take user input and make a new card, add the span , return from visualRep to 
 //the #cards (ID of cards)(also: classes start with a DOT!) 
     

