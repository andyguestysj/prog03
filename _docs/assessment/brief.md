---
title: Assessment
permalink: /docs/brief/
---

The assessment brief is available on moodle and [here](../2CB101-Prog03-Brief.docx).  

[Video recording of assessment brief presentation](https://web.microsoftstream.com/video/88a292b6-684d-45a1-836b-c4ee96fbc831)  

The Pokedex structure is simply to hold the pointers to the start of the player list and to the start of the pokemon list. It should be passed as a pointer to the functions as described in the brief.

``` c
Pokedex pokedex;
pokedex.PlayerHead = NULL;
pokedex.PokemonHead = NULL;

AddPlayerToList(&pokedex, "Andy");

void AddPlayerToList(Pokedex *pokedex, char name[20])
{
    // if list is empty create a new player node and set pokedex->PlayerHead equal to a pointer to the new node
    if (pokedex->PlayerHead==NULL)
    {
        pokedex->PlayerHead = NewPlayerNode(name);
    }
    else
    {
        // list not empty, use a while loop to get to last item in list
        // check to see if player is already in list along the way
        // if you get to the last not without finding the player already exists then 
        // create a new node and add it to the end of the list
    }
}

PlayerNode *NewPlayerNode(char name[20])
{
    PlayerNode * temp = (PlayerNode*)malloc (sizeof(PlayerNode));
    strcpy(temp->name,name);
    temp->PokemonCount=0;
    temp->next=NULL;
    return temp;
}
```


![alt text](/assets/img/pokedex.jpg "Pokedex Help") 