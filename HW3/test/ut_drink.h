#include <bits/stdc++.h>
#include "../src/drink.h"
#include <string>


TEST(DRINK,Sample1){
    /* Setup name to "Signature Black Tea with Milk"（熟成歐蕾）. */
    /* Setup sweetness level to 0.3 */
    Drink drink("Signature Black Tea with Milk",0.3);

    ASSERT_EQ(drink.getName(),"Signature Black Tea with Milk");
    ASSERT_EQ(drink.getSweetnessLevel(),0.3);
}

TEST(DRINK,Sample2){
    /* Add some topping */
    Drink drink;
    drink.addTopping("Bubble");
    drink.addTopping("Pudding");

    ASSERT_EQ(drink.getToppingByIndex(1),"Pudding");
    ASSERT_EQ(drink.getToppingByIndex(0),"Bubble");
    ASSERT_THROW(drink.getToppingByIndex(2),std::string);
}

TEST(DRINK,Sample3){
    /* Add some topping */
    Drink drink;
    /* Add some topping */
    drink.addTopping("Bubble");
    drink.addTopping("Pudding");

    /* Get the count of topping */
    ASSERT_EQ(drink.getToppingCount(),2); // Assert it will return 2.
}

// [5%] Write two test case to check Drink::Drink() work correctly.
TEST(DRINK,Drink_WORK1){
   Drink drink;
   ASSERT_THROW(drink.getName(),std::string);
   ASSERT_THROW(drink.getSweetnessLevel(),std::string);
}
TEST(DRINK,Drink_WORK2){
   Drink drink("abcde",0.3);
   ASSERT_EQ(drink.getName(),"abcde");
   ASSERT_EQ(drink.getSweetnessLevel(),0.3);

   ASSERT_THROW(Drink drink1("abc",0.5);,std::string);


   ASSERT_THROW(Drink drink2("abc",-1);,std::string);

   ASSERT_THROW(Drink drink3("abcde",-1);,std::string);

}
// [6%] Write two test case to check Drink::getName work correctly.
TEST(DRINK,getName1){
    ASSERT_THROW(Drink drink("abc",0.3);,std::string);
}

TEST(DRINK,getName2){
    Drink drink("abcde",0.3);
    ASSERT_EQ(drink.getName(),"abcde");
}

//[6%] Write two test case to check Drink::getSweetnessLevel work correctly.
TEST(DRINK,getSweetnessLevel_1){
    Drink drink;
    ASSERT_THROW(drink.getSweetnessLevel(),std::string);

    for(int i=0;i<10;i++){
        float SweetnessLevel = (float)(rand()%5)/2+(float)(rand()%4)/5;
        std::cout << " SweetnessLevel : "<< SweetnessLevel  <<std::endl;

        if(SweetnessLevel < 0 || SweetnessLevel > 1){
            std::cout << "out of range -- SweetnessLevel" <<std::endl;
            ASSERT_THROW(Drink drink2("bubble",SweetnessLevel),std::string);
        }else{
            Drink drink2("bubble",SweetnessLevel);
            std::cout << "in range -- SweetnessLevel" <<std::endl;
            ASSERT_EQ(drink2.getSweetnessLevel(),SweetnessLevel);
        }
    }
}

TEST(DRINK,getSweetnessLevel_2){

    for(int i=0;i<20;i++){
        /* initial */
        if(i%3==0){
            Drink drink;
            ASSERT_THROW(drink.getSweetnessLevel(),std::string);
        }else if (i%3==1)
        {
            float SweetnessLevel = (float)(rand()%4)/2+(float)(rand()%2)/2;

            std::cout << " SweetnessLevel : "<< SweetnessLevel  <<std::endl;

            if(SweetnessLevel < 0 || SweetnessLevel > 1){
                std::cout << "out of range -- SweetnessLevel" <<std::endl;
                ASSERT_THROW(Drink drink2("bubble",SweetnessLevel),std::string);
            }else{
                Drink drink2("bubble",SweetnessLevel);
                std::cout << "in range -- SweetnessLevel" <<std::endl;
                ASSERT_EQ(drink2.getSweetnessLevel(),SweetnessLevel);
            }
        }
        else
        {
            /* range is negative*/

            ASSERT_THROW(Drink drink3("black tea",(float)(i-20));,std::string);
        }
    }
}

// [6%] Write two test case to check Drink::addTopping work correctly.
// [6%] Write two test case to check Drink::getToppingByIndex work correctly.
// [6%] Write two test case to check Drink::getToppingCount work correctly.
TEST(DRINK,ADDTOP_1){
    std::string eat[12]={"bubble","Pudding","grass jelly","rat noodle","aloe","coconut jelly","aloe vera","OREO","taro paste","taro ball","tangyua","apple"};
    Drink drink("BLACK TEA",0.5);
    int test = (rand()%12 >> rand()%3) << rand()%3 ;
    // int test2=test1;
    std::cout << "test : " << test <<std::endl;
    for(int i=0;test!=0;i++){
        std::cout << "topping : "<< eat[test] << std::endl;
        drink.addTopping(eat[test]);
        ASSERT_EQ(drink.getToppingByIndex(i),eat[test]);
        test = test & (test-1);
    }
}

TEST(DRINK,ADDTOP_2){
    std::string eat[12]={"bubble","Pudding","grass jelly","rat noodle","aloe","coconut jelly","aloe vera","OREO","taro paste","taro ball","tangyua","apple"};
    Drink drink("BLACK TEA",0.5);
    int test = (rand()%12 >> rand()%3) << rand()%3 ;
    // int test2=test1;
    std::cout << "test : " << test <<std::endl;
    for(int i=0;test!=0;i++){
        std::cout << "topping : "<< eat[test] << std::endl;
        drink.addTopping(eat[test]);
        ASSERT_EQ(drink.getToppingByIndex(i),eat[test]);
        test --;
    }
}

TEST(DRINK,getToppingByIndex_1){
    std::string eat[12]={"bubble","Pudding","grass jelly","rat noodle","aloe","coconut jelly","aloe vera","OREO","taro paste","taro ball","tangyua","apple"};
    Drink drink("BLACK TEA",0.5);
    int test = (rand()%12 >> rand()%3) << rand()%3 ;
    // int test2=test1;
    std::cout << "test : " << test <<std::endl;
    for(int i=0;test!=0;i++){
        int rand_test=rand()%12;
        std::cout << "rand_test : "<< rand_test << "| i :" << i << std::endl;
        std::cout << "topping : "<< eat[test] << std::endl;
        drink.addTopping(eat[test]);
        if(rand_test>i){
            ASSERT_THROW(drink.getToppingByIndex(rand_test),std::string);
        }
        else{
            ASSERT_EQ(drink.getToppingByIndex(i),eat[test]);
        }
        test --;
    }
}

TEST(DRINK,getToppingByIndex_2){
    std::string eat[12]={"bubble","Pudding","grass jelly","rat noodle","aloe","coconut jelly","aloe vera","OREO","taro paste","taro ball","tangyua","apple"};
    Drink drink("BLACK TEA",0.5);
    int test = (rand()%12 >> rand()%3) << rand()%3 ;
    // int test2=test1;
    std::cout << "test : " << test <<std::endl;
    for(int i=0;test!=0;i++){
        int rand_test=rand()%12;
        std::cout << "rand_test : "<< rand_test << "| i :" << i << std::endl;
        std::cout << "topping : "<< eat[test] << std::endl;
        drink.addTopping(eat[test]);
        if(rand_test>i){
            ASSERT_THROW(drink.getToppingByIndex(rand_test),std::string);
        }
        else{
            ASSERT_EQ(drink.getToppingByIndex(i),eat[test]);
        }
        test=test&(test-1);
    }
}

TEST(DRINK,getToppingCount1){
    std::string eat[12]={"bubble","Pudding","grass jelly","rat noodle","aloe","coconut jelly","aloe vera","OREO","taro paste","taro ball","tangyua","apple"};
    Drink drink("GREEN TEA",0.5);
    int index=0;
    while(index<12){
        drink.addTopping(eat[index]);
        if(index%2==0){
            ASSERT_EQ(drink.getToppingCount(),index+1);
        }
        index++;
    }
    ASSERT_EQ(drink.getToppingCount(),index);
}

TEST(DRINK,getToppingCount2){
    std::string eat[12]={"bubble","Pudding","grass jelly","rat noodle","aloe","coconut jelly","aloe vera","OREO","taro paste","taro ball","tangyua","apple"};
    Drink drink("GREEN TEA",0.5);
    int index=rand()%12;
    for(int i=0;index!=0;i++){
       drink.addTopping(eat[index]);
       ASSERT_EQ(drink.getToppingCount(),i+1);
       index=index&(index-1);
    }
}