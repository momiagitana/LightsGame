EX4 LIGHTS GAME:


Student's details:

    Ariel Zingman, ID: 342524808
    Zalman Rabin,  ID: 336180005


General details about the project:

    This is a graphic game. In the game there is a symetric amount of nodes.
    The nodes appear in the screen in the shape of an hexagon.
    Each node has up to 6 legs pointing in 6 directions.
    A right click on a node (on the circle) will make it turn right, and a left click turn left.
    The central node is always illuminated and if another node is reachable thruogh legs and or other nodes,
    it also is illuminated.
    The goal of the game is to pass 3 levels each one with more nodes than the last one, 
    to pass each level the player has to connect every node in the graph turning them all on.

Design:

    The classes were designed as follows:

        Controller: 
            controls the run of the game, loads new levels, and waits for clicks which are send to the graph to handle

        DGraph: 
            (D for Drawable) is in the one holding a lineOfNodes (vector <shared_ptr<DNodes>>). 
            The graph knows how to draw itself and handle clicks by iterating thruogh the nodes 
            and letting them handle the click.
            In addition the grahp knows how to run BFS while updating the nodes turning them on or off.
        
        DNode: 
            each node knows how to handle a click, meaning it checks if the click was made on itself and then
            turning left or right depending on the click.
            They also know how to draw themselfs and check to which potential neighbours they are actually conected.
            Each node holds a location, an int ID, a boolean (on/off) parameter, a boolean vector of legs,
            a shared_ptr vector of potential neighbours, and an int vector of actual neighbours (used for BFS)
        
        LevelBuilder: 
            this class is in charge of building levels, its principal function is build() that returns a DGraph.
            To create a level this object first of all makes full graph (all the nodes with all the possible legs),
            and then randomizes the level by taking random legs leaving the puzzle solvable and then randomly rotates
            the nodes.

        button:
            is a very simple class that creates an object button loads an image and knows how to recognize
            if a click was made on it.
            When each level is compleated an arrow button appears in the left-down corner of the screen and the app
            waits for a click on the button to load the next level (or finish the game).

List of files that were giving in:

    main.cpp

    Controller.cpp , Controller.h

    DGraph.cpp, DGraph.h

    DNode.cpp, DNode.h

    LevelBuilder.cpp , LevelBuilder.h

    button.cpp, button.h

    globals.h 
        contains global parameters that can be switched by the user before compiling.

    README.txt



Main data structures:
    
    The level builder uses a matOfNodes which is a vector of lineOfNodes (which is: vector <shared_ptr<DNodes>>)
    in order to build the level.
    
    The graph holds a lineOfNodes.

    Each node holds 3 vectors:
        <shared_ptr<DNode>> where it has its potential neighbours
        <int> where it has the names (ID's) of its actual neighbours
        <bool> used for knowing which legs are on 

Algorithms:
    
    LevelBuilder: 
        The algorithm for building a random level is as follows:
            - a matrix of nodes is created, the matrix has nodes where later will be seen on screen and nullptrs where no node is.
              the matrix looks something like this:
                  [ 0, 0, 1, 0, 1, 0, 1, 0, 0 ]
                  [ 0, 1, 0, 1, 0, 1, 0, 1, 0 ]
                  [ 1, 0, 1, 0, 1, 0, 1, 0, 1 ]
                  [ 0, 1, 0, 1, 0, 1, 0, 1, 0 ]
                  [ 0, 0, 1, 0, 1, 0, 1, 0, 0 ]
            - using the matrix we run thruogh it and set the potential neighbours for each node 
              while adding all the legs possible (each pointing to every potential neighbours)
            - we randomly chose a node and a leg and we take it off, right after we check using BFS that the graph
              is still solvable, if it is we take another leg, if it isnt we bring back the last leg that we took
            - we iterate through every node and take randomly as many legs as possible from each one
            - finally we iterate through every node and rotate it a random number from 0-5 times

    BFS:
        the bfs algorithm is run by the DGraph, it works like a regular BFS with the exeption that 
        we dont give a distance to the nodes but we just set them as on or off if we got to it.
    
    DNode:

        vector placing:
            each place of the boolean vector of legs represents a leg
            when the node draws itself it runs through the vector and wherever theres a 1 it draws a leg
            each place on the shared_ptr<DNode> vector matches the place of the legs

            lets look at an example:

                0   1 
              2   3   4
                5   6

            the node #3 has the following vectors:
            {1, 1, 0, 1, 0, 0}
            {4, 6, 5, 2, 0, 1}
            meaning there is a leg pointing at nodes numbers: 4, 6 and 2
            if it turns left, the boolean vector will rotate and be:
            {1, 0, 1, 0, 0, 1}
            leaving legs poiting at nodes numbers: 4, 1 and 5
            

        checkTouches():
            right after shifting (rotating) each node checks which of the potential neighbours are actual neighbours
            -first we clear the vector of actual neighbours
            -we run through the size of the leg vector
            -for each leg we check if we have a neighbour in that possition
            -if we do we check if theres a leg pointing at him
            -if there is we ask that neighbour if he also has a leg pointing at us
            -if he does we add him as a neighbours
            -if he doesnt we dont add him and we ask him to delete us from its list of actual neighbours (if he had us)

Known bugs:
    Both students use macOS so we had to make the cmake work for us.
    before uploading this excercise conditions were added to the cmake file to work with both windows and mac,
    since we werent taught how to deal with cmake and we had to learn it by ourselves please bear in mind that 
    there might be a problem with the cmake files and thus they might need a check if the game does not compile properly.
    On the same note, loading png for textures work differently in mac and windows, the path set for the loading was set
    considering a windows user case and tested on virtual machines, this is not a 100% reliable so if after wining a level
    a white arrow doesnt appear on the left-down corner of the screen letting the user play the next level,
    be so kind to check that the path has been set correctly by copying the full path of the "next.png" image that should be
    on the build folder.
    Same for the "won.png" thats loaded when the game is finished.
    each load can be found:
    button.cpp -> line 8
    controller.cpp -> line 94
    

Design desicions:
    We decided to have the levels built in every run of the game.
    We made the levels random, meaning it might happen that the level starts and part of it is already on,
    this doesnt mean that this is the correct possition of those nodes but it could. in our trys every few times this happened.
    we couldn't find a way to fix this that was worth the time (speaking in terms of big O)
    

