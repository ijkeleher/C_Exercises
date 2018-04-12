#include <stdio.h>

struct dogFavs {

    char *food;
    char *friend;

};

typedef struct dog{

    const char *name;
    const char *breed;
    int avgHeightCm;
    int avgWeightLbs;

    struct dogFavs favouriteThings;

} dog;

void getDogInfo(struct dog theDog){

    printf("\n");
    printf("Name: %s\n\n", theDog.name);
    printf("Breed: %s\n\n", theDog.breed);
    printf("avgHeight in Cm: %d cms\n\n", theDog.avgHeightCm);
    printf("avgWeight in Lbs: %d pounds\n\n", theDog.avgWeightLbs);

}

/*
print the locations in memory of the data held in variables
using & on ints because they are not pointers
*/

void getMemoryLocation(struct dog theDog){
    printf("Name Location: %d\n\n", theDog.name);
    printf("Breed Location: %d\n\n", theDog.breed);
    printf("Height Location: %d\n\n", &theDog.avgHeightCm);
    printf("Weight Location: %d\n\n", &theDog.avgWeightLbs);
}

/*
because type dog is defined don't need to type struct anymore
input of getDogFavs is just "type structName"
*/

void getDogsFavs(dog theDog){

    printf("\n");
    printf("%s loves to eat %s and his best friend is %s\n\n",
        theDog.name,
        theDog.favouriteThings.food,
        theDog.favouriteThings.friend);

}

void setDogWeightPtr(dog *theDog, int newWeight){
    
   (*theDog).avgWeightLbs = newWeight;
    printf("\nthe weight was changed to %d\n",
        theDog->avgWeightLbs);

}

int main(void){

    /*
    creating a struct inside a struct
    */

    dog fido = {"Fido", "Saint Bernard", 90, 264, {"Kebabs", "John"}};
    
    getDogsFavs(fido);

    setDogWeightPtr(&fido, 100);

    printf("The weight in main() is %d\n\n", fido.avgWeightLbs);
}
