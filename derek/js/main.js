class Entity {
    constructor(){
        this.x = 0;
        this.y = 0;
        this.name = "";
    }

    print_info(){
        console.log("X: " + this.x);
        console.log("Y: " + this.y);
        console.log("Name: " + this.name);
    }
    local_var(){
        let t = 10;
        console.log(t);    //getters and setters.
    }
    get_x(){
        return this.x;
    }
    set_x(_x){
        this.x = _x;  //use underscore to make setter clear for maintainers.
    }
    set_name(st){
        this.name = [];
        for (s in st){
            this.name.push(s);
        }
    }
}


class Player extends Entity {  //extends = "is a child of"
    constructor(){
        super();
        this.health = 10;
    }

    print_info(){
        console.log("Player Health: " + this.health);
    }
    attack_from_keyboard(e){
        // hit some other entity e
    }
}

window.onload = function(){
    p1 = new Player();   //instantiates (a new cookie)
    p1.x = 10;
    p1.set_x(10); // these two are equiv.    Calls set_x ON p1 with the parameter of 10
    p1.y = 15;
    p1.name = "Sparta";
    p1.print_info();

    entities = [];

    entities.push(p1);

    for (x = 0; x < 100; x++){
        y = new Entity();
        y.x = 12;
        y.y = 542;
        y.name = loadFromOtherLocation();
        entities.push(y);
    }

    for (e of entities){
        e.show_on_browser();
    }

    e1 = new Entity();
    e1.x = 19;
    e1.y = 22;
    e1.name = "Lorax";
    e1.print_info();

    e2 = new Entity();
    e2.x = 15;
    e2.y = 22;
    e2.name = "Theodore";
    e2.print_info();
}