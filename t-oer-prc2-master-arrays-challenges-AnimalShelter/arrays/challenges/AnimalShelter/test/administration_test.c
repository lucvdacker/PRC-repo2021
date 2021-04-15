#include <string.h>

#include "administration.h"
#include "unity.h"
#include "resource_detector.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void setUp(void)
{
    // This is run before EACH test
}

void tearDown(void)
{
    // This is run after EACH test
}

void test_EmptyTest(void)
{
    TEST_ASSERT_EQUAL(1,1);
}

void test_Add_Animals(void)
{
    size_t animalspresent = 1;
    size_t* newanimalspresent = 0;
    int maxarraylength = 20;
    Animal array[maxarraylength];
    Animal animal = {123, Cat, Female, 3, {1, 2, 2018}};
    int result = addAnimal(&animal, array, maxarraylength, animalspresent, newanimalspresent);
    TEST_ASSERT_EQUAL(0, result);
    TEST_ASSERT_EQUAL(animal.Id, array[animalspresent].Id);
    TEST_ASSERT_EQUAL(animal.Species, array[animalspresent].Species);
    TEST_ASSERT_EQUAL(animal.Sex, array[animalspresent].Sex);
    TEST_ASSERT_EQUAL(animal.Age, array[animalspresent].Age);
    TEST_ASSERT_EQUAL(animal.DateFound.Day, array[animalspresent].DateFound.Day);
    TEST_ASSERT_EQUAL(animal.DateFound.Month, array[animalspresent].DateFound.Month);
    TEST_ASSERT_EQUAL(animal.DateFound.Year, array[animalspresent].DateFound.Year);
}

void test_Add_Two_Animals(void)
{
    size_t animalspresent = 1;
    size_t* newanimalspresent = 0;
    int maxarraylength = 20;
    Animal array[maxarraylength];
    Animal a1 = {123, Cat, Female, 3, {1, 2, 2018}};
    Animal a2 = {321, Dog, Male, 7, {7, 12, 2020}};
    int result = addAnimal(&a1, array, maxarraylength, animalspresent, newanimalspresent);
    TEST_ASSERT_EQUAL(0, result);
    TEST_ASSERT_EQUAL(a1.Id, array[animalspresent].Id);
    TEST_ASSERT_EQUAL(a1.Species, array[animalspresent].Species);
    TEST_ASSERT_EQUAL(a1.Sex, array[animalspresent].Sex);
    TEST_ASSERT_EQUAL(a1.Age, array[animalspresent].Age);
    TEST_ASSERT_EQUAL(a1.DateFound.Day, array[animalspresent].DateFound.Day);
    TEST_ASSERT_EQUAL(a1.DateFound.Month, array[animalspresent].DateFound.Month);
    TEST_ASSERT_EQUAL(a1.DateFound.Year, array[animalspresent].DateFound.Year);

    int secondResult = addAnimal(&a2, array, maxarraylength, animalspresent, newanimalspresent);
    TEST_ASSERT_EQUAL(0, secondResult);
    TEST_ASSERT_EQUAL(a2.Id, array[animalspresent].Id);
    TEST_ASSERT_EQUAL(a2.Species, array[animalspresent].Species);
    TEST_ASSERT_EQUAL(a2.Sex, array[animalspresent].Sex);
    TEST_ASSERT_EQUAL(a2.Age, array[animalspresent].Age);
    TEST_ASSERT_EQUAL(a2.DateFound.Day, array[animalspresent].DateFound.Day);
    TEST_ASSERT_EQUAL(a2.DateFound.Month, array[animalspresent].DateFound.Month);
    TEST_ASSERT_EQUAL(a2.DateFound.Year, array[animalspresent].DateFound.Year);
    TEST_ASSERT_EQUAL(2, animalspresent);
    TEST_ASSERT_EQUAL(2, newanimalspresent);
}
void test_Find_Animals(void)
{
    size_t animalspresent = 1;
    size_t* newanimalspresent = 0;
    int maxarraylength = 20;
    Animal array[maxarraylength];
    Animal animal = {123, Cat, Female, 3, {1, 2, 2018}};
    Animal* animalPtr;
    int result = addAnimal(&animal, array, maxarraylength, animalspresent, newanimalspresent);
    TEST_ASSERT_EQUAL(0, result);
    TEST_ASSERT_EQUAL(1, newanimalspresent);
    int result = findAnimalById(123, array, animalspresent, animalPtr);
    TEST_ASSERT_EQUAL(0, result);
}

void test_Remove_Animals(void)
{
    size_t animalspresent = 1;
    size_t* newanimalspresent = 0;
    int maxarraylength = 20;
    Animal array[maxarraylength];
    Animal a1 = {123, Cat, Female, 3, {1, 2, 2018}};
    int add = addAnimal(&a1, array, maxarraylength, animalspresent, newanimalspresent);
    TEST_ASSERT_EQUAL(0, add);
    TEST_ASSERT_EQUAL(1, newanimalspresent);

    int wrongChip = removeAnimal(124, array, maxarraylength, animalspresent);
    TEST_ASSERT_EQUAL(-1, wrongChip);
    TEST_ASSERT_EQUAL(1, newanimalspresent);

    int result = removeAnimal(123,array, maxarraylength, animalspresent);
    TEST_ASSERT_EQUAL(0, result);
    TEST_ASSERT_EQUAL(0, newanimalspresent);
} 

void test_compareID(void)
{
    size_t animalspresent = 1;
    size_t* newanimalspresent = 0;
    int maxarraylength = 20;
    Animal array[maxarraylength];
    Animal a1 = {123, Cat, Female, 3, {1, 2, 2018}};
    Animal a2 = {321, Dog, Male, 7, {7, 12, 2020}};
    int result = addAnimal(&a1, array, maxarraylength, animalspresent, newanimalspresent);
    TEST_ASSERT_EQUAL(0, result);
    int secondResult = addAnimal(&a2, array, maxarraylength, animalspresent, newanimalspresent);
    TEST_ASSERT_EQUAL(0, secondResult);

    sortAnimalsByAge(array, animalspresent);
    TEST_ASSERT_EQUAL(a1.Id, array[0].Id);
}

void test_SortAnimalByAge(void)
{
    size_t animalspresent = 0;
    size_t* newanimalspresent = 0;
    int maxarraylength = 20;
    Animal array[maxarraylength];
    Animal a1 = {123, Cat, Female, 3, {1, 2, 2018}};
    Animal a2 = {321, Dog, Male, 7, {7, 12, 2020}};
    addAnimal(&a1, array, maxarraylength, animalspresent, newanimalspresent);
    addAnimal(&a2, array, maxarraylength, animalspresent, newanimalspresent);
}

int main (int argc, char * argv[])
{
    UnityBegin();

    MY_RUN_TEST(test_Add_Animals);
    MY_RUN_TEST(test_Add_Two_Animals);
    MY_RUN_TEST(test_Find_Animals);
    MY_RUN_TEST(test_Remove_Animals);

    return UnityEnd();
}