#include "administration.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// leave resource_detector.h as last include!
#include "resource_detector.h"

/* pre    : animalArrayLength must be greater than numberOfAnimalsPresent
 * post   : animalArray is updated with the information from animalPtr, the
 * updated number of animals is passed in newNumberOfAnimalsPresent returns: 0
 * on success or -1 if an error occurs
 */

int addAnimal(
            const Animal* animalPtr, Animal* animalArray,
            size_t animalArrayLength, size_t numberOfAnimalsPresent,
            size_t* newNumberOfAnimalsPresent)
{
    if(animalArrayLength > numberOfAnimalsPresent)
    {
        *newNumberOfAnimalsPresent = numberOfAnimalsPresent++;
        animalArray[numberOfAnimalsPresent++] = *animalPtr;
    }
    else
    {
        return -1;
    }

    if (&numberOfAnimalsPresent == newNumberOfAnimalsPresent)
    {
        return -1;
    }
    return 0;
}

/* pre    :
 * post   : All animals with id 'animalId' are removed from AnimalArray, the
 * updated number of animals is passed in newNumberOfAnimalsPresent returns: The
 * number of removed animals, 0 if no animals removed or -1 if an error occurs
 */

int removeAnimal(
            int animalId, Animal* animalArray,
            size_t numberOfAnimalsPresent,
            size_t* newNumberOfAnimalsPresent)
{
    for (size_t i = 0; i < numberOfAnimalsPresent; i++)
    {
        if(animalArray[i].Id == animalId)
        {
            animalArray[numberOfAnimalsPresent] = animalArray[i];
            animalArray[i] = animalArray[i - 1];
            *newNumberOfAnimalsPresent = numberOfAnimalsPresent - 1;
        }
    }

    if(&numberOfAnimalsPresent == newNumberOfAnimalsPresent)
    {
        return 0;
    }
    return -1;    
}

/* pre    :
 * post   : The first animal from animalArray with id 'animalId' is copied into
 * animalPtr returns: 1 on success, 0 if not found or -1 if an error occurs
 */

int findAnimalById(
            int animalId, const Animal* animalArray,
            size_t numberOfAnimalsPresent, Animal* animalPtr)
{
    for (size_t i = 0; i < numberOfAnimalsPresent; i++)
    {
        if(animalArray[i].Id == animalId)
        {
            *animalPtr = animalArray[i];
            return 1;
        }
        return 0;
    }
    return -1;
}

/*-------------------------------------------------------------------------------*/

/* pre    :
 * post   : All animals in animalArray are sorted by age
 * returns: 0 on success or -1 if an error occurs 
 * */

int compareAge (const void * a, const void * b)
{
    Animal* y = (Animal*) a;
    Animal* z = (Animal*) b;

    return (y->Age - z->Age);
}

int sortAnimalsByAge(Animal* animalArray, size_t numberOfAnimalsPresent)
{
    qsort(animalArray, numberOfAnimalsPresent, sizeof(Animal), &compareAge);
    if (animalArray[1].Age < animalArray[2].Age)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

/* pre    :
 * post   : All animals in animalArray are sorted by the year in which they were
 * found returns: 0 on success or -1 if an error occurs
 */

int sortAnimalsByYearFound(
            Animal* animalArray, size_t numberOfAnimalsPresent)
{
    Animal temp;
    int swapped;

    while(true)
    {
        swapped = 0;
        for (size_t i = 0; i < numberOfAnimalsPresent; i++)
        {
            if(&animalArray[i].DateFound > &animalArray[i+1].DateFound)
            {
                temp = animalArray[i];
                animalArray[i] = animalArray[i+1];
                animalArray[i+1] = temp;
                swapped = 1;
            }
        }

        if(swapped == 0)
        {
            return 0;
            break;
        }
        
    }
    return -1;
}

int compareSex (const void * a, const void * b)
{
    Animal* y = (Animal*) a;
    Animal* z = (Animal*) b;

    return (y->Sex - z->Sex);
}

int sortAnimalsBySex(Animal* animalArray, size_t numberOfAnimalsPresent)
{
    qsort(animalArray, numberOfAnimalsPresent, sizeof(Animal), &compareSex);
    if(animalArray[1].Sex < animalArray[2].Sex)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
